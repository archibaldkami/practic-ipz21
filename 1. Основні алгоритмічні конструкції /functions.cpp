#include <iostream>
#include "functions.hpp"
#include <cstdlib>
#include <string>
#include <cmath>
#include <time.h>

using namespace std;

double GetRandomNumberFloat(double min, double max, int precision) {
  double value;
  value = rand() % (int)pow(10, precision);
  value = min + (value / pow(10, precision)) * (max - min);
  return value;
}

int GetRandomNumber(int min, int max) {
  int num = min + rand() % (max - min + 1);
  return num;
}

vector<double> user_input(int count) {
    system("clear"); // Код виконується на GNU/Linux
    int choise;
    double x, a, b = 0;
    vector<double> vars = {a, x, b};
    vector<string> vars_str = {"a", "x", "b"};

    cout << "Choose method:\n1. Manual input\n2. Random input\n\nYour choise: "; cin >> choise;
    if (choise - 1) {
        double min, max;
        cout << "Enter min value: "; cin >> min;
        cout << "Enter max value: "; cin >> max;

        srand(time(NULL)); // Для нормального вибору кількох випадкових значень
        for (int i = 0; i < count; i++) vars[i] = GetRandomNumberFloat(min, max, 2);

    } else for (int i = 0; i < count; i++) { 
        cout << "Enter " << vars_str[i] << ": "; cin >> vars[i]; 
    }

    system("clear");
    return vars;
}

double first_task(vector<double> axb) { // Варіант 10
    double a, x, y;
    a = axb[0]; x = axb[1];
    y = sqrt((5*x-a)/(x*x-1)) + cos(abs(x-1));
    return y;
}

double second_task(std::vector<double> axb) { // Варіант 5
    double a, x, b, y;
    a = axb[0]; x = axb[1]; b = axb[2];
    y = (x >= 1) ? sin(x) : (3*pow(x, 2) + b*x - 3);
    return y;
}

vector<double> third_task(std::vector<double> axb) { // Варіант 5
    double a, x, b, y;
    a = axb[0]; x = axb[1]; b = axb[2];
    if (x < 6) {
        if (x < -1) {
            cerr << "Функція не визначена\n";
            return { 0, 1 };
        }
        y = sin(x);
    }
    else if (x == 6) y = 3*pow(x, 4) + b*x - 3;
    else {
        if ((b*x + a) < 0) {
            cerr << "Від'ємне значення логарифмічного виразу\n";
            return { 0, 1 };
        }
        y = log(b*x + a);
    }
    return { y, 0 };
}