#ifndef STRUCT
#define STRUCT

/*  Creating a namespace = space including:
 *	size of matrix
 *	swap function
 *	struct of edge_ (and overloading operator =)
 *	struct of outing (and overloading operator =)	
 */

namespace space {

	const char* name = "8.txt";
	const int sizeOfMatrix = 2048;
	const int numOfThreads = 8;

    void swap (int& a, int& b) {
		int c = a;
		a = b;
		b = c;
    }

    struct Edge {
		int from;
		int in;

		void operator= (Edge obj) {
			this->from = obj.from;
			this->in = obj.in;
		}
    };

    struct CountOut {
		int num;
		int out;

		void operator= (CountOut obj) {
			this->num = obj.num;
			this->out = obj.out;
		}
    };
}

#endif
