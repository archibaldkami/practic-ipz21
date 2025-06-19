#include "mylib.hpp"
#include <iostream>
#include <cstdlib>  // Для rand()
#include <ctime>    // Для ініціалізації rand()
#include <cmath>

using namespace std;

// Функція пошуку мінімального значення в масиві
int MinB(int B[], int n) {
    int minValue = B[0];
    for (int i = 1; i < n; i++) {
        if (B[i] < minValue)
            minValue = B[i];
    }
    return minValue;
}

// Функція пошуку індексу мінімального елемента
int MinIB(int B[], int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (B[i] < B[minIndex])
            minIndex = i;
    }
    return minIndex;
}

// Функція пошуку максимального значення в масиві
int MaxB(int B[], int n) {
    int maxValue = B[0];
    for (int i = 1; i < n; i++) {
        if (B[i] > maxValue)
            maxValue = B[i];
    }
    return maxValue;
}

// Функція пошуку індексу максимального елемента
int MaxIB(int B[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (B[i] > B[maxIndex])
            maxIndex = i;
    }
    return maxIndex;
}

// Функція обчислення середнього арифметичного масиву
double AvgB(int B[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += B[i];
    }
    return sum / n;
}

// Функція виводу масиву на екран
void PrintB(int B[], int n) {
    for (int i = 0; i < n; i++) {
        cout << B[i] << " ";
    }
    cout << endl;
}

// Функція заповнення масиву випадковими числами (від 1 до 100)
void FillRandomB(int B[], int n) {
    srand(time(0));  // Ініціалізація генератора випадкових чисел
    for (int i = 0; i < n; i++) {
        B[i] = rand() % 100 + 1;
    }
}

long long multiplyabs(int B[], int n) {
    long long result = 1;
    for (int i = 0; i < n; i++) {
        result *= abs(B[i]);
    }
    return result;
}
