#pragma once

#include <iostream>

#include <windows.h>

#include "Structs.h"

#include "Getch.h"

#include "Color.h"

#include "Menyu.h"

#include "Telefon.h"

#include <conio.h>


void isci_melumat_tam(Telefon**& arry_telefon, Worker**& arry_worker, short choose_for_arry, short*& size);

void isci_elave_tam(Telefon**& arry_telefon, Worker**& arry_worker, short*& size);

void isci_silinme_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size, short choose_for_arry);

int isci_menyu_color(Worker**& arry_isci, short*& size, short secim);

int isci_menyu(Worker**& arry_isci, short*& size);

void isci_menyu_kecid(Telefon**& arry_telefon, Worker**& arry_worker, short choose, short*& size);

int isci_melumat_color(Worker**& arry_isci, short choose_for_arry, short secim);

int isci_arry(Worker**& arry_isci, short choose_for_arry);

void isci_melumat_yoxlanis(Telefon**& arry_telefon, Worker**& arry_worker, short choose, short choose_for_arry, short*& size);

void isci_silinme(Worker**& arry_isci, short*& size, short choose_for_arry);

void isci_silinme_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size, short choose_for_arry);

void isci_melumat_tam(Telefon**& arry_telefon, Worker**& arry_worker, short choose_for_arry, short*& size);

void isci_menyu_tam(Telefon**& arry_telefon, Worker**& arry_worker, short*& size);

Worker* isci_elave_etmek_menyu(Telefon**& arry_telefon, Worker**& arry_worker, short*& size);

void isci_elave_eden(Worker**& arry_isici, short*& size, Worker* new_isci);

void isci_elave_tam(Telefon**& arry_telefon, Worker**& arry_worker, short*& size);