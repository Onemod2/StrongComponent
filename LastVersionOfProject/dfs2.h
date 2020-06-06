#ifndef DFS
#define DFS

// Including a library and package and using a different namespaces

#include "ofstr.h"

using namespace space;

// Adding and definition class Algo (and his fields)

class Algo {
    private:
		Edge* edge_;
		int	n_;
		int	m_;
		bool* mark_;
		CountOut* countOut_;
		int	count_;
		int	count_out_;

    public:

// Constructor with string (name file containg the connection matrix)

	Algo(string str);

// Destructor (why break the exception)

	~Algo();

// Printing of edge

	void print_edge() const;

// Get queue out number

	int get_num();

// Printing massive

	void print_out() const;

// Quick sorting

	void qsort(int, int);
	void qsort_out(int, int);

// Merge massives

	void merge(int, int, int, int);
	void merge_out(int, int, int, int);

// Mark definition vertex

	bool mark_num(int) const;

// Rebooting marks

	void reboot();

// Deep first search algorithms (for differents massive)

	void dfs(int);
	void dfs_out(int);

// Function for printing count of edges and vertex

	int count_of_edge() const;
	int count_of_vertex() const;

// Search a definition out

	int search(int);

// Mark of definition vertex

	bool cmark(int) const;

};

#endif