/*
Gerador de número de matrícula.
Feito durante aula do curso de análise e desenvolvimento de sistemas.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int V[30], i, num; //V é o vetor que armazena os números de matrícula por linha, i e num são auxiliares
	FILE *arq;
	srand(time(NULL));

	arq=fopen("matr.txt", "w"); //cria o arquivo matr.txt 
	for(i=0; i<30; i++)
	{
		do
		{
			num=(rand()% 10+1)*100000; //gera um número aleatório de 1 a 10, e o multiplica para compor a casa do 100000
			V[i]=rand()% 1000000+num; //gera um número para somar com o num e formar o número de matrícula
		} while (V[i]<99999 || V[i]>999999); //continua gerando até o número ter o número correto de dígitos
		
		fprintf(arq, "%d\n", V[i]); //escreve no arquivo o número de matrícula gerado
		printf(".\n"); //indicador de progressão
	}
	fclose(arq); //fecha o arquivo
	printf("Completo");
}
