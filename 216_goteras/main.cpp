#include <iostream>

void resuelveCaso() {
	int got;
	std::cin >> got;
	int hour, min, seg;
	hour = got / 3600;
	min = (got % 3600) / 60;
	seg = (got % 3600) % 60;
	int h1, h2, m1, m2, s1, s2;
	h1 = hour / 10;
	h2 = hour % 10;
	m1 = min / 10;
	m2 = min % 10;
	s1 = seg / 10;
	s2 = seg % 10;
	std::cout << h1 << h2 << ":" << m1 << m2 << ":" << s1 << s2 << '\n';
}


int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();
	return 0;
}