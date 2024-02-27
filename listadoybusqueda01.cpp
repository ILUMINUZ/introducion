#include <iostream>
#include <algorithm>  // Necesario para transform
#include <ctime>      // Necesario para time
using namespace std;

// Definici�n de las estructuras
struct LIBRO {
	string titulo;
	string autor;
	string ISBN;
	int anioPublicacion;
	string genero;
	float precio;
	bool disponible;
};

struct USUARIO {
	int IDUsuario;
	string nombre;
	string apellido;
	string correo;
	int librosPrestados;
};

struct BIBLIOTECARIO {
	int IDEmpleado;
	string nombre;
	string apellido;
	string correo;
	string departamento;
};

// Listas fijas de nombres y apellidos de ejemplo
string nombres[] = {"Juan", "Ana", "Pedro", "Maria", "Carlos", "Laura", "David", "Elena", "Miguel", "Sofia"};
string apellidos[] = {"Gomez", "Fernandez", "Lopez", "Martinez", "Rodriguez", "Perez", "Garcia", "Diaz", "Sanchez", "Romero"};
string generos[] = {"Terror", "Drama", "Romance", "Comedia", "Melodrama"};
string departamentos[] = {"Recepcion", "Sistemas", "Transporte", "Seguridad", "Limpieza"};

// Funci�n auxiliar para convertir una cadena a min�sculas
string ConvertirAMinusculas(const string& str) {
	string resultado = str;
	transform(resultado.begin(), resultado.end(), resultado.begin(), ::tolower);
	return resultado;
}
// Funci�n para generar un n�mero aleatorio en un rango dado
int randomico(int max) {
	return rand() % max;
}

// Funci�n para generar un n�mero aleatorio en un rango dado
int randomicoRango(int min, int max) {
	return rand() % (max - min + 1) + min;
}

// Sobrecarga de la funci�n de llenado para usuarios
void llenado(USUARIO *p, int cant) {
	for (int i = 0; i < cant; i++) {
		p[i].IDUsuario = i + 1;
		p[i].nombre = nombres[randomicoRango(0, 9)];
		p[i].apellido = apellidos[randomicoRango(0, 9)];
		p[i].correo = p[i].nombre + "." + p[i].apellido + "@gmail.com";
		p[i].librosPrestados = randomico(5);
	}
}

// Sobrecarga de la funci�n de llenado para bibliotecarios
void llenado(BIBLIOTECARIO *p, int cant) {
	for (int i = 0; i < cant; i++) {
		p[i].IDEmpleado = i + 101;
		p[i].nombre = nombres[randomicoRango(0, 9)];
		p[i].apellido = apellidos[randomicoRango(0, 9)];
		p[i].correo = p[i].nombre + "." + p[i].apellido + "@library.com";
		p[i].departamento = departamentos[randomicoRango(0, 4)];
	}
}

// Sobrecarga de la funci�n de llenado para libros
void llenado(LIBRO *p, int cant) {
	string titulos[] = {"Bulling", "Bulling 2", "Bulling 3", "Bulling 4"};
	
	for (int i = 0; i < cant; i++) {
		p[i].titulo = titulos[i];
		p[i].autor = nombres[randomicoRango(0, 9)] + " " + apellidos[randomicoRango(0, 9)];
		p[i].ISBN = "ISBN-" + to_string(i + 1);
		p[i].anioPublicacion = 2000 + randomico(22);
		p[i].genero = generos[randomicoRango(0, 4)];
		p[i].precio = 10.0 + static_cast<float>(randomico(90));
		p[i].disponible = true;
	}
}

// Sobrecarga de la funci�n de impresi�n para usuarios
void Imprimir(const USUARIO& persona) {
	cout << "ID: " << persona.IDUsuario << " | ";
	cout << "Nombre: " << persona.nombre << " | ";
	cout << "Apellido: " << persona.apellido << " | ";
	cout << "Correo: " << persona.correo << " | ";
	cout << "Libros Prestados: " << persona.librosPrestados << endl;
}

