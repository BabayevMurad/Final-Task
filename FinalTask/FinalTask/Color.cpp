#include "Getch.h"

#pragma region Color

void change_color(int color) {
	HANDLE console_color;
	console_color = GetStdHandle(
		STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color, color);
}

#pragma endregion