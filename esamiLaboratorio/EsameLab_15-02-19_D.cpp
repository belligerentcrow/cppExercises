#include <iostream>
#include <cmath>
#include <cstdlib>
#include <typeinfo>
#include <cstring>
#include <string>
using namespace std;

class A{
private:
  int * ptr;
  short len;
public:
  A(short m, short k){
    this->len = m;
    ptr = new int[m];
    for(int i = 0; i < m; i++){
      ptr[i] = (rand()%((int)'k'-1+1)+1);
    }
  }
  virtual double f() const =0;
  int get(short i) const{
    return ptr[i%len];
  }
  short getLen()const {
    return len;
  }
  virtual ostream & print(ostream &s){
    s<<" ptr=[";
    for(int i = 0; i < getLen(); i++){
      s<< get(i)<<" ";
    }
    s << "]";
    return s;
  }
  int operator[](int x){
    return ptr[x];
  }
};

class B : public A{
private:
  double p;
public:
  B(short m, short k, double y): A(m, k){
    this->p = y;
  }
  double f()const{
    double rapp=0.0;
    for(int i = 0; i<A::getLen();i++){
      if(A::get(i)%2==0){
        rapp += A::get(i);
      }
    }
    return rapp/p;
  }
  ostream & print(ostream &s){
    A::print(s);
    s << ", p= "<< p;
    s << ", f()= "<< f();
    return s;
  }
};

class C : public A{
private:
  char x;
public:
  C(short n, short k, char c):A(n, k){
    this->x = c;
  }
  double f()const{
    double medd = 0.0;
    short counter = 0;
    for(int i = 0; i < A::getLen(); i++){
      if(A::get(i)%2!=0){
        medd += A::get(i);
        counter++;
      }
    }
    if(counter ==0){
      return 0;
    }else{
      return medd/counter;
    }

  }
  string g(char c)const{
    string str;
    str += x;
    str += c;
    return str;
  }
  ostream & print(ostream &s){
    A::print(s);
    s << ", x= "<< x;
    s << ", f()= "<< f();
    return s;
  }
};

ostream & operator<<(ostream &s, A&a){
  return a.print(s);
}

int main(){
  srand(111222333);
const int DIM = 50;
A*vett[DIM];
for(int i = 0; i< DIM; i++){
  short n=1+rand()%10;
  short m = 1+rand()%8;
  if(rand()%2==0){
    vett[i]=new B(n, m, rand()/(double)RAND_MAX+0.05);
  }else
  {
    vett[i] = new C(n, m, (char)(rand()%('z'-'a'+1)+'a'));
  }
}
//punto 1
for(int i = 0; i < DIM; i++){
  cout << i <<") ";
  if(typeid(*vett[i])==typeid(B)){
    cout << "B";
  }else{
    cout << "C";
  }
  cout << (*vett[i])<<endl;
}
//punto 2
double media = 0.0;
int count = 0;
string rett;
for(int i = 0; i<DIM; i++){
  media += (vett[i])->f();
  if(typeid(*vett[i])==typeid(C)){
    rett += (static_cast<C*>(vett[i]))->g('h');
    count++;
  }
}
media = media/DIM;
cout << endl<<"media f()= "<<media<<endl;
cout << "concatenazione g('h') per oggetti C = "<<rett<<endl;

//punto 3
cout << "Implementazione overload [] = "<< (*vett[0])[0]<<endl;
}
