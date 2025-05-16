#include <iostream>
#include <vector>

using namespace std;
using ii = pair<int,int>;

bool resolver2(){
    int n;
    cin >> n;
    if (n == 0) return false;
    vector<ii> timbal;
    for (int i = 0; i < n; ++i){
        int ini, fin;
        cin >> ini >> fin;
        timbal.push_back({ini, fin});
    }
    vector<int> compases;
    int c;
    cin >> c;
    while (c != 0){
        compases.push_back(c);
        cin >> c;
    }

    int i = 0, j = 0, cont = 0;
    while (j < compases.size()){
        if (i < n){
            if (compases[j] >= timbal[i].first && compases[j] <= timbal[i].second){
                ++j;
            }
            else if (compases[j] > timbal[i].second) ++i;
            else {
                ++j; ++cont;
            }
        }
        else {
            ++cont; ++j;
        }
        
    }

    cout << cont << '\n';

    return true;
}

int main (){
    while (resolver2());

    return 0;
}