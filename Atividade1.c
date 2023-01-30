#include <stdio.h>
#include <stdlib.h>

void troca(int *valor1, int *valor2) //funcao p/ trocar as posicoes de 2 numeros
{
    int auxiliar = *valor1;
    *valor1 =  *valor2;
    *valor2 = auxiliar;

}

void selecao(int *vetor, int tamanho_vetor, FILE *file) //metodo de selecao para ordenar vetores
{
    int auxiliar_min;

    for (int i = 0; i < tamanho_vetor -1; i++)
    {
        auxiliar_min = i;
        for (int j = i+1; j < tamanho_vetor; j++)
        {
            fprintf(file, "C %d %d\n", auxiliar_min, j);
            if (vetor[j] < vetor[auxiliar_min])
            {
                auxiliar_min = j;
            }
        }

        if (auxiliar_min != i)
        {
            troca(&vetor[i], &vetor[auxiliar_min]);
            fprintf(file, "T %d %d\n", i, auxiliar_min);  
        }
    }

}

void bolha(int *vetor, int tamanho_vetor, FILE* file) //metodo bolha para ordenar vetores
{
    int flag;

    for (int i = 0; i < tamanho_vetor -1; i++)
    {
        flag = 0;
        for (int j = 0; j < tamanho_vetor - i - 1; j++)
        {
            fprintf(file, "C %d %d\n", j, j+1);
            if (vetor[j] > vetor[j+1])
            {
                troca(&vetor[j], &vetor[j+1]);
                fprintf(file, "T %d %d\n", j, j+1);
                flag = 1;
            }
            
        }
        if (flag == 0)
        {
            break;
        }
        
        
    }
    
    

}

int main() //funcao principal - utilizei alocacao dinamica
{
    FILE *file;

    file = fopen("texto.txt", "w");

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
        bolha(vetor, tamanho_vetor, file);
        for (int i = 0; i < tamanho_vetor; i++)
        {
            printf("%d ", vetor[i]);
        }
        
    }
    
    if(metodos[0] == 's')
    {
        selecao(vetor, tamanho_vetor, file);
        for (int i = 0; i < tamanho_vetor; i++)
        {
            printf("%d ", vetor[i]);
        }
    }

    free(vetor);
    return 0;
}