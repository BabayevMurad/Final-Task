#include <iostream>

#include <windows.h>

#include "Structs.h"

#include "Getch.h"

#include "Color.h"

#include "Menyu.h"

#include "Telefon.h"

#include "Isci.h"

#include "Axtaris.h"

#include <conio.h>




#pragma region telefon_maqazasi

void telefon_maqazasi(Worker**& arry_isci, Telefon**& arry_telefon, short size, bool baqlanma = false) {
	bool isleme = true;
	short* size_telefon = new short(size);
	short* size_isci = new short(size);
	if (baqlanma) {
		exit(0);
		return;
	}
	while (isleme) {
		short chose;
		isleme = esas_menyu_tam(arry_telefon, arry_isci, size_telefon, size_isci);
	}
}

#pragma endregion