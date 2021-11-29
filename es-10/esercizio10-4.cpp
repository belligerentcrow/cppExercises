//esercizio di confronto lessicografico

#include <iostream>
#include <cstring>
using namespace std;

int main(){

  string a1 = "sale", a2 = "sole"; // maggiore: sole
  string b1 = "uova", b2 = "suola"; //maggiore: uova
  string c1 = "Marco", c2 = "marco"; //maggiore: marco
  string d1 = "asta", d2 = "canasta"; //maggiore: canasta
  string e1 = "123prova", e2 = "Abaco"; //maggiore: Abaco

  if(a1<a2){
    cout << a2<<endl;
  }else{
    cout << a1 <<endl;
  }

  if(b1<b2){
    cout << b2<<endl;
  }else{
    cout << b1 <<endl;
  }

  if(c1<c2){
    cout << c2<<endl;
  }else{
    cout << c1 <<endl;
  }

  if(d1<d2){
    cout << d2<<endl;
  }else{
    cout << d1 <<endl;
  }

  if(e1<e2){
    cout << e2<<endl;
  }else{
    cout << e1 <<endl;
  }

}
