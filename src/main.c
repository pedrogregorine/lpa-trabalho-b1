#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	float distancia;
	float peso;
	float percentPeso;
	float adicionalPeso;
	float totalEntrega; 
	float precoBaseDistancia;
	float subtotal;
	float tarifa = 1.20;
	int modalidade;
	float percentModalidade; 
	float adicionalModalidade;
	int protecao;
	float adicionalProtecao;
	int tentativas;
	float adicionalTentativas = 4;
	float valorTentativas;
	
	printf("Digite qual a distancia da entrega em KM: \n");
	scanf("%f", &distancia);
	
	printf("\nDigite o peso da encomenda: \n");
	scanf("%f", &peso);
	
	printf("Escolha a modalidade da entrega\n");
	printf("1 - ECONOMICA\n");
	printf("2 - EXPRESSA\n");
	printf("3 - PRIORITARIA\n");
	printf("\nDigite sua opção: \n");
	scanf("%d", &modalidade);
	
	while (modalidade <1 || modalidade > 3){
	printf("Modalidade invalida. \n");
	printf("Digite novamente a modalidade: ");
	scanf("%d", &modalidade);
	}
	
	printf("Servico de Protecao");
	printf("1 - QUERO (+ RS7,50)\n");
	printf("0 - NAO QUERO\n");
	scanf("%d", &protecao);
	
	while (protecao != 0 && protecao != 1){
	printf("Opcao invalida. \n");
	printf("Digite novamente a opcao: ");
	scanf("%d", &protecao);
	}
	
	printf("Quantas tentativas adicionais foram feitas: ");
	scanf("%d", &tentativas);
	
	while (tentativas < 0){
	printf("Opcao invalida. \n");
	printf("Digite novamente as tentativas adicionais: ");
	scanf("%d", &tentativas);
	}
	
    valorTentativas = tentativas * adicionalTentativas;
	
	if(distancia <= 5){
		precoBaseDistancia = 8;
	}else if (distancia <= 15){
		precoBaseDistancia = 12;
	}else if (distancia <= 30){
		precoBaseDistancia = 18;
	}else{
		precoBaseDistancia = 25;
	}
	
	subtotal = precoBaseDistancia + (distancia * tarifa);
	
	if (peso <= 2){
		percentPeso = 0;
	}else if(peso <= 5){
		percentPeso = 0.05;
	}else if (peso <= 10){
		percentPeso = 0.1;
	}else{
		percentPeso = 0.2;
	}
	
	adicionalPeso = subtotal * percentPeso;
	
	switch(modalidade){
		case 1: percentModalidade = 0;
		break;
		case 2: percentModalidade = 0.15;
		break;
		case 3: percentModalidade = 0.3;
	}
	
	adicionalModalidade = subtotal * percentModalidade;
	
	switch(protecao){
	case 1: adicionalProtecao = 7.50 ;
	break;
	case 2: adicionalProtecao = 0;
	break;
	}
	
	totalEntrega = subtotal + adicionalPeso + adicionalModalidade + adicionalProtecao + valorTentativas;
	
	printf("\nValor final da entrega: R$ %.2f\n", totalEntrega);
	
	
	 return 0;
}
