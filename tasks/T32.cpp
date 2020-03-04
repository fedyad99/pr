#include <iostream>
#include <string>
#include <stack>

bool Correct(char str) {
	if (str == '-' || str == '+' || str == '*' || str == '/' || str == '^' || str == ')' || str == '(') return true;
	return false;
}

int Priority(char a)
{
	switch (a)
	{
		case '*': return 2;
		case '/': return 2;
		case '^': return 3;
		default: return 1;
	}
}

std::string ItoOPN(std::string str) 
{
	std::string temp = "";
	std::stack<char> Stack;

	int MoreDigit = 0, // Если в числе больше одного разряда
		SpacesCount = 0, // Чтобы учитывать пробелы при выводе
		j; // Для определения разряда
	for (int i = 0; i < str.size(); i++) 
	{
		if(str[i] != ' ')
		{
			if (isdigit(str[i]) || str[i] == '-' && isdigit(str[i + 1]))// обработка числа, нужна для отрицательных чисел и для тех, у которых разряд больше 1
			{
				j = 1;
				if (i + j != str.size()) 
					while (str[i + j] != ' ') 
					{
						j++; if (i + j == str.size()) break;
					}

				if (j == 1) temp = temp + str[i] + ' ';
				else
				{
					for (int n = 0; n < j; n++) temp += str[n + i];
					temp += ' ';
				}
				i += j - 1;
				MoreDigit += j - 1;
				SpacesCount++;
			}
			else if (Correct(str[i])) 
			{
				if (str[i] == ')') 
				{
					while (Stack.top() != '(')
					{
						temp = temp + Stack.top() + ' ';
						Stack.pop();
					}
					Stack.pop();
				}
				else
				{
					if (Stack.empty()) Stack.push(str[i]);		
					else 
						if(Priority(Stack.top()) == Priority(str[i]) && isdigit(temp[temp.size() - 2]) && Stack.top() != '(')
						{
							temp = temp + Stack.top() + ' ';
							Stack.pop();
							Stack.push(str[i]);
						}
						else Stack.push(str[i]);
				}
			}
		}
	}
	while (!Stack.empty())
	{
		temp = temp + Stack.top() + ' ';
		Stack.pop();
	}
	return temp;
}

double Calculate(std::string str)
{
	std::string temp = "";
	std::stack<double> Stack;
	int j; // Для определения разряда

	for (int i = 0; i < str.size() - 1; i++)
	{
		if (str[i] != ' ')
		{
			if (isdigit(str[i]) || str[i] == '-' && isdigit(str[i + 1]))// обработка числа, нужна для отрицательных чисел и для тех, у которых разряд больше 1
			{
				j = 1;
				if (i + j != str.size())
					while (str[i + j] != ' ')
					{
						j++; if (i + j == str.size()) break;
					}

				if (j == 1) temp = temp + str[i];
				else
				{
					for (int n = 0; n < j; n++) temp += str[n + i];
				}
				i += j - 1;
			}
			if (temp.size() != 0)
			{
				Stack.push(stod(temp));
				temp = "";
			}

			if(Correct(str[i]))
			{
				double a, b = 2;
				switch (str[i])
				{
				case '+':
					a = Stack.top();
					Stack.pop();
					a += Stack.top();
					Stack.pop();
					Stack.push(a);
					break;

				case '-':
					a = Stack.top();
					Stack.pop();
					b = Stack.top();
					Stack.pop();
					a = b - a;
					Stack.push(a);
					break;

				case '/':
					a = Stack.top();
					Stack.pop();
					b = Stack.top();
					Stack.pop();
					a = b / a;
					Stack.push(a);
					break;

				case '*':
					a = Stack.top();
					Stack.pop();
					a *= Stack.top();
					Stack.pop();
					Stack.push(a);
					break;

				case '^':
					a = Stack.top();
					Stack.pop();
					b = Stack.top();
					Stack.pop();
					a = pow(b, a);
					Stack.push(a);
					break;
				}
			}
		}


	}
	return Stack.top();
}


int main()
{
	std::string str;
	std::getline(std::cin, str);
	std::cout << ItoOPN(str)<< std::endl;
	std::cout << Calculate(ItoOPN(str));
}
