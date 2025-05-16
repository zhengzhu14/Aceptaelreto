#include <iostream>
#include <vector>

using namespace std;
using matriz = vector<vector<int>>;


int maxComidaDesc(matriz & maxComida, vector<int>const& cubos, int i, int j){
    if (i == j){
        maxComida[i][j] = cubos[i];
        return cubos[i];
    }
    else if (i > j){
        return 0;
    }
    else if (maxComida[i][j] != -1) return maxComida[i][j];
    else {
        int& res = maxComida[i][j];
        if (cubos[i + 1] > cubos[j] && cubos[j - 1] > cubos[i]){
            res = max(maxComidaDesc(maxComida, cubos, i + 2, j) + cubos[i], maxComidaDesc(maxComida, cubos, i, j - 2)+ cubos[j]);
        }
        else {
            int aux = maxComidaDesc(maxComida, cubos, i + 1, j - 1);
            if (cubos[j - 1] > cubos[i]){
                res = max(aux + cubos[i], maxComidaDesc(maxComida, cubos, i, j - 2) + cubos[j]);
            }
            else if (cubos[i + 1] > cubos[j]){
                res = max(maxComidaDesc(maxComida, cubos, i + 2, j) + cubos[i], aux + cubos[j]);
            }
            else {
                res = max(aux + cubos[i], aux + cubos[j]);
            }
        }
        return res;
    }
}

bool resuelveCaso(){
    int n;
    cin >> n;
    if (n == 0) return false;

    vector<int> cubos(n);
    for (int i = 0; i < n; ++i){
        cin >> cubos[i];
    }

    matriz maxComida(n, vector<int> (n, -1));
    int sol = maxComidaDesc(maxComida, cubos, 0, n - 1);

    cout << sol << '\n'; 


    return true;
}

int main (){
    while(resuelveCaso());
    return 0;
}