#include <iostream>

#include <windows.h>

#include "Structs.h"

#include "Getch.h"

#include "Color.h"

#include "Menyu.h"

#include "Telefon.h"

#include "Isci.h"

#include <conio.h>


#pragma region Isci_All


/*İşçi Menyusunun funksiyaları.*/

int isci_menyu_color(Worker**& arry_isci, short*& size, short secim = 1) {

	system("Cls");

	short i = 0;

	cout << "ESC. Evvele qayitmaq ucun." << endl;
	for (i = 1; i <= *size; i++) {
		if (secim == i) {
			change_color(GREEN);
			cout << i << ". ";
			arry_isci[i - 1]->print_for_menyu();
			change_color(WHITE);
			continue;
		}
		cout << i << ". ";
		arry_isci[i - 1]->print_for_menyu();
	}
	if (i == secim) {
		change_color(GREEN);
		cout << *size + 1 << ". Isci elave et." << endl;
		change_color(WHITE);
	}
	else {
		cout << *size + 1 << ". Isci elave et." << endl;
	}

	short kod = _getch();

	if (kod == DOWN) {
		if (secim < *size + 1) {
			secim++;
			isci_menyu_color(arry_isci, size, secim);
		}

		else {
			secim = 1;
			isci_menyu_color(arry_isci, size, secim);
		}
	}

	else if (kod == UP) {
		if (secim > 1) {
			secim--;
			isci_menyu_color(arry_isci, size, secim);
		}

		else {
			secim = *size + 1;
			isci_menyu_color(arry_isci, size, secim);
		}
	}

	else if (kod == ESC) {
		return 0;
	}

	else if (kod == ENTER) {
		return secim;
	}

	else {
		isci_menyu_color(arry_isci, size, secim);
	}

}

int isci_menyu(Worker**& arry_isci, short*& size) { // Bütün işçiləri çıxardır.

	short choose = isci_menyu_color(arry_isci, size);

	return choose;
}



void isci_menyu_kecid(Telefon**& arry_telefon, Worker**& arry_worker, short choose, short*& size) {
	bool duzgun_secim = true; // İstifadəçinin daxil etdiyi seçiminin düzgunlüyünü yoxlaması üçündür.
	do {
		system("cls");
		if (choose > 0 and choose <= *size) { //Seçimin düzgün olması və lazım olan funksiyaların çağırılması.
			isci_melumat_tam(arry_telefon, arry_worker, choose, size);
		}
		else if (choose == 0) { // Evvele qayidir
			//Burada hec ne yazilmir!!!
		}
		else if (choose == *size + 1) { // Yeni isci eleve edir.
			isci_elave_tam(arry_telefon, arry_worker, size);
		}
		else { // Bu istifadəçinin səhf daxil etdiyini kansola çıxardır.
			cout << "Xais olunur duzgun secim daxil edin.";
			duzgun_secim = false;
			Sleep(2000);
			isci_menyu(arry_worker, size);
		}
	} while (!duzgun_secim);
}



int isci_melumat_color(Worker**& arry_isci, short choose_for_arry, short secim = 1) {

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
			isci_melumat_color(arry_isci, choose_for_arry, secim);
		}

		else {
			secim = 1;
			isci_melumat_color(arry_isci, choose_for_arry, secim);
		}
	}

	else if (kod == UP) {
		if (secim > 1) {
			secim--;
			isci_melumat_color(arry_isci, choose_for_arry, secim);
		}

		else {
			secim = 2;
			isci_melumat_color(arry_isci, choose_for_arry, secim);
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
		isci_melumat_color(arry_isci, choose_for_arry, secim);;
	}

}



int isci_arry(Worker**& arry_isci, short choose_for_arry) { // Telefonun bütün məlumatlarını çıxardır.

	short choose = isci_melumat_color(arry_isci, choose_for_arry);

	return choose;
}



void isci_melumat_yoxlanis(Telefon**& arry_telefon, Worker**& arry_worker, short choose, short choose_for_arry, short*& size) {
	bool duzgun_secim = true; // İstifadəçinin daxil etdiyi seçiminin düzgunlüyünü yoxlaması üçündür.
	do {
		system("cls");
		switch (choose) {
		case 1: // Bu evvele qayitmaq ucundur.
			isci_menyu_tam(arry_telefon, arry_worker, size);
			break;
		case 2: // Bu telefon silmek ucundur.
			isci_silinme_tam(arry_telefon, arry_worker, size, choose_for_arry);
			break;
		default: // Bu istifadəçinin səhf daxil etdiyini kansola çıxardır.
			cout << "Xais olunur duzgun secim daxil edin.";
			duzgun_secim = false;
			Sleep(2000);
			isci_arry(arry_worker, choose_for_arry);
			break;
		}
	} while (!duzgun_secim);
}



void isci_silinme(Worker**& arry_isci, short*& size, short choose_for_arry) { // Telefonu massivdən silir.
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


void isci_silinme_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size, short choose_for_arry) {
	isci_silinme(arry_isci, size, choose_for_arry);
	isci_menyu_tam(arry_telefon, arry_isci, size);
}



void isci_melumat_tam(Telefon**& arry_telefon, Worker**& arry_worker, short choose_for_arry, short*& size) { //Bu telefon ikinci menyunusunu birləşdirir.
	short chose;
	chose = isci_arry(arry_worker, choose_for_arry);
	isci_melumat_yoxlanis(arry_telefon, arry_worker, chose, choose_for_arry, size);
}



void isci_menyu_tam(Telefon**& arry_telefon, Worker**& arry_worker, short*& size) { //Burada bütün funksiyalar birləşəcək
	short chose;
	chose = isci_menyu(arry_worker, size);
	isci_menyu_kecid(arry_telefon, arry_worker, chose, size);

}



Worker* isci_elave_etmek_menyu(Telefon**& arry_telefon, Worker**& arry_worker, short*& size) { //Massivə telefon əlavə edən menyudur.
	char* name = new char[20];
	char* surname = new char[30];
	int age, salary;
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
		isci_menyu_tam(arry_telefon, arry_worker, size);
		break;
	default:
		break;
	}
	cout << "Iscinin soyadini daxil edin: ";
	cin >> surname;
	cout << "Iscinin adini daxil edin: ";
	cin >> name;
	cout << "Iscinin yasini daxil edin: ";
	cin >> age;
	cout << "Iscinin maasini daxil edin: ";
	cin >> salary;
	Worker* new_isci = new Worker{ name,surname,age,salary };
	return new_isci;
}

void isci_elave_eden(Worker**& arry_isici, short*& size, Worker* new_isci) { //Massivə telefon əlave edən funksiyadir.
	Worker** arry_isci_copy = new Worker * [*size + 1];
	for (size_t i = 0; i < *size; i++) {
		arry_isci_copy[i] = arry_isici[i];
	}
	arry_isci_copy[*size] = new_isci;
	delete[] arry_isici;
	arry_isici = arry_isci_copy;
	*size += 1;
}



void isci_elave_tam(Telefon**& arry_telefon, Worker**& arry_worker, short*& size) { //Bütün telefon elavə edən funksiyaları birləşdirir.
	Worker* new_isci;
	new_isci = isci_elave_etmek_menyu(arry_telefon, arry_worker, size);
	isci_elave_eden(arry_worker, size, new_isci);
	isci_menyu_tam(arry_telefon, arry_worker, size);
}



#pragma endregion