#include <iostream>
using namespace std;

#ifndef MEMCASHEDSERVER_COMMON_H
#define MEMCASHEDSERVER_COMMON_H

class Common{
public:
    static bool isNumeric(string);
    static string readNthLine(string, int);
};

#endif //MEMCASHEDSERVER_COMMON_H
