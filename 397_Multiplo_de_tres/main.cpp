#include <iostream>

using namespace std;



int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		long long int n;
		cin >> n;
		cout << (((((n * (n + 1)) / 2) % 3) == 0) ? "SI" : "NO") << endl;
	}


	return 0;
}