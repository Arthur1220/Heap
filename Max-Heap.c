#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    //o indice 0 do vetor pode armazenar a altura da arvore
    int *vet;
    int size;
    int cap;
} Heap;

void inicializar(Heap *H, int qtd);
void addMax(Heap *H, int valor);
void swap(int *x, int *y);
void remMax(Heap *H);
void show(Heap *H);

int main(){
    Heap H;

    inicializar(&H, 1);

    int option, valor;

    while(option != 4)
    {
        system("cls");
        printf("    --Max-Heap\n\n");
        printf("[1] - Inserir\n");
        printf("[2] - Remover\n");
        printf("[3] - Mostrar\n");
        printf("[4] - Sair\n");
        printf("\n    -> ");
        scanf("%d", &option);

        switch (option)
        {
        case 1: //INSERIR
            system("cls");
            printf("    --Insira o valor: ");
            scanf("%d", &valor);

            addMax(&H, valor);
            break;

        case 2: //REMOVER
            system("cls");

            remMax(&H);
            break;

        case 3: //MOSTRAR
            show(&H);
            break;

        case 4:
            return 0;
            break;
        
        default:
            system("cls");
            printf("    --Opcao invalida\n");
            system("pause");
            break;
        }
    }

    return 0;
}

void inicializar(Heap *H, int alt)
{
     //tendo a raiz na alt 0
    int qtd = pow(2, (alt+1)) - 1;
    
    H->vet = malloc(qtd * sizeof(int));
    H->cap = alt;
    H->size = 0;
}

void addMax(Heap *H, int valor)
{
    if(H->size == H->cap)
    {
        H->cap++;
        int qtd = pow(2, (H->cap+1)) - 1;

        H->vet = (int*)realloc(H->vet, qtd * sizeof(int));
    }

    int i = H->size;
    H->vet[H->size] = valor;

    //i != 0 quer dizer que chegou ao indice 0, ou seja, na raiz 
    //H->vet[(i-1)/2] < H->vet[i] quer dizer caso o pai seja menor que o filho
    while (i != 0 && H->vet[(i-1)/2] < H->vet[i])
    {
        swap(&H->vet[i], &H->vet[(i-1)/2]);
        i = (i-1)/2;
    }

    H->size++;

    //raiz = (i-1)/2
    //dir = 2*i + 2
    //esq = 2*i + 1
}

void remMax(Heap *H)
{
    H->size--;
    H->vet[0] = H->vet[H->size];

    int i = 0;

    while (i < H->size)
    {
        //esquerda
        if(H->vet[i] < H->vet[(2*i + 1)])
        {
            swap(&H->vet[i], &H->vet[(2*i + 1)]);
            i = (2*i + 1);
        }

        //direita
        if(H->vet[i] < H->vet[(2*i + 2)]){
            swap(&H->vet[i], &H->vet[(2*i + 2)]);
            i = (2*i + 2);
        }
        
        return;
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void show(Heap *H)
{
    int i;

    system("cls");
    printf("    --Heap\n");

    printf("Size: %d\n", H->size);
    printf("Altura: %d\n", H->cap);
    printf("Capacidade Max: %d\n", pow(2, (H->cap+1)) - 1);

    for(i=0; i<H->size; i++)
        printf("%d  ", H->vet[i]);

    printf("\n");
    system("pause");
}