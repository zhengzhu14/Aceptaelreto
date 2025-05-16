#include <iostream>


using namespace std;

void resolver() {
	int n;
	cin >> n;
	if (n == 2) cout << 2 << endl;
	else if (n == 3) cout << 6 << endl;
	else if (n == 4) cout << 4 << endl;
	else if (n == 1 || n == 0) cout << 1 << endl;
	else cout << 0 << endl;
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)  resolver();
	return 0;
}