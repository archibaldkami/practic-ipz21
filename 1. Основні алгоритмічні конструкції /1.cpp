// Варіант 10

#include "functions.hpp"
#include <iostream>
using namespace std;

int main() {

    vector<double> ax = user_input(2);
    double y = first_task(ax);

    cout << "a = " << ax[0] << endl;
    cout << "x = " << ax[1] << endl;
    cout << "y = " << y << endl;

    return 0;
}