/*Esercizio 2.
Scrivere una funzione che prenda come parametro una matrice A di dimensione NxM di stringhe e restituisca una stringa
che contenga tutte le vocali delle stringhe nelle posizioni A[i][j] tali che A[i][j] è più lunga di A[j%N][i%M] di almeno
i+j unità. */

string funz(string **A, int N, int M){
  string * outputstr = new string; 
  double countleng = 0.0; 
  
  for(int i = 0; i < N; i++){
   for(int j= 0; j <M; j++){
    countleng = (A[i][j].length()) - (A[j%N][i%M].length()); 
    if(countleng >= i+j){
     for(int z =0; z<A[i][j].length(); z++){
      switch(A[i][j][z]){
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U': 
            outputstr += A[i][j][z]; 
            break; 
      }
       
     }
    }
   }
  }
  return outputstr; 
}
