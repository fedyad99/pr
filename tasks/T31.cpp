#include <iostream>
#include <string>

std::string maze[25] = {
"####B######################",
"# #       #   #      #    #",
"# # # ###### #### ####### #",
"# # # #       #   #       #",
"#   # # ######### # ##### #",
"# # # #   #       #     # #",
"### ### ### ############# #",
"# #   #     # #           #",
"# # #   ####### ###########",
"# # # #       # #         C",
"# # ##### ### # # ####### #",
"# # #     ### # #       # #",
"#   ##### ### # ######### #",
"######### ### #           #",
"# ####### ### #############",
"A           #   ###   #   #",
"# ############# ### # # # #",
"# ###       # # ### # # # #",
"# ######### # # ### # # # F",
"#       ### # #     # # # #",
"# ######### # ##### # # # #",
"# #######   #       #   # #",
"# ####### ######### #######",
"#         #########       #",
"#######E############D######"
};

std::string ExitLab = "";

struct Cor {
	int x;
	int y;
};

bool Check(Cor cor) 
{
	if (cor.x > 27 || cor.x < 0 || cor.y > 24 || cor.y < 0 || maze[cor.y][cor.x] == '#') 
	{
		std::cout << "Не верные координаты";
		return true;
	}
	return false;
}

void Sort() 
{
	for (int i = 0; i < ExitLab.size() - 1; i++) 
	{
		for (int j = 0; j < ExitLab.size() - i - 1; j++) 
		{
			if (ExitLab[j] > ExitLab[j+1]) 
			{
				char temp = ExitLab[j];
				ExitLab[j] = ExitLab[j + 1];
				ExitLab[j + 1] = temp;
			}
		}
	}
}

void AddExit(char exit) 
{
	for (int i = 0; i < ExitLab.size(); i++) 
		if (exit == ExitLab[i]) return;
	ExitLab += exit;
	Sort();
}

void Search(Cor cor) 
{

		if (isalpha(maze[cor.y][cor.x])) 
		{ 
			AddExit(maze[cor.y][cor.x]); 
			return; 
		}
		maze[cor.y][cor.x] = '#';

		if (maze[cor.y + 1][cor.x] != '#') Search(Cor{ cor.x, cor.y + 1 });
		if (maze[cor.y - 1][cor.x] != '#') Search(Cor{ cor.x, cor.y - 1 });
		if (maze[cor.y][cor.x + 1] != '#') Search(Cor{ cor.x + 1, cor.y });
		if (maze[cor.y][cor.x - 1] != '#') Search(Cor{ cor.x - 1, cor.y });
	

}

int main()
{
	setlocale(LC_ALL, "Russian");

	Cor Coordinates;
	std::cin >> Coordinates.x >> Coordinates.y;
	if (Check(Coordinates)) return 0;

	Search(Coordinates);

	if (ExitLab.size() == 0) std::cout << "Выхода нет" << std::endl;
	else for (int i = 0; i < ExitLab.size(); i++) std::cout << ExitLab[i] << " ";

	return 0;
}
