#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class A {
private:
  double * w;
  short len;
public:
  A(short m){
    w = new double[m];
    len = m;
    for(int i = 0; i < m; i ++){
      w[i] = ((double)rand()/RAND_MAX);
    }
  }
 virtual double foo(short a) const = 0;
  virtual ostream &print(ostream &s){
    s << "w = [";
  for(int i = 0; i < len; i++){
    s << w[i]<<" ";
  }
  s << "] ";
  s << ", len = "<< getLen();
  s << ", get(1) = "<<get(1);
  return s;
}
 short getLen()const{
   return len;
  }
protected:
  double get(short i)const{
  return w[i%len];
 }
};

class B : public A {
private:
  int p;
public:
  B(short m, int x): A(m){
    p = x;
  }
  double foo(short a) const{
    return sum(a)/p;
  }
  ostream &print(ostream &s){
    A::print(s);
    s <<" B ";
    s << ", p = "<< p;
    s << ", foo(3) = "<<foo(3);
    s << ", sum(3) = "<<sum(3);
    return s;
  }
protected:
  double sum(short s) const{
    double summa = 0.0;
    for(int i = s%getLen(); i<getLen(); i++){
      summa += get(i);
    }
    return summa;
  }
};

template <typename T>

class C : public A {
private:
  T x;
public:
  C(short n):A(n){
    if(typeid(T)==typeid(short int)){
      x = n;
    }else{
      n = log((int)(1+sin(n))^2);
    }
  }
  double foo(short r) const{
    return g(r);
  }
  T g(T k) const{
    return 2*x*(k+1);
  }
  ostream & print(ostream &s){
    A::print(s);

    s << ", x = "<< x;
    s << ", foo(3) = "<<foo(3);
    s << ", g(3) = "<<g(3);
    return s;
  }
};

ostream & operator<< (ostream &s, A& a){
  return a.print(s);
}

int main(){

  int const DIM = 50;
  A* vett[DIM];
  srand(111222333);
  for(int i =0; i<DIM; i++){
    short n = 1+rand()%10;
    switch(rand()%3){
      case 0:
          vett[i] = new B(n, rand()%10+1);
          break;
      case 1:
          vett[i] = new C<double>(n);
          break;
      case 2:
          vett[i] = new C<short>(n);
    }
  }
//(static_cast <C<double>*> (vett[i]))->g(5)
// dynamic_cast<C<double>*>(vett[i])
  //1
  double max = (*vett[0]).foo(3);
  double media = 0.0;
  short counter = 0;
  for(int i = 0; i < DIM; i++){
    cout << i << ") "<<(*vett[i])<<endl;
    if((*vett[i]).foo(3)>max){
      max = (*vett[i]).foo(3);
    }
    if(typeid(*vett[i])==typeid(double)){
      counter++;

      media += (dynamic_cast <C<double>*>(vett[i]))->g(5);
    }
  }
  media = media/counter;
  cout << endl;
  //2 --^
  cout << "max foo(3) = "<<max <<endl;
  cout << "media g(5) di C<double> = "<<media;

}
