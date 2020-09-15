#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"

int main(){
    ABB* a;
    a = inicializar();
    int op;
    int value;


    do{
        printf("------\n1 - INSERIR NUMERO\n2 - BUSCAR NUMERO\n3 - IMPRIMIR EM ORDEM\n4 - DELETAR VALOR\n5 - DELETAR ARVORE\n0 - SAIR\nDigite a Opcao: ");
            scanf("%d", &op);
        switch (op)
        {
        //Inserção do valor na arvore
        case 1:
            printf("\nDigite o valor a ser adicionado na arvore: ");
                scanf("%d", &value);
            a = insere(a, value);
            printf("\n");
            break;
        //Busca de um valor na arvore
        case 2:
            printf("\nDigite o valor a ser procurado: ");
                scanf("%d", &value);
            if(busca(a, value))
                printf("\nValor existe na arvore!\n");
            else
                printf("\nValor inexistente na arvore!\n");
            break;
        /*Imprimir em ordem, primeiro ele vai verificar se a arvore está vazia ou não, se a arvore não estiver vazia, ele vai imprimir os valores em ordem, se estiver vazia
        ele vai retornar dizendo que está vazia*/
        case 3:
            if(vazia(a))
                printf("\nA Arvore esta Vazia!\n");
            else{
                printf("\nValore existentes na arvore em ordem crescente: \n");
                imprimeOrdem(a);
            }
            break;
        /*Deletar um valor da arvore, ele primeiro vai verificar se o valor existe na arvore, se o valor existe, ele vai deletar
        logo em seguida ele vai verificar se o valor ainda existe na arvore para confirmar a exclusão ou não*/
        case 4:
            printf("\nDigite o valor a ser deletado: ");
                scanf("%d", &value);

            if(!busca(a, value)){
                printf("\nValor inexistente na arvore!\n");
                break;
            }
            else{
            a = deletar(a, value);
            if(!busca(a, value))
                printf("\nValor deletado com sucesso!\n");
            else
                printf("\nValor falhou ao ser deletado!\n");
            }
            
            break;
        //ele deleta a arvore por completo, verificar a estrutura DeletarArvore() para mais detalhes
        case 5:
            if(vazia(a)){
                printf("\nA arvore ja se encontra vazia!\n");
                break;
            }
            else{
                DeletarArvore(&a);
                printf("\nArvore deletada com sucesso\n");
                printf("\n");
            }
        break;

        //Condição de Saida
        case 0:

        break;
        
        default:
            printf("\nOpcao Invalida, Digite Novamente!\n");
            break;
        }
    }
    while(op != 0);
}