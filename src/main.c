#include <stdio.h>
#include <stdlib.h>

float criarDistanciaValida(void);
float criarPesoValido(void);
int criarModalidadeValida(void);
int criarProtecaoValida(void);
int criarTentativasValidas(void);

float identificarValorBase(float distancia);
float identificarPercentualPeso(float peso);
float identificarPercentualModalidade(int modalidade);

float calcularValorFinal(float distancia, float peso, int modalidade, int protecao, int tentativas);

void exibirResumo(int totalEntregas, float somaValores, int totalEconomicas, int totalExpressas, int totalPrioritarias, float maiorValor, float menorValor);

int main(void){
	
	float distancia;
	float peso;
	float totalEntrega; 
	int modalidade;
	int protecao;
	int tentativas;
	int continuar;
	int totalEntregas = 0;
	float somaValores = 0;
	int totalEconomicas = 0;
	int totalExpressas = 0;
	int totalPrioritarias = 0;
	float maiorValor = 0;
	float menorValor = 0;
	
	do{
	
    distancia = criarDistanciaValida();
	peso = criarPesoValido();
	modalidade = criarModalidadeValida();
	protecao = criarProtecaoValida();
	tentativas = criarTentativasValidas();
	
	totalEntrega = calcularValorFinal(distancia, peso, modalidade, protecao, tentativas);
	
	printf("\nValor final da entrega: R$ %.2f\n", totalEntrega);
	
	totalEntregas++;
	somaValores += totalEntrega;

	switch(modalidade){
		case 1: totalEconomicas++;
			break;
		case 2: totalExpressas++;
			break;
		case 3: totalPrioritarias++;
			break;
	}

	if (totalEntregas == 1){
		maiorValor = totalEntrega;
		menorValor = totalEntrega;
	} else {
	if (totalEntrega > maiorValor){
		maiorValor = totalEntrega;
	}
	if (totalEntrega < menorValor){
		menorValor = totalEntrega;
	}
	}
	
    printf("\nDeseja processar outra entrega?\n");
	printf("1 - SIM\n");
	printf("0 - NAO\n");
	printf("Escolha: ");
	scanf("%d", &continuar);

	while (continuar != 0 && continuar != 1){
		printf("Opcao invalida. \n");
		printf("Digite novamente: ");
		scanf("%d", &continuar);
	}

	} while (continuar == 1);

	exibirResumo(totalEntregas, somaValores, totalEconomicas, totalExpressas, totalPrioritarias, maiorValor, menorValor);
	
	return 0;
}

int criarModalidadeValida(void){
	int modalidade;

	printf("Escolha a modalidade da entrega\n");
	printf("1 - ECONOMICA\n");
	printf("2 - EXPRESSA\n");
	printf("3 - PRIORITARIA\n");
	printf("\nDigite sua opcao: \n");
	scanf("%d", &modalidade);

	while (modalidade < 1 || modalidade > 3){
		printf("Modalidade invalida. \n");
		printf("Digite novamente a modalidade: ");
		scanf("%d", &modalidade);
	}

	return modalidade;
}

float criarDistanciaValida(void){
	float distancia;

	printf("Digite qual a distancia da entrega em KM: \n");
	scanf("%f", &distancia);

	while (distancia <= 0){
		printf("Distancia invalida. \n");
		printf("Digite novamente a distancia: ");
		scanf("%f", &distancia);
	}

	return distancia;
}

float criarPesoValido(void){
	float peso;

	printf("\nDigite o peso da encomenda: \n");
	scanf("%f", &peso);

	while (peso <= 0){
		printf("Peso invalido. \n");
		printf("Digite novamente o peso: ");
		scanf("%f", &peso);
	}

	return peso;
}

int criarProtecaoValida(void){
	int protecao;

	printf("Servico de Protecao\n");
	printf("1 - QUERO (+ R$7,50)\n");
	printf("0 - NAO QUERO\n");
	scanf("%d", &protecao);

	while (protecao != 0 && protecao != 1){
		printf("Opcao invalida. \n");
		printf("Digite novamente a opcao: ");
		scanf("%d", &protecao);
	}

	return protecao;
}

int criarTentativasValidas(void){
	int tentativas;

	printf("Quantas tentativas adicionais foram feitas: ");
	scanf("%d", &tentativas);

	while (tentativas < 0){
		printf("Quantidade invalida. \n");
		printf("Digite novamente as tentativas adicionais: ");
		scanf("%d", &tentativas);
	}

	return tentativas;
}

float identificarValorBase(float distancia){
	float valorBase;

	if (distancia <= 5){
	valorBase = 8;
	} else if (distancia <= 15){
	valorBase = 12;
	} else if (distancia <= 30){
	valorBase = 18;
	} else {
	valorBase = 25;
	}

	return valorBase;
}

float identificarPercentualPeso(float peso){
	float percentual;

	if (peso <= 2){
	percentual = 0;
	} else if (peso <= 5){
	percentual = 0.05;
	} else if (peso <= 10){
	percentual = 0.1;
	} else {
	percentual = 0.2;
	}

	return percentual;
}

float identificarPercentualModalidade(int modalidade){
	float percentual;

	switch (modalidade){
	case 1:
		percentual = 0;
		break;
	case 2:
		percentual = 0.15;
		break;
	case 3:
		percentual = 0.3;
		break;
	}

	return percentual;
}

float calcularValorFinal(float distancia, float peso, int modalidade, int protecao, int tentativas){
	float subtotal;
	float adicionalPeso;
	float adicionalModalidade;
	float adicionalProtecao;
	float valorTentativas;

	subtotal = identificarValorBase(distancia) + (distancia * 1.20);
	adicionalPeso = subtotal * identificarPercentualPeso(peso);
	adicionalModalidade = subtotal * identificarPercentualModalidade(modalidade);

	adicionalProtecao = 0;
	if (protecao == 1){
		adicionalProtecao = 7.50;
	}

	valorTentativas = tentativas * 4;

	return subtotal + adicionalPeso + adicionalModalidade + adicionalProtecao + valorTentativas;
}

void exibirResumo(int totalEntregas, float somaValores, int totalEconomicas, int totalExpressas, int totalPrioritarias, float maiorValor, float menorValor){
	printf("\nRESUMO\n");
	printf("Total de entregas: %d\n", totalEntregas);
	printf("Valor total: R$ %.2f\n", somaValores);
	printf("Valor medio: R$ %.2f\n", somaValores / totalEntregas);
	printf("Entregas economicas: %d\n", totalEconomicas);
	printf("Entregas expressas: %d\n", totalExpressas);
	printf("Entregas prioritarias: %d\n", totalPrioritarias);
	printf("Maior valor: R$ %.2f\n", maiorValor);
	printf("Menor valor: R$ %.2f\n", menorValor);
}
