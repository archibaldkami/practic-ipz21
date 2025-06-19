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
    void init();

    double GetRandomNumberFloat(double min, double max, int precision);
    int GetRandomNumber(int min, int max);
    
    void err(std::string error);
    bool isErrors();
    void errOut();

    std::vector<double> user_input(int count, bool noUser = false);
    void varOut (std::string vars, std::vector<double> values);

    double first_task(std::vector<double> ax);
    double second_task(std::vector<double> axb);
    double third_task(std::vector<double> axb);
    void sixth_task(double (BaseAlgConstructions::*function)(std::vector<double>), std::vector<double> vars);

};

#endif