#ifndef MYLIB_H
#define MYLIB_H

// Прототипи функцій для роботи з масивом B[n]

#include <vector>
#include <string>

void init();

void PrintB(std::vector<int> array);      // Вивід масиву
void FillRandomB(std::vector<int>& array); // Заповнення масиву випадковими числами

// 2 завдання
void FillRandomDoubleV(std::vector<std::vector<double>>& matrix); // Заповнення матриці випадковими числами
void FillRandomIntV(std::vector<std::vector<int>>& matrix, int min, int max); // Заповнення матриці випадковими числами
void PrintDoubleV(std::vector<std::vector<double>>& matrix); // Вивід матриці
void PrintIntV(std::vector<std::vector<int>>& matrix); // Вивід матриці
void first_task(std::vector<int> array);
void second_task(std::vector<std::vector<double>>& matrix); // Обчислення добутку ненульових елементів матриці
void third_task(std::vector<std::vector<int>>& matrix);

// // Методи сортування
// std::vector<int> Sort_Merge(std::vector<int>& input_list);
// std::vector<int> Sort_Paste(std::vector<int>& input_list);
// std::vector<int> Sort_Select(std::vector<int>& input_list);
int GetRandomNumber(int min, int max);
std::vector<int> user_input(int noUser = 0);

std::vector<int> input_integer_vector(int count = 10);

// Методи сортування
void Sort_Merge(std::vector<int>& input_list);
void Sort_Paste(std::vector<int>& input_list);
void Sort_Select(std::vector<int>& input_list);

#endif