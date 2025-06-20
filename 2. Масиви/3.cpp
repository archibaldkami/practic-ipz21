#include <iostream>
#include "mylib.hpp"

using namespace std;

int main() {
    Functions obj;
    vector<vector<int>> matrix(3, vector<int>(5, 0));
    obj.FillRandomIntV(matrix);
    obj.third_task(matrix);
    return 0;
}
