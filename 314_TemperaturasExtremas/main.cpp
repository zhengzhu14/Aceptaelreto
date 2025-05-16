#include <iostream>
#include <vector>

using namespace std;

void resolver() {
	int pico = 0, valle = 0;
	int tam;
	cin >> tam;
	if (tam >= 3) {
		int uno = 0, medio = 0;
		int next = 0;
		cin >> uno >> medio;
		for (int i = 2; i < tam; ++i) {
			cin >> next;
			if (medio > next && medio > uno) {
				++pico;
			}
			if (medio < next && medio < uno) {
				++valle;
			}

			uno = medio;
			medio = next;

		}
	}
	else {
		int  aux;
		for (int i = 0; i < tam; ++i) cin >> aux;
	}
	cout << pico << ' ' << valle << endl;
}

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();

	return 0;
}