#pragma once

#include <iostream>

#include <windows.h>

#include "Structs.h"

#include "Getch.h"

#include "Color.h"

#include "Menyu.h"

#include "Telefon.h"

#include "Isci.h"

#include <conio.h>

#pragma region Axtaris_Telefon

void axtaris_menyu_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci);

void axtaris_telefon_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci);

void axtaris_isci_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci);

void axtaris_telefon_melumat_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci, short chose_for_arry);

void axtaris_isci_melumat_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci, short chose_for_arry);

int axtaris_menyu_ekran(short secim);

int axtaris_menyu();

void axtaris_menyu_kecid(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci, short secim);

int axtaris_telefon_color(Telefon**& arry_telefon, short* indexler, short indexler_size, short secim);

int axtaris_telefon(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci);

void axtaris_telefon_kecid(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci, short choose);

void axtaris_telefon_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci);

void axtaris_telefon_silinme(Telefon**& arry_telefon, short*& size, short choose_for_arry);

void axtaris_telefon_silinme_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci, short choose_for_arry);

int axtaris_telefon_melumat_color(Telefon**& arry_telefon, short choose_for_arry, short secim);

int axtaris_telefon_melumat(Telefon**& arry_telefon, short choose_for_arry);

void axtaris_telefon_melumat_yoxlanis(Telefon**& arry_telefon, Worker**& arry_worker, short choose, short choose_for_arry, short*& size_telefon, short*& size_isci);

void axtaris_telefon_melumat_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci, short chose_for_arry);

#pragma endregion


#pragma region Axtaris_Isci

int axtaris_isci_color(Worker**& arry_isci, short* indexler, short indexler_size, short secim);

int axtaris_isci(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci);

void axtaris_isci_kecid(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci, short choose);

void axtaris_isci_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci);

void axtaris_menyu_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci);

int axtaris_isci_melumat_color(Worker**& arry_isci, short choose_for_arry, short secim);

int axtaris_isci_melumat(Worker**& arry_isci, short choose_for_arry);

void axtaris_isci_silinme(Worker**& arry_isci, short*& size, short choose_for_arry);

void axtaris_isci_silinme_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci, short choose_for_arry);

void axtaris_isci_melumat_yoxlanis(Telefon**& arry_telefon, Worker**& arry_worker, short choose, short choose_for_arry, short*& size_telefon, short*& size_isci);

void axtaris_isci_melumat_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size_telefon, short*& size_isci, short chose_for_arry);

#pragma endregion
