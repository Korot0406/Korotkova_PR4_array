#include <iostream>
#include <string>
#include <map>
#include <ctime>
using namespace std;

// Функция проверки корректности ввода целого числа
bool IntUserInput(string input){
    if(input.empty()) return false;

    try{
        size_t pos;
        stoi(input, &pos);
        return pos == input.length();
    }catch(...){
        return false;
    }
}

// Функция ввода целого числа с повторением запроса до корректного ввода
int IntEnterNumber(string label){
    string raw_input;
    cout << label;
    getline(cin, raw_input);
    while(!IntUserInput(raw_input)){
        cout << label;
        getline(cin, raw_input);
    }
    return stoi(raw_input);
}


void problem1(){

}

void problem2(){

}

void problem3(){

}

// Структура меню
struct MenuItem{
    string title;
    void(*action)();
};


int main(){
    setlocale(LC_ALL, "Russian");
    map<int, MenuItem> menu = {
        {1, {"Problem 1", problem1}},
        {2, {"Problem 2", problem2}},
        {3, {"Problem 3", problem3}}
    };

    int choice = 0;

    while(true){
        cout << "\nМеню:\n";

        for (const auto& item : menu){
            cout << "Task " << item.first << ". " << item.second.title << "\n";
        }

        cout << "0. Выход\n";

        cin.ignore();
        choice = IntEnterNumber("Введите номер пункта: ");

        if (choice == 0){
            cout << "© 2026 Korotkova I.S.\n";
            break;
        }

        cout << "\n";

        if (menu.find(choice) != menu.end()){
            menu[choice].action();
        }else{
            cout << "Некорректный ввод.\n";
        }
    }
    
    return 0;
}