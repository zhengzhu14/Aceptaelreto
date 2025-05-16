#include <iostream>
#include <vector>

using namespace std;

void resolver() {

	int cont = 0; 
	int dato;
	cin >> dato;
	int div = dato / 5;
	while (div > 0) {
		cont += div;
		div /= 5;
	}

	cout << cont << endl;

}

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i)  resolver();


	return 0;
}