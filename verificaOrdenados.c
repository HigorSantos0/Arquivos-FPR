/*
	FAETERJ-Rio
	FPR Manhã - 20/04/2022
	
	Lista de Exercícios VII (Arquivos)
	
	Questão 04:
	Desenvolver uma função que, dado um arquivo texto contendo números, 
	determine se estes encontram-se ordenados crescentemente.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int verificarOrdenacao (char nomeArq[]);

//main
void main ()
{
	//declaração de variáveis
	char nomeArquivo[20];
	int resultado;
	
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nomeArquivo);
	
	//chamando a função
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

//implementação das funções
int verificarOrdenacao (char nomeArq[])
{
	//declaração de variáveis
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
		
		//lendo os demais números do arquivo
		while (fscanf (arq, "%d", &valor) != EOF)
		{
			//verificando se os elementos não estão ordenados
			if (valor < anterior)
			{
				fclose (arq);
				
				//os elementos do arquivo não estão ordenados
				return 0;
			}
			else
			{
				//atualizando o 'anterior'
				anterior = valor;
			}
		}	
		
		//se chegou aqui, os elementos estão ordenados
		fclose (arq);
		
		return 1;	
	}
}
