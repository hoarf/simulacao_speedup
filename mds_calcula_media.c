float mds_calcula_media(int* array,int array_size)
{
    int i;
    float media = 0;
    for (i = 0; i < array_size; i++)
    {
        media = (media + array[i]);
        printf("%d\n",array[i]);
    }
    media = media/array_size;
    return media;
}

float mds_calcula_media_arquivo(FILE* arquivo)
{
    printf("Calculando média ...\n");
    int valor, count = 0;
    float media = 0.0;
    while (fscanf(arquivo,"%d", &valor) != EOF)  {
        media = media + valor;
        count++;
    }
    return media/count;
}