#include "mylib.hpp"
#include <iostream>
#include <cstdlib>  // Для rand()
#include <ctime>    // Для ініціалізації rand()
#include <cmath>
#include <algorithm>

using namespace std;

// Кольори для логів
const char* red = "\033[31m";
const char* green = "\033[32m";
const char* reset = "\033[0m";

void init() { // Функція для вибору користувачем задачі, і її виконання
    int choice;
    system("clear");
    cout << "=== Tasks ===" << endl;
    cout << "1. Сортування простими методами" << endl;
    cout << "2. Сортування двомірного масиву" << endl;
    cout << "3. Швидкі методи сортування масиву методами С++" << endl;
    
    cout << "Choose task: "; cin >> choice;
    vector<double> vars;
    if (choice == 1) {
        vector<int> B(10, 0);
        B = user_input();
        // Заповнення масиву випадковими числами та вивід
        // FillRandomB(B);
        cout << "Масив: ";
        PrintB(B);
        Sort_Select(B);
        first_task(B);
    } else if (choice == 2) {
        vector<vector<int>> matrix(8, vector<int>(8, 0));
        FillRandomIntV(matrix, 10, 99);
        cout << "Матриця до сортування: \n";
        PrintIntV(matrix);

        for (int i = 0; i < matrix.size(); i++) {
            Sort_Select(matrix[i]);
        }

        cout << "Матриця після сортування: \n";
        PrintIntV(matrix);
    } else if (choice == 3) {
        vector<vector<int>> matrix(5, vector<int>(5, 0));
        FillRandomIntV(matrix, 10, 99);
        third_task(matrix);
    }
}

// Функція заповнення матриці рандомними дійсними числами
void FillRandomDoubleV(vector<vector<double>>& matrix) {
    srand(time(0));  // Ініціалізація генератора випадкових чисел
    double value;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            value = rand() % (int)pow(10, 2);
            value = -10 + (value / pow(10, 2)) * 20;
            matrix[i][j] = value;
        }
    }
}

void FillRandomIntV(vector<vector<int>>& matrix, int min, int max) {
    srand(time(0));  // Ініціалізація генератора випадкових чисел
    double value;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            value = rand() % (int)pow(max, 2);
            value = min + (value / pow(max, 2)) * (max - min);
            matrix[i][j] = value;
        }
    }
}

int GetRandomNumber(int min, int max) { // Ліниво скопіпащена функція отримання рандомного цілого значення
  int num = min + rand() % (max - min + 1);
  return num;
}

// Функція виводу масиву дійсних чисел на екран
void PrintDoubleV(std::vector<std::vector<double>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

vector<int> user_input(int noUser) { // Функція для вводу користувачем / генерації значень для функцій
    int choise;
    int count = 10;
    vector<int> vars(count, 0);
    if (noUser) {
        int min = -10;
        int max = 10;
        srand(time(NULL)); // Для нормального вибору кількох випадкових значень
        for (int i = 0; i < noUser; i++) vars[i] = GetRandomNumber(min, max);
        return vars;
    } else {
        system("clear"); // Код виконується на GNU/Linux
        cout << "Choose method:\n1. Manual input\n2. Random input\n\nYour choise: "; cin >> choise;
        if (choise - 1) {
            FillRandomB(vars);
        } else {
            vars = input_integer_vector(10);
        }
        system("clear");
        return vars;
    }
}

vector<int> input_integer_vector(int count) {
    vector<int> result;

    for (int i = 0; i < count; ++i) {
        int value;
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        result.push_back(value);
    }
    return result;
}

void Sort_Select(vector<int>& input_list) {
    for (int j = input_list.size() - 1; j >= 0; j--) {
        int max = input_list[j];
        int idx = j;
        for (int i = 0; i < j; i++)
            if (input_list[i] > max) {
            max = input_list[i];
            idx = i;
            }
        int tmp = input_list[j];
        input_list[j] = input_list[idx];
        input_list[idx] = tmp;
    }
    // return input_list;
}

void Sort_Paste(vector<int>& input_list) {
    for (int j = 1; j < input_list.size(); j++) {
        int el = 0;
        for (int i = 0; i <= j; i++) {
        el = input_list[j];
        if (input_list[i] >= el) {
            input_list[j] = input_list[i];
            input_list[i] = el;
            }
        }
    }
    // return input_list;
}

void Sort_Merge(vector<int>& input_list) {
    int mid = input_list.size() / 2;
    if (input_list.size() % 2 == 1)
        mid++;
    int h = 1;
    int *c = new int[input_list.size()];
    int step;
    
    while (h < input_list.size()) {
        step = h;
        int i = 0;
        int j = mid;
        int k = 0;
        while (step <= mid) {
            while ((i < step) && (j < input_list.size())) {
                if (j < (mid + step) && (input_list[i] > input_list[j])) {
                    c[k] = input_list[j];
                    j++;
                } else {
                    c[k] = input_list[i];
                    i++;
                }
                k++;
            }
            while (i < step) {
                c[k] = input_list[i];
                i++;
                k++;
            }
            while (j < (mid + step) && j < input_list.size()) {
                c[k] = input_list[j];
                j++;
                k++;
            }
            step = step + h;
        }
        for (i = 0; i < input_list.size(); i++)
        input_list[i] = c[i];
        h = h * 2;
    }
    delete[] c;
    // return input_list;
}
// Функція виводу масиву цілих чисел на екран
void PrintIntV(std::vector<std::vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void first_task(std::vector<int> array) {
    int result = 1;
    for (int i = 0; i < array.size(); i++) {
        result *= (array[i] < 0) ? array[i] : 1;
    }
    cout << "Добуток всіх негативних елементів масиву: " << result << endl;
    cout << "Поточний масив: " << endl;
    PrintB(array);
}

void second_task(std::vector<std::vector<double>>& matrix) {
    double result = 1;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            result *= (matrix[i][j]) ? matrix[i][j] : 1;
        }
    }
    cout << "Добуток всіх дійсних ненульових елементів матриці дорівнює: " << result;
}

void third_task(std::vector<std::vector<int>>& matrix) {
    // 1. Виведення поточної матриці
    cout << "Start matrix:\n";
    PrintIntV(matrix);

    // 2. Сортування рядків за кількістю непарних елементів (спадання)
    sort(matrix.begin(), matrix.end(), [](const vector<int>& a, const vector<int>& b) {
        int oddA = count_if(a.begin(), a.end(), [](int x) { return x % 2 != 0; });
        int oddB = count_if(b.begin(), b.end(), [](int x) { return x % 2 != 0; });
        return oddA > oddB;
    });

    cout << green << "Matrix after sorting rows by count of odd elements (decrease):\n" << reset;
    PrintIntV(matrix);

    // 3. Знаходження максимуму і його координат
    int max_val = matrix[0][0];
    int max_i = 0, max_j = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] > max_val) {
                max_val = matrix[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    cout << green << "Maximum element: " << max_val << " (row " << max_i << ", column " << max_j << ")\n" << reset;
}


// Функція виводу масиву на екран
void PrintB(vector<int> array) {
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Функція заповнення масиву випадковими числами (від 1 до 100)
void FillRandomB(vector<int>& array) {
    srand(time(0));  // Ініціалізація генератора випадкових чисел
    int min = -10;
    int max = 10;
    for (int i = 0; i < array.size(); i++) {
        array[i] = min + rand() % (max - min + 1);
    }
}