#include <iostream>
#include <vector>
using namespace std;

bool resolver() {
	int tam, aux = 0, aux2=0;
	cin >> tam;
	if (tam == 0) return false;

	std::vector <int> v(tam+1);
	v[0] = 0;
	for (int i = 1; i <= tam; ++i) {
		cin >> aux;
      	aux2+= aux;
		v[i] = aux2;
 	}

	
	cin >> aux;
	int ini, fin;
	for (int i = 0; i < aux; ++i) {
		cin >> ini >> fin;
		cout << v[fin] - v[ini - 1] << endl;
	}

	return true;
}

int  main() {

	while (resolver());
	return 0;
}