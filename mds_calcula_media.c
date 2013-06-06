#include <stdio.h>
#include "mds_calcula_media.h"

int mds_calcula_media(int* array)
{
    int i;
    int array_size = sizeof(array)/sizeof(int)
    int media = 0;// se o for começa em 0, tu teria somado duas vezes o primeiro
    for (i = 0; i < array_size; i++)
        //media =  (media + array[i]) / 2; isso daria pesos errados pros valores
        media = (media + array[i]);
    return media;
}
