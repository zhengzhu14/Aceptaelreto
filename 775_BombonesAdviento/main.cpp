#include <iostream>

using namespace std;

bool resolver2(){
    long long int n;
    cin >> n;
    if (n == 0) return false;

    long long int tipos = n;
    long long int ant = n;
    cin >> n;
    while (n != 0){
        if (tipos - ant < n){
            tipos += (n - (tipos - ant));
        }
        ant = n;
        cin >> n;
    }

    cout << tipos << '\n';


    return true;
}

int main (){
    while (resolver2());

    return 0;
}