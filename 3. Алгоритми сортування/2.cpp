#include <iostream>
#include "mylib.hpp"

using namespace std;

int main() {
    vector<vector<int>> matrix(8, vector<int>(8, 0));
    FillRandomIntV(matrix, 10, 99);
    PrintIntV(matrix);

    return 0;
}
