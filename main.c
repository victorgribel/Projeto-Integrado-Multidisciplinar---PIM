#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100

// Definição da estrutura Produto
typedef struct {
    char tipo[50];
    float peso;
    float valor;
} Produto;

// Função para cadastrar produtos
void cadastrarProduto(Produto produtos[], int *numProdutos) {
    if (*numProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido.\n");
        return;
    }

    Produto novoProduto;

    printf("Digite o tipo do produto: ");
    scanf(" %[^\n]s", novoProduto.tipo);

    printf("Digite o peso do produto (em kg): ");
    scanf("%f", &novoProduto.peso);

    printf("Digite o valor do produto: ");
    scanf("%f", &novoProduto.valor);

    produtos[*numProdutos] = novoProduto;
    (*numProdutos)++;

    printf("Produto cadastrado com sucesso!\n");
}

// Função para consultar produtos
void consultarProdutos(Produto produtos[], int numProdutos) {
    if (numProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("Produtos cadastrados:\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Tipo: %s\n", produtos[i].tipo);
        printf("Peso: %.2f kg\n", produtos[i].peso);
        printf("Valor: R$ %.2f\n", produtos[i].valor);
        printf("----------------------------\n");
    }
}

// Função para atualizar o estoque
void atualizarEstoque(Produto produtos[], int numProdutos) {
    if (numProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    char tipo[50];
    printf("Digite o tipo do produto a ser atualizado: ");
    scanf(" %[^\n]s", tipo);

    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].tipo, tipo) == 0) {
            printf("Atualizando o produto: %s\n", produtos[i].tipo);
            printf("Digite o novo peso do produto (em kg): ");
            scanf("%f", &produtos[i].peso);
            printf("Digite o novo valor do produto: ");
            scanf("%f", &produtos[i].valor);
            printf("Produto atualizado com sucesso!\n");
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

// Função para realizar venda (simples)
void realizarVenda(Produto produtos[], int *numProdutos) {
    if (*numProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    char tipo[50];
    printf("Digite o tipo do produto que deseja vender: ");
    scanf(" %[^\n]s", tipo);

    for (int i = 0; i < *numProdutos; i++) {
        if (strcmp(produtos[i].tipo, tipo) == 0) {
            printf("Produto vendido: %s\n", produtos[i].tipo);
            printf("Peso vendido: %.2f kg\n", produtos[i].peso);
            printf("Valor total: R$ %.2f\n", produtos[i].valor);
            // Remover o produto da lista
            for (int j = i; j < *numProdutos - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            (*numProdutos)--;
            printf("Venda realizada com sucesso!\n");
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

int main() {
    int opcao;
    Produto produtos[MAX_PRODUTOS];
    int numProdutos = 0;

    // Menu principal usando do-while
    do {
        printf("----------- Bem vindo ao Hortifruti -----------\n");
        printf("0 - Menu\n");
        printf("1 - Cadastro de Produtos\n");
        printf("2 - Consulta de Produtos\n");
        printf("3 - Atualizacao de Estoque\n");
        printf("4 - Realizar Venda\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        printf("-----------------------------------------------\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 0:
                printf("Retornando ao menu principal.\n");
                break;
            case 1:
                cadastrarProduto(produtos, &numProdutos);
                break;
            case 2:
                consultarProdutos(produtos, numProdutos);
                break;
            case 3:
                atualizarEstoque(produtos, numProdutos);
                break;
            case 4:
                realizarVenda(produtos, &numProdutos);
                break;
            case 5:
                printf("Saindo do sistema. Até logo!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }

        printf("\n");  // Apenas para espaçamento estético

    } while(opcao != 5);  // Continua até o usuário escolher a opção 5 (Sair)

    return 0;
}
