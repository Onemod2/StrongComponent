#ifndef FSTR
#define FSTR

#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include "structDfs.h"

using namespace std;

// Function for convertion string matrix to int matrix

int** ofstr(string str, int countArg) {
  
    string str2 = "";
    ifstream file (str.c_str());
    str = "";
    file >> str;
    while (!file.eof()) {
	    file >> str2;
	    str = str + "," + str2;
    }
    
    str2 = "";
    file.close();

    int** edge_ = new int*[countArg];
    
    for (int i = 0; i < countArg; i++) {
	    edge_[i] = new int[countArg];
    }

    int j = 0, k = 0;
    for (int i = 0; i <= static_cast<int>(str.length()); i++) {
	    if (j % countArg == 0 && i && str[i-1] == ',') {
		    k++;
		    j = 0;
	    }

	    if (str[i] == ',' || str[i] == '\0') {
	        edge_[k][j++] = atoi(str2.c_str());
		str2 = "";
	    }
	    else {
	        str2 += str[i];
	    }
    }

    return edge_;
}

#endif
