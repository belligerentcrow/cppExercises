/*Scrivere un metodo che prenda come parametri formali una matrice A
n x m di long, ed un long x, e restituisca in output l'indice
della colonna di A con il maggior numero di occorrenze di x */

int funz (long ** A, int n, int m, long x){
 int countercol[m] = {};
 int count = 0;
 for(int i = 0; i < m; i++){
    count = 0; 
        for(int j = 0; j < m; j++){
          if(A[j][i] == x){
            count++; 
          }
        }
   countercol[i] = count; 
 }
  
  int * output = new int;
 int max = countercol[0];
  
 for(int i = 0; i < m; i++){
  if(max < countercol[i]{ 
     max = countercol[i]; 
     output = i;
      }
  }
 return output; 
}
