#pragma once

#include <iostream>

#include <windows.h>

#include "Structs.h"

#include "Getch.h"

#include "Color.h"

#include <conio.h>

int telefonlar_menyu(Telefon**& arry_telefon, short*& size); // Bütün telefonları çıxardan funksiya.

void telefonlar_menyu_tam(Telefon**& arry_telefon, Worker**& arry_worker, short*& size);

void isci_menyu_tam(Telefon**& arry_telefon, Worker**& arry_worker, short*& size);

void axtaris_menyu_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci);

void telefon_maqazasi(Worker**& arry_isci, Telefon**& arry_telefon, short size, bool baqlanma);

int esas_menyu_ekran(short secim);

int esas_menyu();

bool esas_menyudan_kecid(Telefon**& arry_telefon, Worker**& arry_worker, short*& size_telefon, short*& size_isci, short secim);

bool esas_menyu_tam(Telefon**& arry_telefon, Worker**& arry_worker, short*& size_telefon, short*& size_isci);
