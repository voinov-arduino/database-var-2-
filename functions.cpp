//
//  functions.cpp
//  lab 7 (var 2)
//
//  Created by Дмитрий Вискунов on 01.12.2022.
//

#include "functions.h" // подключение заголовчного файла с прототипами функций
using namespace::std;
void DataInitialization(){
    // создаем буферный файл
    ofstream _buf("Buffer.txt");
    if(!_buf){
        cout << "Ошибка создания буферного файла!" << endl;}
    _buf.close();
        
}

int AmountOfData(){
    ifstream _buf("Buffer.txt");
    int n;
    
    if(_buf){
        _buf >> n;
    }else{cout << "Ошибка чтения файла" << endl;}
    _buf.close();
    return n;
}
void DataEntry(){
    // временные переменные
    string _surname;
    string _name;
    string _patronymic;
    int stock;
    int stockSerial[99];
    int stockNumber[99];
    int stockValue[99];
    string DateOfBuy[99];
    int pasport;
    int n;
    cout << "Введите количество данных: ";
    cin >> n;
    ofstream record("Buffer.txt",ios::app);
    // запись данных по количеству
    if(record){
        record << n << endl;
        for(int i = 0; i < n;i++){
            cout << "Введите фамилию: ";
            cin >> _surname;
            record << _surname << endl;

            cout << "Введите имя: ";
            cin >> _name;
            record << _name << endl;
            
            cout << "Введите отчество: ";
            cin >> _patronymic;
            record << _patronymic << endl;

            cout << "Введите количество акций: ";
            cin >> stock;
            record << stock << endl;
            
            cout << "Введите номер и серию паспорта: ";
            cin >> pasport;
            record << pasport << endl;
            
            for(int z = 0; z < stock;z++){
                cout << "Введите серию " << z+1 <<" акции: "<< endl;
                cin >> stockSerial[z];
                record << stockSerial[z] << endl;

                cout << "Введите номер" << z+1 <<" акции: " << endl;
                cin >> stockNumber[z];
                record << stockNumber[z] << endl;

                cout << "Введите стоимость" << z+1 <<" акции: " << endl;
                cin >> stockValue[z];
                record << stockValue[z] << endl;

                cout << "Введите дату покупки " << z + 1 <<" акции: " << endl;
                cin >> DateOfBuy[z];
                record << DateOfBuy[z] << endl;
            }
            cout << "______________________________________________________" << endl;
        }
    }else{
        cout << "Ошибка открытия файла" << endl;
    }
    record.close();
}

void DataReading(string FileName){
    ifstream reading(FileName);
    ofstream record("Buffer.txt",ios::out);
    
    if(reading){
        if(record){
            // временные переменные
            string _surname;
            string _name;
            string _patronymic;
            int pasport;
            int stock;
            int stockSerial[99];
            int stockNumber[99];
            int stockValue[99];
            string DateOfBuy[99];
            int n;
            
            // считываем данные
            
            reading >> n;
            record << n << endl;
            
            for(int i = 0; i < n;i++){
                reading >> _surname;
                reading >> _name;
                reading >> _patronymic;
                reading >> stock;
                reading >> pasport;
                for(int z = 0; z < stock;z++){
                    reading >> stockSerial[z];
                    reading >> stockNumber[z];
                    reading >> stockValue[z];
                    reading >> DateOfBuy[z];
                }
            }
            cout << "Данные считаны" << endl;
        }else{
            cout << "Ошибка открытия буфера" << endl;
        }
    }else{
        cout << "Ошибка открытия файла" << endl;
    }
    
    // закрываем файл
    reading.close();
    record.close();
}

