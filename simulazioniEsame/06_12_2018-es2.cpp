/*Esercizio 2. 
Scrivere un metodo che prenda in input tre parametri formali: una matrice di puntatori a stringhe A di
dimensioni n × m, uno short k ed una stringa s. Il metodo restituisca un array di bool di dimensione n in
cui il singolo elemento di indice i assume valore true se la stringa s è sottostringa di almeno k stringhe della
riga i-esima della matrice A. */

bool * funz(string ***A, int m, int n, short k, string s){
 int countercol = 0; 
 bool * outputbool = new bool[n];
 for(int i = 0; i < n; i++){
  outputbool[i] = 0; 
 }
 for(int i = 0; i < n; i++){
  countercol = 0; 
   for(int j=0; j < m; j++){
    if(A[i][j]!=nullptr)&&((*(A[i][j])).find(s)!=string::npos)){
     countercol++; 
    }
   }
   if(countercol>=k){
   outputbool[i]=1; 
   }
 }
  return outputbool; 
}
