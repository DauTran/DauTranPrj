#ifndef _Dept_locations_H_
#define _Dept_locations_H_
#include <string>

class Dept_locations{
    int Id;
    int Dnumber;
    std::string Dlocation;

public:
    // Default Contructor
    Dept_locations();
    // Contructor with paramaters
    Dept_locations(int id, int dNumber,std::string dLocation);
    // delete table row
    void deleteTable(Dept_locations Arr[], int n, int position);
    //Init Array
    void InitArr(Dept_locations Arr[], int n);
    void show(Dept_locations Arr[], int n);
};

#endif