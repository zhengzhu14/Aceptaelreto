//#include <iostream>
//#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int main (){
    /* ios::sync_with_stdio(false);
    cin.tie(NULL); */
    int num; 
    scanf("%d", &num);
    
    while (num != 0)
    {
        int cont = 0;
        int aux;
        for (int i = 0; i < num - 1; ++i){
            scanf("%d", &aux); 
            cont += aux - 1;
        }
        scanf("%d", &aux); 
        cont += aux;
        printf("%d\n", cont);
        scanf("%d", &num);
    }
}