void Print(){
    ifstream reading("Buffer.txt");
    
    if(reading){
        // временные переменные
        int x;
        string _surname;
        string _name;
        string _patronymic;
        int stock;
        int stockSerial[99];
        int stockNumber[99];
        int stockValue[99];
        string DateOfBuy[99];
        int pasport;
        int n;
        cout << "Введите количество данных: ";
        cin >> n;
        reading >> x;
        for(int i = 0; i < n;i++){
            cout << "Данные о владельце №" << i + 1 << endl;
            reading >> _surname;
            cout << "Фамилия:" << _surname << endl;
            
            reading >> _name;
            cout << "Имя:" << _name << endl;
            
            reading >> _patronymic;
            cout << "Отчество:" << _patronymic << endl;
            
            reading >> stock;
            cout << "Количество акций:" << stock << endl;
            
            reading >> pasport;
            cout << "Серия и номер паспорта:" << pasport << endl;
            
            for(int z = 0; z < stock; z++){
                cout << "//////////////////////////"<< z+1 <<"//////////////////////////" << endl;
                reading >> stockSerial[z];
                cout << "Серия акции №" << z+1 <<":" <<stockSerial[z]<< endl;
                
                reading >> stockNumber[z];
                cout << "Номер акции №" << z+1 <<":" <<stockNumber[z]<< endl;
                
                reading >> stockValue[z];
                cout << "Стоимость акции №" << z+1 <<":" <<stockValue[z]<< endl;
                
                reading >> DateOfBuy[z];
                cout << "Дата покупки акции №" << z+1 <<":" <<DateOfBuy[z]<< endl;
            }
            cout << "______________________________________________________" << endl;
        }
    }else{
        cout << "Ошибка чтения данных" << endl;
    }
    reading.close();
}
void Copy(){
    ifstream reading("Buffer_.txt");
    ofstream record("Buffer.txt",ios::out);
    if(reading){
        if(record){
            // временные переменные
            string _surname;
            string _name;
            string _patronymic;
            int _stock;
            int _stockSerial[99];
            int _stockNumber[99];
            int _stockValue[99];
            string _DateOfBuy[99];
            int _pasport;
            int n;
            
            // читаем данные из буфера в новый
            reading >> n;
            record << n << endl;
            for(int i = 0;i < n;i++){
                reading >> _surname;
                record << _surname << endl;
                
                reading >> _name;
                record << _name << endl;
                
                reading >> _patronymic;
                record << _patronymic << endl;
                
                reading >> _stock;
                record << _stock << endl;
                
                reading >> _pasport;
                record << _pasport << endl;
                for(int z = 0; z < _stock;z++){
                    reading >> _stockSerial[z];
                    record << _stockSerial[z] << endl;
                    
                    reading >> _stockNumber[z];
                    record << _stockNumber[z] << endl;
                    
                    reading >> _stockValue[z];
                    record << _stockValue[z] << endl;
                    
                    reading >> _DateOfBuy[z];
                    record << _DateOfBuy[z] << endl;
                }
                
            }
        }else{cout << "Ошибка открытия файла" << endl;}
    }else{cout << "Ошибка открытия буферного файла"<<endl;}
    
    record.close();
    reading.close();
}

void AddData(){
    // временные переменные
    string _surname;
    string _name;
    string _patronymic;
    int stock;
    int stockSerial[99];
    int stockNumber[99];
    int stockValue[99];
    string DateOfBuy[99];
    int pasport;
    int n = AmountOfData() + 1;
    // открываем буферный файл
    ofstream record("Buffer.txt",ios::app);
    ofstream record_("Buffer.txt", ios::out | ios::in);
    fstream _buf("Buffer.txt",ios::out);

    if(_buf.peek() == EOF){
        record << n << endl;
    }
    if(record){
        cout << "Введите фамилию: ";
        cin >> _surname;
        record << _surname << endl;

        cout << "Введите имя: ";
        cin >> _name;
        record << _name << endl;
        
        cout << "Введите отчество: ";
        cin >> _patronymic;
        record << _patronymic << endl;

        cout << "Введите количество акций: ";
        cin >> stock;
        record << stock << endl;
        
        cout << "Введите номер и серию паспорта: ";
        cin >> pasport;
        record << pasport << endl;
        
        for(int z = 0; z < stock;z++){
            cout << "Введите серию " << z+1 <<" акции: ";
            cin >> stockSerial[z];
            record << stockSerial[z] << endl;
            
            cout << "Введите номер " << z+1 <<" акции: ";
            cin >> stockNumber[z];
            record << stockNumber[z] << endl;
            
            cout << "Введите стоимость " << z+1 <<" акции: ";
            cin >> stockValue[z];
            record << stockValue[z] << endl;
            
            cout << "Введите дату покупки " << z+1 <<" акции: ";
            cin >> DateOfBuy[z];
            record << DateOfBuy[z] << endl;
        }
        
        
    }else{cout << "Ошибка открытия файла" << endl;}
    record.close();
    record_.close();
    _buf.close();
}


