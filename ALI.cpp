#include <iostream>

int main() {
	
	double num1, num2, num3;
	
	std::cout << "Ingrese el primer n�mero: ";
	std::cin >> num1;
	
	std::cout << "Ingrese el segundo n�mero: ";
	std::cin >> num2;
	
	std::cout << "Ingrese el tercer n�mero: ";
	std::cin >> num3;
	
	
	double mayor = num1;
	
	if (num2 > mayor) {
		mayor = num2;
	}
	
	if (num3 > mayor) {
		mayor = num3;
	}
	
	
	std::cout << "El n�mero mayor es: " << mayor << std::endl;
	
	return 0;
}
