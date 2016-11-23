#ifndef SarasasGuard
#define SarasasGuard
#include <stdio.h>
#include <stdlib.h>

typedef struct Sarasas Sarasas;

struct Sarasas{
    Sarasas *sekantis;
    int skaicius;
};

int prideti(Sarasas **sr, int reiksme);//grazina 0 jeigu ivyko klaida, 1 jeigu viskas gerai
void atspausdinti(Sarasas *sr);
int istrinti(Sarasas **sr, int index); // grazina 0 jeigu blogas indeksas, 1 jeigu viskas gerai
double vidurkis(Sarasas *sr, int *n);
int iterpti(Sarasas **sr, int reiksme, int vieta); // grazina 0 jeigu nerado reikiamos vietos, 1 jeigu viskas gerai
int gauti_elementa (Sarasas **sr, int vieta);
void naikinti (Sarasas **sr);
void sukurti (Sarasas **sr);
double vidurkisRek (Sarasas *sr, int *n);
#endif
