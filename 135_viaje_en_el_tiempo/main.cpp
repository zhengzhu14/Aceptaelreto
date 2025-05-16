#include <iostream>

using namespace std;

const int MAX = 1e6;


void resolver2(){
    int contador = 0;
    int anterior, actual;
    cin >> anterior;
    cin >> actual;
    while (actual != -1){
        
    }
}

void resolver(){
    int contador = 0;
    int anterior, actual;
    int diferencia;
    cin >> anterior;
    cin >> actual;
    diferencia = (actual + MAX - anterior)%MAX;
    while (actual != -1){
        if (((actual + MAX - anterior)%MAX) != diferencia) {
            ++contador;
            diferencia = (actual + MAX - anterior)%MAX;
        }
        anterior = actual;
        cin >> actual;
    }
    cout << contador << ' ' << (diferencia + MAX + anterior)%MAX << '\n';
}

int main(){
    int casos;
    cin >> casos;
    for (int i = 0; i < casos; ++i) resolver();

    return 0;
}