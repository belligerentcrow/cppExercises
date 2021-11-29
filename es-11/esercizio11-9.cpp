/*Codificare in C++ un programma che chiede all’utente di
inserire due numeri decimali maggiori di zero e diversi tra
loro (ES: 10.2 e 24.7), ed un numero intero N.
• il programma calcola lo arrotondamento per eccesso o
per difetto di entrambi i numeri, a seconda che la parte
decimale sia maggiore o uguale a 0.5 oppure minore di
0.5 rispettivamente. Siano a e b i due numeri ottenuti,
con a < b.
• per ogni numero a ≤ p ≤ b, calcola e stampa la
somma degli N-1 numeri minori di p e la somma dei
2N numeri maggiori di p; */

#include <iostream>
#include <cmath> 
using namespace std; 

int main(){
	double first=0, second=0;
	double a=0, b=0; 
	cout << "Inserisci due diversi numeri decimali maggiori di zero"<<endl;
   	cin >> first >>second;
	bool flagerrore = false; 
	int N =0; 
	if(first==second){	//se i due numeri sono uguali faccio in modo che il programma non continui oltre.
		flagerrore = 1; 
		cout<<"Errore! I due numeri sono uguali"<<endl; 
	}else{
	cout << "Inserisci un numero intero N" <<endl; 
	cin >> N;
	}	
	//controllo se la parte decimale è maggiore o minore di 0.5 e stampo il corrispondente eccesso o difetto.
	if(flagerrore==0){
	if((first-floor(first)>=0.5)){
		cout <<"Arrotondamento eccesso primo: "<<  ceil(first)<<endl;  
		a = ceil(first); 
	}else{
		cout <<"Arrotondamento difetto primo: "<< floor(first)<<endl; 
		a = floor(first); 
	}
	if((second-floor(second)>=0.5)){
		cout <<"Arrotondamento eccesso secondo: "<< ceil(second) <<endl; 
		b = ceil(second);
	}else{
		cout <<"Arrotondamento difetto secondo: "<<floor(second)<<endl; 
		b = floor(second); 
	}
	int j = 0; 
	int sommaprima = 0; 
	int sommaseconda =0; 
	if(a<b){
		cout << "caso a < b" <<endl; 
		for(int p=a;p<=b; p++){
			j = 1; 
			sommaprima = 0; 
			sommaseconda = 0;
			while(j<N){
			sommaprima = sommaprima+(p-j); 
			j++;
			}
			j = 1; 
			while(j<=(2*N)){
			sommaseconda = sommaseconda+(p+j);
			j++; 	 
			}
		cout << "Fine ciclo del p = " << p <<endl; 
		cout << "Somma prima = "<< sommaprima<<endl;
		cout << "Somma seconda = "<<sommaseconda<<endl; 
		}	
	}else if(a>b){
		cout << "caso a > b" <<endl; 
		 for(int p=b;p<=a; p++){
                        j = 1;
			sommaprima=0; 
			sommaseconda=0; 
			while(j<N){
                        sommaprima = sommaprima+(p-j);
                        j++;
                        }
                        j = 1;
                        while(j<=(2*N)){
                        sommaseconda = sommaseconda+(p+j);
                        j++;
                        }
                cout << "Fine ciclo del p = " << p <<endl;
                cout << "Somma prima = "<<sommaprima<<endl; 
		cout << "Somma seconda = "<<sommaseconda<<endl; 
                }
	}
	}


}
