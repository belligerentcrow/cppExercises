/*Esercizio 2 - Scrivere un metodo che prenda in input una matrice di puntatori a stringhe P di dimensioni n × m, due short
a e b, ed una stringa s. Il metodo restituisca il valore booleano true se esiste almeno una colonna in P tale
che la stringa s sia sottostringa di un numero compreso tra a e b (inclusi) di stringhe della colonna stessa.
PS: Si assuma 0 < a ≤ b < n,*/

bool func(string ***P, int n, int m, short a, short b, string s){
    unsigned int lookingfor = 0; 
    int counter = 0; 
    for(int i = 0; i < n; i++){
      counter = 0;
      for(int j = 0; j<m; j++){
        lookingfor = *(P[j][i]).find(s);
        if(lookingfor!=string::npos){
        counter++; 
        }
    }
      if((counter>=a)&&(counter<=b)){
        return true; 
      }
    }
  return false; 
}
