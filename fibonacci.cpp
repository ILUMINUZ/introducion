#include <iostream>
using namespace std;
int fib(int n){
	if(n<=1)
		return n; //CONDICION BASE
	else
		{
		return fib(n-1)+fib(n-2); //CONDICION RECURSIVA
	}
}
int main(int argc, char *argv[]) {
	const int NUM1=7;
	const int NUM2=8;
	const int NUM3=9;
	cout<<"Fibonacci de "<<NUM1<<"="<<fib(NUM1)<<endl;
	cout<<"Fibonacci de "<<NUM2<<"="<<fib(NUM2)<<endl;
	cout<<"Fibonacci de "<<NUM3<<"="<<fib(NUM3)<<endl;
	
	return 0;
}

