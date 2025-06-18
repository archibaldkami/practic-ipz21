// Варіант 5

#include "functions.hpp"
#include <iostream>
using namespace std;

int main() {
    vector<double> axb = user_input(3);
    vector<double> yerr = third_task(axb);
    if (yerr[1]) {
        cerr << "An error occured\n";
        return 1;
    }

    cout << "a = " << axb[0] << endl;
    cout << "x = " << axb[1] << endl;
    cout << "b = " << axb[2] << endl;
    cout << "y = " << yerr[0] << endl;

    return 0;
}