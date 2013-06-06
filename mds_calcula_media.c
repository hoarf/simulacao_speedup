#include <stdio.h>
#include "mds_calcula_media.h"

float mds_calcula_media(int* array,int array_size)
{
    int i;
    float media = 0;// se o for começa em 0, tu teria somado duas vezes o primeiro
    for (i = 0; i < array_size; i++)
    {
        media = (media + array[i]);
        printf("%d\n",array[i]);
    }
    media = media/array_size;
    return media;
}
