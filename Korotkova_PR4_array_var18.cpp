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

// Задание 1. Дан одномерный массив. Найдите длину самой длинной последовательности
// строго возрастающих элементов.
void problem1(){
    const int N = 10;
    int array[N] = {3, -2, 0, -4, 0, 1, 13, 14, -10, -10};
    cout << "Исходный массив: [";

    for (int elem : array){
        cout << " " << elem << " ";
    }
    cout << "]\n";

    int len_max = 0;
    for (int i = 0; i < N-2; i++){
        int len = 1;
        for (int j = i; j < N-1; j++){
            if (array[j] < array[j+1]){
                ++len;
                if(len > len_max){
                    len_max = len;
                }
            }else{
                break;
            }
        }
    }

    cout << "Результат задания 1:\n";
    if (len_max > 1){
        cout << "Длина самой длинной последовательности строго возрастающих элементов: " << len_max << "\n";
    }else{
        cout << "Такая последовательность не найдена.\n";
    }
}

// Задание 2. Дан массив. Сформируйте новый массив, содержащий элементы, которые
// встречаются в исходном массиве ровно два раза.
void problem2(){

}

// Задание 3. Дан массив. Найдите подмассив заданной длины с минимальной суммой элементов
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

        cout << "0. Выход\n\n";

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