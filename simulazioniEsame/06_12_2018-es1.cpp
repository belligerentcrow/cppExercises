/*
Esercizio 1
Scrivere un metodo che prenda in input un parametro formale matrice A di interi di dimensioni n × n ed
un double w, e restituisca un valore booleano true se esiste almeno una colonna della matrice A per cui il
rapporto tra la somma degli elementi della colonna stessa e la somma degli elementi della diagonale principale
di A sia maggiore di w.
*/

bool funz(int ** A, int n, double w) {
int sommacol = 0;
int sommadiag = 0;
double rapp = 0.0; 

for(int i = 0; i<n; i++){
  sommadiag += A[i][i];
}

for(int i=0; i < n; i++){
  rapp = 0.0; 
  sommacol =0; 
  for(int j =0; j < n; j++){
    sommacol += A[j][i]; 
  }
  rapp = ((double)sommacol / (double) sommadiag); 
  if(rapp > w) {
    return true; 
  }
}
return false; 
}
