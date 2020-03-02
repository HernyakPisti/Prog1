#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int sz=10,m=10,a=1,b=1;
#define SZG 50
#define MG 20
int falsz[SZG];
int falm[MG];
void palya(){
system("clear"); //letöröljük az ablakot hogy jól látszódjon a pálya
for (int i=0;i<(SZG+2);i++) //megrajzoljuk az első sort
	printf("X");
	printf("\n");
for (int i=0;i<m;i++){ //megrajzoljuk a sorokat addig a sorig amíg nem kell a labdát
	printf("X");
		for (int j=1;j<(SZG+1);j++)
		printf(" ");
	printf("X\n");
}		//megrajzoltuk a ladba előtti sort
printf("X");	//a labdát tartalmazó sor bal oszlopi X-je 
for (int i=0;i<sz;i++) //a sort addig töltjük fel " "-kel amíg nem kell magát a labdát megrajzolni
	printf(" ");
printf("X"); 	//labda kirajzolása
for (int i=(sz+1);i<SZG;i++) //a labda után feltöltjük a sort " "-kel
	printf(" ");
printf("X\n"); //labdát tartlmazó sor vége
for (int i=m+1;i<MG;i++){ //labda utáni sorok rajzolásának kezdete
	printf("X");
		for (int j=1;j<(SZG+1);j++)
		printf(" ");
	printf("X\n");
}		//utolsó előtti sorig való megrajzolás 
for (int i=0;i<(SZG+2);i++) //megrajzoljuk az utolsó sort
	printf("X");
	printf("\n");
}
void mozdulj(){
if (sz==SZG-1) a=-1;
if (sz==0) a=1;
sz=sz+a; //labdá helyzetetét növeljük
if (m==MG-1) b=-1;
if (m==0) b=1;
m=m+b; //labdá helyzetetét növeljük
}

int main(){
while(free){
palya();
mozdulj();
usleep(60000); //látszódjon a labda rendesen ne okozzon Parkinson kórt
}
}
