#pragma once

#include <iostream>

#include <windows.h>

using namespace std;

#pragma region Structs

// Telefon structu.

struct Telefon { // Telefon structudur.
	char* Vendor = new char[20];
	char* Model = new char[30];
	int Price;

private: // İstifadə etməyə ehtiyac yoxdur.

	Telefon() { //Default kostruktordur.
		strcpy_s(Vendor, 8, "Samsung");
		strcpy_s(Model, 10, "S22 Ultra");
		Price = 2500;
	};

public: // İstifadə etmək lazımdır.

	Telefon(const char* vendor_get, const char* model_get, int price_get) { // Parametric constructordur melumatlari yazmaq ucundur.
		strcpy_s(Vendor, strlen(vendor_get) + 1, vendor_get);
		strcpy_s(Model, strlen(model_get) + 1, model_get);
		Price = price_get;
	};

	void print_for_menyu() { // Menyuda adını çıxartmaq üçün.
		cout << Vendor << " " << Model << endl;
	};

	void showinfo() { // Bütün məlumatı çıxartmaq üçün.
		system("cls");
		cout << "Vendor: " << Vendor << endl;
		cout << "Model: " << Model << endl;
		cout << "Price: " << Price << endl;
	};

	~Telefon() {
		delete[] Vendor;
		delete[] Model;
	};
};




// Person Struct.

struct Person { // İnsan strukturudur.
	char* Name = new char[20];
	char* Surname = new char[20];
	int Age;



protected: // Ancaq öz içində və törənən struktlarda lazımdır.

	Person() {
		strcpy_s(Name, 5, "Veli");
		strcpy_s(Surname, 9, "Fendiyev");
		Age = 20;
	};

	Person(const char* name_get, const char* surname_get, int age_get) { // Parametric constructordur melumatlari yazmaq ucundur.
		strcpy_s(Name, strlen(name_get) + 1, name_get);
		strcpy_s(Surname, strlen(surname_get) + 1, surname_get);
		Age = age_get;
	}


	void showinfo() { // Bütün melumatları çıxardacaq.
		cout << "Name: " << Name << endl;
		cout << "Surname: " << Surname << endl;
		cout << "Age: " << Age << endl;
	}

	~Person() {
		delete[] Name;
		delete[] Surname;
	};

public:

	void print_for_menyu() { // Menyuda adı ekrana çıxartmaq üçündür.
		cout << Surname << " " << Name << endl;
	}


};




// İşçi structu.

struct Worker : Person { // İsci struktudur insan strukturundan törənir.
	int Salary;

private: // İstifadə olunmayacaq.

	Worker() : Person() {
		Salary = 100;
	};

public:

	Worker(const char* name_send, const char* surname_send, int age_send, int salary_get) : Person(name_send, surname_send, age_send) { // Melumatlari yazmaq üçün istifadə olunacaq.
		Salary = salary_get;
	}

	void showinfo_worker() {
		showinfo();
		cout << "Salary: " << Salary << endl;
	}

};

#pragma endregion