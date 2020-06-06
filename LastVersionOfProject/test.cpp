#include <iostream>
using namespace std;
struct test {
    int a;
    int b;
    

    test(int a, int b) {
	this->a = a;
	this->b = b;
    }
    void operator=(test obj) {
	this->a = obj.a;
	this->b = obj.b;
    }

};

int main() {
    test obj(3, 5);
    test obj1(2, 2);
    obj1 = obj;
    cout << obj1.b << endl;
    return 0;
}