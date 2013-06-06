#include <stdio.h>

int mds_calcula_media(int* array, int array_size)
{
    int i;
    int media = array[0];
    for (i = 0; i < array_size; ++i)
        media =  (media + array[i]) / 2;
    return media;
}
