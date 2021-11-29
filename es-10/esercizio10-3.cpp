/*H10.3.   Siano s1, s2  ed s3  tre  oggetti  di  tipo string e mys un altro oggetto di tipo string.
Se (A) la lunghezza di una delle tre stringhe s1,s2,s3 `e maggiore di 10
e se (B) almeno una di esse `e lunga almeno 20 caratteri,
allora copia nella variabile di tipo string denominata mys la concatenazione dei primi tre caratteri in s2
e degli ultimi tre caratteri in s3.

-Se la condizione A `e verificata ma non la B,
allora copia in mys la concatenazione delle tre stringhe, in ordine.

-In tutti gli altri casi stampa la somma delle lunghezze delletre stringhe.*/

#include <iostream>
#include <cstring>
using namespace std;


int main(){
  string s1, s2, s3, mys;
  cout << "Inserisci 3 stringhe "<< endl;
  cin >>s1 >>s2 >>s3;
  bool A = false;
  if(s1.length()>10||s2.length()>10||s3.length()>10){
    A = true;
    if(s1.length()>20||s2.length()>20||s3.length()>20){
      cout << "funziono! "<<endl;
      mys = {s2[0],s2[1],s2[2],s3[s3.length()-3],s3[s3.length()-2],s3[s3.length()-1]};
      cout << "adesso mys = "<<mys <<endl;
      A = false;
    }
  }

  if (A == true){
    mys = s1 + s2 + s3;
    cout <<"stavolta mys = "<<mys<<endl;
  }
cout << "s1 = "<< s1 <<endl<< "s2 = "<<s2 <<endl <<"s3 ="<<s3<< endl <<"mys = "<< mys <<endl;

}
