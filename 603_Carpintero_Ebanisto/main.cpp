#include <iostream>
#include <vector>


using namespace std;


using vi = vector<int>;
using lli = long long int;
using matriz = vector<vi>;

const int INF = 1e9;
int ebanistaDesc(vector<int> const& cortes, matriz& ebanista, int i, int j, int ini, int fin){
    if (i > j){
        return 0;
    }
    else if (ebanista[i][j] != -1) return ebanista[i][j];
    else {
        int minimo = INF;
        int aux;
        for (int k = i; k <= j; ++k){
            aux = ebanistaDesc(cortes, ebanista, i, k - 1, ini, cortes[k]) + ebanistaDesc(cortes, ebanista, k + 1, j, cortes[k], fin);
            aux+=2*(fin - ini);
            if (aux < minimo){
                minimo = aux;
            }
        }
        ebanista[i][j] = minimo;
        return ebanista[i][j];
    }
}

bool resuelveCaso(){
    int l, n;
    cin >> l >> n;
    if (l == 0 && n == 0) return false;

    vector<int> cortes(n);
    for (int i = 0; i < n; ++i){
        cin >> cortes[i];
    }

    matriz ebanista(n, vi(n, -1));
    int sol = ebanistaDesc(cortes, ebanista, 0, n - 1, 0, l);
    cout << sol << '\n';

    return true;
}


int main(){
    
    while(resuelveCaso());

    return 0;
}