#include <iostream>
#include <vector>

using namespace std;


void resolver() {
	int suma = 0;
	cin >> suma;
	char c;
	cin.get(c);
	std::vector <int> v;
	while (c != '\n') {
		cin.get(c);
		if (c != '\n') {
			v.push_back(c - '0');
		}
	}

	int cont = 0;
	int aux = 0;
	int k = 0;
	for (int i = 0; i < v.size(); ++i) {
		aux += v[i];
		if (aux > suma) {
			while (k <= i && aux > suma) {
				aux -= v[k];
				++k;
			}
		}
		if (aux == suma) {
			++cont;
			aux -= v[k];
			++k;
		}
	}
	cout << cont << endl;

}

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i)resolver();

	return 0;
}