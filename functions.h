//
//  functions.h
//  lab 7 (var 2)
//
//  Created by Дмитрий Вискунов on 01.12.2022.
//
#pragma once
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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
