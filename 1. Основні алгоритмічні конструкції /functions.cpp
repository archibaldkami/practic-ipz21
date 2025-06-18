#include "functions.hpp"
#include <iostream>
#include <cmath>
#include <time.h>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

const char* red = "\033[31m";
const char* green = "\033[32m";
const char* reset = "\033[0m";

// BaseAlgConstructions::BaseAlgConstructions()
void BaseAlgConstructions::init() {
    int choice;
    system("clear");
    cout << "=== Tasks ===" << endl;
    cout << "1. Розробити програму мовою С++ лінійної структури" << endl;
    cout << "2. Розробити програму з послідовною перевіркою умов та застосуванням умовного оператора" << endl;
    cout << "3. Рішення системи рівнянь" << endl << endl;
    
    cout << "Choose task: "; cin >> choice;
    vector<double> vars;
    switch (choice) {
    case 1:
        // system("clear");
        vars = user_input(2);
        y = first_task(vars);
        if (isErrors()) {
            errOut();
            break;
        }
        varOut("axy", { vars[0], vars[1], y });
        break;
    case 2:
        vars = user_input(3);
        y = second_task(vars);
        if (isErrors()) {
            errOut();
            break;
        }
        varOut("axby", { vars[0], vars[1], vars[2], y });
        break;
    case 3:
        vars = user_input(3);
        y = third_task(vars);
        if (isErrors()) {
            errOut();
            break;
        }
        varOut("axby", { vars[0], vars[1], vars[2], y });
        break;
    default:
        cout << "Incorrect input :P" << endl;
        break;
    }
}

void BaseAlgConstructions::varOut (std::string vars, std::vector<double> values) {
    for (int i = 0; i < values.size(); i++) cout << vars[i] << " = " << values[i] << endl;
}

void BaseAlgConstructions::err(string error) {
    error_log.push_back(error);
}

void BaseAlgConstructions::errOut() {
    for (auto& error : error_log) cout << red << "ERROR: " << reset << error << endl;
}

bool BaseAlgConstructions::isErrors() {
    return !error_log.empty();
}

double BaseAlgConstructions::GetRandomNumberFloat(double min, double max, int precision) {
  double value;
  value = rand() % (int)pow(10, precision);
  value = min + (value / pow(10, precision)) * (max - min);
  return value;
}

int BaseAlgConstructions::GetRandomNumber(int min, int max) {
  int num = min + rand() % (max - min + 1);
  return num;
}

vector<double> BaseAlgConstructions::user_input(int count) {
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
        if (min > max) {
            err("Min value must be bigger than max value");
            return vars;
        } else if (min == max) {
            err("Min and max must be different");
            return vars;
        }
        srand(time(NULL)); // Для нормального вибору кількох випадкових значень
        for (int i = 0; i < count; i++) vars[i] = GetRandomNumberFloat(min, max, 2);

    } else for (int i = 0; i < count; i++) { 
        cout << "Enter " << vars_str[i] << ": "; cin >> vars[i]; 
    }

    system("clear");
    return vars;
}

double BaseAlgConstructions::first_task(vector<double> ax) { // Варіант 10
    double a, x, y;
    a = ax[0]; x = ax[1];
    if ((5*x-a)/(x*x-1) < 0) {
        err("Negative value in square root");
        return 0;
    }
    y = sqrt((5*x-a)/(x*x-1)) + cos(abs(x-1));
    return y;
}

double BaseAlgConstructions::second_task(std::vector<double> axb) { // Варіант 5
    double a, x, b, y;
    a = axb[0]; x = axb[1]; b = axb[2];
    y = (x >= 1) ? sin(x) : (3*pow(x, 2) + b*x - 3);
    return y;
}

double BaseAlgConstructions::third_task(std::vector<double> axb) { // Варіант 5
    double a, x, b, y;
    a = axb[0]; x = axb[1]; b = axb[2];
    if (x < 6) {
        if (x < -1) {
            err("Функція не визначена");
            return 0;
        }
        y = sin(x);
    }
    else if (x == 6) y = 3*pow(x, 4) + b*x - 3;
    else {
        if ((b*x + a) < 0) {
            err("Від'ємне значення логарифмічного виразу");
            return 0;
        }
        y = log(b*x + a);
    }
    return y;
}

