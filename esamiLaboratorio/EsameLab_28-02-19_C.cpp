#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

class A {
private:
  char * base;
  short len;
public:
  A(short m){
    base = new char[m];
    this->len = m;
    for(int i = 0; i<m; i++){
      base[i] = rand()%('z'-'a'+1)+'a';
    }
  }
  virtual string extract (short x) = 0;
  short getLen(){
    return this->len;
  }
  virtual ostream & print(ostream&s){
    s<<"base = [";
    for(int i = 0; i < getLen(); i++){
      s << get(i)<< " ";
    }
    s << "]";
    return s;
  }
  
protected:
  char get(short i){
    return base[i%len];
  }
};

class B : public A{
private:
  string str;
  double k;
public:
  B(short m, double p) : A(m){
    this->k = p;
    string ret;
    for(int i = 0; i<A::getLen(); i++){
      if(A::get(i)=='a'||A::get(i)=='e'||A::get(i)=='i'||A::get(i)=='o'||A::get(i)=='u'||A::get(i)=='A'||A::get(i)=='E'||A::get(i)=='I'||A::get(i)=='O'||A::get(i)=='U'){
        ret += A::get(i);
      }
    }
    this->str = ret;
  }
  double foo(short s){
    return sin(k+s)/log(s+1);
  }
  string extract(short x){
    string ret2;
    for(int i = 0; i < x; i++){
      ret2[i] = get(rand()%(A::getLen()+1));
    }
    return ret2;
  }
  ostream & print(ostream&s){
    A::print(s);
    s << ", str = "<<str;
    s << ", k ="<<k;
    s << ", extract(3)="<<extract(3);
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
  short g(short w){
    return sin(w+y);
  }
  string extract(short x){
    string ret3;
    short counter =0;
    short i =0;
    while(counter<x||i<A::getLen()){
      if(!(A::get(i)=='a'||A::get(i)=='e'||A::get(i)=='i'||A::get(i)=='o'||A::get(i)=='u'||A::get(i)=='A'||A::get(i)=='E'||A::get(i)=='I'||A::get(i)=='O'||A::get(i)=='U')){
        ret3+=A::get(i);
        counter++;
    }
    i++;
  }
  return ret3;
}
ostream & print(ostream&s){
  A::print(s);
  s << ", y = "<<y;
  s << ", extract(3)="<<extract(3);
  return s;
}

};

ostream & operator<<(ostream&s, A&a){
  return a.print(s);
}

int main(){
const int DIM = 50;
A*vett[DIM];
srand(111222333);
      for(int i=0; i<DIM; i++){
	short n=10+rand()%10;
	switch(rand()%2){
	  case 0:
	    vett[i]= new C(n, rand()%20 + 1);
	    break;
	  case 1:
	    vett[i]= new B(n, rand()/(double) RAND_MAX);
	    break;
	}
    }

//punto 1
for(int i = 0; i<DIM; i++){
  cout << i << ")";
  if(typeid(*vett[i])==typeid(B)){
    cout << "B :";
  }else{
    cout <<"C :";
  }
  cout <<(*vett[i])<<endl;
}
//punto 2
double media = 0;
for(int i = 0; i < DIM; i++){
  if(typeid(*vett[i])==typeid(B)){
    media += (static_cast <B*>(vett[i]))->foo(5);
  }else{
    media += (static_cast <C*>(vett[i]))->g(5);
  }
}
cout << media<<endl;
media = media/50;
cout << "media g(5) e foo(5)= "<<media<<endl;

}
