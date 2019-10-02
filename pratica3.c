#include <stdio.h>
#include <locale.h>

int compara(char *nome, char *nome2);
void concatenar(char *nome, char *nome2, char *nomeCompleto);
int contaCaracteres(char *texto);
int contaVogais(char *texto);
int copia(char *origem,char *destino);

int main(){
	setlocale(LC_ALL,"Portuguese");
		
	int numero;
	
	do {

		//Exibe o menu:
		printf("------------ MENU ------------\n"
		" 0 - Sair\n"
		" 1 - Contador de caracteres\n"
		" 2 - Contador de vogais\n"
		" 3 - Comparador de textos\n"
		" 4 - Copiar texto\n"
		" 5 - Concatenar textos\n" 
		"------------------------------\n");
		
		//Obtem o numero escolhido pelo usuario
		printf("\nDigite um número do menu: ");
		numero=-1;
		scanf("%d",&numero);
		//fflush(stdin) limpa o buffer do teclado para que os textos digitado a mais nao sejam utilizados por outro scanf
		//caso seja linux, tem que mudar para __fpurge(stdin);
		fflush(stdin);
		switch(numero){			
			case 0:  //se zero der tchau
				printf("\nTchau!!!\n\n"); 	
				return 0;
			case 1:{
				char texto[40];
				printf("\nCONTADOR DE CARACTERES\n");
				printf("------------------------------------------------------- \n");		   	
				printf("Informe um texto: ");
				scanf(" %40[^\n]s",&texto);
				printf("O texto digitado tem %d caracteres.\n\n",contaCaracteres(texto)); 
				break;
			}  
			case 2:{
				char texto[40];
				int qVogais;
				printf("\nCONTADOR DE VOGAIS\n");
				printf("------------------------------------------------------- \n");		   	
				printf("Informe um texto: ");
				scanf(" %s",&texto);
				qVogais = contaVogais(texto);
				if(qVogais == 0){
					printf("O texto digitado não tem vogais.\n\n"); 
				}
				else if(qVogais == 1){
					printf("O texto digitado tem 1 vogal.\n\n"); 
				}
				else {
					printf("O texto digitado tem %d vogais.\n\n",qVogais); 
				}
				break;
			} 
			case 3:{
				char texto1[40],texto2[40];
				printf("\nCOMPARADOR DE TEXTOS\n");
				printf("------------------------------------------------------- \n");
				printf("entrada 1: ");
				scanf(" %40[^\n]s",&texto1);
				fflush(stdin);
				printf("entrada 2: ");
				scanf(" %40[^\n]s",&texto2);
				compara(texto1,texto2) ? printf("O textos digitados são iguais.\n\n") : printf("O textos digitados são diferentes.\n\n"); 
				break;
			}   
			case 4:{
				char origem[40],destino[40];
				printf("\nCOPIA TEXTO\n");
				printf("------------------------------------------------------- \n");		   	
				printf("Informe um texto: ");
				scanf(" %s",&origem);
				copia(origem, destino);
				printf("Seu texto foi copiado para outra variável que agora contém: %s.\n\n",destino); 
				break;
			} 
			case 5:{
				char texto1[40],texto2[40],texto3[81];
				texto3[0] = '\0';
				printf("\nCONCATENAR TEXTOS\n");
				printf("------------------------------------------------------- \n");		   	
				printf("entrada 1: ");
				scanf(" %40[^\n]s",&texto1);
				fflush(stdin);
				printf("entrada 2: ");
				scanf(" %40[^\n]s",&texto2);	
				concatenar(texto1,texto2, texto3);
				printf("saída: %s.\n\n",texto3); 
				break;
			}  
			default: //caso seja digitado um numero diferente de 0 a 5, opcao inexistente e reexibe o menu:
				printf("Opcao inexistente!!!\n\n");  
		}
		fflush(stdin);
	} while (numero != 0);
	
	return 0; 	
}

int contaCaracteres(char *texto){
	int contador;
	while (*texto) {
		if (*texto != ' ') contador++;
		*texto++;
	}
	return contador;   
}

int contaVogais(char *texto){
	int i, contador = 0;
	char vogais[11] = "aeiouAEIOU";
	while (*texto) {
		for(i = 0; i < 10; i++){
			if (*texto == vogais[i]) contador++;		  
		}  
		*texto++; 
	}
	return contador;   
}

int copia(char *origem,char *destino){
	if(sizeof(origem) > sizeof(destino)) return 0;
	while (*origem)  *destino++ = *origem++;
	return 1;
}

int compara(char *nome, char *nome2){
	int i;
	for(i = 0; nome[i] == nome2[i] && nome[i] !='\0' && nome2[i] !='\0'; i++ ); 
	return (nome[i] == '\0' &&  nome2[i] == '\0') ? 1 : 0;	
}

void concatenar(char *nome, char *nome2, char *nomeCompleto){
	while (*nome && *nome!='\0') *nomeCompleto++ = *nome++;
	while (*nome2 && *nome2!='\0') *nomeCompleto++ = *nome2++;
	*nomeCompleto = '\0';
}
