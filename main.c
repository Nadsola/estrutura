#include <stdio.h> 
#include <stdlib.h>
typedef struct {
     int dia, mes, ano;
}Data;


typedef struct {
    char nome [50];
    Data data;
}Pessoa;


typedef struct elemento {
    Pessoa pe;
    int numero_id;
   struct  elemento *proximo;
}Elemento;


typedef struct  {
Elemento *inicio;
}Pilha;


int escolher_estrutura ();
int menu_pilha ();
Pilha *criar_pilha();
void manipular_pilha(int retorno_menu_pilha, Pilha *p);
void empilhar (Pilha  *p);
void mostrar_pilha (Pilha *p);
Pessoa ler_pessoa();

int main()
{
    Pilha *p;
int opcao= 1;
do{
  opcao = escolher_estrutura();
switch(opcao){
    case 0:
    printf("Encerrando programa...\n");
    printf ("Programa encerrado\n");
    break;
    case 1:
        printf("Voce escolheu fazer uma Pilha");
       Pilha *p = criar_pilha ();
        manipular_pilha(menu_pilha(), criar_pilha ());
} }while (opcao != 0);
    return 0;
}

int escolher_estrutura (){
    int estrutura_escolhida;
    printf ("qual tipo de estrutura gostaria de implementar?\n");
    printf ("1 - Pilha\n");
    printf ("2 - Fila\n ");
    printf ("\n0 - Encerrar o programa \n");
    printf("\n");
    scanf ("%d",&estrutura_escolhida );
     system("cls");
    return estrutura_escolhida;
}
int menu_pilha (){
    int  opcao;
    printf("Escolha uma das opcoes abaxico\n");
    printf("1 - Para empilhar elementos na pilha\n");
    printf ("2 - Para Desempilhar elementos da pilha\n");
    printf("3 - Para imprimir a pilha\n");
    printf("\n0 - Emcerrar programa\n");
    scanf ("%d", &opcao);
    system("cls");
    return opcao;

}
Pilha *criar_pilha (){
Pilha *nova_pilha = (Pilha *) malloc(sizeof(Pilha));
 return nova_pilha;
}
void manipular_pilha(int retorno_menu_pilha, Pilha*p  ){
 int numero_de_elementos;
int continuar_empilhamento;
 do {

        switch( retorno_menu_pilha){
         case 0:
            printf("Encerrando programa...\n");
            printf ("Programa encerrado\n");
            break;
         case 1:

             do {
             printf("quantos elementos gostaria de adicionar na pilha?\n");
             scanf ("%d", &numero_de_elementos);
             for( int i = 0; i < numero_de_elementos; i++){
             printf("Digite as informacoes  relacionada  a pessoa de numero %d  a ser adicionada:\n", i+1);
             empilhar (p);

             }
             printf("gostaria de empilhar mais Elementos?\n");
              printf("1- Sim\n");
               printf("2- Nao\n");
             scanf ("%d", &continuar_empilhamento);

                }while(continuar_empilhamento != 2);
             break;
         case 2:
           break;
         case 3:
              printf ("\nVocê escolheu imprimir a pilha\n");
              printf ("impressão da pilha:\n");
              mostrar_pilha (p);
            break;
        }

 } while ( retorno_menu_pilha != 0);

}

void empilhar (Pilha *p){
    int valor=0;
    Elemento *novo = malloc(sizeof(Elemento));
    if (novo){
        novo->pe = ler_pessoa();
        printf("Digite um valor inteiro de identificacao para a pessoa a ser adicionada");

        scanf("%d",&valor );
        novo->numero_id = valor;
       if(p->inicio == NULL){
        p->inicio = novo;

       }
       else{
        novo -> proximo = p->inicio;
        p->inicio =  novo;

       }
    }
    else{
        printf("Não foi possível alocar memória para o elemento");
    }
}

Pessoa ler_pessoa() {
    Pessoa pe;
    printf("Digite nome e data de nascimento dd mm aaaa:\n");
    scanf(" %49[^\n]%d%d%d", pe.nome, &pe.data.dia, &pe.data.mes, &pe.data.ano);

    return pe;
}

void desempilhar(Pilha *p){
    Elemento *remover = p->inicio;
    p->inicio = p->inicio->proximo;

    return remover;
}

void mostrar_pilha (Pilha *p){
    Elemento *percorre_pilha = p->inicio;
    if (percorre_pilha != NULL){
        while(percorre_pilha != NULL){
            printf ("Nome: %s \n Data de nascimento: %2d/%2d/%4d\n Numero de identificacao: %d\n", percorre_pilha->pe.nome, percorre_pilha->pe.data.dia, percorre_pilha->pe.data.mes, percorre_pilha->pe.data.ano, percorre_pilha->numero_id);
            percorre_pilha = percorre_pilha->proximo;
        }
    }
    else{
        printf ("Pilha vazia!");
    }

void criar_fila (){

}


}

