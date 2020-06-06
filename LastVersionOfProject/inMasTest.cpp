#include <iostream>
#include <fstream>
#include <cstdlib>
#include <fstream>
#include <cstdlib>

//Creating text file including a randomize matrix definition size

using namespace std;

int main (int argc, char** argv) {

    if (argc == 3) {
	ofstream file{argv[1]};
	string str = "", str1;
	for (int j = 0; j < atoi(argv[2]); j++) {
	    bool a;
	    for (int i = 0; i < atoi(argv[2]) - 1; i++) {
		a = rand() % 2;
		if (a)
		    str += "1,";
		else 
		    str += "0,";
	    }
	    if (j != atoi(argv[2]) - 1) {
		if (rand() % 2)
		    str += "1\n";
		else
		    str += "0\n";
	    }
	    else if (rand() % 2)
		    str += "1";
		 else
		    str += "0";

	    file << str;
	    str = "";
	}
    }

    else {
	cout << "More arguments pls \n";
    }

    return 0;
}