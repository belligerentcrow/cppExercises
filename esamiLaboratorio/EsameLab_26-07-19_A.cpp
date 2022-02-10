#include <iostream>
#include <typeinfo>
#include <cmath>
#include <cstdlib>
using namespace std;

class A {
private:
  double * vec;
  short len;
public:
  A(short w, double a, double b){
    this->len = w;
    vec = new double[w];
    for(int i = 0; i < w; i++){
      vec[i] = a+((double)rand()/RAND_MAX)*(b-a);
    }
  }
  virtual double foo(short a) = 0;
  short getLen(){
    return this->len;
  }
  virtual ostream& print(ostream &s){
    s << " vec = [ ";
    for(int i = 0; i < getLen(); i++){
      s << vec[i]<<" "; //?
    }
    s << " ]";
    return s;
  }
protected:
  double get(short i){
    return vec[i%len];
  }
};

class B : public A {
private:
  int p;
public:
  B(short m, short x, short y): A(m, (double)x, (double)y){
    this->p = ((int)rand()%(y*100-x*10+1)+x*10);
  }
  double foo(short a){
    return log(prod(a, a/2));
  }
  ostream & print(ostream &s){
    A::print(s);
    s << ", p= "<< this->p;
    s << ", foo(3)="<< foo(3);
    return s;
  }
protected:
  double prod(short s, double v){
    double sum = 0.0;
    for(int i = s%A::getLen(); i < A::getLen(); i++){
      sum += get(i);
    }
    return v*sum;
  }
};

template <typename T>

class C : public A {
private:
  T y;
public:
  C(short n, double x, double y) : A(n, x, y){
    if(typeid(T)==typeid(short)){
      this->y = n;
    }else{
      this->y = (1+((int)cos(n)))^2;
    }
  }
  double foo(short r){
    return g(r);
  }
  double g(double k){
    return 2*y*(k+1);
  }
  ostream &print(ostream &s){
    A::print(s);
    s << ", y="<< this->y;
    s << ", foo(3)= "<< foo(3);
    return s;
  }
};

ostream & operator<<(ostream &s, A& a){
  return a.print(s);
}

int main(){
const int DIM = 50;
A* vett[DIM];
srand(111222333);
for(int i = 0; i < DIM; i++){
  short n = 5+rand()%5;
  switch(rand()%3){
    case 0:
      vett[i] = new B(n, rand()%5+1, rand()%10+5);
      break;
    case 1:
      vett[i] = new C<double>(n, rand()%5+1, rand()%10+5);
      break;
    case 2:
      vett[i] = new C<short>(n, rand()%5+1, rand()%10+5);
      break;
  }
}

for(int i = 0; i < DIM; i++){
  cout << i<<") "<<(*vett[i])<<endl;
}
}
