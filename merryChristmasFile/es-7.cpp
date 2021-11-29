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
	int counterinterno = 0; 
	int counteresterno = 0; 
	for(int i =0; i < n; i++){
		counter =0; 
		for(int j = 0; j < m-1; j++){ //gira per colonne
			if(*(A[j][i]!=nullptr && *(A[j+1][i]!=nullptr){
			primoel = (double) *(A[j][i]); 
			secondoel = (double) *(A[j+1][i]); 
			rapporto = primoel / secondoel; 
			if(rapporto>d1&&rapporto<d2){
			counterinterno++; 
			}
			
			}

		}
		if(counterinterno>=s){
		counteresterno++; 
		}
	}
	return counteresterno; 
}
