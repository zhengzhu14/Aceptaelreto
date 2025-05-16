#include <iostream>
#include <vector>
#include <fstream>
#include <queue> 

using namespace std;
using ii = pair<int,int>;


bool resuelveCaso(){
    int n; cin >> n;
    if (n == 0) return false;
    priority_queue<ii, vector<ii>, greater<ii>> cola;
    //Lo ordeno de mayor a menor respecto de la hora de fin y nos vaya devolviendo el minimo;
    int occ, ori;
    for (int i = 0; i < n; ++i){
        cin >> occ >> ori;
        cola.push({ori, occ});
    }
    

    int cont = 0; 
    int actual = 0;
    while (!cola.empty()){
        if (cola.top().second >= actual){
            actual = cola.top().first;
            ++cont;
        }
        cola.pop();
    }
    cout << cont << '\n';
    
    return true;
}

int main(){
    /* #ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf());
    #endif */
    while (resuelveCaso());
    /* #ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    system("PAUSE");
    #endif */
}