#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/* int gcd (int n1, int n2){
    while(n1 != n2) {
        if(n1 > n2)
        n1 -= n2;
        else
        n2 -= n1;
    }

    return n1;
} */

void resolver(){
    int a, b;
    cin >> a >> b;
    int mcd = __gcd(a, b);
    a = a/mcd;
    b = b/mcd;

    cout << (a + b - 1) << '\n';
    
}

int main (){
    int casos;
    cin >> casos;
    for (int i = 0; i < casos; ++i){
        resolver();
    }

    return 0;
}