#include <iostream>
#include <vector>
#include <string> 

using namespace std;

/*
Recursion: 
    aibofobia(i, j) = numero de caracteres a anyadir para formar un palindromo con los caracteres el i al j
    0 <= i <= j < n. Siendo n el numero de caracteres tiene la cadena original. 

    aibofobia(i, j) = { aibofobia(i + 1, j - 1)                 si str[i] == str[j]
                        min(aibofobia(i + 1, j), aibofobia(i, j - 1)) + 1   si str[i] != str[j]
                        }

Llamada inicial : aibofobia(0, n - 1)

Casos Base: 
    aibofobia(i, j) = 0 si i >= j


Voy a resolverlo con la metodología top-down

*/

using vi = vector<int>;
using matriz = vector<vi>;

int aibofobia(int n, string const& str, matriz & aib, int i, int j){
    if (i >= j) {
        return 0;
    }
    else if (aib[i][j] != -1){
        return aib[i][j];
    }
    else {
        if (str[i] == str[j]){
            aib[i][j] = aibofobia(n, str, aib, i + 1, j - 1);
        }
        else {
            aib[i][j] = min(aibofobia(n, str, aib, i + 1, j), aibofobia(n, str, aib, i, j - 1)) + 1;
        }
        return aib[i][j];
    }

}

bool resuelveCaso(){
    string str;
    cin >> str;
    if (!cin) return false;
    int n = str.size();


    matriz aib(n, vi (n, -1));
    int sol = aibofobia(n, str, aib, 0, n - 1);
    
    cout << sol << '\n';



    return true;
}

int main(){

    while(resuelveCaso()); 
    return 0;
}