void DataChange(){
    Copy();
    ifstream reading("Buffer_.txt");
    ofstream record("Buffer.txt",ios::out);
    if(reading){
        if(record){
            // временные переменные
            string _surname;
            string _name;
            string _patronymic;
            int stock;
            int stockSerial[99];
            int stockNumber[99];
            int stockValue[99];
            string DateOfBuy[99];
            int pasport;
            int n, _n;
            // читаем данные из буфера в новый буфер
            reading >> n;
            
            cout << "Выберите номер изменяемого элемента от 1 до " << n << ":";
            cin >> _n;
            
            _n--;
            
            record << n << endl;
            
            if(_n >= 0 and _n < n){
                for(int i = 0; i < n;i++){
                    if(i != _n){
                        reading >> _surname;
                        record << _surname << endl;
                        
                        reading >> _name;
                        record << _name << endl;
                        
                        reading >> _patronymic;
                        record << _patronymic << endl;
                        
                        reading >> stock;
                        record << stock << endl;
                        
                        reading >> pasport;
                        record << pasport << endl;
                        for(int z = 0; z < stock;z++){
                            reading >> stockSerial[z];
                            record << stockSerial[z] << endl;
                            
                            reading >> stockNumber[z];
                            record << stockNumber[z] << endl;
                            
                            reading >> stockValue[z];
                            record << stockValue[z] << endl;
                            
                            reading >> DateOfBuy[z];
                            record << DateOfBuy[z] << endl;
                        }
                    }else{
                        cout << "Введите фамилию: ";
                        cin >> _surname;
                        record << _surname << endl;
                        
                        cout << "Введите имя: ";
                        cin >> _name;
                        record << _name << endl;
                        
                        cout << "Введите отчество: ";
                        cin >> _patronymic;
                        record << _patronymic << endl;
                        
                        cout << "Введите количество акций: ";
                        cin >> stock;
                        record << stock << endl;
                        
                        cout << "Введите номер и серию паспорта: ";
                        cin >> pasport;
                        record << pasport << endl;
                        
                        for(int z = 0; z < stock;z++){
                            cout << "Введите серию " << z+1 <<" акции: ";
                            cin >> stockSerial[z];
                            record << stockSerial[z] <<endl;
                            
                            cout << "Введите номер" << z+1 <<" акции: ";
                            cin >> stockNumber[z];
                            record << stockNumber[z] <<endl;
                            
                            cout << "Введите стоимость" << z+1 <<" акции: ";
                            cin >> stockValue[z];
                            record << stockValue[z] <<endl;

                            cout << "Введите дату покупки акции № " << z + 1 << ": ";
                            cin >> DateOfBuy[z];
                            record << DateOfBuy[z] <<endl;
                        }
                    }
                }
                cout << "Данные изменены" << endl;
            }else{cout <<"Номер введен неверно!" << endl;}
        }else{cout<<"Ошибка открытия файла" << endl;}
    }else{cout << "Ошибка открытия буферного файла"<< endl;}
    record.close();
    reading.close();
    remove("Buffer_.txt");
}

