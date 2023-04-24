

#include <stdio.h>

//exemplo 2, fazer uma que crie um arquivo com numeros de 1 a N, um por linha

int criarArquivo(char nomeArq[], int num);

void main()
{
	FILE *arq;
	char nomeArq[20];
	int i, num;
	
	printf("Entre com o nome do arquivo: ");
	gets(nomeArq);
	
	printf("Entre com o numero: ");
	scanf("%d", &num);
	
	//Abrindo o Arquivo
	// W, R ou A;
	//nesse exemplo - Abrindo para Escrita
	
	if(criarArquivo(nomeArq, num) == 0)
	{
		printf("Erro na abertura do arquivo\n");	
	}
	else
		{
			printf("Arquivo gerado com sucesso\n");
		}
	
}
int criarArquivo(char nomeArq[], int num)
{
	FILE *arq;
	int  i;
	
	//Abrindo o Arquivo
	// W, R ou A;
	//nesse exemplo - Abrindo para Escrita
	arq = fopen(nomeArq, "w");
	
	//testanto se o arquivo foi aberto ou não
	if(arq == NULL)
	{
		return 0;
	}
	else
		{
			for(i = 1; i <= num; i++)
			{
				fprintf(arq, "%d\n", i);
			}
			fclose (arq);	
			
			return 1;	
		}
	
}

