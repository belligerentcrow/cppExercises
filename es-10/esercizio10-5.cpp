/*Codificare un programma in C++ che chiede all’utente di inserire un carattere.
Il programma dovr`a dare il seguente output:
Se il carattere `e una vocale minuscola, stampa il numero che rappresenta la sua codifica;
Se il carattere `e una vocale maiuscola, stampa il carattere stesso sullo standard output;
Se il carattere `e un numero compreso tra 1 e 3, stampa il numero stesso moltiplicato per 10;*/

#include <iostream>
using namespace std;

int main(){
  char carattere;
  int codifica = 0;
  cout << "Inserire un carattere: " << endl;
  cin >> carattere;
  codifica = int(carattere);  //converto nell'equivalente ascii e lo metto nella variab codifica


  switch(carattere){
    case '1':     //cases a cascata per il caso 3
    case '2':
    case '3':
      cout << (codifica-48)*10<<endl;   //il -48 è perché l'ascii di '1' è 49.
      break;                            //Così torno al numero che i chars rappresentano e posso operare con esso.
    case 'a':   //cases a cascata per il caso 1
    case 'e':
    case 'i':
    case 'u':
    case 'o':
      cout <<codifica<<endl;  //stampo l'equivalente ascii se è minuscolo
      break;
    case 'A':     //cases a cascata per il caso 2
    case 'E':
    case 'I':
    case 'U':
    case 'O':
        cout<< carattere<<endl; //stampo il carattere com'è se è maiuscolo
        break;
    default:
      cout <<"Invalid input."<<endl;   //default in caso di input invalido
      break;
  }
}
