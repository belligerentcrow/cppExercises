/*2.Due stringhe si dicono sorelle se hanno lo stesso
numero di vocali. Scrivere un metodo che prenda in
input una matrice A di puntatori a stringhe, e
restituisca un boolean che indichi se esiste una
colonna di A in cui sono puntate almeno due stringhe
sorelle.*/

bool funz(string **A, int n, int m){
	int counter[n]={}; 
	short checker =0; 
	for(int i = 0; i < n; i++){
		checker ; 
		for(int j =0; j<m; j++){
			counter =0; 
			for(int z = 0; z<n-1; z++){
			switch(*(A[i][j])[z]){
				case 'A':
				case 'E':
				case 'I':
				case 'O':
				case 'U':
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					counter++;
				       break; 	
			}
				
			}
			checker[j] = counter;
			

	}
		for(int k =0; k<n; k++){
			for(int y =k+1; y <n; y++){
			if(checker[y]==checker[k]){
				return true;
			}
			}
		}
	
	}
return false; 
}
