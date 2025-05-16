#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;
using imatriz = vector<vector<int>>;

const int INF = 1e9;

/*
Problema similar al de cambio de las monedas

    diana(i, j) = numero minimo de dados para conseguir j puntos con los sectores del 1 al i

    diana(i, j) = {
                        diana(i - 1, j)      si S(i) > j
                        min(diana(i - 1, j), diana(i - 1, j - S(i)) + 1)  si S(i) <= j
    
                    }

    Inicializacion = diana(s, n)

    Casos base: 
        diana(s, 0) = 0
        diana(0, j) = INF si j > 0

    Voy a realizar la estrategia bottom-up con un solo vector como memoria para la programación dinámica

*/

bool resuelveCaso(){
    int n, s;
    cin >> n >> s;
    if (!cin) return false;
    vi sectores(s + 1, 0);
    for (int i = 1; i <= s; ++i){
        cin >> sectores[i];
    }

    vi acumulador(n + 1, INF);

    acumulador[0] = 0;
    for (int i = 1; i <= s; ++i){
        for (int j = sectores[i]; j <= n; ++j){
            acumulador[j] = min(acumulador[j], acumulador[j - sectores[i]] + 1); 
        }
    }

    vector<int> sol;
    if (acumulador[n] < INF) {
        int i = s, j = n;
        while (j > 0) { // no se ha pagado todo
            if (sectores[i] <= j && acumulador[j] == acumulador[j - sectores[i]] + 1) {
                sol.push_back(sectores[i]);
                j = j - sectores[i];
            } else // no tomamos más monedas de tipo i
                --i;
        }
    }

    if (acumulador[n] < INF){
        cout << acumulador[n] << ":";
        for (int i = 0; i < sol.size(); ++i){
            cout << ' ' << sol[i];
        }
        cout  << '\n';
    }
    else {
        cout << "Imposible\n";
    }

    return true;
}

int main(){

    while(resuelveCaso());

    return 0;
}