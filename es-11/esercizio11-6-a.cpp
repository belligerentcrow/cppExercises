/*Codificare un programma che stampi a ritroso la sequenza di caratteri da a a z ma non le vocali. VERSIONE FOR */

#include <iostream>
using namespace std;

int main(){
	int i = int('z'); 
	int arrivo = int('a');
	for(;i>arrivo; i--){
		if((char(i)!='a')&&(char(i)!='e')&&(char(i)!='i')&&(char(i)!='u')&&(char(i)!='o')){
		cout<<char(i) <<endl; 
		}
	}
	
}
