#include <iostream>
#include "mylib.hpp"

using namespace std;

int main() {
    const int n = 10;
    int B[n];

    // Заповнення масиву випадковими числами та вивід
    FillRandomB(B, n);
    cout << "Масив: ";
    PrintB(B, n);

    // Використання функцій бібліотеки
    cout << "Мінімальний елемент: " << MinB(B, n) << endl;
    cout << "Індекс мінімального елемента: " << MinIB(B, n) << endl;
    cout << "Максимальний елемент: " << MaxB(B, n) << endl;
    cout << "Індекс максимального елемента: " << MaxIB(B, n) << endl;
    cout << "Середнє арифметичне: " << AvgB(B, n) << endl;
    cout << "Добуток модулів усіх значень: " << multiplyabs(B, n) << endl;

    return 0;
}
