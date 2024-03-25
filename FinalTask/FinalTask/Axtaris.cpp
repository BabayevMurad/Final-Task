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




#pragma region Axtaris

#pragma region Axtaris_telefon

int axtaris_menyu_ekran(short secim = 1) {

	system("Cls");

	char** menyu = new char* [3];

	menyu[0] = new char[14] {"ESC. Cixish"};
	menyu[1] = new char[14] {"1. Telefonlar"};
	menyu[2] = new char[14] {"2. Ishchiler"};

	for (size_t i = 0; i < 3; i++) {
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
		if (secim < 2) {
			secim++;
			axtaris_menyu_ekran(secim);
		}

		else {
			secim = 1;
			axtaris_menyu_ekran(secim);
		}
	}

	else if (kod == UP) {
		if (secim > 1) {
			secim--;
			axtaris_menyu_ekran(secim);
		}

		else {
			secim = 2;
			axtaris_menyu_ekran(secim);
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

int axtaris_menyu() {

	short secim = axtaris_menyu_ekran();

	return secim;
}


void axtaris_menyu_kecid(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci, short secim) {
	bool duzgun_daxil = true;
	do {
		switch (secim) {
		case 0:
			esas_menyu_tam(arry_telefon, arry_isci, size_telefon, size_isci);
			break;
		case 1:
			axtaris_telefon_tam(arry_telefon, arry_isci, size_telefon, size_isci);
			break;
		case 2:
			axtaris_isci_tam(arry_telefon, arry_isci, size_telefon, size_isci);
			break;
		default:
			system("cls");
			cout << "Xais olunur duzgun secim daxil edin";
			Sleep(2000);
			axtaris_menyu();
			break;
		}
	} while (!duzgun_daxil);
}

int axtaris_telefon_color(Telefon**& arry_telefon, short* indexler, short indexler_size, short secim) {
	system("cls");
	cout << "ESC. Evvele qayitmaq ucun." << endl;
	for (size_t i = 0; i < indexler_size; i++) {
		if (secim == i) {
			change_color(GREEN);
			cout << i + 1 << ". ";
			arry_telefon[indexler[i]]->print_for_menyu();
			change_color(WHITE);
			continue;
		}
		cout << i + 1 << ". ";
		arry_telefon[indexler[i]]->print_for_menyu();
	}

	short kod = _getch();

	if (kod == DOWN) {
		if (secim < indexler_size - 1) {
			secim++;
			axtaris_telefon_color(arry_telefon, indexler, indexler_size, secim);
		}

		else {
			secim = 0;
			axtaris_telefon_color(arry_telefon, indexler, indexler_size, secim);
		}
	}

	else if (kod == UP) {
		if (secim > 1) {
			secim--;
			axtaris_telefon_color(arry_telefon, indexler, indexler_size, secim);
		}

		else {
			secim = indexler_size - 1;
			axtaris_telefon_color(arry_telefon, indexler, indexler_size, secim);
		}
	}

	else if (kod == ESC) {
		return 0;
	}

	else if (kod == ENTER) {
		return indexler[secim] + 1;
	}

	else {
		axtaris_telefon_color(arry_telefon, indexler, indexler_size, secim);
	}

}

int axtaris_telefon(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci) {
	short back, sayqac_indexler = 0, equal = 0;
	char* model = new char[20];
	bool tapilma = true;
	short* indexler = new short[*size_telefon];
	do {
		system("cls");
		cout << "Evvele qayitmaq ucun ESC eks halda istenileni basin:  ";
		back = _getch();
		if (back == ESC) {
			axtaris_menyu_tam(arry_telefon, arry_isci, size_telefon, size_isci);
		}
		system("cls");
		cout << "Xais olunur telefonun modelini daxil edin: ";
		cin >> model;
		system("cls");
		for (size_t i = 0; i < *size_telefon; i++) {
			if (!strcmp(arry_telefon[i]->Model, model)) {
				tapilma = true;
				indexler[sayqac_indexler] = i;
				++sayqac_indexler;
				equal++;
			}
		}
		if (equal == 0) {
			tapilma = false;
			system("cls");
			cout << "Siz daxil etdiyiniz telefon yoxdur." << endl;
			Sleep(1500);
		}
		else {
			short secim_telefonlar = axtaris_telefon_color(arry_telefon, indexler, sayqac_indexler, 0);
			return secim_telefonlar;
		}
	} while (!tapilma);

	delete[] model;
	delete[] indexler;
}


void axtaris_telefon_kecid(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci, short choose) {
	do {
		if (0 < choose && choose < *size_telefon) {
			axtaris_telefon_melumat_tam(arry_telefon, arry_isci, size_telefon, size_isci, choose);
		}
		else if (choose == 0) {
			axtaris_menyu_tam(arry_telefon, arry_isci, size_telefon, size_isci);
		}
		else {
			system("cls");
			cout << "Xais olunur duzgun daxil edin";
			Sleep(1500);
			axtaris_telefon_tam(arry_telefon, arry_isci, size_telefon, size_isci);
		}
	} while (true);
}

void axtaris_telefon_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci) {
	short secim = axtaris_telefon(arry_telefon, arry_isci, size_telefon, size_isci);
	axtaris_telefon_kecid(arry_telefon, arry_isci, size_telefon, size_isci, secim);
}

void axtaris_telefon_silinme(Telefon**& arry_telefon, short*& size, short choose_for_arry) { // Telefonu massivdən silir.
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


void axtaris_telefon_silinme_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci, short choose_for_arry) {
	telefon_silinme(arry_telefon, size_telefon, choose_for_arry);
	axtaris_menyu_tam(arry_telefon, arry_isci, size_telefon, size_isci);
}


int axtaris_telefon_melumat_color(Telefon**& arry_telefon, short choose_for_arry, short secim = 1) {

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
			axtaris_telefon_melumat_color(arry_telefon, choose_for_arry, secim);
		}

		else {
			secim = 1;
			axtaris_telefon_melumat_color(arry_telefon, choose_for_arry, secim);
		}
	}

	else if (kod == UP) {
		if (secim > 1) {
			secim--;
			axtaris_telefon_melumat_color(arry_telefon, choose_for_arry, secim);
		}

		else {
			secim = 2;
			axtaris_telefon_melumat_color(arry_telefon, choose_for_arry, secim);
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
		axtaris_telefon_melumat_color(arry_telefon, choose_for_arry, secim);;
	}

}


int axtaris_telefon_melumat(Telefon**& arry_telefon, short choose_for_arry) { // Telefonun bütün məlumatlarını çıxardır.
	short choose = axtaris_telefon_melumat_color(arry_telefon, choose_for_arry);
	return choose;
}

void axtaris_telefon_melumat_yoxlanis(Telefon**& arry_telefon, Worker**& arry_worker, short choose, short choose_for_arry, short*& size_telefon, short*& size_isci) {
	bool duzgun_secim = true; // İstifadəçinin daxil etdiyi seçiminin düzgunlüyünü yoxlaması üçündür.
	do {
		system("cls");
		switch (choose) {
		case 1: // Bu evvele qayitmaq ucundur.
			axtaris_menyu_tam(arry_telefon, arry_worker, size_telefon, size_isci);
			break;
		case 2: // Bu telefon silmek ucundur.
			axtaris_telefon_silinme_tam(arry_telefon, arry_worker, size_telefon, size_isci, choose_for_arry);
			break;
		default: // Bu istifadəçinin səhf daxil etdiyini kansola çıxardır.
			cout << "Xais olunur duzgun secim daxil edin.";
			duzgun_secim = false;
			Sleep(2000);
			axtaris_telefon_melumat(arry_telefon, choose_for_arry);
			break;
		}
	} while (!duzgun_secim);
}

void axtaris_telefon_melumat_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci, short chose_for_arry) {
	short secim;
	secim = axtaris_telefon_melumat(arry_telefon, chose_for_arry);
	axtaris_telefon_melumat_yoxlanis(arry_telefon, arry_isci, secim, chose_for_arry, size_telefon, size_isci);
}


