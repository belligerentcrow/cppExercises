#include <iostream>
#include <cmath>
#include <typeinfo>
#include <cstdlib>
using namespace std;

class A{
private:
  char * str;
  short len;
public:
  A(short m, string source){
    str = new char[m];
    this->len = m;
    for(int i = 0; i<m; i++){
      str[i] = source[(rand()%(source.length()))];
    }
  }
  virtual char func(short i) = 0;
  short getLen(){
    return this->len;
  }
  virtual ostream & print(ostream &s){
    s << "str = "<< str;
    return s;
  }
protected:
  char get(short i){
    return str[i%len];
  }
};

class B : public A{
private:
  short p;
public:
   B(short m, string source):A(m, source){
     int vocals =0;
     for(int i = 0; i < A::getLen(); i++){
       if(A::get(i)=='a'||A::get(i)=='e'||A::get(i)=='i'||A::get(i)=='o'||A::get(i)=='u'||A::get(i)=='A'||A::get(i)=='E'||A::get(i)=='I'||A::get(i)=='O'||A::get(i)=='U'){
         vocals++;
       }
     }
     this->p = 1+vocals;
   }
   char func(short i){
      for(int i = 0; i<A::getLen(); i++){
     if(!(A::get(i)=='a'||A::get(i)=='e'||A::get(i)=='i'||A::get(i)=='o'||A::get(i)=='u'||A::get(i)=='A'||A::get(i)=='E'||A::get(i)=='I'||A::get(i)=='O'||A::get(i)=='U')){
       return A::get(i);
     }
     }
      return 'X';
    }
    ostream & print(ostream &s){
      A::print(s);
      s << ", p = " << this->p<< ", func(3) = "<<func(3);
      return s;
    }
};

class C : public A{
private:
  char x;
public:
  C(short n, string source, char y) : A(n, source){
    this->x = y;
  }
  char func(short i){
    for(int j = i; j < A::getLen(); j++){
      if(A::get(j) > this->x){
        return A::get(j);
      }
    }
    return this->x;
  }
  string g(char c){
    string ret;
    ret += this->x;
    for(int i = 0; i<A::getLen(); i++){
      ret += A::get(i);
    }
    ret += c;
    return ret;
  }
  ostream & print(ostream &s){
    A::print(s);
    s << ", x = " << this->x<< ", func(3) = "<<func(3);
    return s;
  }
};

ostream & operator<<(ostream&s, A &a){
  return a.print(s);
}

int main(){
const int DIM = 50;
srand(111222333);
A *vett[DIM];
string S = "supercalifragilistichespiralidoso";
for(int i = 0; i<DIM; i++){
  short n = 3+rand()%10;
  if(rand()%2==0){
    vett[i] = new B(n, S);
  }else {
    vett[i] = new C(n, S, (char)(rand()%('z'-'a'+1)+'a'));
  }
}

//punto 1
for(int i = 0; i <DIM; i++){
  cout << i << ") "<< typeid(*vett[i]).name()<< ", "<<(*vett[i])<<endl;
}

}
