#ifndef MYLIB_H
#define MYLIB_H

// Прототипи функцій для роботи з масивом B[n]

#include <vector>
#include <string>

class Functions {
private:
    std::vector<std::string> error_log;
    double a, b, x, y;
public:
    void init();

    // 1 завдання
    int MinB(int B[], int n);         // Пошук мінімального елемента масиву
    int MinIB(int B[], int n);        // Пошук індексу мінімального елемента
    int MaxB(int B[], int n);         // Пошук максимального елемента масиву
    int MaxIB(int B[], int n);        // Пошук індексу максимального елемента
    double AvgB(int B[], int n);      // Обчислення середнього арифметичного масиву
    void PrintB(int B[], int n);      // Вивід масиву
    void FillRandomB(int B[], int n); // Заповнення масиву випадковими числами
    long long multiplyabs(int B[], int n);  // Отримання добутку модулів всіх елементів масиву

    // 2 завдання
    void FillRandomDoubleV(std::vector<std::vector<double>>& matrix); // Заповнення матриці випадковими числами
    void FillRandomIntV(std::vector<std::vector<int>>& matrix); // Заповнення матриці випадковими числами
    void PrintDoubleV(std::vector<std::vector<double>>& matrix); // Вивід матриці
    void PrintIntV(std::vector<std::vector<int>>& matrix); // Вивід матриці
    void second_task(std::vector<std::vector<double>>& matrix); // Обчислення добутку ненульових елементів матриці
    void third_task(std::vector<std::vector<int>>& matrix);

};

#endif