#include <iostream>
#include <cstdlib>
using namespace std;
string sala[6][5] = {"A1", "A2", "A3", "A4", "A5", "B1", "B2", "B3", "B4", "B5", "C1", "C2", "C3", "C4", "C5", "D1", "D2", "D3", "D4", "D5", "E1", "E2", "E3", "E4", "E5", "F1", "F2", "F3", "F4", "F5"}, copia[6][5] = {"A1", "A2", "A3", "A4", "A5", "B1", "B2", "B3", "B4", "B5", "C1", "C2", "C3", "C4", "C5", "D1", "D2", "D3", "D4", "D5", "E1", "E2", "E3", "E4", "E5", "F1", "F2", "F3", "F4", "F5"};
int boletos = 0, dinero = 0;

void compra      ();
void imprimicion ();
int main () {
	
	int opcion = 0;

	imprimicion ();
	
	do {
		if ((boletos*100)/30 > 25)
			system("color A0");
			
		if ((boletos*100)/30 > 50)
			system("color 90");
			
		if((boletos*100)/30 > 75)
			system("color E0");
			
		if ((boletos*100)/30 >= 100)
			system("color C0");

		system("cls");
		cout << " ---------------------------------------\n|\t\tMENU\t\t\t|\n|\t1. Comprar boletos\t\t|\n|\t2. Hacer corte de caja\t\t|\n|\t3. Salir\t\t\t|\n ---------------------------------------\n\nElige una opcion: ";
		cin >> opcion;

		
		if (boletos == 30)
			cout << "La sala esta llena!!";
			
		
		switch (opcion) {
			case 1: {
				if (boletos != 30)
					compra();
				else{
					system("cls");
					cout << "La sala esta llena!!\n";
					system("pause");
				}
				break;
			}
			case 2: {
				system("cls");
				cout << "-------------------CORTE DE CAJA-------------------\n\nTotal de boletos vendidos: " << boletos << "\n\nPorcentaje de ocupacion: " << (boletos*100)/30 << "%\n\nVenta total: $" << dinero << endl;
				if (boletos == 30)
					cout << "\n\nLa sala esta llena!!\n";
				system("pause");
				break;
			}
			case 3: {
				break;
			}
			default: {
				system("cls");
				cout << "Opcionion no valida\n\n";
				system("pause");
			}
		}
	} while(opcion != 3);		
	return 0;
}

void imprimicion() {
	
	system("cls");
	
	cout << "\t\t SALA VIP\n\n:::::::::::::PANTALLA::::::::::::::\n" << endl;
	for (int j = 0; j < 6; j++) {
		
		for (int i = 0; i < 5; i++) {
			cout << sala[j][i] << "\t";
		}
		
		cout << "\n" << endl;
	}
	system("pause");
	
	return;
}

void compra() {
	
	int cantidad = 0, precio = 0;
	char opcion = ' ';
	
	system("cls");
	
	cout << "////////////COMPRA DE BOLETOS////////////\n\n";
	
	do {
		
		cout << "Ingresa precio por boletos: ";
		cin >> precio;
		
	} while (precio <= 0);
	do{
		cantidad = 0;
		opcion = ' ';
	
		do {
			
			imprimicion();
			
			cout << "\tPrecio de los boletos: $" << precio << "\nBoletos a comprar(para salir precione 0): ";
			cin >> cantidad;
			if (boletos + cantidad > 30){
				
				system("color 4");
				system("cls");
				cout << "La cantidad de boletos que quieres comprar exede la capacidad de la sala\n";
				system("pause");
				
				if ((boletos*100)/30 > 25)
					system("color A0");				
				else if ((boletos*100)/30 > 50)
					system("color 90");				
				else if((boletos*100)/30 > 75)
					system("color E0");		
				else if ((boletos*100)/30 >= 100)
					system("color C0");
				else
					system("color 7");
				
			}
			else if (boletos == 0 && cantidad == 30) {
				do {
					cout << "Seguro que quieres comprar todos los asientos?(s/n): ";
					cin >> opcion;
					
					if (opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N')
						cout << "Opcion no valida\n";
				} while (opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N');
			}
				
		} while (boletos + cantidad > 30 || opcion == 'n' || opcion == 'N');
		
		if (cantidad <= 0)
			return;
	
		if (opcion == 's' || opcion == 'S'){
			for (int j = 0; j < 6; j++) {
			
				for (int i = 0; i < 5; i++) {
					sala[j][i] = "**";
				}
			}
			return;
		}
	
		string compra[cantidad];
		
		int existe = 0;
		
		for (int i = 0; i < cantidad; i++) {
			do {
				existe = 0;
	
				cout << "Elige asiento " << i+1 << ": ";
				cin >> compra[i];
	
				if (compra[i][0] >= 97 && compra[i][0] <= 102)
					compra[i][0] -= 32;
	
				for (int j = 0; j < 6; j++) {
					if (compra[i].length() > 2)
						break;
					for (int n = 0; n < 5; n++) {
						if (copia[j][n] == compra[i] && sala[j][n] != "**"){
							//sala[j][n] = "**";
							existe++;
							}
						else if(copia[j][n] == compra[i] && sala[j][n] == "**"){
							cout << "Este asiento ya esta ocupado\n";
							existe += 2;
						}
					}
				}
				if (existe == 0)
					cout << "\nEl asiento no existe\n";
	
			} while(existe == 0 || existe == 2);
			
		}
		
		cout << "Precio a pagar: $" << precio * cantidad << endl;
		
		do {
			cout << "Estas seguro de tu compra? (s/n) ";
			cin >> opcion;
			
			if (opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N')
				cout << "Opcion no valida\n";
				
		} while (opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N');
		
		if (opcion == 's' || opcion == 'S'){
			
			for (int i = 0; i < cantidad; i++){
				for (int j = 0; j < 6; j++) {
					for (int n = 0; n < 5; n++) {
						if (copia[j][n] == compra[i] && sala[j][n] != "**"){
							sala[j][n] = "**";
						}
					}
				}
			}
			
			dinero += precio * cantidad;
			boletos += cantidad;
		}
				
	}while(opcion == 'n' || opcion == 'N');
	
	system("pause");		

	return;
}
