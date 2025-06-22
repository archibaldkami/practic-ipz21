#include <iostream>
#include "mylib.hpp"

using namespace std;

int main() {
    vector<vector<int>> matrix(5, vector<int>(5, 0));
    FillRandomIntV(matrix, 10, 99);
    third_task(matrix);
    return 0;
}
