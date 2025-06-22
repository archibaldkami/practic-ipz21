#include "mylib.hpp"
#include <iostream>
#include <cstdlib>  // Для rand()
#include <ctime>    // Для ініціалізації rand()
#include <cmath>

using namespace std;

// Кольори для логів
const char* red = "\033[31m";
const char* green = "\033[32m";
const char* reset = "\033[0m";

void Functions::init() { // Функція для вибору користувачем задачі, і її виконання
    int choice;
    system("clear");
    cout << "=== Tasks ===" << endl;
    cout << "1. Створення власної бібліотеки функцій для роботи з одномірним масивом" << endl;
    cout << "2. Робота з двомірним масивом. Доповнити бібліотеку функцій" << endl;
    cout << "3. Рішення системи рівнянь" << endl;
    
    cout << "Choose task: "; cin >> choice;
    vector<double> vars;
    if (choice == 1) {
    const int n = 10;
    int B[n];
    Functions obj;
    // Заповнення масиву випадковими числами та вивід
    obj.FillRandomB(B, n);
    cout << "Масив: ";
    obj.PrintB(B, n);

    // Використання функцій бібліотеки
    cout << "Мінімальний елемент: " << obj.MinB(B, n) << endl;
    cout << "Індекс мінімального елемента: " << obj.MinIB(B, n) << endl;
    cout << "Максимальний елемент: " << obj.MaxB(B, n) << endl;
    cout << "Індекс максимального елемента: " << obj.MaxIB(B, n) << endl;
    cout << "Середнє арифметичне: " << obj.AvgB(B, n) << endl;
    cout << "Добуток модулів усіх значень: " << obj.multiplyabs(B, n) << endl;
    } else if (choice == 2) {
        Functions obj;
        vector<vector<double>> matrix(3, vector<double>(3, 0));
        obj.FillRandomDoubleV(matrix);
        obj.PrintDoubleV(matrix);
    } else if (choice == 3) {
        Functions obj;
        vector<vector<int>> matrix(3, vector<int>(3, 0));
        obj.FillRandomIntV(matrix);
        obj.third_task(matrix);
    }
}

// Функція заповнення матриці рандомними дійсними числами
void Functions::FillRandomDoubleV(vector<vector<double>>& matrix) {
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

void Functions::FillRandomIntV(vector<vector<int>>& matrix) {
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

// Функція виводу масиву дійсних чисел на екран
void Functions::PrintDoubleV(std::vector<std::vector<double>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// Функція виводу масиву цілих чисел на екран
void Functions::PrintIntV(std::vector<std::vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void Functions::second_task(std::vector<std::vector<double>>& matrix) {
    double result = 1;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            result *= (matrix[i][j]) ? matrix[i][j] : 1;
        }
    }
    cout << "Добуток всіх дійсних ненульових елементів матриці дорівнює: " << result;
}

void Functions::third_task(std::vector<std::vector<int>>& matrix) {
    double result = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            result += ((matrix[i][j] % 2) && (matrix[i][j] > 0)) ? matrix[i][j] : 0;
            cout << "Елемент " << i << " " << j << ": " << matrix[i][j] << endl;
            cout << "Він нам " << (((matrix[i][j] % 2) && matrix[i][j] > 0) ? "\033[32m" : "\033[31mне ") << "підходить\033[0m\n\n";
        }
    }
    cout << "Сума всіх непарних більших за 0 елементів матриці дорівнює: " << result << endl;
    cout << "Вигляд кінцевої матриці:\n";
    matrix[0][0] = matrix[0][matrix[0].size()-1] = matrix[matrix.size()-1][0] = matrix[matrix.size()-1][matrix[0].size()-1] = result;
    PrintIntV(matrix);
}

// Функція пошуку мінімального значення в масиві
int Functions::MinB(int B[], int n) {
    int minValue = B[0];
    for (int i = 1; i < n; i++) {
        if (B[i] < minValue)
            minValue = B[i];
    }
    return minValue;
}

// Функція пошуку індексу мінімального елемента
int Functions::MinIB(int B[], int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (B[i] < B[minIndex])
            minIndex = i;
    }
    return minIndex;
}

// Функція пошуку максимального значення в масиві
int Functions::MaxB(int B[], int n) {
    int maxValue = B[0];
    for (int i = 1; i < n; i++) {
        if (B[i] > maxValue)
            maxValue = B[i];
    }
    return maxValue;
}

// Функція пошуку індексу максимального елемента
int Functions::MaxIB(int B[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (B[i] > B[maxIndex])
            maxIndex = i;
    }
    return maxIndex;
}

// Функція обчислення середнього арифметичного масиву
double Functions::AvgB(int B[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += B[i];
    }
    return sum / n;
}

// Функція виводу масиву на екран
void Functions::PrintB(int B[], int n) {
    for (int i = 0; i < n; i++) {
        cout << B[i] << " ";
    }
    cout << endl;
}

// Функція заповнення масиву випадковими числами (від 1 до 100)
void Functions::FillRandomB(int B[], int n) {
    srand(time(0));  // Ініціалізація генератора випадкових чисел
    for (int i = 0; i < n; i++) {
        B[i] = rand() % 100 + 1;
    }
}

// Функція обчислення добутку модулів усіх значень масиву
long long Functions::multiplyabs(int B[], int n) {
    long long result = 1;
    for (int i = 0; i < n; i++) {
        result *= abs(B[i]);
    }
    return result;
}
