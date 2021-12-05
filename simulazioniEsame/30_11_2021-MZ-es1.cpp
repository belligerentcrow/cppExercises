/*Esercizio 1.
Scrivere una funzione che prenda come parametri formali una matrice bidimensionale A di double 
(usare un doppio puntatore a double) e due interi M e N indicanti le dimensioni della matrice (dunque MxN)
e restituisca una matrice B di double di dimensioni NxM il cui elemento B[i][j] sia pari a A[j][i]
se A[j][i] è maggiore di un numero casuale s compreso tra 0 e 1, mentre sia uguale a A[i%M][j%N] altrimenti. */

double ** funz(double ** A, int M, int N){
  srand(time(0)); 
  double ** B = new double[M][N];
  double s = ((double) rand() / (double) RAND_MAX); 
  
  for(int i = 0; i < M; i++){
    
   for(int j = 0; j <N; j++){
     
    if(A[j][i] > s){
          B[i][j] = A[j][i]; 
    } else{
          B[i][j] = A[i%M][j%N]; 
    }
     
   }
  }
  return B; 
}