// Sobrecarga de la funci�n de impresi�n para bibliotecarios
void Imprimir(const BIBLIOTECARIO& persona) {
	cout << "ID: " << persona.IDEmpleado << " | ";
	cout << "Nombre: " << persona.nombre << " | ";
	cout << "Apellido: " << persona.apellido << " | ";
	cout << "Correo: " << persona.correo << " | ";
	cout << "Departamento: " << persona.departamento << endl;
}

// Sobrecarga de la funci�n de impresi�n para libros
void Imprimir(const LIBRO& libro) {
	cout << "T�tulo: " << libro.titulo << " | ";
	cout << "Autor: " << libro.autor << " | ";
	cout << "ISBN: " << libro.ISBN << " | ";
	cout << "A�o de publicaci�n: " << libro.anioPublicacion << " | ";
	cout << "G�nero: " << libro.genero << " | ";
	cout << "Precio: $" << libro.precio << " | ";
	cout << "Disponible: " << (libro.disponible ? "S�" : "No") << endl;
}

// Funci�n para imprimir lista completa de usuarios
void ImprimirListaCompleta(const USUARIO *arrUsuarios, int cant) {
	for (int i = 0; i < cant; i++) {
		Imprimir(arrUsuarios[i]);
	}
}

// Funci�n para imprimir lista completa de bibliotecarios
void ImprimirListaCompleta(const BIBLIOTECARIO *arrBibliotecarios, int cant) {
	for (int i = 0; i < cant; i++) {
		Imprimir(arrBibliotecarios[i]);
	}
}

// Funci�n para imprimir lista completa de libros
void ImprimirListaCompleta(const LIBRO *arrLibros, int cant) {
	for (int i = 0; i < cant; i++) {
		Imprimir(arrLibros[i]);
	}
}

// Funci�n recursiva para buscar libros por t�tulo
// Funci�n recursiva para buscar libros por t�tulo
bool BuscarLibroRecursivo(LIBRO *arrLibros, int cant, string tituloBuscado, int index = 0) {
	if (index >= cant) {
		return false;
	}
	
	// Convertir ambas cadenas a min�sculas antes de comparar
	string tituloLibro = ConvertirAMinusculas(arrLibros[index].titulo);
	string tituloBuscadoMinusculas = ConvertirAMinusculas(tituloBuscado);
	
	size_t encontrado = tituloLibro.find(tituloBuscadoMinusculas);
	if (encontrado != string::npos) {
		Imprimir(arrLibros[index]);
	}
	
	// Continuar la b�squeda en la lista y retornar el resultado
	return BuscarLibroRecursivo(arrLibros, cant, tituloBuscado, index + 1) || (encontrado != string::npos);
}

// Funci�n para buscar usuarios por nombre o apellido
bool BuscarUsuarioPorCadena(USUARIO *arrUsuarios, int cant, string cadenaBuscada) {
	bool encontrado = false;
	
	for (int i = 0; i < cant; i++) {
		// Convertir ambas cadenas a min�sculas antes de comparar
		string nombreUsuario = ConvertirAMinusculas(arrUsuarios[i].nombre);
		string apellidoUsuario = ConvertirAMinusculas(arrUsuarios[i].apellido);
		string cadenaBuscadaMinusculas = ConvertirAMinusculas(cadenaBuscada);
		
		size_t encontradoNombre = nombreUsuario.find(cadenaBuscadaMinusculas);
		size_t encontradoApellido = apellidoUsuario.find(cadenaBuscadaMinusculas);
		
		if (encontradoNombre != string::npos || encontradoApellido != string::npos) {
			Imprimir(arrUsuarios[i]);
			encontrado = true;
		}
	}
	
	return encontrado;
}

