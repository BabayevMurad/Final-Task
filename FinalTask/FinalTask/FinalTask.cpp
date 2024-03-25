//Final Task:
//Wrote By: 
//Babayev Murad.

#include "Telefon_maqazasi.h"


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
	arry_telefon[2] = new Telefon{ "Samsung","S24Ultra", 3200 };
	arry_telefon[3] = new Telefon{ "Xiaomi","Mi9", 540 };
	arry_telefon[4] = new Telefon{ "Honor","13Lite", 1200 };

#pragma endregion

	telefon_maqazasi(arry_worker, arry_telefon, size);
}