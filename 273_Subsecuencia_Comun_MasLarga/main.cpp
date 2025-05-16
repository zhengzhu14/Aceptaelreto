#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Tengo str1 y str2 que son las dos cadenas de caracteres. 
N = str1.size(),  M = str2.size(). 

Definicion:

    subComun(i, j) = tamanyo de cadena mas larga en comun desde el caracter 1 hasta i de str1 y del 1 al j en str2.

Recursion:

    subComun(i, j) = {  subComun(i - 1, j - 1) + 1              si str1[i] == str2[j]
                        max(subComun(i - 1, j), subComun(i, j - 1)) en otro caso
                        }

Casos base:

    subComun(i, j) = 0  si i < 0 || j < 0

Llamada inicial: subComun(N, M) (En la implementacion sería subComun(N - 1, M - 1))
Costes:
    - Complejidad en tiempo:
    - Complejidad en espacio adicional:
    - Complejidad en reconstruir la solucion: 
*/

using vi = vector<int>;
using matriz = vector<vi>;

int subComunDesc(string const & str1, string const& str2, matriz & subComun, int i, int j){
    if (i < 0 || j < 0){
        return 0;
    }
    else if (subComun[i][j] != -1) return subComun[i][j];
    else if (str1[i] == str2[j]){
        return subComun[i][j] = subComunDesc(str1, str2, subComun, i - 1, j - 1) + 1;
    }
    else {
        return subComun[i][j] = max(subComunDesc(str1, str2, subComun, i - 1, j), subComunDesc(str1, str2, subComun, i, j - 1));
    }
}

void reconstruirSol(string const& str1, string const& str2, matriz const& subComun, int i, int j, string & sol){
    if (i < 0 || j < 0){
        return;
    }
    else {
        if (str1[i] == str2[j]){
            reconstruirSol(str1, str2, subComun, i - 1, j - 1, sol);
            sol.push_back(str1[i]); //Este caracter se ha tomado si o si
        }
        else if (i > 0 && j > 0){
            if (subComun[i][j] == subComun[i - 1][j]){ //Saltando el caracter str1[i] se consigue el maximo
                reconstruirSol(str1, str2, subComun, i - 1, j, sol); 
            }
            else { //Saltando el caracter str2[j] se consigue el maximo
                reconstruirSol(str1, str2, subComun, i, j - 1, sol);
            }
        }
        
    }
}

bool resuelveCaso(){
    string str1, str2;
    cin >> str1 >> str2;
    if (!cin) return false;
    int n= str1.size();
    int m = str2.size();
    matriz subComun(n, vi(m, -1));

    int valor = subComunDesc(str1, str2, subComun, n - 1, m - 1);
    /* if (valor > 0){
        string sol = "";
        reconstruirSol(str1, str2, subComun, n - 1, m - 1, sol);

        cout << sol;
    } */
    cout << valor;
    cout << '\n';

    return true;
}

int main(){

    while (resuelveCaso());

    return 0;
}