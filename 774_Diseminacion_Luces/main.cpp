#include <iostream>
#include <unordered_map>

using namespace std;

bool resolver2(){
    int n;
    cin >> n;
    if (n == 0) return false;
    unordered_map<int, int> mapa;
    long long int disem = 0;
    int aux;
    for (int i = 0; i < n; ++i){
        cin >> aux;
        if (mapa.count(aux) == 1){
            disem += (i - mapa[aux]);
        }
        mapa[aux] = i;
    }

    cout << disem << '\n';


    return true;
}

int main (){
    while (resolver2());

    return 0;
}