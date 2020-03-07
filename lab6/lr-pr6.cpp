#include <iostream>
#include <httplib/httplib.h>
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

void replace(std::string & str, const std::string from, std::string  to, int key)
{
	switch(key)
	{
		case 1: to = to.substr(1, 10); break;
		case 2: to = to.substr(1, 3); break;
	}
	int start_pos = str.find(from);
	if (start_pos == std::string::npos) return;

	str.replace(start_pos, from.length(), to);
}

// APPID=b3b3215efcb4017b119668066e83bc9e
void gen_response(const httplib::Request& req, httplib::Response& res) 
{
	std::string HtmlCode;
	httplib::Client cli("api.openweathermap.org", 80);
	auto result = cli.Get("/data/2.5/forecast?id=693805&units=metric&APPID=b3b3215efcb4017b119668066e83bc9e");
	json j;
	if (result && result->status == 200) j = json::parse(result->body);

	std::ifstream stream("informer_template.html");
	getline(stream, HtmlCode, '\0');
	stream.close();

	replace(HtmlCode, "{city.name}", j["city"]["name"].dump(), 1);
	for(int i = 0; i < 5; i++)
	{

		int temp = j["list"][0]["dt"];
		for (int i = 0; i < 40; i++) // 40 так как всего 40 объектов в list(5 дней каждые 3 часа, это 8 в день, всего 40)
		{
			if (j["list"][i]["dt"] >= temp)
			{
				replace(HtmlCode, "{list.dt}", j["list"][i]["dt_txt"].dump(), 1);
				replace(HtmlCode, "{list.weather.icon}", j["list"][i]["weather"][0]["icon"].dump(), 2);
				replace(HtmlCode, "{list.main.temp}", j["list"][i]["main"]["temp"].dump(), 0);
				temp += 86400;
			}
		}
	}
	
	res.set_content(HtmlCode, "text/html");
}


int main()
{
	httplib::Server svr;                    
	svr.Get("/", gen_response);   
	svr.listen("localhost", 3000);
}
