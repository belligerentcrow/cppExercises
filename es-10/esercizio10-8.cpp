/*H10.8:  Ricavare una espressione logica perXORfacendo uso di AND, OR, NOT.*/

#include <iostream>
using namespace std;

int main(){
  bool a, b, opXOR;
  cout<< "Assegnare valore di verita' a A e B. (1/0)" <<endl;
  cin >> a >>b; // [valore di A] - a capo/enter - [valore di B]

  if((a&&!b)||(!a&&b)){ //le operazioni logiche. (A AND (NOT B)) OR ((NOT A) AND B)
    opXOR = 1;
  }else{
    opXOR = 0;
  }

  cout << "Il valore dell'operazione A XOR B e': " << opXOR<<endl<<endl;
  cout <<"Tabella di verita' completa: "<< endl;  //stampo tabella 
  cout<<"A    B   |  X"<<endl;
  cout<<"---------------"<<endl;
  cout<<"0    0   |  0"<<(opXOR ? " " :  "        X")<<endl;  //Metto delle X sul caso di verità corrispondente.
  cout<<"0    1   |  1"<<(opXOR ? "       X" : " ")<<endl;    //Avrei potuto scegliere 'esattamente' il caso corrispondente tra i due
  cout<<"1    0   |  1"<<(opXOR ? "       X" : " ")<<endl;    //ma in quel caso avrei dovuto espandere la condizione
  cout<<"1    1   |  0"<<(opXOR ? " " :  "        X")<<endl;  //delle operazioni logiche e ho preferito lasciare così

}
