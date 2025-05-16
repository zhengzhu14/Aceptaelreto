#include <iostream>

using namespace std;

void resolver1(){
    int an;
    cin >> an;
    cout << 4*an << '\n';
}

int main(){

    int casos;
    cin >> casos;
    for (int i = 0; i < casos; ++i){
        resolver1();
    }

    return 0;
}