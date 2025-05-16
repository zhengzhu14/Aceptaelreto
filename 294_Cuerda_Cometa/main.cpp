#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using lli = long long int;
using vi = vector<int>;
using vlli = vector<lli>;
using imatriz = vector<vi>;
using llimatriz = vector<vlli>;

const lli INF = 1000000000000000001;

/*
1. Para saber si es posible formar una cuerda con longitud l. 

        esPosible(i, j) = es posible llegar a j con las cuerdas de 1 a i

    Se inicializa a esPosible(n, l)
    Voy a utilizar la estrategia top-down

    Recursion: 

        esPosible(i, j) = { esPosible (i - 1, j)                                     si L(i) > j
                            esPosible (i - 1, j - L(i)) OR esPosible (i - 1, j)      si L(i) <= j
                           }
        
    Casos Base: 
        esPosible(i , 0) = True    si 0 <= i <= n 
        esPosible(0, j) = False    si j > 0


2. Saber cuántas formas diferentes hay de hacerlo

        formasPosibles(i, j) = numero de formas posibles de llegar a j con las cuerdas del 1 al i
    
    Inicializacion: formasPosibles(n, l)
    Estrategia top-down


    Recursion:

        formasPosibles(i, j) {  formasPosibles(i - 1, j)        si L(i) > j
                                formasPosibles(i - 1, j) + formasPosibles(i - 1, j - L(i))  si L(i) <= j
                                }
    Casos Base: 
        formasPosibles(i, 0) = 1
        formasPosibles(0, j) = 0 si j > 0

3. Saber el numero minimo de cuerdas necesarias
4. Saber el coste minimo de las cuerdas posibles

                         
*/

bool esPosible (vi const & medidas, imatriz & mat, int i, int j){
    if (j == 0){
        return true;
    }
    else if (i == 0){ //Aqui j != 0 pero i ya es 0
        return false;
    }
    else if (mat[i][j] != -1) return mat[i][j];
    else {
        mat[i][j] = esPosible(medidas, mat, i - 1, j);
        if (!mat[i][j] && medidas[i - 1] <= j){
            mat[i][j] = esPosible(medidas, mat, i - 1, j - medidas[i - 1]);
        }
        return mat[i][j];
    }
}

lli formasPosibles(vi const & medidas, llimatriz & mat, int i, int j){
    if (j == 0) return 1;
    else if (i == 0) return 0;
    else if (mat[i][j] != -1) return mat[i][j];
    else {
        mat[i][j] = formasPosibles(medidas, mat, i - 1, j);
        if (medidas[i - 1] <= j){
            mat[i][j] += formasPosibles(medidas, mat, i - 1, j - medidas[i - 1]);
        }
        return mat[i][j];
    }

}


lli cuerdasMinimas(vi const & medidas, llimatriz & mat, int i, int j){
    if (j == 0) return 0;
    else if (i == 0) return INF;
    else if (mat[i][j] != -1) return mat[i][j];
    else {
        mat[i][j] = cuerdasMinimas(medidas, mat, i - 1, j);
        if (medidas[i - 1] <= j){
            mat[i][j] = min(mat[i][j], cuerdasMinimas(medidas, mat, i - 1, j - medidas[i - 1]) + 1) ;
        }
        return mat[i][j];
    }

}

lli costeMinimos(vi const & medidas, vi const & costes, llimatriz & mat, int i, int j){
    if (j == 0) return 0;
    else if (i == 0) return INF;
    else if (mat[i][j] != -1) return mat[i][j];
    else {
        mat[i][j] = costeMinimos(medidas, costes, mat, i - 1, j);
        if (medidas[i - 1] <= j){
            mat[i][j] = min(mat[i][j], costeMinimos(medidas, costes,  mat, i - 1, j - medidas[i - 1]) + costes[i - 1]) ;
        }
        return mat[i][j];
    }

}

bool siesPosible(int n, int l, vi const & medidas){
    imatriz posibilidad(n + 1, vi(l + 1, -1)); //Inicializo la matriz a -1. 0 es false y 1 es true

    return esPosible(medidas, posibilidad, n, l);
}

void calcularFormasPosibles(int n, int l, vi const & medidas){
    llimatriz formPosibles(n + 1, vlli(l + 1, -1));
    cout << formasPosibles(medidas, formPosibles, n, l) << ' ';
}

void calcularCuerdasMinimas(int n, int l, vi const & medidas){
    llimatriz cuerdMinimas(n + 1, vlli(l + 1, -1));

    cout << cuerdasMinimas(medidas, cuerdMinimas, n, l) << ' ';
}

void calcularCosteMinimo(int n, int l, vi const & medidas, vi const & costes){
    llimatriz costMinimos(n + 1, vlli(l + 1, -1));

    cout << costeMinimos(medidas, costes, costMinimos, n, l);
}

void resolver(int n, int l){
    //Para empezar voy a demostrar que es posible formar una cuerda de cometa con longitud l
    vi medidas(n);
    vi costes(n);
    for (int i = 0; i < n; ++i){
        cin >> medidas[i] >> costes[i];
    }

    bool posible = siesPosible(n, l, medidas);
    if (posible){
        cout << "SI ";
        //A partir de aqui calculo la cantidad de formas hay de hacerlo
        
        calcularFormasPosibles(n, l, medidas);
        calcularCuerdasMinimas(n, l, medidas);
        calcularCosteMinimo(n, l, medidas, costes);

    }
    else {
        cout << "NO";
    }
    cout << '\n';

}

void resolverEficiente(int n, int l){
    vi medidas(n);
    vi costes(n);
    for (int i = 0; i < n; ++i){
        cin >> medidas[i] >> costes[i];
    }

    vector<lli> formas(l + 1, 0);
    vector<lli> cuerdasMinimas(l + 1, INF);
    vector<lli> costeMinimos(l + 1, INF);

    formas[0] = 1;
    cuerdasMinimas[0] = 0;
    costeMinimos[0] = 0;


    for (int i = 1; i <= n; ++i){
        for (int j = l; j >= 0; --j){
            if (j - medidas[i - 1] >= 0){
                formas[j] += formas[j - medidas[i - 1]];
                cuerdasMinimas[j] = min(cuerdasMinimas[j], cuerdasMinimas[j - medidas[i - 1]] + 1);
                costeMinimos[j] = min(costeMinimos[j], costeMinimos[j - medidas[i - 1]] + costes[i - 1]);
            } 
        }
    }

    if (formas[l] == 0) cout << "NO\n";
    else {
        cout << "SI " << formas[l] << ' ' << cuerdasMinimas[l] << ' ' << costeMinimos[l] << '\n';
    }

}

bool resuelveCaso(){ 
    int n, l;
    cin >> n>> l;
    if (!cin) return false;

    //resolver(n, l);
    //cout << INF << '\n';

    resolverEficiente(n, l);

    return true;
}

int main (){

   /*  #ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf());
    #endif */
    while (resuelveCaso());


   /*  #ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    system("PAUSE");
    #endif */
    return 0;
}