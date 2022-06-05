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

//funcoes gerais
void inicializar(Heap *H, int qtd);
void swap(int *x, int *y);
void show(Heap *H);

//funcoes para a Max-Heap
void menuMax();
void addMax(Heap *H, int valor);
void remMax(Heap *H);

//funcoes para a Min-Heap
void menuMin();
void addMin(Heap *H, int valor);
void remMin(Heap *H);

int main()
{
    int option;

    while(option != 3)
    {
        system("cls");
        printf("    --Heap\n\n");
        printf("[1] - Max-Heap\n");
        printf("[2] - Min-Heap\n");
        printf("[3] - Sair\n");
        printf("\n    -> ");
        scanf("%d", &option);

        switch (option)
        {
        case 1: //direciona para o menu da Max-Heap
            system("cls");
            menuMax();
            break;

        case 2: //direciona para o menu da Min-Heap
            system("cls");
            menuMin();
            break;

        case 3: //SAIR
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

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void show(Heap *H)
{
    int i, cap = pow(2, (H->cap+1)) - 1;

    system("cls");
    printf("    --Heap\n");

    printf("Size: %d\n", H->size);
    printf("Altura: %d\n", H->cap);
    printf("Capacidade Max: %d\n", cap);

    for(i=0; i<H->size; i++)
        printf("%d  ", H->vet[i]);

    printf("\n");
    system("pause");
}

void menuMax()
{
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
}

void addMax(Heap *H, int valor)
{
    if(H->size == pow(2, (H->cap+1)) - 1)
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

void menuMin()
{
    Heap H;

    inicializar(&H, 1);

    int option, valor;

    while(option != 4)
    {
        system("cls");
        printf("    --Min-Heap\n\n");
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

            addMin(&H, valor);
            break;

        case 2: //REMOVER
            system("cls");

            remMin(&H);
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
}

void addMin(Heap *H, int valor)
{
    if(H->size == pow(2, (H->cap+1)) - 1)
    {
        H->cap++;
        int qtd = pow(2, (H->cap+1)) - 1;

        H->vet = (int*)realloc(H->vet, qtd * sizeof(int));
    }

    int i = H->size;
    H->vet[H->size] = valor;

    //i != 0 quer dizer que chegou ao indice 0, ou seja, na raiz 
    //H->vet[(i-1)/2] < H->vet[i] quer dizer caso o pai seja menor que o filho
    while (i != 0 && H->vet[(i-1)/2] > H->vet[i])
    {
        swap(&H->vet[i], &H->vet[(i-1)/2]);
        i = (i-1)/2;
    }

    H->size++;

    //raiz = (i-1)/2
    //dir = 2*i + 2
    //esq = 2*i + 1
}

void remMin(Heap *H)
{
    H->size--;
    H->vet[0] = H->vet[H->size];

    int i = 0;

    while (i < H->size)
    {
        //esquerda
        if(H->vet[i] > H->vet[(2*i + 1)])
        {
            swap(&H->vet[i], &H->vet[(2*i + 1)]);
            i = (2*i + 1);
        }

        //direita
        if(H->vet[i] > H->vet[(2*i + 2)]){
            swap(&H->vet[i], &H->vet[(2*i + 2)]);
            i = (2*i + 2);
        }
        
        return;
    }
}
