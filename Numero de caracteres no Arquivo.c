/*
	FAETERJ-Rio
	FPR Manhã - 20/04/2022
	
	Lista de Exercícios VII (Arquivos)
	
	Questão 01:
	Desenvolver uma função que, dado um arquivo texto, verifique 
	o número de caracteres no mesmo.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int quantidadeCaracteres (char nomeArq[]);

//main
void main ()
{
	//declaração de variáveis
	char nomeArquivo[20];
	int quant;
	
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nomeArquivo);
	
	//chamando a função
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

//implementação das funções
int quantidadeCaracteres (char nomeArq[])
{
	//declaração de variáveis
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
