#include <algorithm>
#include <fstream>
#include "common.h"

//check if string is integer
bool Common::isNumeric(const string input) {
    return std::all_of(input.begin(), input.end(), ::isdigit);
}

// read line from file
string Common::readNthLine(string filename, int N)
{
    ifstream in(filename.c_str());

    string s = "";

    getline(in,s);
    //skip N lines
    while (N > 0 && getline(in,s)){
        N--;
    }

    if (N > 0){
        throw;
    }

    return s;
}
