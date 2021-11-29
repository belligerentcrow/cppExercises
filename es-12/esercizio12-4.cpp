/*Codificare un programma in linguaggio C++ che calcoli e
stampi l’ipotenusa di un triangolo rettangolo.
L’utente dovrà inserire i due cateti a e b da tastiera. Il
programma dovrà controllare che i valori inseriti siano positivi.*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int c1, c2;
  int ipotenusa=0;
  cout << "Inserisci i due cateti"<<endl;
  cin >> c1 >>c2;
  if(c1>0&&c2>0){
    ipotenusa = sqrt(pow(c1,2)+pow(c2,2));
    cout <<"L'ipotenusa di "<<c1<<" e "<<c2<<" è "<<ipotenusa<<"."<<endl;
  }else{
    cout << "you inserted a negative/null value. Please reconsider."<<endl;
  }

}
