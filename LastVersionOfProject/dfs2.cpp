// Include all library and header files
#include "define.h"

// Starter timer count 

double start = clock();

int main() {

// Two variable for count of iteration and print num of threads

	const int numOfThreads = space::numOfThreads;
	int countOfIteration = 1;

while (countOfIteration--) {

// Create an object of class and thread objects

	Algo obj(name);
	thread m[numOfThreads];

	int countOfEdge = obj.count_of_edge();
	cout << countOfEdge << '\n';

// Parallel quick sort matrix with threads

	for (int i = 0; i < numOfThreads; i++) {
		m[i] = thread([&obj, i, countOfEdge, numOfThreads](){
			obj.qsort((countOfEdge * i) / (numOfThreads),
				(countOfEdge * (i + 1)) / numOfThreads - 1);
		});
	}

	for (int i = 0; i < numOfThreads; i++) {
		m[i].join();
	}

// Parallel merge for sorting piece

        threadMerge1(obj, m, numOfThreads);

// Deep first searching from one universe vertex

	for (int i = 0; i < obj.count_of_vertex(); i++) {
		if (obj.cmark(i)) {
			obj.dfs(i);
		}
	}

// Function for  rebooting a mark_ massive

	obj.reboot();

// Variable for counting Vertex, and quick parallel sorting a outing matrix

	int countOfVertex = obj.count_of_vertex();

	for (int i = 0; i < numOfThreads; i++) {
		m[i] = thread([&obj, i, countOfVertex, numOfThreads](){
			obj.qsort_out((countOfVertex * i) / (numOfThreads),
				(countOfVertex * (i + 1)) / numOfThreads - 1);
		});
	}

	for (int i = 0; i < numOfThreads; i++) {
		m[i].join();
	}

// Parallel merging a sorting pieces of massive (3 condition depend of number of threads)

	threadMerge2(obj, m, numOfThreads);

	int help = 1;

// Printing a hightly dependend components

	for (int i=0; i<sizeOfMatrix; i++) {
		
		int a = obj.get_num();
		
		if (obj.mark_num(a)) {
			cout << "Im " << help++ << " komponent *** ";
			obj.dfs_out(a);
			cout << "***\n";
		}	
	}

	cout << '\n';

}

// End of time counter and division on CLOCKS_PER_SEC

double end = clock();
cout << (end - start)/CLOCKS_PER_SEC << '\n';

return 0;

}
