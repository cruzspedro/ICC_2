#include <stdio.h>
#include <stdlib.h>

void troca(int *valor1, int *valor2) //funcao p/ trocar as posicoes de 2 numeros
{
    int auxiliar = *valor1;
    *valor1 =  *valor2;
    *valor2 = auxiliar;

}

void selecao(int *vetor, int tamanho_vetor) //metodo de selecao para ordenar vetores
{
    int auxiliar_min;

    for (int i = 0; i < tamanho_vetor -1; i++)
    {
        auxiliar_min = i;
        for (int j = i+1; j < tamanho_vetor; j++)
        {
            printf("C %d %d\n", auxiliar_min, j);
            if (vetor[j] < vetor[auxiliar_min])
            {
                auxiliar_min = j;
            }
        }

        if (auxiliar_min != i)
        {
            troca(&vetor[i], &vetor[auxiliar_min]);
            printf("T %d %d\n", i, auxiliar_min);  
        }
    }

}

void bolha(int *vetor, int tamanho_vetor) //metodo bolha para ordenar vetores
{
    int aux = tamanho_vetor - 1;
    int ultimo;
    while (aux != 0)
    {
        ultimo = 0;

        for (int i = 0; i < aux; i++)
        {
            printf( "C %d %d\n", i, i+1);

            if (vetor[i] > vetor[i+1])
            {
                troca(&vetor[i], &vetor[i+1]);
                printf("T %d %d\n", i, i+1);
                ultimo = i;
            }
            
        }
        
        aux = ultimo;

    }
    

}

int main() //funcao principal - utilizei alocacao dinamica
{

    int *vetor;

    int tamanho_vetor;

    char metodos[8];

    scanf("%s", metodos);

    scanf("%d", &tamanho_vetor);

    vetor = (int*) calloc(tamanho_vetor, sizeof(int));

    for (int i = 0; i < tamanho_vetor; i++)
    {
        scanf("%d", &vetor[i]);
    }
    

    if (metodos[0] == 'b')
    {
        bolha(vetor, tamanho_vetor);
        for (int i = 0; i < tamanho_vetor; i++)
        {
            printf("%d ", vetor[i]);
        }
        
    }
    
    if(metodos[0] == 's')
    {
        selecao(vetor, tamanho_vetor);
        for (int i = 0; i < tamanho_vetor; i++)
        {
            printf("%d ", vetor[i]);
        }
    }

    free(vetor);
    return 0;
}