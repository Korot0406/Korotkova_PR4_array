#include <iostream>
#include <string>
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

