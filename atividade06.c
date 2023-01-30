#include <stdio.h>
#include <stdlib.h>

int shell(int v[], int n) {
    
    int cmp = 0, cpy = 0;

    int gap = 1;

    while(gap <= n) {

        gap *= 2;

    }

    gap = gap / 2 - 1;

    while(gap > 0) {

            for (int i = gap; i < n; i+=gap){

                int x = v[i];
                cpy++;

                int j = i - gap;

        //if (j >= 0)
        //{
          //  cpy ++;
        //}
        
        while (j >= 0 && v[j] > x) {
            v[j+gap] = v[j];
            j -= gap;
            cpy++;
            cmp++;
        }
        if(j >= 0 ) cmp++; 
        v[j+gap] = x;
        cpy++;
        }

        gap /= 2;
    }
    return cmp+cpy;
}

void quick(int v[], int f, int l, int *vetorSoma) 
{
    if (f >= l) {

        return;

    }

        int m = (l + f)/2;

        int pivot = v[m];
        vetorSoma[0]+=1;

        int i = f;

        int j = l;

        while(1) {
                
                while(v[i] < pivot) {

                        i++;
                        vetorSoma[0]+=1;

                }
                vetorSoma[0]+=1;
                vetorSoma[0]+=1;
                while(v[j] > pivot) {

                        j--;
                        vetorSoma[0]+=1;

                }

                if (i >= j) {

                    break;

                }

                int aux = v[i];

                v[i] = v[j];

                v[j] = aux;

                vetorSoma[0]+=3;

                i++;

                j--;

        }

        quick(v, f, j, vetorSoma);

        quick(v, j+1, l, vetorSoma);
}

int* criarVetor(int* vetor, int* subvetor, int tamanho)
{

    subvetor = calloc(tamanho, sizeof(int));

    for (int i = 0; i < tamanho; i++)
    {
        subvetor[i] = vetor[i];
    }

    return subvetor;
    
}

int main()
{

    int entrada, count_shell, count_quick;
    int *vetor;
    int *vetorSoma;

    scanf("%d", &entrada);

    vetor = calloc(entrada, sizeof(int));

    for (int i = 0; i < entrada; i++)
    {
        scanf("%d", &vetor[i]);
    }

    vetorSoma = calloc(entrada, sizeof(int));
    
    for (int i = 1; i <= entrada; i++)
    {
        int *subvetor1 = criarVetor(vetor, subvetor1, i);
        int *subvetor2 = criarVetor(vetor, subvetor2, i);

        count_shell = shell(subvetor1, i);

        //printf("%d ", count_shell);

        quick(subvetor2, 0, i-1, vetorSoma);

        count_quick = vetorSoma[0];

        //printf("%d ", count_quick);

        if (i == entrada)
        {
            if (count_shell == count_quick)
        {
            printf("-");
        }

        else if (count_shell < count_quick)
        {
            printf("S");
        }

        else if (count_shell > count_quick)
        {
            printf("Q");
        }
        }

        else
        {
            if (count_shell == count_quick)
        {
            printf("- ");
        }

        else if (count_shell < count_quick)
        {
            printf("S ");
        }

        else if (count_shell > count_quick)
        {
            printf("Q ");
        }
        }
        

        vetorSoma[0] = 0;

        free(subvetor1);
        free(subvetor2);
    }
    

    return 0;
}