// Funci�n para buscar bibliotecarios por nombre o apellido
bool BuscarBibliotecarioPorCadena(BIBLIOTECARIO *arrBibliotecarios, int cant, string cadenaBuscada) {
	bool encontrado = false;
	
	for (int i = 0; i < cant; i++) {
		// Convertir ambas cadenas a min�sculas antes de comparar
		string nombreBibliotecario = ConvertirAMinusculas(arrBibliotecarios[i].nombre);
		string apellidoBibliotecario = ConvertirAMinusculas(arrBibliotecarios[i].apellido);
		string cadenaBuscadaMinusculas = ConvertirAMinusculas(cadenaBuscada);
		
		size_t encontradoNombre = nombreBibliotecario.find(cadenaBuscadaMinusculas);
		size_t encontradoApellido = apellidoBibliotecario.find(cadenaBuscadaMinusculas);
		
		if (encontradoNombre != string::npos || encontradoApellido != string::npos) {
			Imprimir(arrBibliotecarios[i]);
			encontrado = true;
		}
	}
	
	return encontrado;
}

// Funci�n para limpiar la pantalla seg�n el sistema operativo
void LimpiarPantalla() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

// Funci�n para mostrar el men� principal
void MostrarMenu() {
	cout << "MENU:" << endl;
	cout << "1) Llenado de Datos" << endl;
	cout << "2) Listados" << endl;
	cout << "3) B�squedas" << endl;
	cout << "0) Salir" << endl;
	cout << "Ingrese su elecci�n: ";
}

// Funci�n para mostrar el submen� de b�squeda de libros por t�tulo
void MostrarSubMenuBusquedaLibro(LIBRO *arrLibros, int cant) {
	LimpiarPantalla();
	string titulo;
	cout << "B�squeda de Libro por T�tulo:" << endl;
	cout << "Ingrese el t�tulo del libro: ";
	cin.ignore();
	getline(cin, titulo);
	
	// Realizar b�squeda por t�tulo
	bool encontrado = BuscarLibroRecursivo(arrLibros, cant, titulo);
	
	if (!encontrado) {
		cout << "Libro no encontrado." << endl;
	}
}

// Funci�n para mostrar el submen� de b�squeda de usuarios por cadena
void MostrarSubMenuBusquedaUsuarioPorCadena(USUARIO *arrUsuarios, int cant) {
	LimpiarPantalla();
	string cadena;
	cout << "B�squeda de Usuario por Nombre o Apellido:" << endl;
	cout << "Ingrese nombre o apellido a buscar: ";
	cin.ignore();
	getline(cin, cadena);
	
	// Realizar b�squeda por cadena en nombre o apellido
	bool encontrado = BuscarUsuarioPorCadena(arrUsuarios, cant, cadena);
	
	if (!encontrado) {
		cout << "Usuario no encontrado." << endl;
	}
}

// Funci�n para mostrar el submen� de b�squeda de bibliotecarios por cadena
void MostrarSubMenuBusquedaBibliotecarioPorCadena(BIBLIOTECARIO *arrBibliotecarios, int cant) {
	LimpiarPantalla();
	string cadena;
	cout << "B�squeda de Bibliotecario por Nombre o Apellido:" << endl;
	cout << "Ingrese el nombre o apellido a buscar: ";
	cin.ignore();
	getline(cin, cadena);
	
	// Realizar b�squeda por cadena en nombre o apellido
	bool encontrado = BuscarBibliotecarioPorCadena(arrBibliotecarios, cant, cadena);
	
	if (!encontrado) {
		cout << "Bibliotecario no encontrado." << endl;
	}
}

