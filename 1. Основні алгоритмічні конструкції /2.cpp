// Варіант 5

#include "functions.hpp"
#include <iostream>
using namespace std;

int main() {
    vector<double> axb = user_input(3);
    double y = second_task(axb);

    cout << "a = " << axb[0] << endl;
    cout << "x = " << axb[1] << endl;
    cout << "b = " << axb[2] << endl;
    cout << "y = " << y << endl;

    return 0;
}