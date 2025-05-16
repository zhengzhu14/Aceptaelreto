#include <iostream>
#include <vector>

using namespace std;

bool resolver2(){
    int n;
    cin >> n;
    if (n == 0) return false;

    long long int num;
    cin >> num;
    int cont = 1;
    long long int maximo = num;
    
    for (int i = 1; i < n; ++i){
        cin >> num;
        if (num < maximo) { //Este esta desordenado
            cont = 0;
        }
        else {
            if (num > maximo) maximo = num;
            ++cont;
        }
        
    }
    cout << cont << '\n';

    return true;
}

int main (){
    while (resolver2());

    return 0;
}