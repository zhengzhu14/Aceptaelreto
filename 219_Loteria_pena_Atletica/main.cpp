#include <iostream>

void resuelveCaso() {
	int n, numPares=0, x;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> x;
		if (x % 2 == 0) {
			numPares += 1;
		}
		else
			numPares += 0;
	}
	std::cout << numPares << '\n';
}

int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();
	return 0;
}