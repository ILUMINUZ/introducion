#include <iostream>
#include <ctime>
using namespace std;

const int TAMJ = 3;
const int MNOMBRE = 5;

struct vjuego {
	string nombre;
	int ranking;
	bool tipo;
	string desarrollador;
	string des;
};

struct persona {
	string nombre;
	int id_persona;
	vjuego juegos[TAMJ];
};

string nombres_personas[] = {"Juan Perez", "Maria Flor", "Pedro Pascal", "Sebastian Yatra", "Febet Hurtado"};
string nombres_juegos[] = {"WoW", "Mobile Legends", "Dota", "COD", "Free Fire"};
string desarrolladores[] = {"Sega", "Nintendo", "Activision", "F24", "A23"};

int randomico(int max);
bool repetido(string n, persona *p, int cant);
bool repetido(string n, vjuego *j, int cant);
void llenar(persona *p, vjuego *j, int cant_personas, int cant_juegos);
void llenar(vjuego *j, int cant);
void imprimir(persona *p, int cant);
void imprimir(vjuego *j, int cant);
void valoracion(persona *p, int cant_personas);
void menu(persona *p, vjuego *j, int cant_personas, int cant_juegos);

int main(int argc, char *argv[]) {
	const int TAMP = 5;
	persona personas[TAMP];
	vjuego juegos[TAMJ];
	menu(personas, juegos, TAMP, TAMJ);
	
	return 0;
}

int randomico(int max) {
	srand(static_cast<unsigned int>(time(0)));
	return rand() % max;
}

bool repetido(string n, persona *p, int cant) {
	for (int i = 0; i < cant; i++) {
		if (n.compare(p[i].nombre) == 0)
			return true;
	}
	return false;
}

bool repetido(string n, vjuego *j, int cant) {
	for (int i = 0; i < cant; i++) {
		if (n.compare(j[i].nombre) == 0)
			return true;
	}
	return false;
}

void llenar(persona *p, vjuego *j, int cant_personas, int cant_juegos) {
	string n;
	for (int i = 0; i < cant_personas; i++) {
		n = nombres_personas[randomico(MNOMBRE)];
		if (!repetido(n, p, i)) {
			p[i].nombre = n;
			cout << "AGREGO PERSONA: " << n << endl;
			
			// Llenar juegos para la persona actual
			llenar(p[i].juegos, cant_juegos);
		} else {
			i--;
		}
	}
}

void llenar(vjuego *j, int cant) {
	string n;
	for (int i = 0; i < cant; i++) {
		n = nombres_juegos[randomico(MNOMBRE)];
		if (!repetido(n, j, i)) {
			j[i].nombre = n;
			j[i].ranking = randomico(10) + 1;
			j[i].tipo = randomico(2);
			j[i].desarrollador = desarrolladores[randomico(6)];  // Agrega el desarrollador
			j[i].des = "Descripción del juego " + to_string(i + 1);
			cout << "AGREGO JUEGO: " << n << " - Ranking: " << j[i].ranking << " - Tipo: " << (j[i].tipo ? "Online" : "Offline")
				<< " - Desarrollador: " << j[i].desarrollador << endl;
		} else {
			i--;
		}
	}
}

void imprimir(persona *p, int cant) {
	cout << "IMPRIMIENDO PERSONAS Y VIDEOJUEGOS:" << endl;
	for (int i = 0; i < cant; i++) {
		cout << "Nombre de la persona: " << p[i].nombre << endl;
		for (int j = 0; j < TAMJ; j++) {
			cout << "  - Juego: " << p[i].juegos[j].nombre << " - Tipo: " << (p[i].juegos[j].tipo ? "Online" : "Offline")
				<< " - Desarrollador: " << p[i].juegos[j].desarrollador << endl;
		}
		cout << "---------------------" << endl;
	}
}

void imprimir(vjuego *j, int cant) {
	cout << "IMPRIMIENDO JUEGOS:" << endl;
	for (int i = 0; i < cant; i++) {
		cout << "Nombre del juego: " << j[i].nombre << " - Tipo: " << (j[i].tipo ? "Online" : "Offline")
			<< " - Desarrollador: " << j[i].desarrollador << endl;
	}
}

void valoracion(persona *p, int cant_personas) {
	cout << "RANKING DE JUEGOS POR PERSONA:" << endl;
	for (int i = 0; i < cant_personas; i++) {
		cout << "Nombre de la persona: " << p[i].nombre << endl;
		for (int j = 0; j < TAMJ; j++) {
			cout << "Juego: " << p[i].juegos[j].nombre << " - Ranking: " << p[i].juegos[j].ranking << endl;
		}
		cout << "---------------------" << endl;
	}
}

void menu(persona *p, vjuego *j, int cant_personas, int cant_juegos) {
	int opcion;
	do {
		cout << "MENU:" << endl;
		cout << "1) Llenado de personas y videojuegos" << endl;
		cout << "2) Impresion personas y videojuegos" << endl;  // Modificado
		cout << "3) Ranking de juego por persona" << endl;
		cout << "0) Salir" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			llenar(p, j, cant_personas, cant_juegos);
			break;
		case 2:
			imprimir(p, cant_personas);
			break;
		case 3:
			valoracion(p, cant_personas);
			break;
		case 0:
			cout << "Saliendo del programa." << endl;
			break;
		default:
			cout << "Opcion no valida. Intente de nuevo." << endl;
		}
		
	} while (opcion != 0);
}
