/*Codificare un programma in linguaggio C++ nel quale si chieda
all’utente di inserire due numeri in virgola mobile (a e b) da
tastiera.
Il programma dovrà poi stampare la somma, la media, ed il max
tra i due numeri.
Tutti gli output del programma dovranno essere in notazione
scientifica, con una precisione di 4 cifre dopo la virgola.*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  float a, b;
  float somma=0, max, media;
  cout << "Inserisci due numeri in virgola mobile. "<<endl;
  cout << "Numero 1: ";
  cin >> a;
  cout <<endl<<"Numero 2: ";
  cin >> b;
  cout <<endl;

  somma = a+b;
  if(a<=b){
    max = b;
  }else{
    max = a; 
  }
  media = (a+b)/2;

  cout << "Somma: "<< scientific << setprecision(4)<<somma<<endl;
  cout << "Max: "<< scientific << setprecision(4)<<max<<endl;
  cout << "Media: "<< scientific << setprecision(4)<<media<<endl;


}
