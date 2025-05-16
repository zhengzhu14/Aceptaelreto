#include <iostream>
#include <vector>

using namespace std;

void mostrar( const std::vector<std::vector <char>>& matriz) {
	for (int i = 0; i < matriz.size(); ++i) {
		for (int j = 0; j < matriz[i].size(); ++j) {
			cout << matriz[i][j];
		}
		cout << endl;
	}
}

int buscarColor(char elemento, std::vector <std::pair<char, char>> colores) {
	int i = 0; 
	while (i < colores.size() && colores[i].first != elemento) {
		++i;
	}
	if (i < colores.size()) return i;
	return -1;
}




bool resolver() {
	int col, fil;
	cin >> fil >> col;
	if (fil == 0 && col == 0) return false;

	std::vector <std::vector<char>> matriz;
	std::vector <pair<char, char>> colores;
	std::pair <char, char> dato;

	for (int i = 0; i < fil; ++i) {
		std::vector <char> fila;
		char elemento;
		for (int j = 0; j < col; ++j) {
			cin >> elemento;
			fila.push_back(elemento);
			if (buscarColor(elemento, colores) == -1) {
				dato.first = elemento;
				dato.second = elemento;
				colores.push_back(dato);
			}
		}
		matriz.push_back(fila);
	}

	int pintores;
	char ini, fin;
	cin >> pintores;
	for (int i = 0; i < pintores; ++i) {
		cin >> ini >> fin;
		for (int k = 0; k < colores.size(); ++k) {
			if (colores[k].second == ini) {
				colores[k].second = fin;
			}
		}
	}
	int pos = 0;
	for (int i = 0; i < fil; ++i) {
		for (int j = 0; j < col; ++j) {
			pos = buscarColor(matriz[i][j], colores);
			matriz[i][j] = colores[pos].second;
		}
	}
	mostrar(matriz);
	return true;
}
int main() {
	while (resolver());

	return 0;
}