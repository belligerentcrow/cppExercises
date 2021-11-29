#include <iostream>
using namespace std;

int main(){
  char ambiente; // E = esterno, I = interno
  double carico = 0;
  double lunghezza = 0;
  bool tipo_di_legno;
  double spessore = 0;
  double variab_Q = 0;

  cout << "All'esterno o all'interno? (inserire 'e' per esterno, 'i' per interno.)" << endl;
  cin >> ambiente;
  cout << "Massimo carico che il singolo ripiano puo' sopportare?"<<endl;
  cin >>carico;
  cout << "Lunghezza in metri di ogni ripiano?"<<endl;
  cin >>lunghezza;

  if(ambiente=='e'){  //determino il tipo di legno. Uso un bool così da poter usare operatore ternario in seguito e perché è una scelta fra due opzioni.
    tipo_di_legno = 1; //legno di castagno è 1;
  }else{
    tipo_di_legno = 0; //legno di pino è 0;
  }

  //calcolo la variabile Q
  if(tipo_di_legno==1&&carico>100){
    variab_Q =1.1;
  }else if(tipo_di_legno==0&&carico>80){
    variab_Q = 1.2;
  } else{
    variab_Q = 1.0;
  }
  //calcolo lo spessore in base alla formula dell'esercizio
  spessore = ((tipo_di_legno ? 0.018 : 0.02)+max(0.0, lunghezza-1)*(tipo_di_legno ? 0.02 : 0.022))*variab_Q;
  
  //output dei risultati.
  cout << "Il materiale da usare sara' il legno di " << (tipo_di_legno ? "castagno." : "pino.") << endl;
  cout << "Lo spessore dei ripiani sara': "<< spessore <<"."<<endl;
}
