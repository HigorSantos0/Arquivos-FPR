/*
	FAETERJ-Rio
	FPR Manhã - 20/04/2022
	
	Lista de Exercícios VII (Arquivos)
	
	Questão 03:
	Desenvolver uma função que, dado um arquivo texto, verifique o 
	número de letras existentes no mesmo (entendendo que no arquivo 
	podem existir letras, algarismos e símbolos).
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int quantidadeLetras (char nomeArq[]);

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
	quant = quantidadeLetras (nomeArquivo);
	
	//testando se houve erro
	if (quant == -1)
	{
		printf ("\nErro na abertura do arquivo!");
	}
	else
	{
		printf ("\nForam encontradas %d letras no arquivo %s.", quant, nomeArquivo);
	}
}

//implementação das funções
int quantidadeLetras (char nomeArq[])
{
	//declaração de variáveis
	FILE *arq;
	char ch;
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
		while (fscanf (arq, "%c", &ch) != EOF)
		{
			ch = toupper (ch);
			
			//verificando se o caracter lido é uma letra			
			if ((ch >= 'A') && (ch <= 'Z'))
			{
				cont++;
			}
		}
		
		//fechando o arquivo
		fclose (arq);
		
		//retornando a quantidade de caracteres do arquivo
		return cont;
	}
}	
