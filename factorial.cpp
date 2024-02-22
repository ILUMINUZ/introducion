#include <iostream>
using namespace std;
int factorialNormal (int n) {
	int fact = 1;
	for (int i = 1; i <= n; i++)
		fact = i * fact;
	return fact;
}
int factorial (int n){
	if(n==0)
		return 1;
	else
		return factorial(n-1)*n;
}

int main(int argc, char *argv[]) {
	const int NUM1=5;
	const int NUM2=6;
	const int NUM3=7;
	cout<<"Factorial:"<<NUM1<<"="<<factorial(NUM1)<<endl;
	cout<<"Factorial:"<<NUM2<<"="<<factorial(NUM2)<<endl;
	cout<<"Factorial:"<<NUM3<<"="<<factorial(NUM3)<<endl;
	return 0;
}

