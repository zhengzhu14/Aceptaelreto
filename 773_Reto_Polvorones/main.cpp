#include <iostream>
#include <vector>

using namespace std;

bool resolver2(){
    int n, p;
    cin >> n >> p;
    if (n == 0 && p == 0) return false;
    vector<int> maximos(p);
    for (int i = 0; i < p; ++i){
        cin >> maximos[i];
    } 
    vector<int> hay(p);
    for (int i = 0; i < p; ++i){
        cin >> hay[i];
    }

    int cont = 0;
    int i = 0; 
    while (i < p && cont + hay[i] <= n && hay[i] <= maximos[i]){
        cont += hay[i];
        ++i;
    }

    if (i < p){
        cout << "NO\n";
    }
    else cout << "SI\n";
    

    return true;
}

int main (){
    while (resolver2());

    return 0;
}