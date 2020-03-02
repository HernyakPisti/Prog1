#include <stdio.h>

int main()
{
    int a, b;
    printf("Add meg az a erteket: "); 
    scanf("%d", &a);//a=10
    printf("Add meg a b erteket: ");
    scanf("%d", &b);//b=5
    a=a+b; //a=15 b=5
    b=a-b;//a=15 b=10
    a=a-b;//a=5 b=10
    printf("a: %d	b: %d\n",a,b);
    a=a*b;//a=50 b=10
    b=a/b;//a=50 b=5
    a=a/b;//a=10 b=5
    printf("a: %d	b: %d\n",a,b);
    return 0;
}


