
/*
	FAETERJ-Rio
	FPR Manh� - 20/04/2022
	
	Lista de Exerc�cios VII (Arquivos)
	
	Quest�o 02:
	Desenvolver uma fun��o que, dado um arquivo texto, verifique o 
	n�mero de vezes que um determinado caracter aparece no arquivo.
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int quantidadeCaracteres (char nomeArq[], char caracter);

//main
void main ()
{
	//declara��o de vari�veis
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
	
	//chamando a fun��o
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

//implementa��o das fun��es
int quantidadeCaracteres (char nomeArq[], char caracter)
{
	//declara��o de vari�veis
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
			//verificando se o caracter lido � aquele sendo buscado
			//if (toupper(ch) == toupper(caracter))
			if (toupper(ch) == caracter)
			{
				//atualizando o n�mero de ocorr�ncias
				cont++;
			}
		}
		
		//fechando o arquivo
		fclose (arq);
		
		//retornando a quantidade de caracteres do arquivo
		return cont;
	}
}
