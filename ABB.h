#include<stdio.h>
#include<stdlib.h>

//Definição da estrutura do Nó da Arvore
typedef struct No{
    int info;
    struct No *esquerda;
    struct No *direita;
}ABB;

//Função para verificar se a arvore está vazia
int vazia(ABB *a){
    if(a == NULL)
        return 1;
    else
        return 0;
}

//Inicialização do nó, retornando NULL;
ABB* inicializar(){
    return NULL;
}
    
//Inserção de um nó na Arvore por metodo Recursivo;
ABB* insere(ABB* a, int valor){
    if(vazia(a)){
        a = (ABB*) malloc(sizeof(ABB));
        a->info = valor;
        a->esquerda = NULL;
        a->direita = NULL;
        printf("\nO valor %d foi adicionado com sucesso!\n", valor);
        }
    else
    {

        if(valor < a->info)
            a->esquerda = insere(a->esquerda, valor);
        else
            if(valor > a->info)
                a->direita = insere(a->direita, valor);
    }
    return a;
}

//A busco por um valor especifico por metodo recursivo
ABB *busca(ABB *a, int valor){
    if(vazia(a))
        return NULL;
    
    if(a->info == valor)
        return a;
    
    if(a->info > valor)
        return busca(a->esquerda, valor);
    
    if(a->info < valor)
        return busca(a->direita, valor);
}

//Indicar qual é o menor valor da arvore
ABB* MenorValor(ABB* a){
    ABB* n = a;

    while(n && n->esquerda != NULL)
        n = n->esquerda;
    return n;
}

ABB* deletar(ABB* raiz, int valor){
    if(vazia(raiz)) 
        return raiz;
    
    if(valor < raiz->info)
        raiz->esquerda = deletar(raiz->esquerda, valor);
    else
        if(valor > raiz->info)
            raiz->direita = deletar(raiz->direita, valor);
        else
        {
            if(raiz->esquerda == NULL){
                return raiz->direita;
            }
            else
                if(raiz->direita == NULL){
                    return raiz->esquerda;
                }
            
            ABB* temp = MenorValor(raiz->direita);
            raiz->info = temp->info;
            raiz->direita = deletar(raiz->direita, temp->info);
        }
    return raiz;
}

void imprimeOrdem(ABB* a){
    if (!vazia(a)){
        imprimeOrdem(a->esquerda);
        printf("%d\n", a->info);
        imprimeOrdem(a->direita);
    }
}

//Deleta todas as estruturas da arvore, porem não transforma ela em NULL
void _DeletarArvore(ABB* a){
    if (vazia(a)) return; 
  
    _DeletarArvore(a->esquerda); 
    _DeletarArvore(a->direita); 
    
    printf("\nDeletando valor: %d", a->info); 
    free(a); 
}

//NÃO MANDAR O NÓ DE UMA VEZ, MAS SIM O ENDEREÇO DO NÓ E.G DeletarArvore(&a);
//ele manda a referencia do nó para _DeletarArvore para deletar as estruturas, e quando volta, ele torna a arvore NULL, fazendo com que ela deixe de existir.
void DeletarArvore(ABB** referencia_no) 
{ 
  _DeletarArvore(*referencia_no); 
  *referencia_no = NULL; 
} 