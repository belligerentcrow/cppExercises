/*Siano a, b e c tre variabili di tipo int ed str una variabile di tipo string.
Se a `e diverso da c e la lunghezza della stringa str`e minore di 8,
allora copia in b la somma di a e c;
Se a `e uguale a c e  la  lunghezza  della  stringa str`e  minore  di  8,
allora  copia  in a il valore c−b;
in tutti gli altri casi poni a,b e c a zero.*/

#include <iostream>
using namespace std;

int main(){
  int a, b, c;
  string str;
  cout <<"Insert 3 numbers"<<endl;
  cin >>a >>b >>c;
  cout << "Insert a string"<<endl;
  cin >>str;
  cout << "the string is "<< str.length() << " long" << endl;
  if(a!=c&&str.length()<8){
    b = a+c;
  }else if(a==c&&str.length()<8){
    a = c-b;
  }else{
    a=0;
    b=0;
    c=0;
  }
  cout << "a = "<<a <<endl <<"b = "<<b <<endl <<"c = "<<c <<endl;
}
