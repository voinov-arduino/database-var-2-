//
//  main.cpp
//  lab 7 (var 2)
//
//  Created by Дмитрий Вискунов on 01.12.2022.
//
#include <iostream>
#include "functions.h"
using namespace std;
int _StateMenu;
void Menu(){
    cout << "Выберите действие:" << endl;
    cout << "Выход из программы (0)" << endl;
    cout << "Ввод данных (1)" << endl;
    cout << "Вывод данных (2)" << endl;
    cout << "Изменение данных (3)" << endl;
    cout << "Удаление данных (4)" << endl;
    cout << "Добавление данных (5)" << endl;
    cout << "Сохранение данных (6)" << endl;
    cin >> _StateMenu;


}
int main() {
    DataInitialization();
    Menu();
    
    int _actions;
    string FileName; 
    while (_StateMenu !=0){
        switch(_StateMenu){
            case 1:
                cout << "Ввод вручную или с файла?: ";
                cin >> _actions;
                if (_actions == 1){
                    // ввод вручную
                    DataEntry();
                }else{
                    // чтение из файла
                    cout << "Введите название файла: ";
                    cin >> FileName;
                    DataReading(FileName);
                }
                Menu();
                break;
            case 2:
                Print();
                
                Menu();
                break;
            case 3:
                DataChange();
                Menu();
                break;
            case 4:
                DeleteData();
                Menu();
                break;
            case 5:
                AddData();
                Menu();
                break;
            case 6:
                SaveData(FileName);
                Menu();
                break;
            default:
                cout << "Неправильный выбор меню" << endl;
                break;
        }
    }
    system("cls");
    if (DataCleaning()){
        cout << "Данные очищены!" << endl;
    }else{
        cout << "Данные НЕ очищены!" << endl;
    }
    cout << "Работа завершена" << endl;
}
