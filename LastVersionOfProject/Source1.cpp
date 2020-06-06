#include <iostream>
#include <thread>
#include <ctime>
#include <cstdlib>

using namespace std;

void qqsort(int* mas, int l, int r) {
	int i = l;
	int j = r;
	int cmp = mas[l];
	while (i <= j) {
		while (mas[i] < cmp) i++;
		while (mas[j] > cmp) j--;
		if (i <= j) {
			swap(mas[i], mas[j]);
			i++;
			j--;
		}
	}
	if (l < j) qqsort(mas, l, j);
	if (r > i) qqsort(mas, i, r);
}

bool test(int* mas, int n) {
	for (int i = 0; i < n - 1; i++)
		if (mas[i] > mas[i + 1])
			return false;
	return true;
}

int main() {
	srand(time(0));
	double start = clock();

	const int n = 2000000, num = 8;
	int mas[n];
	thread m[num];

		for (int i = 0; i < num; i++) {
			m[i] = thread(qqsort,mas, (n*i)/(num), (n*(i+1))/num - 1);
		}
		for (int i = 0; i < num; i++) {
			m[i].join();
			cout << "Im thread num - " << i + 1 << '\n';
		}

	double end = clock();
	cout << '\n' << (end - start) / 1000000 << '\n';
	return 0;
}