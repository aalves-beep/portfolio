/* Gerador de senhas com saída em arquivo de texto, com as senhas sendo geradas para cada número de matrícula do arquivo matr.txt. 
Feito durante aula do curso de análise e desenvolvimento de sistemas.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	FILE *arq; //variável de leitura de arquivo
	FILE *arqsai; //variável de criação do arquivo de saída
	int *V, tamv, auxv; //*V sendo a variável do vetor dinâmico, com tamv sendo o tamanho do vetor V e auxv sendo variável auxiliar do vetor dinâmico
	char *S; //vetor dinâmico que armazena os caracteres da senha gerada
	int tams, auxs, num, numg; //tams sendo o tamanho do vetor S, auxs sendo a variável auxiliar do vetor S, 
	//num sendo usado para aleatoriamente decidir 
	char tipo; //marca o tipo da senha a gerar
	int i, j, k, qtdc; //i, j, e k são variáveis auxiliares, e qtdc é o tamanho da senha
	
	srand(time(NULL));
	V=NULL;
	S=NULL;
	
	printf("A-Numerica \nB-Alfabetica \nC-Alfanumerica 1(letras maiusculas e algarismos)");
	printf("\nD-Alfanumerica 2(letras maiusculas, minusculas e algarismos) \nE-Geral (com s�mbolos especiais)\n");
	printf("\nInforme o tipo de senha (A-E):");
	scanf("%c", &tipo);
	printf("Escreva quantos caracteres deseja que a senha contenha:");
	scanf("%d", &qtdc);
	
	arq=fopen("matr.txt", "r"); //lendo o arquivo de matrícula
	while (fscanf(arq, "%d\n", &auxv) != EOF) //ler o conteúdo até acabar as linhas
	{
		tamv++; //aumenta o medidor do tamanho do vetor a cada linha lida
		V=(int *)realloc(V, sizeof(int) * tamv); //muda o tamanho do vetor para ser igual ao medidor
		V[tamv-1]=auxv; //atribui a linha atual a posição equivalente no vetor
	}
	fclose(arq); //fecha o arquivo
	
	tams=qtdc; //tamanho do vetor de senha=quantidade de caracteres inserida
	S=(char *)realloc(S, sizeof(char) * tams); //muda o tamanho do vetor para poder conter o número de caracteres da senha

	if(tipo=='A' || tipo=='a') //gera senha composta de números
	{
		arqsai=fopen("senhas.txt", "w");//abre o arquivo de saída
		for(i=0;i<tamv; i++)
		{
			fprintf(arqsai, "%d;", V[i]); //escreve o número de matrícula que seria dono da senha
			for(j=0; j<qtdc; j++) //loop que roda para cada caracter
			{
				S[j]=rand()%10; //gera um número aleatório
				fprintf(arqsai, "%d", S[j]); //escreve o número no arquivo
			}
			fprintf(arqsai, "\n"); //pula a linha para o próximo número de matrícula, e o loop volta ao começo
		}
		fclose(arqsai);
	}
	
	if(tipo=='B' || tipo=='b') //gera senha composta de letras do alfabeto
	{
		arqsai=fopen("senhas.txt", "w");//abre o arquivo de saída
		for(i=0;i<tamv; i++)
		{
			fprintf(arqsai, "%d;", V[i]); //escreve o número de matrícula que seria dono da senha
			for(j=0; j<qtdc; j++) //loop que roda para cada caracter
			{
				num=rand()%2+1; //gera um número para decidir se o caracter vai ser maiúsculo ou minúsculo
				if(num==1) //caracter maiúsculo
				{
					do
					{
						S[j]=rand()% 90+1; //gera um número aleatório e ao converter o número a char, vira uma letra (usando ASCII)
					} while(S[j]<65); //garante que o número gerado esteja na faixa de letras maiúsculas em ASCII eliminando números abaixo de 65
				}
				else //caso tenha gerado 2, caracter minúsculo
				{
					do
					{
						S[j]=rand()% 122+1; //gera um número aleatório e ao converter o número a char, vira uma letra (usando ASCII)
					} while(S[j]<97); //garante que o número gerado esteja na faixa de letras minúsculas em ASCII da mesma forma que a letra maiúscula
				}
				fprintf(arqsai, "%c", S[j]); //escreve a letra no arquivo
			}
			fprintf(arqsai, "\n"); //pula a linha para o próximo número de matrícula, e o loop volta ao começo
		}
		fclose(arqsai);
	}
	
	if(tipo=='C' || tipo=='c') //gera senha composta de letras maiúsculas e números
	{
		arqsai=fopen("senhas.txt", "w");//abre o arquivo de saída
		for(i=0;i<tamv; i++)
		{
			fprintf(arqsai, "%d;", V[i]);//escreve o número de matrícula que seria dono da senha
			for(j=0; j<qtdc; j++) //loop que roda para cada caracter
			{
				num=rand()%2+1; //gera um número para decidir se o caracter vai ser número ou letra
				if(num==1) //se rolar 1, o caracter é letra
				{
					do
					{
						S[j]=rand()% 90+1; //gera um número aleatório e ao converter o número a char, vira uma letra (usando ASCII)
					} while(S[j]<65); //garante que o número gerado esteja na faixa de letras maiúsculas em ASCII eliminando números abaixo de 65
					fprintf(arqsai, "%c", S[j]); //escreve a letra no arquivo
				}
				else //se rolar 2, o caracter é número
				{
					S[j]=rand()% 10; //gera um número aleatório
					fprintf(arqsai, "%d", S[j]); //escreve o número no arquivo
				}
			}
			fprintf(arqsai, "\n"); //pula a linha para o próximo número de matrícula, e o loop volta ao começo
		}
		fclose(arqsai);
	}
	
	
	if(tipo=='D' || tipo=='d') //gera senha composta de letras maiúsculas, minúsculas e números
	{
		arqsai=fopen("senhas.txt", "w");//abre o arquivo de saída
		for(i=0;i<tamv; i++) 
		{
			fprintf(arqsai, "%d;", V[i]);//escreve o número de matrícula que seria dono da senha
			for(j=0; j<qtdc; j++) //loop que roda para cada caracter
			{
				num=rand()%3+1; //gera um número para decidir se o caracter vai ser número ou letra (maiúscula ou minúscula)
				if(num==1) //se rolar 1 é letra maiúscula
				{
					do
					{
						S[j]=rand()% 90+1; //gera um número aleatório e ao converter o número a char, vira uma letra (usando ASCII)
					} while(S[j]<65); //garante que o número gerado esteja na faixa de letras maiúsculas em ASCII eliminando números abaixo de 65
					fprintf(arqsai, "%c", S[j]); //escreve a letra no arquivo
				}
				if(num==2) //se rolar 2 é letra minúscula
				{
					do
					{
						S[j]=rand()% 122+1; //gera um número aleatório e ao converter o número a char, vira uma letra (usando ASCII)
					} while(S[j]<97); //garante que o número gerado esteja na faixa de letras minúsculas em ASCII da mesma forma que a letra maiúscula
					fprintf(arqsai, "%c", S[j]); //escreve a letra no arquivo
				}
				if(num==3) //se rolar 3 é um número
				{
					S[j]=rand()% 10; //gera um número aleatório
					fprintf(arqsai, "%d", S[j]); //escreve o número no arquivo
				}
			}
			fprintf(arqsai, "\n"); //pula a linha para o próximo número de matrícula, e o loop volta ao começo
		}
		fclose(arqsai);
	}
	
	if(tipo=='E' || tipo=='e') //gera senha que pode incluir letras maiúsculas, letras minúsculas, números, ou caracteres especiais simultaneamente
	{
		arqsai=fopen("senhas.txt", "w");//abre o arquivo de saída
		for(i=0;i<tamv; i++)
		{
			fprintf(arqsai, "%d;", V[i]);//escreve o número de matrícula que seria dono da senha
			for(j=0; j<qtdc; j++) //loop que roda para cada caracter
			{
				num=rand()%4+1; //gera um número para decidir que tipo de caracter vai ser inserido agora
				if(num==1) //se rodar 1, vai ser uma letra maiúscula
				{
					do
					{
						S[j]=rand()% 90+1; //gera um número aleatório e ao converter o número a char, vira uma letra (usando ASCII)
					} while(S[j]<65); //garante que o número gerado esteja na faixa de letras maiúsculas em ASCII eliminando números abaixo de 65
					fprintf(arqsai, "%c", S[j]); //escreve a letra no arquivo
				}
				if(num==2) //se rodar 2, vai ser uma letra minúscula
				{
					do
					{
						S[j]=rand()% 122+1; //gera um número aleatório e ao converter o número a char, vira uma letra (usando ASCII)
					} while(S[j]<97); //garante que o número gerado esteja na faixa de letras minúsculas em ASCII da mesma forma que a letra maiúscula
					fprintf(arqsai, "%c", S[j]); //escreve a letra no arquivo
				}
				if(num==3) //se rodar 3, vai ser um número
				{
					S[j]=rand()% 10; //gera um número aleatório
					fprintf(arqsai, "%d", S[j]); //escreve o número no arquivo
				}
				if(num==4) //se rodar 4, vai ser um caracter especial
				{
					numg=rand()% 12+1; //escolhe um número aleatório para decidir o caracter especial a inserir na senha
					if(numg==1)
					S[j]='+';
					if(numg==2)
					S[j]='-';
					if(numg==3)
					S[j]='_';
					if(numg==4)
					S[j]='!';
					if(numg==5)
					S[j]='?';
					if(numg==6)
					S[j]='#';
					if(numg==7)
					S[j]='@';
					if(numg==8)
					S[j]='*';
					if(numg==9)
					S[j]='&';
					if(numg==10)
					S[j]='=';
					if(numg==11)
					S[j]='$';
					if(numg==12)
					S[j]='%';
					
					fprintf(arqsai, "%c", S[j]); //escreve o caracter no arquivo
				}
			}
			fprintf(arqsai, "\n"); //pula a linha para o próximo número de matrícula, e o loop volta ao começo
		}
		fclose(arqsai);
	}
	
	//saída para caso a entrada do tipo de senha seja inválida
	if(tipo!='A' && tipo!='a' && tipo!='B' && tipo!='b' && tipo!='C' && tipo!='c' && tipo!='D' && tipo!='d' && tipo!='E' && tipo!='e')
	printf("Tipo invalido. Senha nao foi gerada.");
	
	else
	printf("Arquivo de senhas gerado.");
	
	return 0;
}
