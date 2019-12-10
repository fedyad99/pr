#include <iostream>
#include "libbmp.h"
#include <string>
using namespace std;

enum Channel {
	RED,
	GREEN,
	BLUE
};

int binary_to_int(string t){
	int result = (int)(t[0] - 48) * 128 + (int)(t[1] - 48) * 64 +
		(int)(t[2] - 48) * 32 + (int)(t[3] - 48) * 16 +
		(int)(t[4] - 48) * 8 + (int)(t[5] - 48) * 4 +
		(int)(t[6] - 48) * 2 + (int)(t[7] - 48);
	return result;
}

bool check(string* temp) {
	if (temp->size() == 8) {
		if ((char)binary_to_int(*temp) == '\0') return false;
		cout << (char)binary_to_int(*temp);
		*temp = "";
	}
	return true;
}

bool getChar(BmpImg* img, int x, int y, string* temp, Channel channel ) {
	switch (channel){
	case RED: 
		*temp += ((int)img->red_at(x, y)) % 2 + 48;
		break;
	case GREEN: 
		*temp += ((int)img->green_at(x, y)) % 2 + 48;
		break;
	case BLUE: 
		*temp += ((int)img->blue_at(x, y)) % 2 + 48;
		break;
	}
	if (!check(temp)) return false;
	return true;
}


int main(){
	setlocale(LC_ALL, "Russian");
	BmpImg img;
	img.read("pic2.bmp");
	string temp = "";

	for (int i = 0; i < img.get_height(); i++) {         // KEY  =  00r 00g 00b 10r 10g 10b 01r 01g
		for (int j = 0; j < img.get_width(); j++) {   
			if (!getChar(&img, j, i, &temp, RED)) return 1;
			if (!getChar(&img, j, i, &temp, GREEN)) return 2;
			if (!getChar(&img, j, i, &temp, BLUE)) return 3;
		}
	}

	return 4;
}