#include <iostream>

#include <windows.h>

#include "Structs.h"

#include "Getch.h"

#include "Color.h"

#include "Menyu.h"

#include <conio.h>

#pragma region Menyu

/*Telefon menyu funksiyalari define*/

int telefonlar_menyu(Telefon**& arry_telefon, short*& size); // Bütün telefonları çıxardan funksiya.

void telefonlar_menyu_tam(Telefon**& arry_telefon, Worker**& arry_worker, short*& size);

void isci_menyu_tam(Telefon**& arry_telefon, Worker**& arry_worker, short*& size);

void axtaris_menyu_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci);

void telefon_maqazasi(Worker**& arry_isci, Telefon**& arry_telefon, short size, bool baqlanma);


/*Esas Menyu funksiyalari.*/


int esas_menyu_ekran(short secim = 1) {

	system("Cls");

	char** menyu = new char* [4];

	menyu[0] = new char[14] {"ESC. Cixish"};
	menyu[1] = new char[14] {"1. Telefonlar"};
	menyu[2] = new char[14] {"2. Ishchiler"};
	menyu[3] = new char[14] {"3. Axtarish" };

	for (size_t i = 0; i < 4; i++) {
		if (secim == i) {
			change_color(GREEN);
			cout << menyu[i] << endl;
			change_color(WHITE);
			continue;
		}
		cout << menyu[i] << endl;
	}

	short kod = _getch();

	if (kod == DOWN) {
		if (secim < 3) {
			secim++;
			esas_menyu_ekran(secim);
		}

		else {
			secim = 1;
			esas_menyu_ekran(secim);
		}
	}

	else if (kod == UP) {
		if (secim > 1) {
			secim--;
			esas_menyu_ekran(secim);
		}

		else {
			secim = 3;
			esas_menyu_ekran(secim);
		}
	}

	else if (kod == ESC) {
		delete[] menyu;
		return 0;
	}

	else if (kod == ENTER) {
		delete[] menyu;
		return secim;
	}

	else {
		esas_menyu_ekran(secim);
	}

}



int esas_menyu() { // Ekrana ilk seçimler və seçimin daxil edilməsi cıxır.
	system("cls");

	return esas_menyu_ekran();
}



bool esas_menyudan_kecid(Telefon**& arry_telefon, Worker**& arry_worker, short*& size_telefon, short*& size_isci, short secim) { // Esas menyudan (istifadəçi daxil etdiyi melumata görə) lazım olan funksiyanı çağırmaq üçündür.
	bool duzgun_secim = true; // İstifadəçinin daxil etdiyi seçiminin düzgunlüyünü yoxlaması üçündür.
	do {
		system("cls");
		switch (secim) {
		case 0: // Bu proqramı bağlayır. (Arxaya deyer qaytarmaqla.)
			telefon_maqazasi(arry_worker, arry_telefon, *size_telefon, true);
			break;
		case 1: // Bu telefonlar menyusunu çıxardır.
			telefonlar_menyu_tam(arry_telefon, arry_worker, size_telefon);
			break;
		case 2: // Bu işçilər menyusunu çıxardır.
			isci_menyu_tam(arry_telefon, arry_worker, size_isci);
			break;
		case 3: // Bu axtarış menyusunu çıxardır.
			axtaris_menyu_tam(arry_telefon, arry_worker, size_telefon, size_isci);
			break;
		default: // Bu istifadəçinin səhf daxil etdiyini kansola çıxardır.
			cout << "Xais olunur duzgun secim daxil edin.";
			duzgun_secim = false;
			Sleep(2000);
			esas_menyu();
			break;
		}
	} while (!duzgun_secim);

	return true;
}



bool esas_menyu_tam(Telefon**& arry_telefon, Worker**& arry_worker, short*& size_telefon, short*& size_isci) {
	short secim = esas_menyu();
	return esas_menyudan_kecid(arry_telefon, arry_worker, size_telefon, size_isci, secim);
}

#pragma endregion