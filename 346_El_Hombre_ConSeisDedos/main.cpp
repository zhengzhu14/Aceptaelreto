#include <iostream>
#include <vector>
using namespace std;

bool resolver() {
	int tam, a;
	cin >> tam >> a;
	if (tam == 0 && a == 0) return false;

	std::vector <int> v(tam);
	for (int i = 0; i < tam; ++i) {
		cin >> v[i];
	}

	int d = v[0];
	int i = 0;
	int j = 0;
	int cont = 0;
	int max = 0;
	while (j < v.size()) {
		while (j< v.size() && v[j] <= (d + a - 1)) {
			++j;
			++cont;
		}
		if (cont > max) max = cont;
		if (j < v.size()) {
			while (v[i] == d) {
				++i;
				--cont;
			}
			d = v[i];
		}
	}

	cout << max << endl;

	return true;
}


int main() {
	while (resolver());
	return 0;
}