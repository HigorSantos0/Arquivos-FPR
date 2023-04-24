/*
	FAETERJ-Rio
	FPR Manh� - 20/04/2022
	
	Lista de Exerc�cios VII (Arquivos)
	
	Quest�o 01:
	Desenvolver uma fun��o que, dado um arquivo texto, verifique 
	o n�mero de caracteres no mesmo.
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int quantidadeCaracteres (char nomeArq[]);

//main
void main ()
{
	//declara��o de vari�veis
	char nomeArquivo[20];
	int quant;
	
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nomeArquivo);
	
	//chamando a fun��o
	quant = quantidadeCaracteres (nomeArquivo);
	
	//testando se houve erro
	if (quant == -1)
	{
		printf ("\nErro na abertura do arquivo!");
	}
	else
	{
		printf ("\nForam encontrados %d caracteres do arquivo %s.", quant, nomeArquivo);
	}
}

//implementa��o das fun��es
int quantidadeCaracteres (char nomeArq[])
{
	//declara��o de vari�veis
	FILE *arq;
	char caracter;
	int cont = 0;
	
	//abrino os arquivos
	arq = fopen (nomeArq, "r");
	
	//verificando se houve erro na abertura do arquivo
	//if (arq == NULL)
	if (!arq)
	{
		return -1;	//representando que houve erro
	}
	else
	{
		//lendo todos os caracteres do arquivo
		while (fscanf (arq, "%c", &caracter) != EOF)
		{
			//atualizando a quantidade de caracteres
			cont++;
		}
		
		//fechando o arquivo
		fclose (arq);
		
		//retornando a quantidade de caracteres do arquivo
		return cont;
	}
}