#pragma endregion


#pragma region Axtaris_isci

int axtaris_isci_color(Worker**& arry_isci, short* indexler, short indexler_size, short secim) {
	system("cls");
	cout << "ESC. Evvele qayitmaq ucun." << endl;
	for (size_t i = 0; i < indexler_size; i++) {
		if (secim == i) {
			change_color(GREEN);
			cout << i + 1 << ". ";
			arry_isci[indexler[i]]->print_for_menyu();
			change_color(WHITE);
			continue;
		}
		cout << i + 1 << ". ";
		arry_isci[indexler[i]]->print_for_menyu();
	}

	short kod = _getch();

	if (kod == DOWN) {
		if (secim < indexler_size - 1) {
			secim++;
			axtaris_isci_color(arry_isci, indexler, indexler_size, secim);
		}

		else {
			secim = 0;
			axtaris_isci_color(arry_isci, indexler, indexler_size, secim);
		}
	}

	else if (kod == UP) {
		if (secim > 0) {
			secim--;
			axtaris_isci_color(arry_isci, indexler, indexler_size, secim);
		}

		else {
			secim = indexler_size - 1;
			axtaris_isci_color(arry_isci, indexler, indexler_size, secim);
		}
	}

	else if (kod == ESC) {
		return 0;
	}

	else if (kod == ENTER) {
		return indexler[secim] + 1;
	}

	else {
		axtaris_isci_color(arry_isci, indexler, indexler_size, secim);
	}

}


