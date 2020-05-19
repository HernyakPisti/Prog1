#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int f(int x, int y){
return x+y;
}

int g(int x){
return x*2;
}

int h(int* x){
return *x;
}

void jelkezelo(){
printf("\nJel érkezett\n");
exit(0);
}

int main(){
if (signal(SIGINT, jelkezelo)==SIG_IGN)
	signal(SIGINT, SIG_IGN);

int tomb[10];
int dt[40], st[40];
int *s=st;
int *d=dt;
int n=40;
int a=5;
int i=0;
for (i=0;i<5;++i)
	printf("%d\n",i);

for (i=0;i<5;i++)
	printf("%d\n",i);


for(i=0;i<5;tomb[i]=i++)
	printf("%d\n", tomb[i]);

for(i=0; (i<n && (*d++=*s++));i++)
	printf("%d\n", i);

printf("%d %d\n", f(a, ++a), f(++a, a));

printf("%d %d\n", g(a), a);

printf("%d %d\n", h(&a),a);

for(;;){}
return 0;

}
