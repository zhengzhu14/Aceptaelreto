#include <iostream>

void resuelveCaso() {
	int year, week, day;
	std::cin >> year >> week >> day;
	int semanas = 0;
	if (day == 1) {
		semanas = year / week;
	}
	else {
		int out = week - day + 1;
		//La variable "out" seria los dias del año que se quedarian fuera de la division entera pues representan una semana incompleta.
		semanas = (year - out) / week;
	}
	std::cout << semanas << '\n';
}

int main() {
	//Tratar casos dependiendo del numero de casos.
	int numCasos;
	//Declarar la variable para el numero de casos.
	std::cin >> numCasos;
	//Lectura del numero de casos.
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	//Bucle con la cual la funcion resuelveCaso se ejecuta tantas veces como numero de casos haya.
	return 0;
}