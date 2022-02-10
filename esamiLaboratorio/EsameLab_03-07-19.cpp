#include <iostream>
#include <cstdlib>
using namespace std;

class A {
private:
  int * arr;
  short len;

public:
  A(short m, int a, int b){
    srand(111222333);
    arr = new int[m];
    for(int i =0; i < m; i++){
      arr[i] = a + (rand()% b+1);
    }
  }

  virtual double func(short i) = 0;

  short getLen(){
    return len;
  }

  virtual ostream &print(ostream &s){
    s << " arr= [";
    for(int i = 0; i<A::getLen(); i++){
      s << A::get(i) << " ";
      }
    s << "]";
    return s;
  }

protected:
  double get(short i){   //???????
    return ((double) arr[i%len]);
  }
};

class B : public A{
private:
  double p;
public:
  B(short m, int y, int z, double x) : A(m, y, z){
    this->p = x;
    }

  double func(short i){
    int min = A::get(i);
    int max = A::get(i);
    for(int i=0; i < A::getLen(); i++){
      if(min>A::get(i)){
        min = A::get(i);
      }
      if(max < A::get(i)){
        max = A::get(i);
      }
    }
    return ((double)min / max)+this->p;
  }
  ostream &print(ostream &s){
    A::print(s);
    s << ", p = "<<this->p;
    s << ", func(3)= "<< func(3);
    return s;
  }
};

class C : public A{
private:
  char t;
public:
  C(short n, char c, int a, int b) : A(n, a, b){
    this-> t = c;
  }

  double func(short i){
    double media = 0.0;
    for(int i = 0; i < A::getLen(); i++){
      media += A::get(i);
    }
    return (media / A::getLen());
  }

  string g(char c, short k){
    string cat;
    for(int i = 0; i<k; i++){
      cat += this->t;
      cat += c;
    }
    return cat;
  }

  ostream &print(ostream &s){
    A::print(s);
    s << ", t = "<<this->t;
    s << ", func(3)= "<< func(3);
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
  for (int i =0; i <DIM; i++){
  short n=1+rand()%10;
  if(rand()%2==0){
    vett[i] = new B(n, rand()%5+1, rand()%11+10, (double)rand()/(RAND_MAX));
  }else{
    vett[i] = new C(n, (char)(rand()%('z'-'a'+ 1)+'a'), rand()%5+1, rand()%11+10);
  }
}

for(int i = 0; i < DIM; i++){
  cout << i << ") "<<typeid(*vett[i]).name()<<(*vett[i])<<endl;
}
}
