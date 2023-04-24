/*
	FAETERJ-Rio
	FPR Manh� - 20/04/2022
	
	Lista de Exerc�cios VII (Arquivos)
	
	Quest�o 04:
	Desenvolver uma fun��o que, dado um arquivo texto contendo n�meros, 
	determine se estes encontram-se ordenados crescentemente.
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int verificarOrdenacao (char nomeArq[]);

//main
void main ()
{
	//declara��o de vari�veis
	char nomeArquivo[20];
	int resultado;
	
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nomeArquivo);
	
	//chamando a fun��o
	resultado = verificarOrdenacao (nomeArquivo);
	
	//verificando o restorno
	switch (resultado)
	{
		case -1: printf ("\nErro na abertura do arquivo!");
		         break;
		         
		case  1: printf ("\nO arquivo esta ordenado!");
		         break;
		         
		case  0: printf ("\nO arquivo nao esta ordenado!");
	}
}

//implementa��o das fun��es
int verificarOrdenacao (char nomeArq[])
{
	//declara��o de vari�veis
	FILE *arq;
	int valor, anterior;
		
	//abrindo o arquivo
	arq = fopen (nomeArq, "r");
	
	//verificando se houve erro na abertura do arquivo
	//if (arq == NULL)
	if (!arq)
	{
		return -1;	//representando que houve erro
	}
	else
	{
		//lendo o primeiro valor do arquivo
		fscanf (arq, "%d", &anterior);
		
		//lendo os demais n�meros do arquivo
		while (fscanf (arq, "%d", &valor) != EOF)
		{
			//verificando se os elementos n�o est�o ordenados
			if (valor < anterior)
			{
				fclose (arq);
				
				//os elementos do arquivo n�o est�o ordenados
				return 0;
			}
			else
			{
				//atualizando o 'anterior'
				anterior = valor;
			}
		}	
		
		//se chegou aqui, os elementos est�o ordenados
		fclose (arq);
		
		return 1;	
	}
}
