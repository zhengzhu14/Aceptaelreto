#include <iostream>
#include <vector>

using namespace std;

bool resuelveCaso() {
	int mont;
	cin >> mont;
	if (mont == 0) return false;

	std::vector <int> alturas;
	int dato;
	for (int i = 0; i < mont; ++i) {
		cin >> dato;
		alturas.push_back(dato);
	}

	int cont = 1;	 //por defecto inicializo el contador a 1, 
					//porque la montaña que está en el Este siempre es buen sitio para montar la abadia

	int max = alturas.size() - 1;
	for (int i = alturas.size() - 2; i >= 0; --i) {
		if (alturas[i] > alturas[max]) {
			max = i;
			++cont;
		}
	}

	cout << cont << endl;

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}