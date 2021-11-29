/*Esercizio 2
Scrivere un metodo che prenda in input due matrici quadrate A e B di double di dimensioni n × n e restituisca in output
un array di bool di dimensione n. Sia ri il rapporto tra il massimo valore degli elementi della riga i-esima di A ed il massimo
valore degli elementi della colonna i-esima di B. L’elemento i-esimo del vettore in ouput conterrà il valore booleano true se e
solo se 0 ≤ ri ≤ 1.*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std; 
#define N 10

bool * funz(double A[N][N], double B[N][N], int n){
	double maxA = 0; 
	double maxB = 0;
       	double rapp = 0.0; 
	bool * output = new bool[n];
	
	for(int i = 0; i < n; i++){
	maxA = A[i][0];
        maxB = B[0][i]; 
	  for(int j = 0; j < n; j++){
          if(maxA < A[i][j]){
		maxA = A[i][j]; 
	  } 
	  if(maxB < B[j][i]){
		maxB = B[j][i]; 
	  }
	  }
	rapp = maxA/maxB; 
	if((rapp >= 0)&&(rapp<=1)){
		output[i] = 1; 
	}else{
	output[i] = 0; 
	}
	}
	return output; 	
}

int main(){
	srand(time(0)); 
	int n = 10; 
	double matrA[N][N]; 
	double matrB[N][N];

	for(int i =0; i < n; i++){
		for(int j =0; j <n; j++){
		matrA[i][j]=(double)(rand()%100); 
		matrB[i][j] =(double)(rand()%100); 
		}
	}

	bool * array = {funz(matrA, matrB, n)}; 	
	for(int i =0; i<N; i++){
	cout << array[i]<<endl;
	}	
}
