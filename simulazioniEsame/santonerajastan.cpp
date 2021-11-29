/*Un santone induista si trova nella regione indiana del Rajasthan, quest’ultima simulata con una matrice quadrata di boolean
in cui il valore true indica la presenza di un libro sacro. Scrivere un metodo che prenda in input una matrice di boolean e
restituisca il numero di libri raccolti dal santone che, partendo dal centro della regione, esegue un movimento casuale unitario
alla volta in una delle quattro direzioni prima che egli sia traviato dalle usanze oltre confine. */

#include <iostream> 
#include <cstdlib>
#include <ctime>

#define N 8 
int funz(bool ** M, int dim){
 srand(time(0)); 
 int numero_libri = 0; 
  short direzione = 0; 
  int i = dim/2, j=dim/2; 
  while((i<dim && i >= 0)&&(j<dim)&&(j>=0)){
   if(regione[i][j] ==1){
    numero_libri++; 
    regione[i][j] = 0; 
   }
    direzione = rand()%4; 
      switch(direzione){
        case 0:
           i++;
           break; 
        case 1: 
            i--; 
            break; 
        case 2:
            j++;
            break; 
        case 3: 
            j--; 
            break; 
      }
  }
  return numero_libri; 
}
  
