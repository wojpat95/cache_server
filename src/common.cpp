#include <algorithm>
#include <fstream>
#include "common.h"

//TODO out of range file error handler

bool Common::isNumeric(const string input) {
    return std::all_of(input.begin(), input.end(), ::isdigit);
}
string Common::readNthLine(string filename, int N)
{
    ifstream in(filename.c_str());

    string s;
    //for performance
//    s.reserve(some_reasonable_max_line_length);

    //skip N lines
    for(int i = 0; i < N; ++i)
        getline(in, s);

    getline(in,s);
    return s;
}