int axtaris_isci(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci) {
	short back, secim_isci, sayqac_index = 0, equal = 0;
	char* name = new char[20];
	bool tapilma = true;
	short* indexler = new short[*size_telefon];
	do {
		system("cls");
		cout << "Evvele qayitmaq ucun ESC eks halda istenileni basin:  ";
		back = _getch();
		if (back == ESC) {
			axtaris_menyu_tam(arry_telefon, arry_isci, size_telefon, size_isci);
		}
		system("cls");
		cout << "Xais olunur iscinin adini daxil edin: ";
		cin >> name;
		system("cls");
		cout << "0. Evvele qayitmaq ucun." << endl;
		for (size_t i = 0; i < *size_isci; i++) {
			if (!strcmp(arry_isci[i]->Name, name)) {
				tapilma = true;
				indexler[sayqac_index] = i;
				sayqac_index++;
				equal++;
			}
		}
		if (equal == 0) {
			tapilma = false;
			system("cls");
			cout << "Siz daxil etdiyiniz isci yoxdur." << endl;
			Sleep(1500);
		}
		else {
			short secim_isci = axtaris_isci_color(arry_isci, indexler, sayqac_index, 0);
			return secim_isci;
		}
	} while (!tapilma);

	delete[] name;
}


void axtaris_isci_kecid(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci, short choose) {
	bool secim_duz = true;
	do {
		if (0 < choose && choose <= *size_isci) {
			system("cls");
			axtaris_isci_melumat_tam(arry_telefon, arry_isci, size_telefon, size_isci, choose);
		}
		else if (choose == 0) {
			system("cls");
			axtaris_menyu_tam(arry_telefon, arry_isci, size_telefon, size_isci);
		}
		else {
			system("cls");
			cout << "Xais olunur duzgun daxil edin";
			Sleep(1500);
			axtaris_isci_tam(arry_telefon, arry_isci, size_telefon, size_isci);
		}
	} while (!secim_duz);
}


void axtaris_isci_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci) {
	short secim = axtaris_isci(arry_telefon, arry_isci, size_telefon, size_isci);
	axtaris_isci_kecid(arry_telefon, arry_isci, size_telefon, size_isci, secim);
}


