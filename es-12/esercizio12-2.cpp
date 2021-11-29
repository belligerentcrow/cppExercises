/*Codificare un programma in linguaggio C++ che chieda all’utente
di inserire tre numeri da tastiera. L’utente può inserire numeri
interi o decimali.
Il programma dovrà stampare, per ogni numero in input,
l’arrotondamento al valore intero più vicino.*/

#include <iostream>
#include <cmath>
using namespace std;
int main(){
  double a, b, c;
  cout << "Inserisci 3 numeri, interi o decimali."<<endl;
  cin >>a >>b >>c;
  cout << round(a) << " "<< round(b)<< " "<< round(c)<<endl;  

}
