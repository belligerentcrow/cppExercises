/*8.Scrivere un metodo che prenda in input una matrice
quadrata di puntatori a stringhe Q ed una stringa s. Il
metodo restituisca il valore booleano true se e solo se
il numero di stringhe che contengono s, presenti nella
diagonale principale di Q, è maggiore del numero di
stringhe che contengono s presenti nella diagonale
secondaria di Q. */

#include <iostream>
#include <string>
using namespace std;


bool funz(string* **Q, int n, string s){
    int countdiag1 =0;
    int countdiag2 =0;
    for(int i =0; i < n; i++){

        if((Q[i][i])&&(*Q[i][i]).find(s)!=string::npos){
            countdiag1++;
        }
        if((Q[i][n-1-i])&&(*Q[i][n-1-i]).find(s)!=string::npos){
            countdiag2++;
        }

    }

    if(countdiag1>countdiag2){
        return true;
    } else{
        return false;
    }
}

#define n 4
int main(){

        cout << "ok";
        string * **Matr = new string **[n];
        for (int i = 0; i < n; i ++) {
         Matr[i] = new string*[n];
            for (int j =0; j < n; j++) {

             Matr[i][j]= new string[1];
            }
        }
        string prova = "bofa";
        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
               *(Matr[i][j]) = "jjjjjj";
        }
        }
        *(Matr[0][0]) = "hbofa";
        //*(Matr[1][1]) = "bofad";
        *(Matr[0][3]) = "ggbofa";
        cout << "Output: "<<funz(Matr, n, prova);
}
