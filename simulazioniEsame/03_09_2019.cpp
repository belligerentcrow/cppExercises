/*Esercizio 1 (punti 15) (scrivere la soluzione di seguito)
Scrivere un metodo che prenda in input un parametro formale matrice quadrata Q di interi ed un double w,
e restituisca un valore booleano true se esiste almeno una colonna della matrice Q tale che il rapporto tra
la somma degli elementi della colonna stessa e la somma degli elementi della diagonale secondaria di Q sia
maggiore di w.*/

bool funz(int ** Q, double w, int n){
  int sommacol = 0; 
  int sommadiag = 0; 
  
  
  //
  
