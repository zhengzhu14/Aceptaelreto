#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ii = pair <int, int>;
using lliii = pair<long long int, ii>;

struct Comparador{
    bool operator () (lliii const & a, lliii const & b){
        return a.first < b.first || (a.first == b.first && (a.second.first > b.second.first));
    }
};

bool resolver2(){
    int n, k;
    cin >> n >> k;
    if (n == 0 && k == 0) return false;
    vector<int> r(n);
    for (int i = 0; i < n; ++i){
        cin >> r[i];
    }
    
    long long int acum = 0;
    for (int i = 0; i < k; ++i){
        acum += r[i];
    }
    priority_queue<lliii, vector<lliii> , Comparador> cola;
    cola.push({acum, {0, k - 1}});
    int ai = 1, aj = k;
    while (aj < n){
        acum = acum - r[ai - 1] + r[aj];
        cola.push({acum, {ai, aj}});
        ++ai; ++aj;
    }

    vector<bool> visitado(n, false);
    while (!cola.empty()){
        lliii top = cola.top(); cola.pop();
        int aux1 = top.second.first; int aux2 = top.second.second;
        long long int acumulado = top.first;
        if (!visitado[aux1] && !visitado[aux2]){
            for (int i = aux1; i <= aux2; ++i){
                visitado[i] = true;
            }
        }
    }


    long long int perdido = 0;
    for (int i = 0; i < n; ++i){
        if(!visitado[i]) {
            perdido += r[i];
        }
    }
    cout << perdido << '\n';


    return true;
}

int main (){
    while (resolver2());

    return 0;
}