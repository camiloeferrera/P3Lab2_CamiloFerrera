#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

int MCD (int a, int b){
    if (a%b == 0){
        return b;
    } else {
        return MCD (b, a%b);
    }
}

bool Ganador (int x [], int size){
	int cont = 0;
	for (int i = 0; i < size ; i ++){
		if (x[i] == 100){
			cont ++;
		}
	}
	
	if (cont == size){
		return true;
	} else {
		return false;
	}
}

int main (){
	srand (time(NULL));
	while (true){
		int opcion;
		cout << "1. La funcion de Euler " << endl;
		cout << "2. Triangulo de Pascal " << endl;
		cout << "3. Arreglo " << endl;
		cout << "Ingrese opcion o pulse [0] para salir: "; cin >> opcion; cout << endl;
		
		switch (opcion){
			case 1: {
				int n, fi = 0;
				cout << "Ingrese n: "; cin >> n; cout << endl;
				
				for (int i = 1; i <= n ; i++){
					if (MCD(i,n) == 1){
						fi++;
					}
				}
				
				cout << "Fi de n es: " << fi << endl;
				break;
			}
			case 2: {
				int n;
				cout << "Ingrese n filas: "; cin >> n; cout << endl;
				int matriz [n][n];
				for (int i = 0; i < n; i++){
					
					for (int j = 0; j <= i; j++){
						if (i == 0){							
							cout << 1;
							matriz [i][j] = 1;
						} else {
							if (j == 0){
								cout << 1 << ", ";
								matriz[i][j] = 1;
							} else if (j == i){
								cout << 1;
								matriz [i][j] = 1;
							} else {
								int x = matriz[i-1][j] + matriz[i-1][j-1];
								cout << x << ", ";
								matriz[i][j] = x;
							}
						}
					}
					
					cout << endl;
				}
				break;
			}
			case 3: {
				int n;
				cout << "Ingrese un numero par: "; cin >> n;
				
				while (n%2 != 0){
					cout << endl << "El numero no es par!" << endl << endl << "Ingrese un numero par: "; cin >> n;
				}
				cout << endl;
				
				int arreglo [n] = {};
				int arreglooriginal [n] = {};
				
				for (int i = 0; i < n; i++){
					arreglo[i] = (-50) + rand() % (51-(-50));
					arreglooriginal[i] = arreglo[i];
				}
				cout << "A JUGAR!" << endl << endl;
				
				int j1, j2, puntajej1 = 0, puntajej2 = 0;
				
				bool ganador = Ganador (arreglo,n);
				while (ganador == false){
					cout << "J1 escoge: "; cin >> j1;
					while (arreglo[j1] == 100){
						cout << endl << "Este numero ya fue usado"<<endl << endl << "J1 escoge: "; cin >> j1;;
					}					
					cout << "Obtuvo: " << arreglo[j1] << endl;
					puntajej1 += arreglo[j1];
					arreglo [j1] = 100;
					cout << "J2 escoge: "; cin >> j2;
					while (arreglo[j2] == 100){
						cout << endl << "Este numero ya fue usado"<<endl << endl << "J2 escoge: "; cin >> j2;;
					}
					cout << "Obtuvo: " << arreglo[j2] << endl;
					puntajej2 += arreglo[j2];
					arreglo [j2] = 100;
					
					cout << endl;
					
					ganador = Ganador (arreglo,n);					
				}
				
				cout << "FINAL - [PTS J1: " << puntajej1 << " <->  PTS J2: " << puntajej2 << "]" << endl << endl; 
				
				if (puntajej1 > puntajej2){
					cout << "GANA J1"<< endl << endl;
				} else if (puntajej2 > puntajej1){
					cout << "GANA J2" << endl << endl;
				}
				
				cout << "Arreglo usado: ";
				for (int i = 0; i < n; i++){
					cout << "[" << arreglooriginal[i] << "] ";
				}
				cout << endl;
				break;
			}
			
			case 0: {
				return 0;
				break;
			}
			default: {
				cout << "Opcion Incorrecta" << endl;
				break;
			}
		}
		cout << endl;
	}
}
