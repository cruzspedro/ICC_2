#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  Membros do Grupo
- Henrique Gualberto Marques / NUSP: 13692380
- João Otávio Cano / NUSP: 11858651
- Pedro Henrique Cruz da Silva / NUSP: 11833236
- Pedro Zambrozi Brunhara / NUSP: 12608664
*/

//Prints no meio do código em formato de comentário são para testes :)

//Retorna os primeiros n_chars da str
char* comecoStr(char* str, int n_chars){
    if (n_chars == 0)
    {
        return NULL;
    }
    
    char* aux;
    aux = malloc(1000);
    memcpy(aux, str, n_chars);
    return aux;
}

//Retorna os últimos n_chars da str
char* fimStr(char* str, int n_chars){
    if (n_chars == 0)
    {
        return NULL;
    }
    int aux;
    aux = strlen(str) - n_chars;
    return str+aux;
}

//Funcao que, ao usar lista auxiliar, exclui os itens a serem concatenados e adiciona o aglomerado ao inicio da lista
void arrumaLista(char** lista, int dest, int pos, int tam_lista){
    
    char** lista_aux;
    lista_aux = malloc(sizeof(char*) * tam_lista);
    lista_aux[0] = malloc(1000);
    strcpy(lista_aux[0], lista[dest]);
    int aux = 1;
    for (int i = 0; i < tam_lista; i++)
    {
        if (i != dest && i != pos)
        {
            lista_aux[aux] = malloc(1000);
            strcpy(lista_aux[aux], lista[i]);
            aux++;
        }
        
    }
    for (int i = 0; i < tam_lista - 1; i++)
    {
        strcpy(lista[i], lista_aux[i]);
    }
    free(lista_aux);
}

//funcao recursiva que concatena as strings no melhor aglomerado possível
void overlap(char** lista, int tam_lista){

    if (tam_lista == 1)
    {
        return;
    }

    //[0] = overlap, [1] = pos dest, [2] = pos source, [3] = tipo de aglomeracao
    int resultado_final[4] = {0, 0, 0, 0};

    //laço pra andar na lista, pegando todas as combinações de 2 strings
    for (int i = 0; i < tam_lista; i++)
    {
        for (int j = 0; j < tam_lista; j++)
        {
            //Não adianta fazer overlap de uma palavra com ela mesma :)
            if (i != j)
            {
                //resultado da iteração
                int resultado_parcial = 0;
                //usado para incrementar algum valor no ponteiro da string, lendo, portanto, 1 letra à frente
                int avanco = 0;
                //a ideia do código é achar uma aglomeração em algum dos 2 estágios possíveis descritos abaixo
            
                //caso 1, quando a string2 está dentro da string1
                while (strlen(lista[i]+avanco) >= strlen(lista[j])){
                    if(strstr(lista[i] + avanco, lista[j]) != NULL){
                        resultado_parcial = strlen(lista[j]);
                        if (resultado_parcial > resultado_final[0])
                        {
                            resultado_final[0] = resultado_parcial;
                            resultado_final[1] = i;
                            resultado_final[2] = j;
                            resultado_final[3] = 1;
                        }
                    }
                    avanco++;
                }
                int aux2 = strlen(lista[j]);
                //caso 2, quando a string2 está após a string1
                while(aux2 >= 1){
                    if (strstr(fimStr(lista[i], aux2), comecoStr(lista[j],aux2)) != NULL)
                    {
                        resultado_parcial = aux2;
                        if (resultado_parcial > resultado_final[0])
                        {
                            resultado_final[0] = resultado_parcial;
                            resultado_final[1] = i;
                            resultado_final[2] = j;
                            resultado_final[3] = 2;
                        }
                    }
                    aux2--;
                }

            continue;   
            }  
        }
    }
    //coleta de  resultados

    //se não houve nenhuma aglomeração, entende-se que não há mais o que fazer, apenas aglomerar tudo como puder
    if (resultado_final[0] == 0)
    {
        for (int i = 1; i < tam_lista; i++)
        {
            strcat(lista[0], lista[i]);
            
        }
        return;
    }
    else{
        //caso 1
        if (resultado_final[3] == 1){
            //printf("%d\n", resultado_final[3]);
            //printf("%s %s\n", lista[resultado_final[1]], lista[resultado_final[2]]);
            arrumaLista(lista, resultado_final[1], resultado_final[2], tam_lista);
            //printf("%s\n", lista[0]);
            overlap(lista, tam_lista-1);
        }
        //caso 2
        if (resultado_final[3] == 2){
            //printf("%d\n", resultado_final[3]);
            //printf("%s %s\n",lista[resultado_final[1]], lista[resultado_final[2]]);
            strcat(lista[resultado_final[1]], lista[resultado_final[2]]+resultado_final[0]);
            arrumaLista(lista, resultado_final[1], resultado_final[2], tam_lista);
            //printf("%s\n", lista[0]);
            overlap(lista, tam_lista-1);
        }
    } 

}

//funcao principal: coleta de dados e chamada de funções declaradas anteriormente
int main(){

    int tam_lista;

    scanf("%d", &tam_lista);

    char **lista;

    lista = malloc(sizeof(char*)*tam_lista);

    //alocando memoria para as "palavras"
    for (int i = 0; i < tam_lista; i++)
    {   //máximo de 1000 caracteres. Não por palavra em si, mas no total MESMO.
        lista[i] = malloc(1000);
        scanf("%100s", lista[i]);
    }

    //printf("\n\n");

    overlap(lista, tam_lista);

    printf("%s\n", lista[0]);

    //desalocando a memoria
    free(lista);
    
    return 0;
}