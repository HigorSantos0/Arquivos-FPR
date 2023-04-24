/*
	FAETERJ-Rio
	FPR Manh� - 20/04/2022
	
	Lista de Exerc�cios VII (Arquivos)
	
	Quest�o 05:
	Fa�a uma fun��o que, dado um arquivo A contendo n�meros reais, 
	um por linha, crie um novo arquivo B contendo os mesmos elementos 
	de A, por�m ordenados decrescentemente e sem repeti��o.
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <float.h>

//prot�tipos das fun��es
int criarArquivoOrdenado (char nomeArqA[], char nomeArqB[]);
int buscarMaiorElemento (char nomeArq[], float limite, float *maior);

//main
void main ()
{
	//declara��o de vari�veis
	char nomeArquivoA[20], nomeArquivoB[20];
	int resultado;
	
	//lendo o nome do arquivo A
	printf ("Entre com o nome do arquivo original: ");
	fflush (stdin);
	gets (nomeArquivoA);

	//lendo o nome do arquivo B
	printf ("Entre com o nome do novo arquivo: ");
	fflush (stdin);
	gets (nomeArquivoB);	
	
	//chamando a fun��o
	resultado = criarArquivoOrdenado (nomeArquivoA, nomeArquivoB);
	
	//verificando o restorno
	if (resultado == 0)
	{
		printf ("\nErro na abertura dos arquivos!");
	}
	else
	{
		printf ("\nArquivo gerado com sucesso!");
	}
}

//implementa��o das fun��es
int criarArquivoOrdenado (char nomeArqA[], char nomeArqB[])
{
	//declara��o de vari�veis
	FILE *arqB;
	float ultimo = FLT_MAX, valor;
			
	//abrindo o arquivo a ser gerado
	arqB = fopen (nomeArqB, "w");
	
	//verificando se houve erro na abertura do arquivo
	if (!arqB)
	{
		return 0;	//representando que houve erro
	}
	else
	{
		//buscando no arquivo original o maior elemento que seja inferior
		//ao �ltimo inserido no novo arquivo
		while (buscarMaiorElemento (nomeArqA, ultimo, &valor) != 0)
		{
			//inserindo no novo arquivo o elemento encontrado
			fprintf (arqB, "%.2f\n", valor);
			
			//atualizando o 'ultimo'
			ultimo = valor;
		}
		
		//fechando o novo arquivo
		fclose (arqB);
		
		return 1;
	}
}

int buscarMaiorElemento (char nomeArq[], float limite, float *maior)
{
	//declara��o de arquivos
	FILE *arq;
	float ma = FLT_MIN, numero;
	int mudou = 0;
	
	//abrindo o arquivo
	arq = fopen (nomeArq, "r");
	
	//houve erro?
	if (!arq)
	{
		return -1;
	}
	else
	{
		//lendo os valores do arquivo
		while (fscanf (arq, "%f", &numero) != EOF)
		{
			//verificando se o n�mero lido � menor do que o limite
			if ((numero < limite) && (numero > ma)) //e se � maior do que 'ma'
			{
				ma = numero;  //atualizando o maior n�mero
				mudou = 1;
			}
		}
		
		//fechando o arquivo
		fclose (arq);
		
		//retornando...
		if (mudou == 1)
		{
			*maior = ma;
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
