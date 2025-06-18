#ifndef FUNCTIONS
#define FUNCTIONS

#include <vector>
#include <cstdlib>
#include <string>

class BaseAlgConstructions {
private:
    std::vector<std::string> error_log;
    double a, b, x, y;
public:
    // BaseAlgConstructions();
    void init();

    double GetRandomNumberFloat(double min, double max, int precision);
    int GetRandomNumber(int min, int max);
    
    void err(std::string error);
    bool isErrors();
    void errOut();

    std::vector<double> user_input(int count);
    void varOut (std::string vars, std::vector<double> values);

    double first_task(std::vector<double> ax);
    double second_task(std::vector<double> axb);
    double third_task(std::vector<double> axb);
};

#endif