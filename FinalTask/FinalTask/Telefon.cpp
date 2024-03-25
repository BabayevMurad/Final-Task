#include <iostream>

#include <windows.h>

#include "Structs.h"

#include "Getch.h"

#include "Color.h"

#include "Menyu.h"

#include "Telefon.h"

#include <conio.h>

#pragma region Telefon_All


/*Telefon Menyusunun funksiyaları.*/


/*Telefon Menyusunun funksiyalarının defineleri.*/


void telefon_melumat_tam(Telefon**& arry_telefon, Worker**& arry_worker, short choose_for_arry, short*& size);

void telefon_elave_tam(Telefon**& arry_telefon, Worker**& arry_worker, short*& size);

void telefon_silinme_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size, short choose_for_arry);

int telefonlar_menyu_color(Telefon**& arry_telefon, short*& size, short secim) {

	system("Cls");

	short i = 0;

	cout << "ESC. Evvele qayitmaq ucun." << endl;
	for (i = 1; i <= *size; i++) {
		if (secim == i) {
			change_color(GREEN);
			cout << i << ". ";
			arry_telefon[i - 1]->print_for_menyu();
			change_color(WHITE);
			continue;
		}
		cout << i << ". ";
		arry_telefon[i - 1]->print_for_menyu();
	}
	if (i == secim) {
		change_color(GREEN);
		cout << *size + 1 << ". Telefon elave et." << endl;
		change_color(WHITE);
	}
	else {
		cout << *size + 1 << ". Telefon elave et." << endl;
	}

	short kod = _getch();

	if (kod == DOWN) {
		if (secim < *size + 1) {
			secim++;
			telefonlar_menyu_color(arry_telefon, size, secim);
		}

		else {
			secim = 1;
			telefonlar_menyu_color(arry_telefon, size, secim);
		}
	}

	else if (kod == UP) {
		if (secim > 1) {
			secim--;
			telefonlar_menyu_color(arry_telefon, size, secim);
		}

		else {
			secim = *size + 1;
			telefonlar_menyu_color(arry_telefon, size, secim);
		}
	}

	else if (kod == ESC) {
		return 0;
	}

	else if (kod == ENTER) {
		return secim;
	}

	else {
		telefonlar_menyu_color(arry_telefon, size, secim);
	}

}

int telefonlar_menyu(Telefon**& arry_telefon, short*& size) { // Bütün telefonları çıxardır.

	short choose = telefonlar_menyu_color(arry_telefon, size);

	return choose;
}



void telefonlar_menyu_kecid(Telefon**& arry_telefon, Worker**& arry_worker, short choose, short*& size) {
	bool duzgun_secim = true; // İstifadəçinin daxil etdiyi seçiminin düzgunlüyünü yoxlaması üçündür.
	do {
		system("cls");
		if (choose > 0 and choose <= *size) { //Seçimin düzgün olması və lazım olan funksiyaların çağırılması.
			telefon_melumat_tam(arry_telefon, arry_worker, choose, size);
		}
		else if (choose == 0) { // Evvele qayidir
			//esas_menyu_tam(arry_telefon, arry_worker, size);
		}
		else if (choose == *size + 1) { // Yeni telefon eleve edir.
			telefon_elave_tam(arry_telefon, arry_worker, size);
		}
		else { // Bu istifadəçinin səhf daxil etdiyini kansola çıxardır.
			cout << "Xais olunur duzgun secim daxil edin.";
			duzgun_secim = false;
			Sleep(2000);
			telefonlar_menyu(arry_telefon, size);
		}
	} while (!duzgun_secim);
}



int telefon_melumat_color(Telefon**& arry_telefon, short choose_for_arry, short secim) {

	system("Cls");

	char** menyu = new char* [2];

	menyu[0] = new char[18] {"1. Evele qayitmaq"};
	menyu[1] = new char[18] {"2. Telefon silmek"};

	arry_telefon[choose_for_arry - 1]->showinfo();

	for (size_t i = 0; i < 2; i++) {
		if (secim == i + 1) {
			change_color(GREEN);
			cout << menyu[i] << endl;
			change_color(WHITE);
			continue;
		}
		cout << menyu[i] << endl;
	}

	short kod = _getch();

	if (kod == DOWN) {
		if (secim < 2) {
			secim++;
			telefon_melumat_color(arry_telefon, choose_for_arry, secim);
		}

		else {
			secim = 1;
			telefon_melumat_color(arry_telefon, choose_for_arry, secim);
		}
	}

	else if (kod == UP) {
		if (secim > 1) {
			secim--;
			telefon_melumat_color(arry_telefon, choose_for_arry, secim);
		}

		else {
			secim = 2;
			telefon_melumat_color(arry_telefon, choose_for_arry, secim);
		}
	}

	else if (kod == ESC) {
		delete[] menyu;
		return 1;
	}

	else if (kod == ENTER) {
		delete[] menyu;
		return secim;
	}

	else {
		telefon_melumat_color(arry_telefon, choose_for_arry, secim);;
	}

}



