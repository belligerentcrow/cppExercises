/* Esercizio 11-6 VERSIONE WHILE*/

#include <iostream>
using namespace std; 
int main(){
	
	int i = int('z');
	int arrivo = int('a');

	while(i>arrivo){
		if(i!=int('a')&&i!=int('e')&&i!=int('i')&&i!=int('u')&&i!=int('o')){
		cout << char(i)<<endl; 
	}
	i--; 		
	}

}
