#ifndef Work_onUI_h_
#define Work_onUI_h_

#include <iostream>
#include <string>

#include "../businessobject/Work_on.h"

using namespace std;

class Work_onUI
{
    int Id;
    long ESSN;
    int PNO;
    float Hours;

public:
    Work_on* AddMemberUI();
    Work_on* UpdateMemberUI();
    int DeleteMemberUI(); 

};

#endif