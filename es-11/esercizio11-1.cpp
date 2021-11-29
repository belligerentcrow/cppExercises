/* Sulla base degli esempi precedenti, codificare un ciclo
 * while in linguaggio c++ nel quale:
 * > Il loop termina quando il capitale o montante raggiunge o supera la cifra target definita in una costante T;
 * >Tuttavia il periodo di accumulo di interessi sul montante
 *  non deve in ogni caso superare il numero di anni definito in unacostante N. */

#include <iostream>
using namespace std; 

int main(){
	
	const int N =10;
	int anno = 0; 	
	const int T = 1600;
   	double capitale = 1000;
	const double interessi = 0.10; 	

	while(anno<N && capitale<=T){
		capitale =capitale+capitale*interessi; 
	  	cout <<"Il capitale è "<<capitale<<" nell'anno " << anno<<"."<<endl;
		anno++; 	
	}	
	cout <<"Fine loop. Il capitale è: "<<capitale<< " nell'anno " << anno <<"."<< endl; 

}
