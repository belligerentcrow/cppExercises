/*Scrivere  un  programma  in  C++  che  permetta  di  simulareuna  sequenza  di  N  lanci  di  una  coppia  di  dadi,  
dove  N `e  unnumero scelto dall’utente oppure una costante scelta a tempodi  compilazione.   
Il  programma  dovr`a  stampare  le  sequenzedei due numeri (output primo dado e output secondo dado)in due colonne separate. */

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std; 

int main(){
	srand(time(0));
	int N = 0; 
	cout << "Quante volte vuoi lanciare i dadi?" << endl; 
	cin >> N; 

	for(int i = 0; i <N; i++)
		cout <<rand()%6+1 <<" " <<rand()%6+1 <<endl; 

}
