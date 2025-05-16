#include <iostream> 
#include <vector>

using namespace std;

bool resolver(){
    int n, k;
    cin >> n >> k;
    if (n == 0 && k == 0) return false;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int max = 0; int sum = 0; int aux = 0;
    int i = 0; 
    while (i < n){
        if (a[i] == 1){
            int j = i;
            while (j < n && aux <= k){
                ++sum;
                if (a[i] == 1){
                    if (max < sum) max = sum;
                    aux = 0;
                }
                else {
                    ++aux;
                }
                if (aux <= k){
                    ++i;++j;
                } 
            }
        }
        sum = 0;
        aux = 0;
        ++i;
    }
    cout << max << '\n';
    return true;
}

int main(){
    while (resolver());
    return 0;
}