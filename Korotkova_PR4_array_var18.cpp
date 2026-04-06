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
    // Вывод исходного массива
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
    int n = IntEnterNumber("Введите размер массива: ");
    // Проверка корректности ввода размера массива
    while(n < 1){
        n = IntEnterNumber("Введите размер массива: ");
    }
    // Создание исходного массива и нового массива
    int* A = new int[n];
    int* B = new int[n];
    // Размер нового массива
    int n1 = 0;

    // Ввод элементов исходного массива
    for (int i = 0; i < n; i++){
        string s = "Введите " + to_string(i) + "-й элемент массива: ";
        A[i] = IntEnterNumber(s);
    }

    // Вывод исходного массива
    cout << "\nИсходный массив:\n";
    for (int i = 0; i < n; i++){
        cout << A[i] << " ";
    }

    for (int i = 0; i < n; i++){
        bool added = false;
        // Проверка наличия элемента в новом массиве
        for (int j = 0; j < n1; j++) {
            if (B[j] == A[i]) {
                added = true;
                break;
            }
        }
        if (added) continue;

        // Подсчет элемента в массиве
        int count = 0;
        for (int k = 0; k < n; k++) {
            if (A[k] == A[i]) {
                count++;
            }
        }

        if (count == 2) {
            B[n1] = A[i];
            n1++;
        }

    }
    
    // Вывод полученного массива
    cout << "\nМассив, содержащий элементы, которые встречаются в исходном массиве ровно два раза:\n";
    for (int i = 0; i < n1; i++){
        cout << B[i] << " ";
    }

    delete[] A;
    delete[] B;
}

// Задание 3. Дан массив. Найдите подмассив заданной длины с минимальной суммой элементов
void problem3(){
    int n = IntEnterNumber("Введите размер массива: ");
    // Проверка корректности ввода размера массива
    while(n < 1){
        n = IntEnterNumber("Введите размер массива: ");
    }
    int m = IntEnterNumber("Введите размер подмассива: ");
    // Проверка корректности ввода размера подмассива
    while (m < 1 || m > n){
        m = IntEnterNumber("Введите размер подмассива: ");
    }
    // Создание исходного массива и подмассива
    int* A = new int[n];
    int* A_ = new int[m];

    int i = 0;
    srand(time(0));
    // Заполнение массива рандомными значениями
    while (i < n){
        *(A + i) = rand() % 20 - 10;
        ++i;
    }

    // Вывод исходного массива
    cout << "Вывод массива:\n";
    i = 0;
    while (i < n){
        cout << *(A + i) << " ";
        i++;
    }
    cout << "\n";

    int min = 100;
    i = 0;
    // Поиск подмассива заданной  длины с минимальной суммой элементов
    while (i < n - m + 1){
        int sum = 0;
        int j = i;
        int index_start = j;
        int k = 0;
        while (k < m){
            sum = sum + *(A + j);
            j++;
            k++;
        }
    
        if (min > sum){
            min = sum;
            int i_ = 0;
            while (i_ < m){
                A_[i_] = *(A + index_start + i_);
                i_++;
            }
        }
        i++;
    }

    // Вывод найденного подмассива
    cout << "Вывод подмассива с минимальной суммой элементов:\n";
    i = 0;
    while (i < m){
        cout << *(A_ + i) << " ";
        i++;
    }
    cout << "\n";
    delete[] A;
    delete[] A_;
}

// Структура меню
struct MenuItem{
    string title;
    void(*action)();
};


int main(){
    setlocale(LC_ALL, "Russian");
    map<int, MenuItem> menu = {
        {1, {"Problem 1. Найти длину самой длинной последовательности строго возрастающих элементов в заданном массиве.", problem1}},
        {2, {"Problem 2. Сформировать новый массив, содержащий элементы, которые встречаются в исходном массиве ровно два раза.", problem2}},
        {3, {"Problem 3. Найти подмассив заданной длины с минимальной суммой элементов.", problem3}}
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