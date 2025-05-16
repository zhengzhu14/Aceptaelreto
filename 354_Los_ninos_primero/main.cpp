#include <iostream>
#include <vector>

using namespace std;

bool resolver() {
	int tam;
	cin >> tam;
	if (tam == 0) return false;
	std::vector <int> v(tam);
	for (int i = 0; i < tam; ++i) {
		cin >> v[i];
	}
	int cont = 1;
	int max = v[0];
	int aux = max;
	int i = 0;
	while (i < tam) {
		if (v[i] > max) {
			max = v[i];
		}
		if (v[i] <= aux) {
			cont = i + 1;
			aux = max;
		}
		++i;
	}
	cout << cont << endl;

	return true;
}

int main() {
	while (resolver());

	return 0;

}