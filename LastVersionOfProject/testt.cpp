#include <thread>
#include <iostream>

using namespace std;

class test {

    public:
	int a;
	test(int a) {
	    this->a = a;
	}
	
};

void fun(test* t) {
    cout << t->a << "Hello world \n";
}

int main() {

    test* obj = new test(10);
    thread t(fun, &obj);
    t.join();
    return 0;

}