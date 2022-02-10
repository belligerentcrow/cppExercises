#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class A {
protected:
  double * ptr;
  short len;
public:
  A(short n){
    len = n;
     ptr = new double[n];
    for(int i = 0; i < n; i++){
      ptr[i] = ((double)rand()/RAND_MAX);
    }
  }
  virtual double foo(short a) const= 0;
  virtual ostream& print(ostream&s){
    s << " ptr = [";
    for(int i = 0; i < len; i++){
      s << ptr[i] << " ";
    }
    s << "] ";
    return s;
  }

};

class B : public A{
private:
  double alpha;
  double extract(short s) const {
    return (ptr[s%len]/alpha);
  }

public:
  B(short m, double d): A(m){
    alpha = d;
  }

  double foo(short b) const{
    return log(1+extract(b));
  }

  ostream& print(ostream&s){
    A::print(s);
    s << ", alpha = "<<alpha;
  //  s << ", foo(5) = " << foo(5);
    return s;
  }
};

template <typename T>

class C : public A{
private:
  T x;
public:
  C(short n) : A(n){
    if(typeid(T)==typeid(short int)){
      this->x = g(n);
    }else{
      this->x = log(1+n);
    }
  }
  double foo(short r) const{
    return g(r*x);
  }
  T  g(T k) const{
    return 3*k;
  }
  ostream& print(ostream&s){
    A::print(s);
    s << ", x = "<< x;
  //  s << ", foo(5) = " << foo(5);
    s << ", g(5) = "<< g(5);
    return s;
  }
};

ostream& operator<< (ostream &s, A&a){
      return a.print(s);
 }

int main(){
 const int DIM = 30;
 A * vett[DIM];


 cout << *vett[0]<<endl;

 srand(328832748);
 for(int i = 0; i<DIM; i++){
   short n = 1+rand()%5;
   switch(rand()%3){
     case 0:
        vett[i] = new B(n, n/100.0);
        break;
     case 1:
        vett[i] = new C<double>(n);
        break;
     case 2:
        vett[i] = new C<int>(n);
   }
   A * punt = new B(n, n/100.0);
   cout << *punt<<endl;
 }


//1


  for(int i = 0; i < DIM; i++){
    cout << i << ") "<<(*vett[i])<<endl;
  }

}
