#ifndef MYLIB_H
#define MYLIB_H

// Прототипи функцій для роботи з масивом B[n]
int MinB(int B[], int n);         // Пошук мінімального елемента масиву
int MinIB(int B[], int n);        // Пошук індексу мінімального елемента
int MaxB(int B[], int n);         // Пошук максимального елемента масиву
int MaxIB(int B[], int n);        // Пошук індексу максимального елемента
double AvgB(int B[], int n);      // Обчислення середнього арифметичного масиву
void PrintB(int B[], int n);      // Вивід масиву
void FillRandomB(int B[], int n); // Заповнення масиву випадковими числами

long long multiplyabs(int B[], int n);  // Отримання добутку модулів всіх елементів масиву

#endif