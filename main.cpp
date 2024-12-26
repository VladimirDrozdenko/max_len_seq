#include <iostream>
#include <set>
using namespace std;

int main() {
	int a[] = {3, 10, 4, 2, 16, 1, -1, 6, 5};
	const size_t N = sizeof(a)/sizeof(*a);

	set<int> hs;
	for (size_t i = 0; i < N; ++i) {
		hs.insert(a[i]);
	}

	int max_cnt = 0;
	for (size_t i = 0; i < N; ++i) {
		if (hs.find(a[i] - 1) == hs.end()) {
			// begining of a sequence

			int cnt = 1;
			int val = a[i] + 1;
			while (hs.find(val) != hs.end()) {
				++cnt;
				++val;
			}

			max_cnt = max(max_cnt, cnt);
		}
	}

	cout << "Max sequence: " << max_cnt << endl;
}