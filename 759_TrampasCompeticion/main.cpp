#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>


using namespace std;
using ii = pair<int, int>;

enum tEstado {HUNDIDO, TOCADO, NO_VISTO};   
int n, c;

vector<unordered_set<int>> grafo;
vector<pair<char, ii>> clasif;
vector<tEstado> estado;



struct UFDS {
    vector<int> p;
    int numSets;
    UFDS (int n): p(n, 0), numSets(n){
        for (int i = 0; i < n; ++i) p[i] = i;
    }
    int find(int x){
        return (p[x] == x) ? x: p[x] = find(p[x]);
    }
    void merge(int x, int y){
        int i = find(x), j = find(y);
        if (i == j) return;
        p[i] = j;
        --numSets;
    }

};


bool dfs(int u) {
    estado[u] = TOCADO;
    for(int v: grafo[u]){
        if (estado[v] == TOCADO)
            return true;
        else if ((estado[v] == NO_VISTO) && dfs(v))
            return true;
    }
    estado[u] = HUNDIDO;
    return false;
}

bool verTramposo( UFDS &igualdades){
   
    int i = 0; 
    
    while (i < clasif.size()){
        char op = clasif[i].first;
        int v = clasif[i].second.first; int u = clasif[i].second.second;
        if (op == '>'){ // v > u
            grafo[igualdades.find(v)].insert(igualdades.find(u));
        }
        else if (op == '<'){ //u < v
            grafo[igualdades.find(u)].insert(igualdades.find(v));
        }
        ++i;
    }

    bool trampas = false;
    int j = 0; 
    while (j < n && !trampas){
        if (estado[j] != HUNDIDO){
            trampas = dfs (j);
        }
        ++j;
    }

    return trampas;
}

bool resuelveCaso(){
    cin >> n >> c;
    if (!cin) return false;
    clasif.assign(0, {});
    grafo.assign(n, {});
    estado.assign(n, NO_VISTO);
    UFDS igualdades(n); //Inicializo las igualdades

    int v, u;
    char aux;
    for (int i = 0; i < c; ++i){
        cin >> v >> aux >> u;
        if (aux == '='){
            igualdades.merge(v - 1, u - 1);
        }
        else clasif.push_back({aux, {v - 1, u - 1}});
    }

    bool sol = verTramposo(igualdades);
    if (sol){ //Hay trampas
        cout << "TRAMPAS\n";
    } 
    else {
        cout << "DESCONFIADO\n";
    }

    return true;
}

int main(){
    

    while(resuelveCaso());

    
    return 0;
}