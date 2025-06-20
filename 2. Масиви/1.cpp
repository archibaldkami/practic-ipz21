#include <iostream>
#include "mylib.hpp"

using namespace std;

int main() {
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

    return 0;
}
