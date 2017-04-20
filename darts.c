#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int m, n, k;
    char *kek = (char*)calloc(10000, sizeof(int));
    scanf("%d %d", &m, &n);
	int *a=(int*)malloc(100000*sizeof(int)); 
    char **Mas=(char**)malloc(n*sizeof(char*));
    for(int i = 0; i < n; i++){
		Mas[i]=(char*)malloc(100000*sizeof(char));
        scanf("%s %d", Mas[i], &a[i]);
    }
    for( int i = 0; i < n; i++){
		for(int j = 1; j < n; j++){
			if( strcmp (Mas[i], Mas[j]) == 0 && a[i] < a[j] ){
				k = a[n-1];
				a[n-1] = a[i];
				a[i] = k;
				strcpy(kek, Mas[n-1]);
				strcpy(Mas[n-1], Mas[i]);
				strcpy(Mas[i], kek);
				n = n - 1;
			}
			if( strcmp (Mas[i], Mas[j]) == 0 && a[i] > a[j] ){
				k = a[n-1];
				a[n-1] = a[j];
				a[j] = k;
				strcpy(kek, Mas[n-1]);
				strcpy(Mas[n-1], Mas[j]);
				strcpy(Mas[j], kek);
				n = n - 1;
			}
		}
	}
	for( int i = 0; i < n; i++){
		for(int j = 1; j < n; j++){
			if( a[i] < a[j] ){
				k = a[i];
				a[i] = a[j];
				a[j] = k;
				strcpy(kek, Mas[i]);
				strcpy(Mas[i], Mas[j]);
				strcpy(Mas[j], kek);
			}
		}
	}
	for( int i = 0; i < m; i++){
		printf("%s %d\n", Mas[i], a[i]);
	}
	return 0;
}
