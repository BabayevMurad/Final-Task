#pragma once

#include <iostream>

#include <windows.h>

#include "Structs.h"

#include "Getch.h"

#include "Color.h"

#include "Menyu.h"

#include <conio.h>

void telefon_melumat_tam(Telefon**& arry_telefon, Worker**& arry_worker, short choose_for_arry, short*& size);

void telefon_elave_tam(Telefon**& arry_telefon, Worker**& arry_worker, short*& size);

void telefon_silinme_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size, short choose_for_arry);

int telefonlar_menyu_color(Telefon**& arry_telefon, short*& size, short secim = 1);

int telefonlar_menyu(Telefon**& arry_telefon, short*& size);

void telefonlar_menyu_kecid(Telefon**& arry_telefon, Worker**& arry_worker, short choose, short*& size);

int telefon_melumat_color(Telefon**& arry_telefon, short choose_for_arry, short secim = 1);

int telefon_melumat(Telefon**& arry_telefon, short choose_for_arry);

void telefon_melumat_yoxlanis(Telefon**& arry_telefon, Worker**& arry_worker, short choose, short choose_for_arry, short*& size);

void telefon_silinme(Telefon**& arry_telefon, short*& size, short choose_for_arry);

void telefon_silinme_tam(Telefon**& arry_telefon, Worker**& arry_isci, short*& size, short choose_for_arry);

void telefon_melumat_tam(Telefon**& arry_telefon, Worker**& arry_worker, short choose_for_arry, short*& size);

void telefonlar_menyu_tam(Telefon**& arry_telefon, Worker**& arry_worker, short*& size);

Telefon* telefon_elave_etmek_menyu(Telefon**& arry_telefon, Worker**& arry_worker, short*& size);

void telefon_elave_eden(Telefon**& arry_telefon, short*& size, Telefon* new_phone);

void telefon_elave_tam(Telefon**& arry_telefon, Worker**& arry_worker, short*& size);