/*Esercizio 1 (punti 15) (scrivere la soluzione di seguito)
Scrivere un metodo che prenda in input un parametro formale matrice quadrata Q di interi ed un double w,
e restituisca un valore booleano true se esiste almeno una colonna della matrice Q tale che il rapporto tra
la somma degli elementi della colonna stessa e la somma degli elementi della diagonale secondaria di Q sia
maggiore di w.*/

bool funz(int ** Q, double w, int n){
  int sommacol = 0; 
  int sommadiag = 0; 
  
  for(int i =0; i <n; i++){
   sommadiag = sommadiag + Q[i][n-1-ui];
  }
  
  for(int i =0; i<n; i++){
    sommacol = 0; 
    for(int j =0; j<n; j++){
      sommacol = Q[j][i] + sommacol; 
    }
    if( ((double)sommacol)/((double)sommadiag) > w){
      return true; 
    }
  }
  return false; 
}
  
  
