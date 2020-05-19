#include <stdio.h>

int* eg(); //egészre mutató mutatót visszaadó függvény

int main () {

int a; //egész
int* b; //egészre mutató mutató
int* c = &a; //egész referenciája
int d[100]; //egészek tömbbje
int* e = &d[10]; //egészek tömbbjének referenciája (nem az első elemé)
int* pp[100]; //egészre mutató mutatók tömbbje
int* (*eg_pointer) ();//egészre mutató mutatót visszaadó függvényre mutató mutató
int (*egesz (int c3)) (int c1, int c2);//egészet visszaadó és két egészet kapó függvényre mutató mutatót visszaadó, egészet kapó függvény
int (*(*egeszre) (int f3)) (int f1, int f2); //függvénymutató egy egészet visszaadó és két egészet kapó függvényre mutató mutatót visszaadó, egészet kapó függvényre
return 0;
}
