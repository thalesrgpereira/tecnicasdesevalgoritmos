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
		switch(numero){			
		   case 0:  //se zero der tchau
			   printf("\nTchau!!!\n\n"); 	
			   exit(1);
			  
		   case 1:{
                int numPrimo;
				printf("\nN�MERO PRIMO\n");
			    printf("------------------------------------------------------- \n");
				printf("\nDigite um n�mero para saber se ele � primo: ");
	            scanf("%d",&numPrimo);
				ePrimo(numPrimo) ? printf("\nO n�mero %d � primo.\n\n",numPrimo) : printf("\nO n�mero %d n�o � primo.\n\n",numPrimo) ; 		   	   
			    break;
		   }  
		        
		   case 2:{
			   float a; 
			   int b;
			   printf("\nPOT�NCIA\n");
			   printf("------------------------------------------------------- \n");
			   printf("Informe um n�mero de ponto flutuante para A: ");
	           scanf("%f",&a);
	           printf("Informe um n�mero inteiro para B: ");
	           scanf("%d",&b);
	           printf("A pot�ncia de A elevado a B �: %.2f.\nO resultado na forma cient�fica �: %e.\n\n",pow(a,b),pow(a,b));
			   break;
		   }
		   case 3:{
		   	   float a; 
			   int b;
			   printf("\nRAIZ\n");
			   printf("------------------------------------------------------- \n");
			   printf("Informe um n�mero de ponto flutuante para A: ");
	           scanf("%f",&a);
	           printf("Informe um n�mero inteiro, diferente de zero, para B: ");
	           scanf("%d",&b);
	           if(b == 0) {
	           		printf("O n�mero digitado em B � inv�lido!\n\n");
			   }
			   else {
			   		printf("A raiz de A na base B �: %f.\nO resultado na forma cient�fica �: %e.\n\n",pow(a,1.0/(float)b),pow(a,(1.0/(float)b)));
			   }
			   break;
		   }
		   case 4:{
				int ano;
			    printf("\nANO BISSEXTO\n");
			    printf("------------------------------------------------------- \n");
			    printf("Informe um ano para saber se ele e bissexto: ");
	            scanf("%d",&ano);
			    (ano % 4) ? printf("O ano %d n�o � bissexto!\n\n",ano) : printf("O ano %d � bissexto!\n\n",ano);
			    break;
		   }
		   case 5:{
		   	    float nota1, nota2, nota3, media;
			    printf("\nM�DIA PONDERADA TR�S NOTAS\n");
			    printf("------------------------------------------------------- \n");
			    printf("Informe sua primeira nota: ");
	            scanf("%f",&nota1);
	            printf("Informe sua segunda nota: ");
	            scanf("%f",&nota2);
	            printf("Informe sua terceira nota: ");
	            scanf("%f",&nota3);
	            media = ((nota1 + nota2 + (nota3 * 2))/4);
			    printf("Sua m�dia foi: %.2f\n",media);
			    (media >= 60) ? printf("Voc� foi aprovado. Parab�ns!!!\n\n") : printf("Voc� foi reprovado!!!\n\n");
			    break;
		   }
		   	
		   case 6:{
		   	float nota1, nota2, media;
			    printf("\nM�DIA DUAS NOTAS \n");
			    printf("------------------------------------------------------- \n");
			    printf("Informe sua primeira nota: ");
	            scanf("%f",&nota1);
	            if(nota1 < 0 || nota1 > 10) {
	               printf("\nNota inv�lida!!\n\n");
	               break;
				}
				printf("Informe sua segunda nota: ");
	            scanf("%f",&nota2);
			    if(nota2 < 0 || nota2 > 10) {
	               printf("\nNota inv�lida!!\n\n");
	               break;
				}
				media = ((nota1 + nota2) /2);
				printf("Sua m�dia foi: %.2f\n\n",media);
			    break;
		   } 	
		   case 7:
		   case 8:
		   	   break;
		   case 9:
		        printf("\nMEUS DADOS\n");
			    printf("------------------------------------------------------- \n"); 	
				printf("NOME: THALES RAMALHO\n");
				printf("MATR�CULA: %e\n\n",1920026785);
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
