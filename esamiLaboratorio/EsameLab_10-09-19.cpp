#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class A {
private:
  double * arr;
  short len;
public:
  A(short m){
    this->len = m;
    arr = new double[m];
    for(int i = 0; i < m; i++){
      arr[i] = ((double)rand()/RAND_MAX);
    }
  }
  virtual double f(short a) = 0;
  short getLen(){
    return len;
  }
  virtual ostream & print(ostream &s){
    s << "arr = [ ";
    for(int i = 0; i < getLen(); i++){
      s << get(i) << " ";
    }
    s << "] ";
    return s;
  }
  virtual double& operator() (int i1, int i2);
protected:
  double get(short i){
    return arr[i%len];
  }
};

class B : public A{
private:
  double p;
public:
  B(short m) : A(m){
    double media = 0.0;
    for(int i = 0; i<m; i++){
      media += A::get(i);
    }
    media = media/m;
  }
  double f(short a){
    return log(foo(a, 2*a))/2;
  }
  ostream & print(ostream &s){
    A::print(s);
    s << ", p = " << this->p;
    s << "f(3)= "<< f(3);
    return s;
  }
  double& operator() (int i1, int i2){
  double *sumOper = new double;
  for(int i = i1; i < i2; i++){
    sumOper += A::get(i);
  }
  return sumOper;
}
protected:
  double foo(short s, int k){
    double ret = 0.0;
    for(int i = (s%A::getLen()); i < A::getLen(); i++){
      ret += A::get(i);
    }
    return ret*k;
  }
};

template <typename T>

class C : public A{
private:
  T x;
public:
  C(short n) : A(n){
    if(typeid(x)==typeid(n)){
      x = n;
    }else{
      x = log(((int)(1+(sin(n))))^2);
    }
  }
  double f(short r){
    return g(r);
  }
  T g(T k){
    return 2*x*(k+1);
  }
  ostream & print(ostream &s){
    A::print(s);
    s << ", x = " << this->x;
    s << "f(3)= "<< f(3);
    return s;
  }
};

ostream & operator<< (ostream &s, A& a){
    return a.print(s);
  }



int main(){
  const int DIM = 50;
  A* vett[DIM];

  srand(111222333);

  for(int i = 0; i < DIM; i++){
    short n=1+rand()%10;
    switch(rand()%3){
      case 0:
        vett[i] = new B(n);
        break;
      case 1:
        vett[i] = new C<double>(n);
        break;
      case 2:
        vett[i] = new C<short>(n);
        break;
    }
  }

  //1
  for(int i = 0; i < DIM; i++){
    cout << i << ") "<<typeid(*vett[i]).name()<< ", "<<*vett[i]<<endl;
  }

  //2
  double max = (*vett[0]).f(3);
  int counter = 0;
  double mediag = 0.0;
  for(int i = 0; i < DIM; i++){
    if((*vett[i]).f(3)>max){
      max = (*vett[i]).f(3);
    }
    if(typeid(*vett[i])==typeid(C<double>)){
      counter++;
      //(static_cast <C<double>*> (vett[i]))->g(5)
      //mediag += (*vett[i]).C<double>::g(5);
      mediag += (static_cast <C<double>*>(vett[i]))-> g(5);
    }
  }
  cout << endl;
  cout << "2) il max valore f(3) è "<< max<<endl;
  if(counter>0){
    mediag = mediag /counter;
    cout << "la media di g(5) degli oggetti di tipo C<double> è "<<mediag<<endl;
    }else{
    cout << "non ci sono oggetti di tipo C<double> quindi è risultato impossibile calcolare la media."<<endl;
  }

  
  

}
