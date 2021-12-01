/* Scrivere un metodo che prenda come parametro formale un cubo 
(array tridimensionale) C di stringhe, e restituisca in output una stringa 
contenente tutte le desinenze di due caratteri delle stringhe sulla
faccia superiore del cubo C. */

string funz(string *** C, int n){

  string * outputstr = new string; 
  int desinenze = 0; 
  for(int j = 0; j < n; j++){
    for(int z = 0; z < n; z++){
     if( (C[0][j][z]).length() >= 2 ){ //controllo se la stringa contenga almeno 2 lettere
       
        outputstr[desinenze] = C[0][j][z][C[0][j][z].length()-2]; //prendo la penultima lettera della stringa
        outputstr[desinenze+1] = C[0][j][z][C[0][j][z].length()-1];  //prendo l'ultima lettera
        desinenze = desinenze + 2; //desinenze conta a due a due perché devo prendere le desinenze di 2 char
     }
    }
  }
  return outputstr; 
}
