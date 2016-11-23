#include "Sarasas.h"

void sukurti (Sarasas **sr)
{
    *sr = NULL;
}

int prideti(Sarasas **sr, int reiksme)
{
    Sarasas *tmp = NULL;

    tmp = *sr;
    if ( tmp == NULL)
    {
        tmp = (Sarasas *) malloc(sizeof(Sarasas));
        if (tmp == NULL)
        {
            return 0;
        }
        tmp -> sekantis = NULL;
        tmp -> skaicius = reiksme;
        *sr = tmp;
        return 1;
    }

    while (tmp -> sekantis != NULL)
    {
        tmp = tmp -> sekantis;
    }
    tmp -> sekantis = (Sarasas *) malloc(sizeof(Sarasas));
    if (tmp -> sekantis == NULL)
    {
        puts("Nepaviko iskirti vietos");
        return 0;
    }
    tmp = tmp -> sekantis;
    tmp -> skaicius = reiksme;
    tmp -> sekantis = NULL;

}

void atspausdinti(Sarasas *sr)
{
    Sarasas *tmp;

    tmp = sr;
    while (tmp != NULL)
    {
        printf("%d ", tmp -> skaicius);
        tmp = tmp -> sekantis;

    }
}

int istrinti(Sarasas **sr, int index)
{
    Sarasas *sar;
    Sarasas *tmp;
    int i;

    if (index <= 0)
    {
        return 0;
    }
    sar = *sr;
    if (index == 1)
    {
        tmp = sar;
        sar = tmp -> sekantis;
        free(tmp);
        *sr = sar;
        return 1;
    }
    for (i = 0; i<index-1; i++)
    {
        if ( sar -> sekantis == NULL)
        {
            return 0;
        }
        tmp = sar;
        sar = sar -> sekantis;
    }
    sar = tmp ;
    tmp = tmp -> sekantis;
    sar -> sekantis = tmp -> sekantis;
    //tmp = NULL;
    free(tmp);
    return 1;
}

double vidurkis(Sarasas *sr, int *n)
{
    *n = 0;
    return vidurkisRek(sr,n);
}

int iterpti(Sarasas **sr, int reiksme, int vieta)
{
    Sarasas *sar;
    Sarasas *tmp;
    int i;

    if (vieta <= 0)
    {
        return 0;
    }
    sar = *sr;
    if (vieta == 1)
    {
        tmp = (Sarasas *) malloc(sizeof(Sarasas));
        tmp -> sekantis = *sr;
        tmp -> skaicius = reiksme;
        *sr = tmp;
        return 1;
    }
    if (*sr == NULL)
    {
        return 0;
    }

    for (i=2; i < vieta ; i++)
    {
        if ((sar -> sekantis == NULL) )
        {
            return 0;
        }
        sar = sar -> sekantis;
    }
    tmp = (Sarasas *) malloc(sizeof(Sarasas));
    tmp -> skaicius = reiksme;
    tmp -> sekantis = sar -> sekantis;
    sar -> sekantis = tmp;
    return 1;
}

int gauti_elementa (Sarasas **sr, int vieta)
{
    Sarasas *sar;

    int i;

    if ((vieta <= 0) || (*sr == NULL))
    {
        return 0;
    }

    sar = *sr;

    for (i = 1; i < vieta; i++)
    {
        if ((sar -> sekantis == NULL) )
        {
            return 0;
        }
        sar = sar -> sekantis;
    }
    return sar -> skaicius;
}

void naikinti (Sarasas **sr)
{
    Sarasas *tmp = NULL;
    while (*sr != NULL)
    {
        tmp = *sr;
        *sr = (*sr) -> sekantis;
        free(tmp);
    }
}

double vidurkisRek (Sarasas *sr, int *n)
{
    double sum;
    Sarasas *tmp;
    (*n)++;
    if ( sr -> sekantis == NULL)
    {
        return (double)sr -> skaicius/ *n;
    }
    tmp = sr -> sekantis;
    sum = (double) vidurkisRek( tmp , n);
    sum = (double)sum + (double)sr -> skaicius / *n;
    return sum;
}
