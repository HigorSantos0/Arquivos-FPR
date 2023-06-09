/*
	FAETERJ-Rio
	FPR Manh� - 20/04/2022
	
	Lista de Exerc�cios VII (Arquivos)
	
	Quest�o 03:
	Desenvolver uma fun��o que, dado um arquivo texto, verifique o 
	n�mero de letras existentes no mesmo (entendendo que no arquivo 
	podem existir letras, algarismos e s�mbolos).
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int quantidadeLetras (char nomeArq[]);

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

//implementa��o das fun��es
int quantidadeLetras (char nomeArq[])
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
		//lendo todos os caracteres do arquivo
		while (fscanf (arq, "%c", &ch) != EOF)
		{
			ch = toupper (ch);
			
			//verificando se o caracter lido � uma letra			
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
