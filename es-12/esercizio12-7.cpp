/*Tre vasche A, B e C raccolgono acqua da 15 tubi differenti.

• La vasca A riceve l’acqua convogliata nei tubi 1,5,6,10.
• La vasca B riceve l’acqua convogliata nei tubi da 2 a 4 e da 7
    a 9.
• La vasca C riceve l’acqua convogliata nei rimanenti tubi.
    Inoltre, i tubi con numero dispari hanno una portata di 60 litri al
    minuto, mentre quelli con numero pari hanno una portata di 120
    litri al minuto.

Codificare un programma in linguaggio C++ che esegua le seguenti
operazioni:
• il programma chiede in input all’utente 5 numeri distinti, compresi
    tra 1 e 15. Tali numeri rappresentano 5 differenti tubi. NB: il
    programma deve operare un controllo sulla validità dell’input (ad
    esempio che i numeri siano tutti differenti tra loro);
• il programma chiede all’utente il numero totale di minuti (M)
    durante i quali i tubi specificati forniranno acqua alla rispettiva
    vasca. NB: il programma deve operare un controllo sulla validità
    dello input, ad esempio che il numero immesso sia positivo.
• il programma calcola e stampa la quantità d’acqua raccolta in ogni
    vasca dopo gli M minuti specificati dall’utente. */

//Tre vasche, 15 tubi
//A = 1, 5, 6, 10
//B = 2, 3, 4, 7, 8, 9
//C = 11, 12, 13, 14, 15
//tubi pari = 60L/m
//tubi dispari = 120L/m
//Input controllato i1 i2 i3 i4 i5 - 5 numeri tra 1 e 15 diversi fra loro
//Input positivo controllato M - numero minuti durante i quali
//l'acqua va in vasca
//Output: Quantità d'acqua nelle vasche dopo gli M minuti

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main(){
  int A=0, B=0, C=0;   //vasche
  int i1=0, i2=0, i3=0, i4=0, i5=0; //tubi scelti
  int M=0;  //minuti
  const int velDispari = 60;
  const int velPari = 120; //costanti velocità
  bool inputCorretto = 0; //uno strumentopolo che ci servirà più tardi
  int arrayTubi[6]= {};

  while(inputCorretto == 0){      //metto in un while tutti gli inputs dei tubi. In realtà è un po' ridondante dato che controllo ogni while, ma meglio essere certi
    cout<<"Inserisci 5 numeri diversi fra loro compresi tra 1 e 15."<<endl;
    while(i1==0){
      cout << "Numero 1: ";
      cin >>i1;
      if(i1>15||i1<1||cin.fail()){  //controllo che l'utente non inserisca cretinate
        cin.clear();
        cin.ignore(); //se le ha inserite non lo/la faccio uscire dal while del numero del tubo scelto e azzero la variabile
        i1=0;
        cout << "Inserisci un numero tra 1 e 15. "<<endl;
      }else{
        arrayTubi[1]=i1; //se il numero è accettabile, metto il numero del tubo scelto in questo array. Inizio da 1 e non da 0 cosicché quadri per le operazioni di dopo.
      }                  //essenzialmente questo array avrà l'indice 0 vuoto, ma va bene così, perché nel loop con cui controllo tutto più tardi inizio a "controllarlo"
                        //direttamente dall'indice 1.
                        //Riempio l'array in "rappresentazione estesa" --> Vedi strutture discrete, parte 1, slide 106
    }
    while(i2==0){
      cout << "Numero 2: ";
      cin >>i2;
      if(i2>15||i2<1||cin.fail()||i2==i1){ // <--------------
        cin.clear();
        cin.ignore();
        i2=0;
        cout << "Inserisci un numero tra 1 e 15, diverso da i1. "<<endl;
      }else{
        arrayTubi[2]=i2;
      }
    }
    while(i3==0){
      cout << "Numero 3: ";
      cin >>i3;
      if(i3>15||i3<1||cin.fail()||i3==i1||i3==i2){ //<---------------
        cin.clear();
        cin.ignore();
        i3=0;
        cout << "Inserisci un numero tra 1 e 15, diverso da i1 e da i2. "<<endl;
      }else{
        arrayTubi[3]=i3;
      }
    }
    while(i4==0){
      cout << "Numero 4: ";
      cin >>i4;
      if(i4>15||i4<1||cin.fail()||i4==i1||i4==i2||i4==i3){
        cin.clear();
        cin.ignore();
        i4=0;
        cout << "Inserisci un numero tra 1 e 15, diverso da i1, i2 e i3. "<<endl;
      }else{
        arrayTubi[4]=i4;
      }
    }

    while(i5==0){
      cout << "Numero 5: ";
      cin >>i5;
      if(i5>15||i5<1||cin.fail()||i5==i1||i5==i2||i5==i3||i5==i4){
        cin.clear();
        cin.ignore();
        i5=0;
        cout << "Inserisci un numero tra 1 e 15, diverso da i1, i2, i3, e i4. "<<endl;
      }else{
        arrayTubi[5]=i5;
      }
    }
    inputCorretto=1;
  }           //era possibile rendere questi loops meno ridondanti? probabilmente. Ma per adesso va bene così

  inputCorretto=0;  //azzero questa bool perché la uso di nuovo per controllare che l'input-minuti sia corretto
  while(inputCorretto==0){
    cout<<"Inserisci il numero di minuti per i quali l'acqua deve scorrere"<<endl;
    cin>>M;
    if(M<1||cin.fail()){ //uso la stessa tecnica di prima per assicurarmi che l'utente non inserisca cretinate
      cin.clear();
      cin.ignore();
      M=0;
      cout<<"Inserisci un numero positivo."<<endl;
    }else{
      inputCorretto=1; //così si può uscire dal loop
    }
  }

  for(int i = 1; i<6; i++){   //loop in cui riempio le vasche
    if(arrayTubi[i]==1||arrayTubi[i]==5||arrayTubi[i]==6||arrayTubi[i]==10){  //controllo prima la vasca
      A = A + (arrayTubi[i]%2==0 ? velPari*M : velDispari*M);             //e poi se il tubo è pari o dispari, e a seconda di qual è metto la giusta quantità d'acqua
      cout << "A - Arriva acqua dal tubo numero " << arrayTubi[i] << "."<<" A = "<<A<<endl;  //controllo se sta facendo quello che deve fare

    }else if(arrayTubi[i]==2||arrayTubi[i]==3||arrayTubi[i]==4||arrayTubi[i]==7||arrayTubi[i]==8||arrayTubi[i]==9){
      B = B + (arrayTubi[i]%2==0 ? velPari*M : velDispari*M);
        cout <<"B - Arriva acqua dal tubo numero " << arrayTubi[i] << "."<<" B = "<<B<<endl;

    }else{
      C = C+(arrayTubi[i]%2==0 ? velPari*M : velDispari*M);
      cout <<"C - Arriva acqua dal tubo numero " << arrayTubi[i] << "."<<" C = "<<C<<endl;;
    }

  }
  /* for(int i = 0; i<6; i++){
    cout << arrayTubi[i]<<" ";  //eventualmente decommentare per stampare l'array dove ho messo il numero dei tubi, ma funziona
  } */                          //l'indice 0 è a 0. Parto a contare da 1 per facilitare la corrispondenza tra indice e numero di tubo.
  cout << endl;
  cout << "La vasca A contiene "<< A <<" litri."<<endl;
  cout << "La vasca B contiene "<< B <<" litri."<<endl;
  cout << "La vasca C contiene "<< C <<" litri."<<endl;

}
