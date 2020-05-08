#include <cstdlib>
#include <iostream>

using namespace std;

int MCD (int a, int b){
    if (a%b == 0){
        return b;
    } else {
        return MCD (b, a%b);
    }
}

int main (){
	while (true){
		int opcion;
		cout << "1. La funcion de Euler " << endl;
		cout << "2. Triangulo de Pascal " << endl;
		cout << "3. Arreglo " << endl;
		cout << "Ingrese opcion o pulse [0] para salir: "; cin >> opcion; cout << endl;
		
		switch (opcion){
			case 1: {
				int n, fi;
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
