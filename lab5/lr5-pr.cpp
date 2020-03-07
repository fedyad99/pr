#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

enum Sex {
	MALE,
	FAMALE
};

struct Answer {
	int Survival = 0;
	int SurvivalP1 = 0;
	int SurvivalP2 = 0;
	int SurvivalP3 = 0;
	int SurvivalM = 0;
	int SurvivalF = 0;
	double AverageAge[3]; // 0 - пассажир/ 1 - женский/2 - мужской
	int Embarked[3] = { 0 };// 0 - Cherbourg; 1 - Queenstown; 2 - Southampton
	string emb = "";
	vector<int> id;
};

struct TrainData {
	int PassengerId;
	bool Survived;
	int Pclass;
	string Name;
	Sex sex;
	int Age;
	int SibSp;
	int Parch;
	string Ticket;
	double Fare;
	string Cabin;
	char Embarked;
};

TrainData ParsStr(string str) {
	TrainData train;
	string temp[13];
	int i = 0;

	for (int j = 0; j < 13; j++) {
		while (str[i] != ',' && str[i] != '\0') {
			temp[j] += str[i];
			i++;
		}
		i++;
	}

	train.PassengerId = atoi(temp[0].c_str());
	train.Survived = atoi(temp[1].c_str());
	train.Pclass = atoi(temp[2].c_str());
	train.Name = temp[3] + "," + temp[4];
	temp[5].size() > 5 ? train.sex = FAMALE : train.sex = MALE;
	train.Age = atoi(temp[6].c_str());
	train.SibSp = atoi(temp[7].c_str());
	train.Parch = atoi(temp[8].c_str());
	train.Ticket = temp[9];
	train.Fare = atof(temp[10].c_str());
	train.Cabin = temp[11];
	train.Embarked = temp[12][0];
	return train;
}

void read_file(char* filename, vector<TrainData> &train) {
	ifstream in(filename); 
	string TempLine;
	bool FirstLine = true;
	if (in.is_open()){
		while (getline(in, TempLine)){
			if (FirstLine) {
				FirstLine = false;
				continue;
			}
			train.push_back(ParsStr(TempLine));
		}
	}
	in.close();
}

void print(Answer ans) {
	cout << "Общее число выживших: " << ans.Survival << endl;
	cout << "Число выживших из 1 класса: " << ans.SurvivalP1 << endl;
	cout << "Число выживших из 2 класса: " << ans.SurvivalP2 << endl;
	cout << "Число выживших из 3 класса: " << ans.SurvivalP3 << endl;
	cout << "Количество выживших женщин: " << ans.SurvivalF << endl;
	cout << "Количество выживших мужчин: " << ans.SurvivalM << endl;
	cout << "Средний возраст пассажира/женский/мужской: " << ans.AverageAge[0] << "/" << ans.AverageAge[1] << "/" << ans.AverageAge[2] << endl;
	cout << "Штат, в котором село больше всего пассажиров: " << ans.emb << endl;
	cout << "Список идентификаторов несовершеннолетних: ";
	for (int i = 0; i < ans.id.size(); i++) {
		cout << ans.id[i];
		if (i != ans.id.size() - 1) cout << ",";
	}
}

void write(Answer ans,char *filename) {
	ofstream out(filename, ios::out);
	out << ans.Survival<<endl;
	out << ans.SurvivalP1 << endl;
	out << ans.SurvivalP2 << endl;
	out << ans.SurvivalP3 << endl;
	out << ans.SurvivalF << endl;
	out << ans.SurvivalM << endl;
	out << ans.AverageAge[0] << " " << ans.AverageAge[1] << " " << ans.AverageAge[2] << endl;
	out << ans.emb << endl;
	for (int i = 0; i < ans.id.size(); i++) {
		out << ans.id[i];
		if (i != ans.id.size() - 1) out << ",";
	}
	out.close();
}

int main(){
	setlocale(LC_ALL, "Russian");
	char filename[] = "train.csv";
	char filename2[] = "Answer.txt";
	vector<TrainData> train;
	read_file(filename, train);

	Answer ans; double temp[3] = { 0 }; int tempCount[3] = { 0 };
	for (int i = 0; i < train.size(); i++) {
		if (train[i].Age < 18) ans.id.push_back(train[i].PassengerId);
		if (train[i].Survived) {
			ans.Survival++;
			switch (train[i].Pclass){
			case 1: ans.SurvivalP1++; break;
			case 2: ans.SurvivalP2++; break;
			case 3: ans.SurvivalP3++; break;
			}
			train[i].sex == MALE ? ans.SurvivalM++ : ans.SurvivalF++;
		}
		if (train[i].Age > 0) {
			tempCount[0]++;
			temp[0] += train[i].Age;
			if (train[i].sex == FAMALE) {
				temp[1] += train[i].Age;
				tempCount[1]++;
			}
			else {
				temp[2] += train[i].Age;
				tempCount[2]++;
			}
			
		}
		if (train[i].Embarked == 'C') ans.Embarked[0]++;
		else if (train[i].Embarked == 'Q') ans.Embarked[1]++;
		else if (train[i].Embarked == 'S') ans.Embarked[2]++;
	}
	if (ans.Embarked[0] > ans.Embarked[1]) {
		if (ans.Embarked[0] > ans.Embarked[2]) ans.emb = "Cherbourg";
		else ans.emb = "Southampton";
	}
	else if (ans.Embarked[1] > ans.Embarked[2]) {
		ans.emb = "Queenstown";
	}
	else ans.emb = "Southampton";
	ans.AverageAge[0] = temp[0] / tempCount[0];
	ans.AverageAge[1] = temp[1] / tempCount[1];
	ans.AverageAge[2] = temp[2] / tempCount[2];

	print(ans);
	write(ans,filename2);
	return 0;
}
