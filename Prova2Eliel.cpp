// Erro : ta escrito studio.h o certo é stdio.h
#include<stdio.h>
#include<locale.h>
// Erro : define nao tem " = " 
#define MAX 100
// Erro : Variavel total precisa ser global
int total;

void cadastrarPecas(int codigos[], int quantidades[], float custos[]) {
    int continuar = 1;
    // Erro : comparacão de continuar com só 1 " = ", sendo 2
    while (continuar == 1 && total < MAX) {
        printf("\n--- CADASTRO DE PEÇA ---\n");
        printf("Código da peça: ");
        // Erro : faltou & 
        scanf("%d", &codigos[total]);

        printf("Quantidade produzida: ");
        scanf("%d", &quantidades[total]);

        printf("Custo unitário (R$): ");
        // Erro : faltou & 
        scanf("%f", &custos[total]);
		
        total++;      

        printf("\nDeseja cadastrar outra peça? (1 - Sim / 0 - Não): ");
        // Erro : faltou & 
        scanf("%d", &continuar);
    }

    if (total >= MAX) {
    	// erro : está faltando ;
        printf("\n Limite máximo de peças atingido!\n");
    }
}

void listarPecas(int codigos[], int quantidades[], float custos[]) {
	// Erro : comparacão de continuar com só 1 " = ", sendo 2
    if (total == 0) {
        printf("\n Nenhuma peça cadastrada.\n");
        return;
    }

    printf("\n--- LISTAGEM DE PEÇAS ---\n");
    // Erro : i tem que ser menor que total 
    for (int i = 0; i < total; i++) {
        printf("Código: %d | Quantidade: %d | Custo Unitário: R$ %.2f | Custo Total: R$ %.2f\n",
        	// Erro : variavel custos escrita como " custo " 
            codigos[i], quantidades[i], custos[i], quantidades[i] * custos[i]);
    }
}

float calcularCustoTotal(int quantidades[], float custos[]) {
    float soma;
    for (int i = 0; i < total; i++) {
        soma = soma + quantidades[i] * custos[i];
    }
    // Erro : return escrito como retrun
    return soma;
}

float calcularMediaCusto(float custos[]) {
    float soma = 0;
    for (int i = 0; i < total; i++) {
        soma += custos[i];
    }
    // Erro : if sem {} e else tambem
    // Erro : comparacão de continuar com só 1 " = ", sendo 2
    if (total == 0){
        return 0;
	} else {
		return soma / total;
	}   
}

void mostrarPecaMaisCara(int codigos[], float custos[]) {
	// Erro : if sem {} e else tambem
    if (total == 0){
        printf("\n Nenhuma peça cadastrada.\n");
        return;
    }
    int indiceMaior = 0;
    // Erro : i tem que ser menor que total
    for (int i = 1; i < total; i++) {
        if (custos[i] > custos[indiceMaior]) {
        	// Erro : indiceMaior recebia 1, mas precisa receber i
            indiceMaior = i;
        }
    }

    printf("\n Peça mais cara:\n");
    // Erro :  variavel custos escrita como " custo " 
    printf("Código: %d | Custo Unitário: R$ %.2f\n", codigos[indiceMaior], custos[indiceMaior]);
}

int main() {
	
	// Arrumar acentuação e . para ,
	setlocale(LC_ALL, "Portuguese_Brazil.1252");
	
    int codigos[MAX];
    int quantidades[MAX];
    float custos[MAX];
    int opcao;

    do {
        printf("\n========== FÁBRICA DE COSTURA ==========\n");
        printf("1 - Cadastrar peças\n");
        printf("2 - Listar peças\n");
        printf("3 - Mostrar custo total da produção\n");
        printf("4 - Mostrar média dos custos unitários\n");
        printf("5 - Mostrar peça mais cara\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        // Erro : faltou & 
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                cadastrarPecas(codigos, quantidades, custos);
                break;
            case 2:
                listarPecas(codigos, quantidades, custos);
                break;
            case 3:
            	// Erro : variavel quantidades escrita como " quantidade "
                printf("\nCusto total da produção: R$ %.2f\n", calcularCustoTotal(quantidades, custos));
                break;
            case 4:
            	// Erro :  variavel custos escrita como " custo " 
                printf("\n Média de custo unitário: R$ %.2f\n", calcularMediaCusto(custos));
                break;
            case 5:
                mostrarPecaMaisCara(codigos, custos);
                break;
            case 0:
            	// Erro : falta ;
                printf("\nEncerrando o sistema...\n");
                break;
            default:
            	// Erro : falta ;
                printf("\nOpção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}

