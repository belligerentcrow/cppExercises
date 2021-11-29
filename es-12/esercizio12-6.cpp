/*Scrivere un programma in C++ finalizzato al calcolo dei valori di
  dosaggio per la ricetta di un dolce.
Il programma chiede all’utente di inserire un numero compreso tra 2 e 16
  che rappresenta il numero di persone che mangeranno il dolce.
Il programma chiede all’utente di inserire un valore che indica se tra i
  commensali ci sono diabetici.
Il programma calcola il dosaggio nel seguente modo:

A dosaggio “base”, per un numero di persone compreso tra 2 e 4
    (estremi inclusi): 0.3kg di farina, 4 uova, 0.1kg di zucchero.
B dosaggio “medio”, per un numero di persone compreso tra 5 e 8
    (estremi inclusi). 2 volte e mezzo il dosaggio base per la farina e le
    uova, 1 volta e mezzo il dosaggio base di zucchero.
C dosaggio “grande”, per un numero di persone compreso tra 9 e 16
    (estremi inclusi): in questo caso il dosaggio andrà calcolato come la
    somma dei dosaggi dei due casi precedenti (medio e base).

Inoltre:
 • se ci sono diabetici tra i commensali, usare il fruttosio al posto dello
    zucchero, e la dose sarà la seguente:
    dosaggio Fruttosio = 2/3 × dosaggio Zucchero.
• il numero di uova va arrotondato sempre per eccesso (es: 2.1 → 3,
    2.9 → 3, 9.45 → 10). */

#include <iostream>
using namespace std;

int main(){
  int numeroInvitati = 0;
  bool diabetici = 0;
  bool rispostadiabete = 0;
  char x;
  while(numeroInvitati<2||numeroInvitati>16){ //ciclo finché l'utente non inserisce un input valido
    cout << "Inserisci il numero di invitati: ";
    cin >>numeroInvitati;
    if(numeroInvitati<2||numeroInvitati>16){
      cout << "Inserisci un numero tra 2 e 16."<<endl;
    }
  }

  while(rispostadiabete==0){    
  cout << "Ci sono diabetici? (Y/N): "<<endl;
  cin >> x;
  if(x=='Y'||x=='y'){
    diabetici = 1;
    rispostadiabete = 1;
  }else if(x=='N'||x=='n'){
    diabetici = 0;
    rispostadiabete = 1;
  }else{
    cout << "Inserisci un input valido."<<endl;
  }
  }

  //sezione ricette

  //ingredienti
  double farinaInKg;
  int uova = 0;
  double zuccheroInKg;
  double fruttosio;

  //dosaggio A
  if(numeroInvitati>=2&&numeroInvitati<=4){
  farinaInKg = 0.3;
  uova = 4;

  if(diabetici==1){
   // fruttosio = 0.1*0.6666667;
   fruttosio = 0.1 *(2.0/3.0); 
  }else{
    zuccheroInKg = 0.1;
  }
}else if(numeroInvitati>=5&&numeroInvitati<=8){
  farinaInKg = 0.6;
  uova = 8;

  if(diabetici==1){
   // fruttosio = 0.15*0.6666667;
   fruttosio = 0.15*(2.0/3.0); 
  }else{
    zuccheroInKg = 0.15;
  }
}else if(numeroInvitati>=9&&numeroInvitati<=16){
  farinaInKg=0.9;
  uova =12;

  if(diabetici==1){
    //fruttosio = 0.25*0.6666667;
    fruttosio = 0.25*(2.0/3.0); 
  }else{
    zuccheroInKg = 0.25;
  }
}
  cout <<"Farina: "<< farinaInKg <<endl<< "Uova: "<< uova <<endl;
  if(diabetici==1){
    cout<<"Fruttosio: "<<fruttosio<<endl;
  }else{
    cout<<"Zucchero: "<< zuccheroInKg<<endl;
  }
}
