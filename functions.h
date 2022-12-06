//
//  functions.h
//  lab 7 (var 2)
//
//  Created by Дмитрий Вискунов on 01.12.2022.
//
#pragma once // защита от двойного подключения файла
#include <stdio.h>  // библиотека работы с потоками
#include <iostream> // стандартная библиотека ввода-вывода
#include <fstream> // библиотека для работы с файлами(чтение/запись)
#include <string> // библиотека для работы со строками

using namespace std;

// прототипы функций
void DataInitialization();
void DataEntry();
void DataReading(string FileName);
void Print();
bool DataCleaning();
void DataChange();
int AmountOfData();
void DeleteData();
void AddData();
void SaveData(string FileName);
