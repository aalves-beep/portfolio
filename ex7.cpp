/*Programa que carrega um vetor a partir da leitura de um arquivo .txt em disco, exibe-o,
elimina elementos repetidos, e exibe o vetor resultante na tela.
Feito durante aula do curso de análise e desenvolvimento de sistemas.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	//declaração de variáveis
	int tamv, X, N, cont; 
	int *V; //variável que irá se tornar um vetor
	FILE *Arq; //variável de leitura de arquivos
	
	V=NULL;
	
	Arq=fopen("vetor.txt", "r"); //leitura do arquivo do vetor
	
	while(fscanf(Arq, "%d\n", &X) !=EOF)
	{
		tamv++; //variável que armazena o tamanho do vetor aumentando
		V=(int *)realloc(V, sizeof(int)*tamv);
		V[tamv-1]=X;
	}
	
	fclose(Arq);
	
	cont=0;
	while(cont<tamv)
	{
		printf("\nEscreva um valor para procurar no vetor.");
		scanf("%d", &N);
		
		if(N==V[cont])
		{
			
		}
		
		if(N!=V[cont])
		{
			cont++;
		}
		
	}
	
	
	for(cont=0; cont<tamv; cont++)
	{
		printf("%2d ", V[cont]);
		if(cont%10==0 && cont!=0)
		printf("\n");
	}
	
	
	
	
	
	
}
