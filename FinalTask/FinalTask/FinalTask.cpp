//Final Task:
//Wrote By: 
//Babayev Murad.

#include <iostream>

#include <windows.h>

#include "Structs.h"

using namespace std;




#pragma region Menyu

/*Telefon menyu funksiyalari define*/

int telefonlar_menyu(Telefon**& arry_telefon, short*& size); // Bütün telefonları çıxardan funksiya.

void telefonlar_menyu_tam(Telefon**& arry_telefon, Worker**& arry_worker, short*& size);

void isci_menyu_tam(Telefon**& arry_telefon, Worker**& arry_worker, short*& size);

void axtaris_menyu_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci);

void telefon_maqazasi(Worker**& arry_isci, Telefon**& arry_telefon, short size, bool baqlanma);



/*Esas Menyu funksiyalari.*/


int esas_menyu() { // Ekrana ilk seçimler və seçimin daxil edilməsi cıxır.
	system("cls");

	short secim;

	cout << "0. Cixish" << endl;
	cout << "1. Telefonlar" << endl;
	cout << "2. Ishchiler" << endl;
	cout << "3. Axtarish" << endl;

	cout << "Seciminizi daxil edin: ";
	cin >> secim;

	return secim;
}



bool esas_menyudan_kecid(Telefon**& arry_telefon, Worker**& arry_worker, short*& size_telefon, short*& size_isci, short secim) { // Esas menyudan (istifadəçi daxil etdiyi melumata görə) lazım olan funksiyanı çağırmaq üçündür.
	bool duzgun_secim = true; // İstifadəçinin daxil etdiyi seçiminin düzgunlüyünü yoxlaması üçündür.
	do {
		system("cls");
		switch (secim) {
		case 0: // Bu proqramı bağlayır. (Arxaya deyer qaytarmaqla.)
			telefon_maqazasi(arry_worker, arry_telefon, *size_telefon ,true);
			break;
		case 1: // Bu telefonlar menyusunu çıxardır.
			telefonlar_menyu_tam(arry_telefon, arry_worker, size_telefon);
			break;
		case 2: // Bu işçilər menyusunu çıxardır.
			isci_menyu_tam(arry_telefon, arry_worker, size_isci);
			break;
		case 3: // Bu axtarış menyusunu çıxardır.
			axtaris_menyu_tam(arry_telefon, arry_worker, size_telefon ,size_isci);
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




#pragma region Telefon_All


/*Telefon Menyusunun funksiyaları.*/


/*Telefon Menyusunun funksiyalarının defineleri.*/


void telefon_melumat_tam(Telefon**& arry_telefon, Worker**& arry_worker, short choose_for_arry, short*& size);

void telefon_elave_tam(Telefon**& arry_telefon, Worker**& arry_worker, short*& size);

void telefon_silinme_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size, short choose_for_arry);


int telefonlar_menyu(Telefon**& arry_telefon, short*& size) { // Bütün telefonları çıxardır.
	system("cls");
	short choose;
	cout << "0. Evvele qayitmaq ucun." << endl;
	for (size_t i = 0; i < *size; i++) {
		cout << i + 1 << ". ";
		arry_telefon[i]->print_for_menyu();
	}
	cout << *size + 1 << ". Telefon elave et." << endl;

	cout << "Seciminizi daxil edin: ";
	cin >> choose;

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



int telefon_melumat(Telefon**& arry_telefon, short choose_for_arry) { // Telefonun bütün məlumatlarını çıxardır.
	short choose;
	arry_telefon[choose_for_arry - 1]->showinfo();
	cout << "1. Evele qayitmaq" << endl;
	cout << "2. Telefon silmek" << endl;
	cout << "Seciminizi daxil edin: ";
	cin >> choose;
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
			telefon_silinme_tam(arry_telefon, arry_worker,size, choose_for_arry);
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


void telefon_silinme_tam(Telefon**& arry_telefon, Worker**& arry_isci,short*& size, short choose_for_arry) {
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
	cout << "Evvele qayitmaq isteyirsiniz 1-He / 2-Yox : ";
	cin >> back;
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




#pragma region Isci_All


/*İşçi Menyusunun funksiyaları.*/


/*içşi Menyusunun funksiyalarının defineleri.*/


void isci_melumat_tam(Telefon**& arry_telefon, Worker**& arry_worker, short choose_for_arry, short*& size);

void isci_elave_tam(Telefon**& arry_telefon, Worker**& arry_worker, short*& size);

void isci_silinme_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size, short choose_for_arry);

//void isci_menyu_tam(Telefon**& arry_telefon, Worker**& arry_worker, short*& size);


int isci_menyu(Worker**& arry_isci, short*& size) { // Bütün işçiləri çıxardır.
	system("cls");
	short choose;
	cout << "0. Evvele qayitmaq ucun." << endl;
	for (size_t i = 0; i < *size; i++) {
		cout << i + 1 << ". ";
		arry_isci[i]->print_for_menyu();
	}
	cout << *size + 1 << ". Isci elave et." << endl;

	cout << "Seciminizi daxil edin: ";
	cin >> choose;

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



int isci_arry(Worker**& arry_isci, short choose_for_arry) { // Telefonun bütün məlumatlarını çıxardır.
	short choose;
	arry_isci[choose_for_arry - 1]->showinfo_worker();
	cout << "1. Evele qayitmaq" << endl;
	cout << "2. Isci silmek" << endl;
	cout << "Seciminizi daxil edin: ";
	cin >> choose;
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


void isci_silinme_tam(Telefon**& arry_telefon ,Worker**& arry_isci, short*& size, short choose_for_arry) {
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
	cout << "Evvele qayitmaq isteyirsiniz 1-He / 2-Yox :";
	cin >> back;
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




#pragma region Axtaris


void axtaris_menyu_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci);

void axtaris_telefon_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci);

void axtaris_isci_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci);

void axtaris_telefon_melumat_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci, short chose_for_arry);

void axtaris_isci_melumat_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci, short chose_for_arry);

int axtaris_menyu() {
	short secim;
	system("cls");
	cout << "0. Evvele qayitmaq" << endl;
	cout << "1. Telefonlar" << endl;
	cout << "2. Isciler" << endl;
	cout << "Seciminizi daxil edin: ";
	cin >> secim;
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


int axtaris_telefon(Telefon**& arry_telefon, Worker**& arry_isci ,short*& size_telefon, short*& size_isci) {
	short back, secim_telefonlar,equal = 0;
	char* model = new char[20];
	bool tapilma = true;
	do {
		system("cls");
		cout << "Evvele qayitmaq isteyirsiniz 1-He / 2-Yox : ";
		cin >> back;
		if (back == 1) {
			axtaris_menyu_tam(arry_telefon, arry_isci, size_telefon, size_isci);
		}
		system("cls");
		cout << "Xais olunur telefonun modelini daxil edin: ";
		cin >> model;
		system("cls");
		cout << "0. Evvele qayitmaq ucun." << endl;
		for (size_t i = 0; i < *size_telefon; i++) {
			if (!strcmp(arry_telefon[i]->Model,model)) {
              tapilma = true;  
				cout << i + 1 << ". ";
				arry_telefon[i]->print_for_menyu();
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
			cout << "Xais olunur secim daxil edin: ";
			cin >> secim_telefonlar;
			return secim_telefonlar;
		}
	} while (!tapilma);

	delete[] model;
}


void axtaris_telefon_kecid(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci, short choose) {
	do {
		if (0<choose && choose < *size_telefon) {
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

int axtaris_telefon_melumat(Telefon**& arry_telefon, short choose_for_arry) { // Telefonun bütün məlumatlarını çıxardır.
	short choose;
	arry_telefon[choose_for_arry - 1]->showinfo();
	cout << "1. Evele qayitmaq" << endl;
	cout << "2. Telefon silmek" << endl;
	cout << "Seciminizi daxil edin: ";
	cin >> choose;
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




int axtaris_isci(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci) {
	short back, secim_isci, equal = 0;
	char* name = new char[20];
	bool tapilma = true;
	do {
		system("cls");
		cout << "Evvele qayitmaq isteyirsiniz 1-He / 2-Yox : ";
		cin >> back;
		if (back == 1) {
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
				cout << i + 1 << ". ";
				arry_isci[i]->print_for_menyu();
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
			cout << "Secimini daxil edin: ";
			cin >> secim_isci;
			return secim_isci;
		}
	} while (!tapilma);

	delete[] name;
}


void axtaris_isci_kecid(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci, short choose) {
	bool secim_duz = true;
	do {
		if (0 < choose && choose < *size_isci) {
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

int axtaris_isci_melumat(Worker**& arry_isci, short choose_for_arry) { // Telefonun bütün məlumatlarını çıxardır.
	short choose;
	arry_isci[choose_for_arry - 1]->showinfo_worker();
	cout << "1. Evele qayitmaq" << endl;
	cout << "2. Isci silmek" << endl;
	cout << "Seciminizi daxil edin: ";
	cin >> choose;
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




int main() {

#pragma region arrays

	int size = 5;
	Worker** arry_worker = new Worker * [size];
	arry_worker[0] = new Worker{ "Murad","Babayev",15,500 };
	arry_worker[1] = new Worker{ "Elmir","Helilov",19, 460 };
	arry_worker[2] = new Worker{ "Gunay","Velilova",21, 520 };
	arry_worker[3] = new Worker{ "Nicat","Qocayev",20, 530 };
	arry_worker[4] = new Worker{ "Gunay","Qarayeva",24, 620 };
	Telefon** arry_telefon = new Telefon * [size];
	arry_telefon[0] = new Telefon{ "Samsung","A70", 630 };
	arry_telefon[1] = new Telefon{ "Apple","Iphone15ProMax", 4000 };
	arry_telefon[2] = new Telefon{ "Samsung","S24 Ultra", 3200 };
	arry_telefon[3] = new Telefon{ "Xiaomi","Mi9", 540 };
	arry_telefon[4] = new Telefon{ "Honor","13Lite", 1200 };

#pragma endregion

	telefon_maqazasi(arry_worker, arry_telefon, size);
}
