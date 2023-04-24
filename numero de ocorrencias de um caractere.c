
/*
	FAETERJ-Rio
	FPR Manhã - 20/04/2022
	
	Lista de Exercícios VII (Arquivos)
	
	Questão 02:
	Desenvolver uma função que, dado um arquivo texto, verifique o 
	número de vezes que um determinado caracter aparece no arquivo.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int quantidadeCaracteres (char nomeArq[], char caracter);

//main
void main ()
{
	//declaração de variáveis
	char nomeArquivo[20];
	char ch;
	int quant;
	
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nomeArquivo);
	
	//lendo o caracter a ser buscado no arquivo
	printf ("Entre com o caracter a ser buscado: ");
	fflush (stdin);
	scanf ("%c", &ch);
	
	//chamando a função
	quant = quantidadeCaracteres (nomeArquivo, ch);
	
	//testando se houve erro
	if (quant == -1)
	{
		printf ("\nErro na abertura do arquivo!");
	}
	else
	{
		printf ("\nO caracter %c aparece %d vezes no arquivo %s.", ch, quant, nomeArquivo);
	}
}

//implementação das funções
int quantidadeCaracteres (char nomeArq[], char caracter)
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
		caracter = toupper (caracter);
		
		//lendo todos os caracteres do arquivo
		while (fscanf (arq, "%c", &ch) != EOF)
		{
			//verificando se o caracter lido é aquele sendo buscado
			//if (toupper(ch) == toupper(caracter))
			if (toupper(ch) == caracter)
			{
				//atualizando o número de ocorrências
				cont++;
			}
		}
		
		//fechando o arquivo
		fclose (arq);
		
		//retornando a quantidade de caracteres do arquivo
		return cont;
	}
}
