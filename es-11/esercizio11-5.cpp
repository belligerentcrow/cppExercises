/*Codificare un programma che stampi a ritroso i numeri 
 * pari minori o uguali a mille. 
 * Terminare se la somma dei numeri stampati è >= 100'000*/ 

#include <iostream> 
using namespace std;

int main(){

	const int stopp = 100000; 
	int i = 1000; 
	int somma=0; 
	while(i>0&&somma<stopp){
	

	somma =somma+i; 
	cout <<"i è "<<i <<endl;
	i=i-2; 
	}
	 

}
