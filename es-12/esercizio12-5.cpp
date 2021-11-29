/*Codificare un programma in linguaggio C++ che chieda
all’utente di inserire il raggio di un cerchio.
Il programma dovrà calcolare e stampare l’area e la
circonferenza del cerchio. */

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double r;
    double area;
    double circonf;
    cout << "Inserisci il raggio di un cerchio: ";
    cin >> r;
    if(r>0){
      area = (r*r)*(3.1415926535898);
      circonf = 2*r*(3.1415926535898);
      cout << "L'area è "<< area << " e la circonferenza è "<< circonf<<endl;
    }else{
      cout<<"Invalid input. Please reconsider."<<endl;
    }
}
