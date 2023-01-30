#include <stdio.h>
#include <stdlib.h>

/*  Membros do Grupo
- Henrique Gualberto Marques / NUSP: 13692380
- João Otávio Cano / NUSP: 11858651
- Pedro Henrique Cruz da Silva / NUSP: 11833236
- Pedro Zambrozi Brunhara / NUSP: 12608664
*/

//Funcao pra calcular o maior entre 2 valores
int maior(int x, int y){

    if (x >= y){
        return x;
    }
    else return y;
}

//funcao recursiva que calcula a melhor rota
int _amigosNoCaminho(int** cache, int** lista, int chave){
    if (cache[chave][0] == -1)
    {
        int res = 0;
        int r1 = 0;
        int r2 = 0;
        if(chave == 0){
            return res;
        }
        int i = 0;
        int j = 0;
        while(lista[i][1] != -1){

            if (lista[i][1] == chave)
            {
                if (j == 0)
                {
                    r1 = lista[i][2] + _amigosNoCaminho(cache, lista, lista[i][0]);
                    j = 1;
                }
                if (j == 1)
                {
                    r2 = lista[i][2] + _amigosNoCaminho(cache, lista, lista[i][0]);
                }
                
            }
            i++;
        }
        cache[chave][0] = maior(r1, r2);
    }
    return cache[chave][0];

}

//funcao com o cache
int amigosNoCaminho(int** lista, int chave, int n_pontos){
    int** cache;
    cache = malloc(sizeof(int*)* n_pontos);
    for (int i = 0; i < n_pontos; i++)
    {
        cache[i] = malloc(sizeof(int));
    }
    for (int i = 0; i < n_pontos; i++)
    {
        cache[i][0] = -1;
    }
    return _amigosNoCaminho(cache, lista, chave);
}

//funcao principal
int main(){

    //coleta de dados
    int linhas, colunas;
    int **lista;

    scanf("%d %d",&linhas, &colunas);

    int n_trajetos;

    n_trajetos = linhas*(colunas-1) + colunas*(linhas-1);

    int n_pontos = linhas*colunas;

    n_trajetos++;

    //alocação de memoria para a matriz a armazenar os dados de rota
    lista = malloc(sizeof(int*)* n_trajetos);

    for (int i = 0; i < n_trajetos; i++)
    {
        lista[i] = malloc(sizeof(int)* 3);
    }
    n_trajetos--;
    for (int i = 0; i < n_trajetos; i++)
    {
        scanf("%d %d %d", &lista[i][0], &lista[i][1], &lista[i][2]);

    }
    
    lista[n_trajetos][1] = -1;

    printf("%d", amigosNoCaminho(lista, (linhas*colunas)-1, n_pontos));

    return 0;
}