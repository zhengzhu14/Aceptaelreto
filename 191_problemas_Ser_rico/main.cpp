#include <iostream>

void resuelveCaso() {
	int numComp, biggestComp, difComp, Capacidad=0;
	std::cin >> numComp >> biggestComp >> difComp;
	for (int i = 0; i < numComp; ++i) {
	 Capacidad = Capacidad + (biggestComp - (difComp * i));
	}
	std::cout << Capacidad << '\n';
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();
	return 0;
}