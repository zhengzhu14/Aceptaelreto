#include <iostream>

using namespace std;

bool resolver2(){
    int n, num;
    cin >> n >> num;
    if (n == 0 && num == 0) return false;

    cout <<"[" << n + (74*num) << " .. "<< n + (79*num) << "]\n";

    return true;
}

int main (){
    while (resolver2());

    return 0;
}