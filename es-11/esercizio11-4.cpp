/* Codificare un programma che produca la somma dei 
 * numeri interi dispari da 1 a 99, facendo uso del costrutto for. Dalla somma vanno esclusi i numeri divisibili per 3.*/

#include <iostream>
using namespace std; 

int main(){
	
	int x=0;

	for(int i = 1; i<99;i=i+2){
		if(i%3!=0){
			x=x+i; 
		}

	}
	cout<<x<<endl; 
}
