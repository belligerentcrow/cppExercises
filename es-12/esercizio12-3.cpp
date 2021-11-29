/*Codificare un programma in linguaggio C++ che chieda
all’utente di inserire da tastiera il proprio nome e cognome.
Successivamente il programma dovrà stampare le seguenti
informazioni:
1. il primo e l’ultimo carattere del nome, il secondo ed il
terzo carattere del cognome.
2. una stringa formata da tutti i caratteri che sono presenti
sia nel nome che nel cognome. ES: se nome=”Mario”,
cognome= ”Rossi” lo output sarà ”io”.*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
  string yourName;
  string surname;
  string name;
  int surnameStart=0;
  cout << "Enter your name"<<endl;
  getline(cin, yourName);
  if(!cin.fail()){
    cout << yourName[0] << yourName[1];
    for(int i=0; i<yourName.length(); i++){
      if(yourName[i]==' '){
        surname = yourName.substr(i,yourName.length()-1);
        name = yourName.substr(0,i);
        surnameStart = i;
        break;
      }
    }
    cout << surname[1]<<surname[2]<<endl;

    for(int i = 0; i<surname.length(); i++){
      for(int j = 0; j<name.length(); j++){
        if(surname[i]==name[j]){
          cout<<name[j];
        }
      }
    }
    cout<<endl; 
    }else{
    cout << "Invalid input!"<<endl;
  }


}
