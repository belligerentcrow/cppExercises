#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <cmath>
using namespace std;

class A{
private:
  char * ptr;
  short len;
public:
  A(short m, char c){
      this->len = m;
      ptr = new char[m];
      for(int i = 0; i < m; i++){
        //if(c > 'a'){
            ptr[i] = (rand()%(c-'a'+1)+'a');
          //}else if(c == 'a'){
            //ptr[i] = 'a';
          //}else{
        //    ptr[i] = (rand()%('a'-c+1)+c);
          //}
      }
  }
  virtual string elab(short a, char c) = 0;
  short getLen(){
    return len;
  }
  virtual ostream & print(ostream &s){
    s << ", ptr = [";
    for(int i = 0; i <len; i++){
      s << get(i)<< " ";
    }
    s << "]";
    return s;
  }
  char & operator[] (int i){
    return ptr[i];
  }
protected:
  char get(short i){
    return ptr[i%len];
  }
};

class B : public A{
private:
  double x;
public:
  B(short m, double y, char c):A(m, c){
    this->x = y;
  }
  double foo(short s){
    return sin(x+s)/log(x+s);
  }
  string elab(short a, char c){
    string ret;
    for(int i = 0; i < A::getLen(); i++){
      if((A::get(i)-c)<=a||-(A::get(i)-c)<=a){
        ret += A::get(i);
      }
    }
    return ret;
  }
  ostream & print(ostream &s){
    A::print(s);
    s << ", x= "<< x;
    s << ", elab(5, z)= "<<elab(5, 'z');
    return s;
  }
};

template <typename T>
class C : public A{
private:
  T y;
public:
  C(short n, double k, char c): A(n, c){
    if(typeid(T)==typeid(short)){
      this->y = round(100*k);
    }else{
      this->y = k;
    }
  }
  string elab(short a, char c){
    string retu;
    if(A::getLen()>=a){
      for(int i = 0; i < a; i++){
        retu += c;
      }
    }else{
      for(int i = 0; i < A::getLen(); i++){
        retu += A::get(i);
      }
    }
    return retu;
  }
  double g(short w){
    return sin(w+y);
  }
  ostream & print(ostream &s){
    A::print(s);
    s << ", y= "<< y;
    s << ", elab(5, z)= "<<elab(5, 'z');
    return s;
  }
};

ostream & operator<<(ostream &s, A&a){
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
          vett[i] = new B(n, (double)rand()/RAND_MAX, rand()%('z'-'a'+1)+'a');
          break;
      case 1:
          vett[i] = new C<double>(n, (double)rand()/RAND_MAX, rand()%('z'-'a'+1)+'a');
          break;
      case 2:
          vett[i] = new C<short>(n, (double)rand()/RAND_MAX, rand()%('z'-'a'+1)+'a');
      }
  }

  //punto 1
  for(int i = 0; i<DIM; i++){
    cout << i << ") "<<typeid(*vett[i]).name()<<(*vett[i])<<endl;
  }

  //punto 2
  double mediaFoo = 0.0;
  short counterf = 0;
  double mediaG = 0.0;
  short counterg = 0;
  for(int i = 0; i < DIM; i++){
    if(typeid(*vett[i])==typeid(B)){
      mediaFoo += (dynamic_cast<B*>(vett[i]))->foo(5);
      counterf++;
    }else if(typeid(*vett[i])==typeid(C<short>)){
      mediaG += (dynamic_cast<C<short>*>(vett[i]))->g(5);
      counterg++;
    }
  }
  mediaFoo = mediaFoo/counterf;
  mediaG = mediaG/counterg;
  cout << "media foo(3) = "<< mediaFoo<<endl;
  cout << "media g(5) = "<< mediaG <<endl;

  //punto 3
  cout << "ptr[0], ptr[1] = "<< (*vett[0])[0]<<", "<<(*vett[0])[1]<<endl; 
}
