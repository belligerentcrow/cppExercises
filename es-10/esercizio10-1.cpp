/*H10.1.  Siano a, b e c tre variabili di tipo int.
 Trovare il massimo dei tre numeri usando
 l’operatore condizionale.*/


#include <iostream>
using namespace std;

int main(){
  int a, b, c;
  cout << "Inserisci 3 numeri" <<endl;
  cin >>a >>b >>c;

  if(a>b){
      if(a>c){
        cout << "Max value is a= "<< a << endl;
      }else if(c>a){
        cout << "Max value is c= " << c <<endl;
      }
  }else if(b>c){
    cout << "Max value is b= " << b <<endl; 
  }

}