void axtaris_menyu_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci) {
	short secim;
	secim = axtaris_menyu();
	axtaris_menyu_kecid(arry_telefon, arry_isci, size_telefon, size_isci, secim);
}

int axtaris_isci_melumat_color(Worker**& arry_isci, short choose_for_arry, short secim = 1) {

	system("Cls");

	char** menyu = new char* [2];

	menyu[0] = new char[18] {"1. Evele qayitmaq"};
	menyu[1] = new char[18] {"2. Isci silmek"};

	arry_isci[choose_for_arry - 1]->showinfo_worker();

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
			axtaris_isci_melumat_color(arry_isci, choose_for_arry, secim);
		}

		else {
			secim = 1;
			axtaris_isci_melumat_color(arry_isci, choose_for_arry, secim);
		}
	}

	else if (kod == UP) {
		if (secim > 1) {
			secim--;
			axtaris_isci_melumat_color(arry_isci, choose_for_arry, secim);
		}

		else {
			secim = 2;
			axtaris_isci_melumat_color(arry_isci, choose_for_arry, secim);
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
		axtaris_isci_melumat_color(arry_isci, choose_for_arry, secim);
	}

}

int axtaris_isci_melumat(Worker**& arry_isci, short choose_for_arry) { // Telefonun bütün məlumatlarını çıxardır.
	short choose = axtaris_isci_melumat_color(arry_isci, choose_for_arry);
	return choose;
}

void axtaris_isci_silinme(Worker**& arry_isci, short*& size, short choose_for_arry) { // Telefonu massivdən silir.
	Worker** arry_isci_copy = new Worker * [*size - 1];
	for (size_t i = 0; i < (choose_for_arry - 1); i++) {
		arry_isci_copy[i] = arry_isci[i];
	}
	for (size_t i = (choose_for_arry); i < *size; i++) {
		arry_isci_copy[i - 1] = arry_isci[i];
	}
	delete[] arry_isci;
	arry_isci = arry_isci_copy;
	*size -= 1;
	system("cls");
	cout << "Uqurla silindi.";
	Sleep(2000);
	system("cls");
}


void axtaris_isci_silinme_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci, short choose_for_arry) {
	axtaris_isci_silinme(arry_isci, size_isci, choose_for_arry);
	axtaris_menyu_tam(arry_telefon, arry_isci, size_telefon, size_isci);
}

void axtaris_isci_melumat_yoxlanis(Telefon**& arry_telefon, Worker**& arry_worker, short choose, short choose_for_arry, short*& size_telefon, short*& size_isci) {
	bool duzgun_secim = true; // İstifadəçinin daxil etdiyi seçiminin düzgunlüyünü yoxlaması üçündür.
	do {
		system("cls");
		switch (choose) {
		case 1: // Bu evvele qayitmaq ucundur.
			axtaris_menyu_tam(arry_telefon, arry_worker, size_telefon, size_isci);
			break;
		case 2: // Bu telefon silmek ucundur.
			axtaris_isci_silinme_tam(arry_telefon, arry_worker, size_telefon, size_isci, choose_for_arry);
			break;
		default: // Bu istifadəçinin səhf daxil etdiyini kansola çıxardır.
			cout << "Xais olunur duzgun secim daxil edin.";
			duzgun_secim = false;
			Sleep(2000);
			axtaris_isci_melumat_tam(arry_telefon, arry_worker, size_telefon, size_telefon, choose_for_arry);
			break;
		}
	} while (!duzgun_secim);
}

void axtaris_isci_melumat_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci, short chose_for_arry) {
	short secim;
	secim = axtaris_isci_melumat(arry_isci, chose_for_arry);
	axtaris_isci_melumat_yoxlanis(arry_telefon, arry_isci, secim, chose_for_arry, size_telefon, size_isci);
}

#pragma endregion

#pragma endregion