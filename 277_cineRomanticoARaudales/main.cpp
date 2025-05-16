#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
using vii = vector<pair<int, int>>;

const int MIN_DIA = 1440 + 10;
const int DES = 10;
int pasarMinutos(int horas, int minutos){
    return (horas*60) + minutos;
}

/* 
//Es la solucion con descendente hacia delante
int romanticoDesc(vii const& programacion, vector<vector<int>> & romantico, int i , int j){
    if (i >= programacion.size()){
        return 0;
    }
    else if (romantico[i][j] != -1) return romantico[i][j];
    else {
        int &res = romantico[i][j];
        if (programacion[i].first < j){
            res = romanticoDesc(programacion, romantico, i + 1, j);
        }
        else {
            int nj = programacion[i].first + programacion[i].second;
            res = max(romanticoDesc(programacion,romantico, i + 1,j), romanticoDesc(programacion, romantico, i + 1, nj + 
            ((nj <= MIN_DIA) ? 10: 0)) + programacion[i].second);
        }
        return res;
    }
} */

/* 
//Solucion hacia delante de la solucion descendente
int romanticoDesc(vii const& prog, vector<vector<int>> & romantico, int i , int j){
    if (i >= prog.size()){
        return 0;
        
    }
    else if (romantico[i][j] != -1){
        return romantico[i][j];
    }
    else {
        int &res = romantico[i][j];
        if (j != 0 && prog[i].first < (prog[j - 1].first + prog[j - 1].second + 10)){
            res = romanticoDesc(prog, romantico, i + 1, j);
            return res;
        }
        else {
            res = max(romanticoDesc(prog, romantico, i + 1, j), romanticoDesc(prog, romantico, i + 1, i + 1) + prog[i].second);
        }
        return res;
    }
} */


int romanticoAsc(vii const& pelis){
    vector<int> romantico(MIN_DIA + 1, 0);
    for (auto p: pelis){
        for (int j = p.first + p.second + DES; j <= MIN_DIA; ++j){
            romantico[j] = max(romantico[j], romantico[p.first] + p.second);
        }
    }

    return romantico[MIN_DIA];
}

bool resuelveCaso(){
    int n;
    cin >> n;
    if (n == 0) return false;
    vector<pair<int, int>> pelis(n);
    int h, m;
    char p;
    int duracion;
    for (int i = 0; i < n; ++i){
        cin >> h >> p >> m;
        cin >> duracion;
        int inicio = (h*60) + m;

        pelis[i] = {inicio, duracion};
    }
    sort(pelis.begin(), pelis.end()); //vector ordenado por el primer elemento que es la hora de inicio.
    
    //vector<vector<int>> romantico(n, vector<int>(MIN_DIA + 1, -1));
    //int sol = romanticoDesc(program, romantico, 0, 0);
    //cout  << sol << '\n';


    //Metodo ascendente hacia delante
/*     vector<int> romantico(MIN_DIA + 1, 0);
    for (int i = n - 1; i >= 0; --i){
        for (int j = MIN_DIA; j >= 0; --j){
            if (program[i].first >= j){
                romantico[j] = max(romantico[j], romantico[program[i].first + program[i].second + 10] + program[i].second);
            }
        }
    }

    cout << romantico[0] << '\n'; */


/*     vector<int> romantico(n + 1, 0);

    for (int i = n - 1; i >= 0; --i){
        for (int j = n; j >= 0; --j){
            if (j == 0 || (program[i].first >= (program[j - 1].first + program[j - 1].second + 10))){
                romantico[j] = max(romantico[j], romantico[i] + program[i].second);
            }
        }
    }

    cout << romantico[0] << '\n'; */


    /* vector<vector<int>> romantico(n, vector<int>(n +  1, - 1));
    int sol  = romanticoDesc(program, romantico, 0, 0);

    cout << sol << '\n'; */

    int sol = romanticoAsc(pelis);

    cout << sol << '\n';




    return true;
}

int main(){
    while (resuelveCaso());
    return 0;
}