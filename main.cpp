//
//  main.cpp
//  lab 7 (var 2)
//
//  Created by Дмитрий Вискунов on 01.12.2022.
//
#include "functions.h" // подключение заголовчного файла с прототипами функций
int _StateMenu;
void Menu(){
    cout << "Выберите действие:" << endl;
    cout << "(0) Выход из программы" << endl;
    cout << "(1) Ввод данных" << endl;
    cout << "(2) Вывод данных" << endl;
    cout << "(3) Изменение данных" << endl;
    cout << "(4) Удаление данных" << endl;
    cout << "(5) Добавление данных" << endl;
    cout << "(6) Сохранение данных" << endl;
    cin >> _StateMenu;
}
int main() {
    DataInitialization(); // стандартый процесс создания буферного файла
    Menu(); // ввыод меню
    
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
                Menu();
                break;
        }
    }
    if (DataCleaning()){
        cout << "Данные очищены!" << endl;
    }else{
        cout << "Данные НЕ очищены!" << endl;
    }
    cout << "Работа завершена" << endl;
}
