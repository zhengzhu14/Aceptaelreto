#include <iostream>

void resuelveCaso() {
	int largo, ancho;
	std::cin >> largo >> ancho;
	int numCerillas = (largo*2) + (ancho*2) + (largo*(ancho-1)) + (ancho*(largo-1));
	std::cout << numCerillas << '\n';
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();
	return 0;
}