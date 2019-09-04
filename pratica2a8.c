#include <stdio.h>
#include <stdlib.h>
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
		printf("1 - Número Primo\n");
		printf("2 - Potência\n");
		printf("3 - Raiz\n");
		printf("4 - Ano Bissexto\n");
		printf("5 - Média Ponderade Três Notas\n");
		printf("6 - Média Duas Notas\n");
		printf("7 - *****\n");
		printf("8 - *****\n");
		printf("9 - Meus Dados\n"); 
		printf("------------------------------\n");
		//Obtem o numero
		printf("\nDigite um número do menu: ");
	    scanf("%d",&numero);
		switch(numero){			
		   case 0:  //se zero der tchau
			   printf("\nTchau!!!\n\n"); 	
			   exit(1);
			  
		   case 1:{
                int numPrimo;
				printf("\nNÚMERO PRIMO\n");
			    printf("------------------------------------------------------- \n");
				printf("\nDigite um número para saber se ele é primo: ");
	            scanf("%d",&numPrimo);
				ePrimo(numPrimo) ? printf("\nO número %d é primo.\n\n",numPrimo) : printf("\nO número %d não é primo.\n\n",numPrimo) ; 		   	   
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
		   case 7:
		   case 8:
		   	   break;
		   case 9:
		        printf("\nMEUS DADOS\n");
			    printf("------------------------------------------------------- \n"); 	
				printf("NOME: THALES RAMALHO\n");
				printf("MATRÍCULA: %e\n\n",1920026785);
				break;
		  default: //caso seja digitado um numero diferente de 0 a 9, opcao inexistente e reexibe o menu:
				printf("Opcao inexistente!!!\n\n");   
			 
		}
		
	} while (numero !=0);
	
	return 0;
}

int ePrimo(int numero) {
	register int i, divisores = 0;
	for (i = 1; i <= numero; i++) {
		if(numero % i == 0) divisores++;
		if(divisores > 2) break;
	}   
	if(divisores == 2)
	    return 1;
	else
	    return 0;
}
