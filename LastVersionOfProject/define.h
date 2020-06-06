#ifndef DEFINE_OF_CLASS
#define DEFINE_OF_CLASS
#include "dfs2.h"

	Algo::Algo(string str) {
	
	    int helpForCin = 0;
	    int** masHelp;
	    masHelp = ofstr(str, sizeOfMatrix);
	    
	    for (int i = 0; i < sizeOfMatrix; i++)
			for (int j = 0; j < sizeOfMatrix; j++)
				if (masHelp[i][j] > 0)
					helpForCin++;

	    this->n_ = sizeOfMatrix;
	    this->m_ = helpForCin;
	    this->edge_ = new Edge[helpForCin];
	    this->mark_ = new bool[sizeOfMatrix];
	    this->countOut_ = new CountOut[sizeOfMatrix];
	    this->count_ = 0;
	    this->count_out_ = 0;
	
	    int helpForCin1 = 0;
	    for (int i = 0; i < sizeOfMatrix; i++)
			for (int j = 0; j < sizeOfMatrix; j++)
				if (masHelp[i][j] > 0) {
					edge_[helpForCin1].from = i;
					edge_[helpForCin1].in = j;
					helpForCin1++;
				}
	    
	    for (int i = 0; i < sizeOfMatrix; i++)
			countOut_[i].num = i;

	    for (int i = 0; i < sizeOfMatrix; i++)
			mark_[i]=true;
	    
	    for (int i = 0; i < sizeOfMatrix; i++)
			delete[] masHelp[i];
	    
		delete[] masHelp;
	}
	
	Algo::~Algo() {/* Doing smth with this block - exception!!!*/
	    //delete[] this->edge_;
	    //delete[] this->mark_;
	    //delete[] this->countOut_;
	}

	void Algo::print_edge() const {
	    for (int i = 0; i < m_; i++)
			cout << edge_[i].in+1 << ' ';
	    cout << '\n';
	}

	int Algo::get_num() {
		return countOut_[count_out_++].num;
	}

	void Algo::print_out() const {
		cout << '\n';
		for (int i = 0; i < n_; i++)
		    cout << "\nNum of vertex " << countOut_[i].num+1 << 
			" queue out " << countOut_[i].out+1 << '\n';
	}
	
	void Algo::qsort(int l, int r) {
		int i = l;
		int j = r;
		int cmp = edge_[l].in;

		while (i <= j) {
			while (edge_[i].in < cmp) i++;
			while (edge_[j].in > cmp) j--;
			if (i <= j) {
				swap(edge_[i].in, edge_[j].in);
				swap(edge_[i].from, edge_[j].from);
				i++;
				j--;
			}
		}

		if (l < j) qsort(l, j);
		if (r > i) qsort(i, r);
	}
	
	bool Algo::mark_num(int num) const {
		return mark_[num];
	}

	void Algo::qsort_out(int l, int r) {
		int i = l;
		int j = r;
		int cmp = countOut_[l].out;

		while (i <= j) {
			while (countOut_[i].out > cmp) i++;
			while (countOut_[j].out < cmp) j--;
			
			if (i <= j) {
				swap(countOut_[i].out, countOut_[j].out);
				swap(countOut_[i].num, countOut_[j].num);
				i++;
				j--;
			}
		}
		
		if (l < j) qsort_out(l, j);
		if (r > i) qsort_out(i, r);
	}

	void Algo::reboot() {
		for (int i = 0; i < n_; i++)
			mark_[i] = true;
	}

	void Algo::dfs(int u) {
		mark_[u] = false;
		//cout << "IN " << u+1 << "   ";
		
		for (int i = 0; i < m_; i++)
			if ((edge_[i].from == u) && (mark_[edge_[i].in]))
				dfs(edge_[i].in);

		//cout << "OUT " << u+1 << "   ";

		countOut_[u].out = count_++;
	}
	
	int Algo::search(int u) {
		for (int i = 0; i < n_; i++)
			if (countOut_[i].num == u)
				return countOut_[i].out;
		
		cout << "Exception\n";
		return -1;
	}
	
	void Algo::dfs_out(int u) {
		mark_[u] = false;
		cout << u+1 << ' ';

		for (int i = 0; i < m_; i++) 
			if ((edge_[i].in == u) && (mark_[edge_[i].from]) && (Algo::search(u) > Algo::search(edge_[i].from)))
				Algo::dfs_out(edge_[i].from);
	}

	void Algo::merge(int l1, int r1, int l2, int r2) {
		int size = r1 - l1 + r2 - l2 + 2;
		int i = l1;
		int j = l2;
		int k = 0;

		Edge* m = new Edge[size];

		while ((r1 - i >= 0) && (r2 - j >= 0))
			if (edge_[i].in < edge_[j].in)
				m[k++] = edge_[i++];
			else
				m[k++] = edge_[j++];

		while (r1 - i >= 0)
			m[k++] = edge_[i++];


		while (r2 - j >= 0)
			m[k++] = edge_[j++];


		for (int i = 0; i < size; i++)
			edge_[l1+i] = m[i];
	}

	void Algo::merge_out(int l1, int r1, int l2, int r2) {
		int size = r1 - l1 + r2 - l2 + 2;
		int i = l1;
		int j = l2;
		int k = 0;
	    
		CountOut* m = new CountOut[size];
	    
		while ((r1 - i >= 0) && (r2 - j >= 0))
			if (countOut_[i].out > countOut_[j].out)
				m[k++] = countOut_[i++];
			else
				m[k++] = countOut_[j++];

		while (r1 - i >= 0)
			m[k++] = countOut_[i++];

		while (r2 - j >= 0)
			m[k++] = countOut_[j++];

		for (int i = 0; i < size; i++)
			countOut_[l1+i] = m[i];
	}

	int Algo::count_of_edge() const {
		return this->m_;
	}

	int Algo::count_of_vertex() const {
		return this->n_;
	}

	bool Algo::cmark(int u) const {
		return mark_[u];
	}

    void threadMerge1 (Algo& obj, thread* m, const int numOfThreads) {
        int countOfEdge = obj.count_of_edge();

        if (numOfThreads == 8) {
                for (int i = 0; i < numOfThreads / 2; i++) {
                        m[i] = thread([&obj, i, countOfEdge, numOfThreads](){
                                obj.merge((countOfEdge * i * 2) / (numOfThreads),
                                        (countOfEdge * (2 * i + 1)) / numOfThreads - 1,
                                        (countOfEdge * (2 * i + 1)) / (numOfThreads),
                                        (countOfEdge * (2 * i + 2)) / numOfThreads - 1);
                        });
                }

                for (int i = 0; i < numOfThreads/2; i++) {
                        m[i].join();
                }
        }

        if (numOfThreads >= 4) {
                m[0] = thread([&obj, countOfEdge, numOfThreads](){
                        obj.merge(0, countOfEdge/4 - 1, countOfEdge/4,
                                countOfEdge/2 - 1);
                });

                m[1] = thread([&obj, countOfEdge, numOfThreads](){
                        obj.merge(countOfEdge/2, countOfEdge * 3 / 4 - 1,
                                countOfEdge * 3 / 4, countOfEdge - 1);
                });

                for (int i = 0; i < 2; i++) {
                        m[i].join();
                }
        }

        if (numOfThreads >= 2) {
                m[0] = thread([&obj, countOfEdge, numOfThreads](){
                        obj.merge(0, countOfEdge/2 - 1, countOfEdge/2, countOfEdge - 1);
                });

                m[0].join();
        }

    }

    void threadMerge2 (Algo& obj, thread* m, const int numOfThreads) {
        const int countOfVertex = obj.count_of_vertex();

        if (numOfThreads == 8) {
                for (int i = 0; i < numOfThreads / 2; i++) {
                        m[i] = thread([&obj, i, countOfVertex, numOfThreads](){
                                obj.merge_out((countOfVertex * i * 2) / (numOfThreads),
                                        (countOfVertex * (2 * i + 1)) / numOfThreads - 1,
                                        (countOfVertex * (2 * i + 1)) / (numOfThreads),
                                        (countOfVertex * (2 * i + 2)) / numOfThreads - 1);
                        });
                }

                for (int i = 0; i < numOfThreads/2; i++) {
                        m[i].join();
                }
        }

        if (numOfThreads >= 4) {
                m[0] = thread([&obj, countOfVertex, numOfThreads](){
                        obj.merge_out(0, countOfVertex/4 - 1, countOfVertex/4,
                                countOfVertex/2 - 1);
                });

                m[1] = thread([&obj, countOfVertex, numOfThreads](){
                        obj.merge(countOfVertex/2, countOfVertex * 3 / 4 - 1,
                                countOfVertex * 3 / 4, countOfVertex - 1);
                });

                for (int i = 0; i < 2; i++) {
                        m[i].join();
                }
        }

        if (numOfThreads >= 2) {
                m[0] = thread([&obj, countOfVertex, numOfThreads](){
                        obj.merge_out(0, countOfVertex/2 - 1, countOfVertex/2,
                                countOfVertex - 1);
                });

                m[0].join();
        }
    }

#endif
