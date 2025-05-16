#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//problema de la mochila entera. Pero con dos caras de cinta. 
//Para este problema tengo que elegir si ponerla en la cara 1 o en la cara 2.
//Para la estimacion el hueco lo calculo con el hueco restante de cada cara. 

enum tCara{C1, C2, Null};

struct Objeto {
    double duracion;
    double puntuacion;
    
};

struct Comparador{
    bool operator() (Objeto const & o1, Objeto const& o2){
        return (o1.puntuacion/o1.duracion) > (o2.puntuacion/o2.duracion);
    }
};

struct Nodo {
    //vector<tCara> sol; //Pongo la cara que la que lo he puesto
    int k;
    double d1, d2; //Veo cuanto se ha llenado de cada cara.
    double p;
    double estim;

    bool operator < (Nodo const& otro) const{
        return otro.estim > estim;
    }
};


double calculo_voraz(vector<Objeto> const& canciones, double M, Nodo const& X){
    //Supongo como que las dos caras estan juntas y utilizo el algoritmo voraz para la mochila
    double hueco = (M - X.d1) + (M - X.d2);
    double estimacion = X.p;
    int i = X.k + 1;

    while (i < canciones.size() && canciones[i].duracion <= hueco){
        hueco -= canciones[i].duracion;
        estimacion += canciones[i].puntuacion;
        ++i;
    }

    if (i < canciones.size()){
        estimacion += (hueco/canciones[i].duracion)*canciones[i].puntuacion;
    }

    return estimacion;
}


void cintas_rp(vector<Objeto> const& canciones, double M ,/*, vector<tCara> &sol_mejor,*/ double & punt_mayor){
    int n = canciones.size();

    //Nodo Y = {vector<tCara>(n), -1, 0, 0, 0, 0};
    Nodo Y = { -1, 0, 0, 0, 0};
    
    
    Y.estim = calculo_voraz(canciones, M, Y);

    priority_queue<Nodo> cola;

    cola.push(Y);
    

    while (!cola.empty() && cola.top().estim > punt_mayor){
        Y = cola.top(); cola.pop();
        Nodo X (Y);
        ++X.k;

        //Lo anyado a la primera cara
        if (Y.d1 + canciones[X.k].duracion <= M){
            //X.sol[X.k] = C1;
            X.d1 = Y.d1 + canciones[X.k].duracion;
            X.d2 = Y.d2;
            X.p = Y.p + canciones[X.k].puntuacion;
            X.estim = Y.estim;

            if (X.k == n - 1){
                //sol_mejor = X.sol; 
                punt_mayor = X.p;
            }else {
                cola.push(X);
            }

        }

        if (Y.d2 + canciones[X.k].duracion <= M){
            //X.sol[X.k] = C2;
            X.d1 = Y.d1;
            X.d2 = Y.d2 + canciones[X.k].duracion;
            X.p = Y.p + canciones[X.k].puntuacion;
            X.estim = Y.estim;

            if (X.k == n - 1){
                //sol_mejor = X.sol; 
                punt_mayor = X.p;
            }else {
                cola.push(X);
            }
        }

        //X.sol[X.k] = Null;
        X.d1 = Y.d1; X.d2 = Y.d2;
        X.p = Y.p;
        X.estim = calculo_voraz(canciones, M, X);
        if (X.estim > punt_mayor){
            if (X.k == n - 1){
                //sol_mejor = X.sol; 
                punt_mayor = X.p;
            }
            else {
                cola.push(X);
            }
        }

    }

    
}


bool resuelveCaso(){
    int n;
    cin >> n;
    if (n == 0) return false;
    int caras;
    cin >> caras; //duracion de cada cara  de la cinta

    double d, p;
    vector<Objeto> canciones (n);
    for (int i = 0; i < n; ++i){
        cin >> d >> p;
        canciones[i] = {d, p};
    }
    sort(canciones.begin(), canciones.end(), Comparador());
    
    //vector<tCara> sol_mejor(n, Null);
    double mejor = 0;
    //cintas_rp(canciones, caras, sol_mejor, mejor);
    cintas_rp(canciones, caras, mejor);

    cout << int(mejor) << '\n';

    return true;
}


int main(){
    while (resuelveCaso());

    return 0;
}