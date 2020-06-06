#include <iostream>
#include <fstream>
#include <cstdlib>
#include <fstream>
#include <cstdlib>

using namespace std;

int main (int argc, char** argv) {

    if (argc == 3) {
	ofstream file{argv[1]};
	string str = "", str1;
	for (int i = 0; i < atoi(argv[2]) - 1; i++) {
	    bool a = rand() % 2;
	    if (a)
		str += "1,";
	    else 
		str += "0,";
	}
	//str += "1\n";
	
	for (int i = 0; i < atoi(argv[2]) - 1; i++) {
	    file << str << "1\n";
	}
	file << str << "1";
    }
    else {
	cout << "More arguments pls \n";
    }
    return 0;
}