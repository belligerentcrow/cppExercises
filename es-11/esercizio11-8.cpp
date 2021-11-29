/* Codificare in linguaggio C++ un programma che stampi le prime N
 * potenze di 2, dove N è un parametro scelto dall'utente (input da tastiera) */ 

#include <iostream>
#include <cmath> 
using namespace std; 

int main() {
		int N = 0; 
		cout << "Fino a che potenza di due vuoi stampare? "<<endl;
	       cout<< "Inserisci il numero: "; 	
		cin >> N; 
		 	
		for(int i=0; i<=N;i++)
			{
				cout << pow(2, i)<<endl;
			}
		
		
}
