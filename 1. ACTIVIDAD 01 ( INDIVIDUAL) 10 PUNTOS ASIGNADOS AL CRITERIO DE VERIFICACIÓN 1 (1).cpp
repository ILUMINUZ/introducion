#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Definición de las estructuras
struct LIBRO {
	string title;
	string author;
	string ISBN;
	int publicationYear;
};

struct USUARIO {
	int userID;
	string name;
	string lastname;
	string email;
};

struct BIBLIOTECARIO {
	int employeeID;
	string name;
	string lastname;
	string email;
};

// Listas fijas de nombres y apellidos de ejemplo
string nombres[] = {"Juan", "Ana", "Pedro", "María", "Carlos", "Laura", "David", "Elena", "Miguel", "Sofía"};
string apellidos[] = {"Gómez", "Fernández", "López", "Martínez", "Rodríguez", "Pérez", "García", "Díaz", "Sánchez", "Romero"};

// Función para generar datos aleatorios
string generateRandomString(const string array[], int length) {
	return array[rand() % length];
}

// Función para generar el ISBN de forma aleatoria
string generateRandomISBN() {
	return to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + "-" + to_string(rand() % 10) + "-" + to_string(rand() % 10);
}

// Función para combinar nombre y apellido en el email
string combineNameAndLastname(const string& name, const string& lastname) {
	return name + lastname + "@gmail.com";
}

int main() {
	// Semilla para la generación de números aleatorios
	srand(static_cast<unsigned int>(time(0)));
	
	// Arrays fijos de referencia
	string listaLibros[] = {"Como Agua Para Chocolate","Bulling","Trading en la Zona","Padre Rico, Padre Pobre"};
	int listaUserIDs[] = {1, 2, 3, 4, 5};
	int listaEmployeeIDs[] = {101,102,103,104,105};
	
	// Crear e inicializar estructuras
	LIBRO libros[3];
	USUARIO usuarios[3];
	BIBLIOTECARIO bibliotecarios[3];
	
	// Generar datos aleatorios y asignar a las estructuras
	for (int i = 0; i < 3; i++) {
		libros[i].title = listaLibros[rand() % 3];
		libros[i].author = generateRandomString(nombres, 10) + " " + generateRandomString(apellidos, 10);
		libros[i].ISBN = generateRandomISBN();
		libros[i].publicationYear = rand() % 50 + 1970;
		
		usuarios[i].userID = listaUserIDs[rand() % 5];
		usuarios[i].name = generateRandomString(nombres, 10);
		usuarios[i].lastname = generateRandomString(apellidos, 10);
		usuarios[i].email = combineNameAndLastname(usuarios[i].name, usuarios[i].lastname);
		
		bibliotecarios[i].employeeID = listaEmployeeIDs[rand() % 3];
		bibliotecarios[i].name = generateRandomString(nombres, 10);
		bibliotecarios[i].lastname = generateRandomString(apellidos, 10);
		bibliotecarios[i].email = combineNameAndLastname(bibliotecarios[i].name, bibliotecarios[i].lastname);
	}
	
	// Utilizando punteros para pasar los arrays de las estructuras
	LIBRO* libros_ptr = libros;
	USUARIO* usuarios_ptr = usuarios;
	BIBLIOTECARIO* bibliotecarios_ptr = bibliotecarios;
	
	// Imprimir los datos
	cout << "LIBROS:" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "Titulo: " << libros_ptr[i].title << ", Autor: " << libros_ptr[i].author << ", ISBN: " << libros_ptr[i].ISBN << ", Año de publicacion: " << libros_ptr[i].publicationYear << endl;
	}
	
	cout << "\nUSUARIOS:" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "ID: " << usuarios_ptr[i].userID << ", Nombre: " << usuarios_ptr[i].name << ", Apellido: " << usuarios_ptr[i].lastname << ", Email: " << usuarios_ptr[i].email << endl;
	}
	
	cout << "\nBIBLIOTECARIOS:" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "ID: " << bibliotecarios_ptr[i].employeeID << ", Nombre: " << bibliotecarios_ptr[i].name << ", Apellido: " << bibliotecarios_ptr[i].lastname << ", Email: " << bibliotecarios_ptr[i].email << endl;
	}
	
	return 0;
}

