#include <iostream>
#include "mylib.hpp"

using namespace std;

int main() {
    Functions obj;
    vector<vector<double>> matrix(3, vector<double>(3, 0));
    obj.FillRandomDoubleV(matrix);
    obj.PrintDoubleV(matrix);

    return 0;
}
