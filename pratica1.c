#include <stdio.h>
#include <math.h>
#include <locale.h>

int ePrimo(int numero);

int main(){
    setlocale(LC_ALL,"Portuguese");
		
	int numero;

	do {
		//Exibe o menu:
		printf("------------ MENU ------------\n");
		printf("0 - Sair\n");
		printf("1 - N�mero Primo\n");
		printf("2 - Pot�ncia\n");
		printf("3 - Raiz\n");
		printf("4 - Ano Bissexto\n");
		printf("5 - M�dia Ponderade Tr�s Notas\n");
		printf("6 - M�dia Duas Notas\n");
		printf("7 - *****\n");
		printf("8 - *****\n");
		printf("9 - Meus Dados\n"); 
		printf("------------------------------\n");
	
		//Obtem o numero
		printf("\nDigite um n�mero do menu: ");
	    scanf("%d",&numero);
	    printf("\n");
		/*
	      0      - sair do programa
	      1..9   - exibe o menu
	      outros - opcao inexistente e exibe o menu
		*/
	    if(numero == 0){ 
	    	printf("Tchau!!!\n\n");
	    	break;
		} else if(!(numero >=1 && numero <=9)) {    
			printf("Opcao inexistente!!!\n\n");
		}  
	
	} while (numero !=0);
	
	return 0;
}