int telefon_melumat(Telefon**& arry_telefon, short choose_for_arry) { // Telefonun bütün məlumatlarını çıxardır.

	short choose = telefon_melumat_color(arry_telefon, choose_for_arry);

	return choose;
}



void telefon_melumat_yoxlanis(Telefon**& arry_telefon, Worker**& arry_worker, short choose, short choose_for_arry, short*& size) {
	bool duzgun_secim = true; // İstifadəçinin daxil etdiyi seçiminin düzgunlüyünü yoxlaması üçündür.
	do {
		system("cls");
		switch (choose) {
		case 1: // Bu evvele qayitmaq ucundur.
			telefonlar_menyu_tam(arry_telefon, arry_worker, size);
			break;
		case 2: // Bu telefon silmek ucundur.
			telefon_silinme_tam(arry_telefon, arry_worker, size, choose_for_arry);
			break;
		default: // Bu istifadəçinin səhf daxil etdiyini kansola çıxardır.
			cout << "Xais olunur duzgun secim daxil edin.";
			duzgun_secim = false;
			Sleep(2000);
			telefon_melumat(arry_telefon, choose_for_arry);
			break;
		}
	} while (!duzgun_secim);
}



void telefon_silinme(Telefon**& arry_telefon, short*& size, short choose_for_arry) { // Telefonu massivdən silir.
	Telefon** arry_telefon_copy = new Telefon * [*size - 1];
	for (size_t i = 0; i < (choose_for_arry - 1); i++) {
		arry_telefon_copy[i] = arry_telefon[i];
	}
	for (size_t i = (choose_for_arry); i < *size; i++) {
		arry_telefon_copy[i - 1] = arry_telefon[i];
	}
	delete[] arry_telefon;
	arry_telefon = arry_telefon_copy;
	*size -= 1;
	system("cls");
	cout << "Uqurla silindi.";
	Sleep(2000);
	system("cls");
}


void telefon_silinme_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size, short choose_for_arry) {
	telefon_silinme(arry_telefon, size, choose_for_arry);
	telefonlar_menyu_tam(arry_telefon, arry_isci, size);
}



void telefon_melumat_tam(Telefon**& arry_telefon, Worker**& arry_worker, short choose_for_arry, short*& size) { //Bu telefon ikinci menyunusunu birləşdirir.
	short chose;
	chose = telefon_melumat(arry_telefon, choose_for_arry);
	telefon_melumat_yoxlanis(arry_telefon, arry_worker, chose, choose_for_arry, size);
}



void telefonlar_menyu_tam(Telefon**& arry_telefon, Worker**& arry_worker, short*& size) { //Burada bütün funksiyalar birləşəcək
	short chose;
	chose = telefonlar_menyu(arry_telefon, size);
	telefonlar_menyu_kecid(arry_telefon, arry_worker, chose, size);

}



Telefon* telefon_elave_etmek_menyu(Telefon**& arry_telefon, Worker**& arry_worker, short*& size) { //Massivə telefon əlavə edən menyudur.
	char* vendor = new char[20];
	char* model = new char[30];
	int price;
	short back;
	cout << "Evvele qayitmaq ucun ESC eks halda istenileni basin:  ";
	back = _getch();
	if (back == ESC) {
		back = 1;
	}
	system("cls");
	switch (back) {
	case 1:
		system("cls");
		telefonlar_menyu_tam(arry_telefon, arry_worker, size);
		break;
	default:
		break;
	}
	cout << "Telefonun istehsalcisini daxil edin: ";
	cin >> vendor;
	cout << "Telefonun modelini daxil edin: ";
	cin >> model;
	cout << "Telefonun qiymetini daxil edin: ";
	cin >> price;
	Telefon* new_phone = new Telefon{ vendor,model,price };
	return new_phone;
}



void telefon_elave_eden(Telefon**& arry_telefon, short*& size, Telefon* new_phone) { //Massivə telefon əlave edən funksiyadir.
	Telefon** arry_telefon_copy = new Telefon * [*size + 1];
	for (size_t i = 0; i < *size; i++) {
		arry_telefon_copy[i] = arry_telefon[i];
	}
	arry_telefon_copy[*size] = new_phone;
	delete[] arry_telefon;
	arry_telefon = arry_telefon_copy;
	*size += 1;
	return;
}



void telefon_elave_tam(Telefon**& arry_telefon, Worker**& arry_worker, short*& size) { //Bütün telefon elavə edən funksiyaları birləşdirir.
	Telefon* new_phone;
	new_phone = telefon_elave_etmek_menyu(arry_telefon, arry_worker, size);
	telefon_elave_eden(arry_telefon, size, new_phone);
	telefonlar_menyu_tam(arry_telefon, arry_worker, size);
}



#pragma endregion