void DeleteData(){
    Copy();
    ifstream reading("Buffer_.txt");
    ofstream record("Buffer.txt",ios::out);
    if(reading){
        if(record){
            // временные переменные
            string _surname;
            string _name;
            string _patronymic;
            int stock;
            int stockSerial[99];
            int stockNumber[99];
            int stockValue[99];
            string DateOfBuy[99];
            int pasport;
            int n, _n;
            reading >> n;
            int b = n -1;
            cout << "Выберите номер изменяемого элемента от 1 до " << n << ":";
            cin >> _n;
            _n--;
            record << b << endl;
            
            if(_n >= 0 and _n < n){
                for(int i = 0; i < n;i++){
                    if(i != _n){
                        reading >> _surname;
                        record << _surname << endl;
                        
                        reading >> _name;
                        record << _name << endl;
                        
                        reading >> _patronymic;
                        record << _patronymic << endl;
                        
                        reading >> stock;
                        record << stock << endl;
                        
                        reading >> pasport;
                        record << pasport << endl;
                        for(int z = 0; z < stock;z++){
                            reading >> stockSerial[z];
                            record << stockSerial[z] << endl;
                            
                            reading >> stockNumber[z];
                            record << stockNumber[z] << endl;
                            
                            reading >> stockValue[z];
                            record << stockValue[z] << endl;
                            
                            reading >> DateOfBuy[z];
                            record << DateOfBuy[z] << endl;
                        }
                        
                    }else{
                        reading >> _surname;
                        reading >> _name;
                        reading >> _patronymic;
                        reading >> stock;
                        reading >> pasport;
                        for(int z = 0; z < stock;z++){
                            reading >> stockSerial[z];
                            reading >> stockNumber[z];
                            reading >> stockValue[z];
                            reading >> DateOfBuy[z];
                        }
                    }
                    cout << "Данные удалены" << endl;
                }
            }else{cout <<"Номер введен неверно!" << endl;}
        }else{cout<<"Ошибка открытия файла" << endl;}
    }else{cout << "Ошибка открытия буферного файла"<< endl;}
    record.close();
    reading.close();
    
    remove("Buffer_.txt");
}

void SaveData(string FileName){
    cout << "Введите название файла в который вы хотите сохранить данные (с расширением файла): ";
    cin >> FileName;
    ifstream reading("Buffer.txt");
    ofstream record(FileName,ios::out);
    
    if(reading){
        if(record){
            // временные переменные
            string _surname;
            string _name;
            string _patronymic;
            int stock;
            int stockSerial[99];
            int stockNumber[99];
            int stockValue[99];
            string DateOfBuy[99];
            int pasport;
            int n;
            reading >> n;
            record << n << endl;
            
            for(int i = 0;i < n;i++){
                reading >> _surname;
                record << _surname << endl;
                
                reading >> _name;
                record << _name << endl;
                
                reading >> _patronymic;
                record << _patronymic << endl;
                
                reading >> stock;
                record << stock << endl;
                
                reading >> pasport;
                record << pasport << endl;
                for(int z = 0; z < stock;z++){
                    reading >> stockSerial[z];
                    record << stockSerial[z] << endl;
                    
                    reading >> stockNumber[z];
                    record << stockNumber[z] << endl;
                    
                    reading >> stockValue[z];
                    record << stockValue[z] << endl;
                    
                    reading >> DateOfBuy[z];
                    record << DateOfBuy[z] << endl;
                }
                
            }
            cout << "Данные сохранены в файле" << FileName << endl;
        }else{cout <<"Ошибка открытия буферного файла" << endl;}
    }else{cout << "Ошибка открытия файла" << endl;}
    record.close();
    reading.close();
}

bool DataCleaning(){
    bool clear = false;
    
    fstream _buf("Buffer.txt",ios::out);
    
    if(!_buf){
        cout << "Ошибка открытия буферного файла" << endl;
    }
    _buf.clear();
    
    if(_buf.peek() == EOF){
        clear = true;
    }else{
        clear = false;
    }
    _buf.close();
    return clear;
}
