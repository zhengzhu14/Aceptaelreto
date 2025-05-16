//#include <iostream>
#include <bits/stdc++.h>
#include <vector>
//#include <cstring>

using namespace std;

/* bool resuelveCaso(){
    int num; cin >> num;
    if (num == 0 )return false;
    //int a[100];
    //memset(a, 0, 4*100); 
    vector<int> a(100, 0);
    int cont = 0;
    int aux;
    for (int i = 0; i < num; ++i){
        cin >> aux;
        a[aux - 1] += 1;
    }

    int g4 = 0, g2 = 0;
    for (int v: a){
        if (v > 0){
            g4 += v/4;
            g2 += (v%4 >= 2) ? 1: 0;
        }
    }

    if (g2 >= g4) cout << g4 << '\n';
    else {
        int cont = g2;
        int g4_restantes = g4 - g2;
        cont += 2*(g4_restantes/3);
        cont += (g4_restantes%3 == 2) ? 1: 0;
        cout << cont << '\n';
    }

    return true;
} */

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //while (resuelveCaso());
    int num; cin >> num;
    int a[100];
    while (num != 0){
        //int a[100];
        memset(a, 0, 4*100);
        //vector<int> a(100, 0);
        int cont = 0;
        int aux;
        for (int i = 0; i < num; ++i){
            cin >> aux;
            a[aux - 1] += 1;
        }

        int g4 = 0, g2 = 0;
        for (int v: a){
            if (v > 0){
                g4 += v/4;
                g2 += (v%4 >= 2) ? 1: 0;
            }
        }

        if (g2 >= g4) cout << g4 << '\n';
        else {
            int cont = g2;
            int g4_restantes = g4 - g2;
            cont += 2*(g4_restantes/3);
            cont += (g4_restantes%3 == 2) ? 1: 0;
            cout << cont << '\n';
        }

        cin >> num;
    }

    return 0;
}