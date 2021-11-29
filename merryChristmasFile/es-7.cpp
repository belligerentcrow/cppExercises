/*7.Scrivere un metodo che prenda in input un
parametro formale matrice A di puntatori ad interi di
dimensione nxm, due double d1 e d2 ed uno short s, e
restituisca il numero di colonne di A nelle quali
esistano almeno s coppie di elementi contigui (ES:
A[1][1] e A[2][1]) tali che il rapporto tra il primo ed il
secondo elemento sia compreso tra d1 e d2. NB: Si
assuma a priori che s<=n-1 e che d1 < d2. Si presti
attenzione ai numeri "mancanti"nella matrice A.*/

int funz(int * **A, int n, int m, double d1, double d2, short s){
	int primoel =0;
	int secondoel =0;
       	double rapporto = 0.0; 	
	int counterinterno = 0;  //Contatore per segnare i contigui di ogni colonna, si azzera al loop
	int * counteresterno = new int;  //Contatore del numero di colonne, che "verrà ritornato"
	
	for(int i =0; i < n; i++){
		counter =0; //azzero il contatore prima di una nuova colonna
		for(int j = 0; j < m-1; j++){ //m-1 perché sennò controllerebbe l'elemento m-esimo, che è maggiore dell'indice max, m-1
			
			   if(*(A[j][i])!=nullptr && *(A[j+1][i])!=nullptr){ //controllo per eventuali puntatori nulli in A
			        primoel = (double) *(A[j][i]); //Scrivendo A[j][i] "giro la matrice per colonne" 
			        secondoel = (double) *(A[j+1][i]); //typecasting per confronto con i double e per fare il rapporto 
				
			   rapporto = primoel / secondoel; 
		           
		           if(rapporto>d1&&rapporto<d2){ //controllo che il rapporto sia compreso tra i due (non inclusi, testo non lo specifica)
				counterinterno++;  //<-- Coppie di contigui in una colonna
			   }
			
			}//chiudo if esterno

		}//chiudo for interno
		if(counterinterno>=s){ //controllo il requisito
		counteresterno++; //incremento il numero di colonne che soddisfano il requisito
		}
	}//chiudo il loop esterno
	return counteresterno; 
}
