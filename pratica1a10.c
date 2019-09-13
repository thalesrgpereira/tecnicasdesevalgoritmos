#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int  ePrimo(int numero);
void ePar(int numero);
void imprimeSequenciaFibonacci(int elementos);
void imprimeFatorial(int numero);

int main(){
	setlocale(LC_ALL,"Portuguese");
		
	int numero;

	do {
		//Exibe o menu:
		printf("------------ MENU ------------\n"
		" 0  - Sair\n"
		" 1  - Par ou Ímpar\n"
		" 2  - Potência\n"
		" 3  - Raiz\n"
		" 4  - Ano Bissexto\n"
		" 5  - Média Ponderade Três Notas\n"
		" 6  - Média Duas Notas\n"
		" 7  - Fatorial\n"
		" 8  - Número Primo\n"
		" 9  - Fibonacci\n"
		" 10 - Meus Dados\n" 
		"------------------------------\n");
		
		//Obtem o numero
		printf("\nDigite um número do menu: ");
		scanf("%d",&numero);
		switch(numero){			
			case 0:  //se zero der tchau
				printf("\nTchau!!!\n\n"); 	
				exit(1);
			  
			case 1:{
				int numero;
				printf("\nPAR OU ÍMPAR\n");
				printf("------------------------------------------------------- \n");		   	
				printf("Informe um número para saber se ele é par ou ímpar:");
				scanf("%d",&numero);
				ePar(numero);
				break;
			}  
			    
			case 2:{
				float a; 
				int b;
				printf("\nPOTÊNCIA\n");
				printf("------------------------------------------------------- \n");
				printf("Informe um número de ponto flutuante para A: ");
				scanf("%f",&a);
				printf("Informe um número inteiro para B: ");
				scanf("%d",&b);
				printf("A potência de A elevado a B é: %.2f.\nO resultado na forma científica é: %e.\n\n",pow(a,b),pow(a,b));
				break;
			}
			case 3:{
				float a; 
				int b;
				printf("\nRAIZ\n");
				printf("------------------------------------------------------- \n");
				printf("Informe um número de ponto flutuante para A: ");
				scanf("%f",&a);
				printf("Informe um número inteiro, diferente de zero, para B: ");
				scanf("%d",&b);
				if(b == 0) {
					printf("O número digitado em B é inválido!\n\n");
				}
				else {
					printf("A raiz de A na base B é: %f.\nO resultado na forma científica é: %e.\n\n",pow(a,1.0/(float)b),pow(a,(1.0/(float)b)));
				}
				break;
			}
			case 4:{
				int ano;
				printf("\nANO BISSEXTO\n");
				printf("------------------------------------------------------- \n");
				printf("Informe um ano para saber se ele e bissexto: ");
				scanf("%d",&ano);
				(ano % 4) ? printf("O ano %d não é bissexto!\n\n",ano) : printf("O ano %d é bissexto!\n\n",ano);
				break;
			}
			case 5:{
				float nota1, nota2, nota3, media;
				printf("\nMÉDIA PONDERADA TRÊS NOTAS\n");
				printf("------------------------------------------------------- \n");
				printf("Informe sua primeira nota: ");
				scanf("%f",&nota1);
				printf("Informe sua segunda nota: ");
				scanf("%f",&nota2);
				printf("Informe sua terceira nota: ");
				scanf("%f",&nota3);
				media = ((nota1 + nota2 + (nota3 * 2))/4);
				printf("Sua média foi: %.2f\n",media);
				(media >= 60) ? printf("Você foi aprovado. Parabéns!!!\n\n") : printf("Você foi reprovado!!!\n\n");
				break;
			}
			
			case 6:{
				float nota1, nota2, media;
				printf("\nMÉDIA DUAS NOTAS \n");
				printf("------------------------------------------------------- \n");
				printf("Informe sua primeira nota: ");
				scanf("%f",&nota1);
				if(nota1 < 0 || nota1 > 10) {
					printf("\nNota inválida!!\n\n");
					break;
				}
				printf("Informe sua segunda nota: ");
				scanf("%f",&nota2);
				if(nota2 < 0 || nota2 > 10) {
					printf("\nNota inválida!!\n\n");
					break;
				}
				media = ((nota1 + nota2) /2);
				printf("Sua média foi: %.2f\n\n",media);
				break;
			} 	
			case 7:{
				int numero;	
				printf("\nFATORIAL\n");
				printf("------------------------------------------------------- \n");
				printf("Informe um número para que seja obtido o seu fatorial:");
				scanf("%d",&numero);
				imprimeFatorial(numero);
				break;
			}
			case 8:{
				int numPrimo;
				printf("\nNÚMERO PRIMO\n");
				printf("------------------------------------------------------- \n");
				printf("\nDigite um número para saber se ele é primo: ");
				scanf("%d",&numPrimo);
				ePrimo(numPrimo) ? printf("\nO número %d é primo.\n\n",numPrimo) : printf("\nO número %d não é primo.\n\n",numPrimo) ; 		   	   
				break;
			}
			case 9:{
				int elementos;	
				printf("\nFIBONACCI\n");
				printf("------------------------------------------------------- \n");
				printf("Informe a quantidade de elementos da sequência de Fibonacci a ser exibida:");
				scanf("%d",&elementos);
				imprimeSequenciaFibonacci(elementos);
				break;
			}
			case 10:
				printf("\nMEUS DADOS\n");
				printf("------------------------------------------------------- \n"); 	
				printf("NOME: THALES RAMALHO\nMATRÍCULA: %e\n\n",1920026785);
				break;
			default: //caso seja digitado um numero diferente de 0 a 9, opcao inexistente e reexibe o menu:
				printf("Opcao inexistente!!!\n\n");  
			 
		}
		
	} while (numero !=0);
	
	return 0;
}

int ePrimo(int numero) {
	if(numero < 2){
		return 0;
	}
	else if(numero == 2) {
		return 1;
	}
	else {
		register int i;
		for (i = 2; i < numero; i++) {
			if(numero % i == 0) return 0;
		}
		return 1;
	}	    
}

void ePar(int numero){
	(numero % 2 == 0) ? printf("\nO número %d é par!\n\n",numero):printf("\nO número %d é impar!\n\n",numero);
}

void imprimeSequenciaFibonacci(int elementos){
	if(elementos < 1) {
		printf("\nQuantidade inválida!\n\n");
	}
	else {
		int i, anterior = 1, proximo = 0, atual;	
		for (i = 0; i < elementos; i++) {
			atual = proximo;
			proximo += anterior;
			anterior = atual;
			(i == 0) ? printf("%d",proximo):printf(", %d",proximo);
		}
		printf("\n\n");
	}
}
void  imprimeFatorial(int numero){
	printf("%d! = 1",numero);
	if(numero > 1) {
		int i,fatorial = 1;
		for (i = 2; i <= numero; i++) {
			printf(" * %d",i);
			fatorial *= i;
		}	
		printf(" = %d\n\n",fatorial);
	}
	else {
		printf("\nO número digitado é inválido.\nO fatorial só pode ser calculado de números inteiros positivos.\n\n");
	}
}
