#include <iostream>
#include <typeinfo>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

class A{
private:
  short * arr;
  short len;
public:
  A(short m){
    arr = new short[m];
    this->len = m;
    for(int i = 0; i < m; i++){
      arr[i] = (rand()%10)+1;
    }
  }
  virtual double f(short a) = 0;
  short getLen(){
    return this->len;
  }
  virtual ostream & print(ostream & s){
    s << ", arr = [ ";
    for(int i = 0; i < getLen(); i++){
      s << get(i) << " ";
    }
    s<< "] ";
    return s;
  }
protected:
  short get(short i){
    return arr[i%len];
  }
};

template <class T>

class B : public A{
private:
  T x;
public:
  double foo(short s){
    return log(s) + sin(f(s));
  }
  double f(short a){
    double media = 0.0;
    int counter = 0;
    for(int i = (a%A::getLen()); i < A::getLen(); i++){
      media += (double) A::get(i);
      counter++;
    }
    counter++;
    media = media/counter;
    return media;
  }
  B(short m, char c) : A(m){

    if(typeid(T)==typeid(char)){
      this->x = c;
    }else{

      for(int i = 0; i < m; i++){
        x+= c;
      }

    }
  }

  ostream & print(ostream & s){
    A::print(s);
    s << ", x = "<< x;
    s << ", f(3) = " << f(3);
    return s;
  }
};

class C : public A{
private:
  int y;
public:
  C(short n, int k) : A(n){
    this->y = k;
  }
  double f(short a){
    short r;
    r = A::get(rand()%A::getLen());
    return (a+y)/r;
  }
  short g(short w){
    return sin(w+this->y);
  }
  ostream & print(ostream & s){
    A::print(s);
    s << ", y = "<< y;
    s << ", f(3) = " << f(3);
    return s;
  }
};

ostream & operator<<(ostream & s, A& a){
  return a.print(s);
}

int main(){
const int DIM = 50;
srand(111222333);
A *vett[DIM];

for(int i = 0; i<DIM; i++){
  short n=1+rand()%10;
  switch(rand()%3){
    case 0:
      vett[i] = new C(n, rand()%10+1);
      break;
    case 1:
      vett[i] = new B<string>(n, rand()%('z'-'a'+1)+'a');
      break;
    case 2:
      vett[i] = new B<char>(n, rand()%('z'-'a'+1)+'a');
  }
}
//punto 1
for(int i = 0; i < DIM; i++){
  cout << i <<") ";
  if(typeid(*vett[i])==typeid(C)){
    cout<< "C";
  }else if(typeid(*vett[i])==typeid(B<char>)){
    cout << "B<char>";
  }else{
    cout << "B<string>";
  }
   cout << " "<< (*vett[i])<<endl;
}

//punto 2
double maxF = (*vett[0]).f(3);
short mediag = 0;
short counter = 0;
 for(int i = 0; i < DIM; i++){
   if((*vett[i]).f(3)> maxF){
     maxF = (*vett[i]).f(3);
   }
    if(typeid(*vett[i])==typeid(C)){
      cout << "hello";
      counter++;
      mediag += (double)(static_cast <C*>(vett[i]))->g(5);
    }
 }
 //mediag = mediag/counter;
 cout << "Max value of f(3) = "<<maxF<<endl;
 cout << "Media dei valori g(5) degli oggetti C ="<<mediag<<endl;
}
