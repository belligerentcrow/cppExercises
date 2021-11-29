/*L'utente deve inserire da tastiera il capitale iniziale C,
 * il tasso d'interesse TI, il target T e il numero di anni N.
 * Se uno tra T e N è un numero minore o uguale a 0, 
 * il programma non tiene conto di tali parametri.
 * Nel caso in cui entrambi siano minori di 0, il programma termina con messaggio di errore.*/

#include <iostream>
using namespace std; 

int main(){	
	int N;
	double C, TI, T; 
	int anno =0; 

	cout << "Inserisci il capitale iniziale: " <<endl; 
	cin >> C; 
	cout << "Inserisci il tasso d'interesse: "<<endl; 
	cin >>TI; 
	cout << "Inserisci numero di anni e/o target."<<endl<<"Numero di anni: "; 
	cin >> N; 
	cout <<endl<<"Target: "; 
	cin >> T; 
	cout <<endl; 

	if(N>0||T>0){
		while(((N>0)? anno<N : C<=T) && ((T>0)? C<=T : anno<N)){
		C += C*TI; 
		anno++; 
		cout << "Il capitale è " << C << " nell'anno "<< anno<<endl; 
	       }
	} else {
		cout << "Errore. Specificare parametri validi per numero di anni e/o target." <<endl; 	
	}

}
