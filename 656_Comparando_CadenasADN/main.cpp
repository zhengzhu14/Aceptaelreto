#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <cmath>

using namespace std;



const int MAXN = 26;
//const char adn [] = {'A', 'C', 'G', 'T', 'Z'};
const char adn [] = {'A', 'C', 'G', 'T', '-'};

class Trie {
    int prefixes;
    int words;
    std::unordered_map<char, Trie *> child;

    public:
    Trie():prefixes(0),words(0),child() {}
    ~Trie() {
        for (auto it: child){
            delete it.second;
        }
    }
    void add(const char *s) {
        if (*s == '\0' ) ++words;
        else {
            Trie* t;
            if (child.count(*s) == 0){
                t = child[*s] = new Trie();
                t->prefixes = 1;
            }
            else {
                t = child[*s];
                t-> prefixes++;
            }
            t->add(s+1);
        }
        
    }
    int search (int restante, const char *s){
        if (restante < 0) return prefixes; //Si ya es el ultimo caracter, pues retorno todo.
        int total = 0;
        if (*s != '-'){
            if(child.count(*s) != 0) total += child[*s]->search(restante - 1, s + 1);
            if (child.count('-') != 0) total += child['-']->search(restante - 1, s + 1);
        }
        else { //El caracter encontrado es un '-'
            //Miro todos los hijos (que incluye tambien al '-')
            /* for (auto it: child){
                total+= it.second->search(restante - 1, s + 1);
            } */
           for (char c: adn){
            if (child.count(c) != 0){
                total+=child[c]->search(restante - 1, s + 1);
            }
           }
        }
        return total;
    }
    void addPrefixes(){
        this->prefixes++;
    }

};


/* class Trie {
    int prefixes;
    int words;
    std::vector<Trie *> child;

    public:
    Trie():prefixes(0),words(0),child(MAXN, nullptr) {}
    ~Trie() {
        for (int i = 0; i < MAXN; ++i)
            delete child[i];
    }
    void add(const char *s) {
        if (*s == '\0' ) ++words;
        else {
            Trie* t;
            char aux = *s;
            if (*s == '-') aux = 'Z';
            if (child[aux - 'A'] == nullptr){
                t = child[aux - 'A'] = new Trie();
                t->prefixes = 1;
            }
            else {
                t = child[aux - 'A'];
                t-> prefixes++;
            }
            t->add(s+1);
        }
        
    }
    int search (int restante, const char *s){
        if (restante < 0) return prefixes; //Si ya es el ultimo caracter, pues retorno todo.
        int total = 0;
        if (*s != '-'){
            if(child[*s - 'A'] != nullptr) total += child[*s - 'A']->search(restante - 1, s + 1);
            if (child['Z' - 'A'] != nullptr) total += child['Z' - 'A']->search(restante - 1, s + 1);
        }
        else { //El caracter encontrado es un '-'
            //Miro todos los hijos (que incluye tambien al '-')
            for (char c: adn){
                if (child[c - 'A'] != nullptr)
                    total += child[c - 'A']->search(restante - 1, s + 1);
            }
        }
        return total;
    }
    void addPrefixes(){
        this->prefixes++;
    }

}; */

/*Para buscar lo que hago es: 
    - Si es un caracter miro el caracter y luego, si hay, tambien en el '-'.
    - Si es '-' bajo por todos los hijos (incluido el guion).
    - Si llego al caracter a partir del cual son todos guiones simplemente retorno prefixes */

int n;
vector<string> lista;
vector<int> fin;
Trie *arbol;

void buscarFinal (string const& cfinal){
    int i = cfinal.size() - 1;
    while (i >= 0 && cfinal[i] == '-') --i;
    fin.push_back(i); //i es donde debería acabar la busqueda 
    //return i;
}

string optimizacion(string const& cadena){
    string cfinal = "";
    int mitad = cadena.size()/2;
    cfinal.push_back(cadena[mitad]);
    int iz = mitad - 1, der = mitad + 1;
    while (iz >= 0 && der < cadena.size()){
        cfinal.push_back(cadena[iz]);
        cfinal.push_back(cadena[der]);
        --iz;++der;
    }
    while (iz >= 0){
        cfinal.push_back(cadena[iz]); --iz;
    }
    while (der < cadena.size()){
        cfinal.push_back(cadena[der]); ++der;
    }
    return cfinal;
}
bool resuelveCaso(){
    cin >> n;
    if (!cin) return false;
    arbol = new Trie();
    fin.assign(0,{});
    lista.assign(0, {});
    string cadena;
    for (int i = 0; i < n; ++i){
        cin >> cadena;
        string cfinal = optimizacion(cadena);
        lista.push_back(cfinal);
        buscarFinal(cfinal);
        arbol->add(cfinal.c_str()); 
        arbol->addPrefixes();
    }
    
    //int acaba = buscarFinal(lista[0]);
    int sol = arbol->search(fin[0], lista[0].c_str());
    cout << sol -1;
    for (int i = 1; i < n; ++i){
        //acaba = buscarFinal(lista[i]);
        sol = arbol->search(fin[i], lista[i].c_str());
        cout << ' ' << sol - 1;
    }
    cout << '\n';

    delete arbol;
    return true;
}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    /* #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif  */
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     /* #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif */
    
    return 0;
}