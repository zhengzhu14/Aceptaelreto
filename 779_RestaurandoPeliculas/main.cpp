#include <iostream>
#include <queue> 
#include <vector>

using namespace std;
using ii = pair <int, int>;

bool resolver(){
    int frag, museos;
    cin >> frag >> museos;
    if (frag == 0 && museos == 0) return false;

    priority_queue<ii, vector<ii>, greater<ii>> cola;   
    for (int i = 0; i < museos; ++i){
        int partes; cin >> partes;
        for (int j = 0; j < partes; ++j){
            int ini, fin;
            char aux;
            cin >> ini >> aux >> fin;
            cola.push({ini, fin});
        }
    }

    int momento = 0;
    while (!cola.empty() && cola.top().first <= (momento + 1) && momento < frag){
        int aux = momento;
        while (!cola.empty() && cola.top().first <= (momento + 1)){
            ii par = cola.top(); cola.pop(); 
            if (par.second > aux){
                aux = par.second;
            }
        }
        if (aux > momento){
            momento = aux;;
        }
    }

    if (momento >= frag){
        cout << "SI\n";
    }
    else cout << "NO\n";


    return true;
}

int main (){
    while (resolver());
    return 0;
}