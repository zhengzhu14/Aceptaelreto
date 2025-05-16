#include <iostream>
#include <vector>


using namespace std;

bool resolver() {
	int paises;
	cin >> paises;
	if (paises == 0) return false;
	std::vector <int> p;
	int al;
	for (int i = 0; i < paises; ++i) {
		cin >> al;
		p.push_back(al);
	}

	long long int cont = 0;
	long long int suma = 0;
	for (int i = p.size() - 1; i > 0; --i) {
		suma += p[i];
		cont += suma * p[i - 1];
	}
	cout << cont << endl;

	return true;
}


int main() {

	while (resolver());

	return 0;
}