#include <iostream>
#include <vector>
#include "mylib.hpp"

using namespace std;

int main() {
    vector<int> B(10, 0);
    // Заповнення масиву випадковими числами та вивід
    FillRandomB(B);
    cout << "Масив: ";
    PrintB(B);
    Sort_Select(B);
    first_task(B);

    return 0;
}
