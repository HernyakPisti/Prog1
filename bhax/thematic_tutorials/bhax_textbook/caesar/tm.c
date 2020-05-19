#include <stdlib.h>
#include <stdio.h>
int main(){

double **tm;
int nr=5;

if((tm = (double**) malloc (nr*sizeof(double*)))==NULL)
	return -1;

for (int i=0; i<nr; ++i){
	if((tm[i]=(double*) malloc((i+1)*sizeof(double)))==NULL){
		free (tm);
		return -1;
	}
}

for (int i=0; i<nr;++i){
	for (int j=0;j<i+1;++j)
		tm [i][j] = i +j;
}

for (int i=0; i<nr;++i){
	for (int j=0; j<i+1;++j)
		printf("%f\t",tm[i][j]);
	printf("\n");
}

for (int i=0; i<nr;++i){
	free(tm[i]);	
}
	free(tm);
	return 0;

}