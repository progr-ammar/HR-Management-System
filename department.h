#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <string>
using namespace std;

class Department {
private:
    string departName;
public:
    Department() : departName("Unknown") {}
    void setDepartmentName(string name) { departName = name; }
    string getDepartmentName() { return departName; }
};
#endif