int main() {
	// Agregar esta l�nea para inicializar la semilla de manera diferente cada vez
	srand(static_cast<unsigned int>(time(nullptr)));
	
	const int TAM_USUARIOS = 4;
	const int TAM_BIBLIOTECARIOS = 3;
	const int TAM_LIBROS = 4;
	
	USUARIO arrUsuarios[TAM_USUARIOS];
	BIBLIOTECARIO arrBibliotecarios[TAM_BIBLIOTECARIOS];
	LIBRO arrLibros[TAM_LIBROS];
	
	int opcion;
	char subopcion;
	
	do {
		LimpiarPantalla();
		MostrarMenu();
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			llenado(arrUsuarios, TAM_USUARIOS);
			llenado(arrBibliotecarios, TAM_BIBLIOTECARIOS);
			llenado(arrLibros, TAM_LIBROS);
			cout << "Datos llenados exitosamente." << endl;
			break;
			
		case 2:
			do {
				LimpiarPantalla();
				cout << "Submen� Listados:" << endl;
				cout << "A) Listados de Libros" << endl;
				cout << "B) Listado Usuarios" << endl;
				cout << "C) Listados Bibliotecarios" << endl;
				cout << "X) Salir al Men� Principal" << endl;
				cout << "Ingrese su elecci�n: ";
				cin >> subopcion;
				
				switch (subopcion) {
				case 'A':
					LimpiarPantalla();
					cout << "Listado de Libros:" << endl;
					ImprimirListaCompleta(arrLibros, TAM_LIBROS);
					break;
					
				case 'B':
					LimpiarPantalla();
					cout << "Listado de Usuarios:" << endl;
					ImprimirListaCompleta(arrUsuarios, TAM_USUARIOS);
					break;
					
				case 'C':
					LimpiarPantalla();
					cout << "Listado de Bibliotecarios:" << endl;
					ImprimirListaCompleta(arrBibliotecarios, TAM_BIBLIOTECARIOS);
					break;
					
				case 'X':
					cout << "Volviendo al Men� Principal." << endl;
					break;
					
				default:
					cout << "Opci�n no v�lida. Intente de nuevo." << endl;
				}
				
				// Esperar a que el usuario presione Enter para continuar
				cout << "Presione Enter para continuar...";
				cin.ignore(); // Limpiar el buffer del teclado
				cin.get();    // Esperar a que se presione Enter
				
			} while (subopcion != 'X');
			
			break;
			
		case 3:
			do {
				LimpiarPantalla();
				cout << "Submen� B�squedas:" << endl;
				cout << "A) B�squeda de Libro" << endl;
				cout << "B) B�squeda de Usuario" << endl;
				cout << "C) B�squeda de Bibliotecario" << endl;
				cout << "X) Salir al Men� Principal" << endl;
				cout << "Ingrese su elecci�n: ";
				cin >> subopcion;
				
				switch (subopcion) {
				case 'A':
					MostrarSubMenuBusquedaLibro(arrLibros, TAM_LIBROS);
					break;
					
				case 'B':
					MostrarSubMenuBusquedaUsuarioPorCadena(arrUsuarios, TAM_USUARIOS);
					break;
					
				case 'C':
					MostrarSubMenuBusquedaBibliotecarioPorCadena(arrBibliotecarios, TAM_BIBLIOTECARIOS);
					break;
					
				case 'X':
					cout << "Volviendo al Men� Principal." << endl;
					break;
					
				default:
					cout << "Opci�n no v�lida. Intente de nuevo." << endl;
				}
				
				// Esperar a que el usuario presione Enter para continuar
				cout << "Presione Enter para continuar...";
				cin.ignore(); // Limpiar el buffer del teclado
				cin.get();    // Esperar a que se presione Enter
				
			} while (subopcion != 'X');
			
			break;
			
		case 0:
			cout << "Saliendo del programa. �Hasta luego!" << endl;
			break;
			
		default:
			cout << "Opci�n no v�lida. Intente de nuevo." << endl;
		}
		
		// Esperar a que el usuario presione Enter para continuar
		cout << "Presione Enter para continuar...";
		cin.ignore(); // Limpiar el buffer del teclado
		cin.get();    // Esperar a que se presione Enter
		
	} while (opcion != 0);
	
	return 0;
}
