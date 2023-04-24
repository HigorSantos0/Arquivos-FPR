#include <stdio.h>

void main()
{
	FILE *arq;
	char nomeArq[20];
	int num, i;
	
	//Lendo o nome do arquivo
	
	printf("Entre com o nome do arquivo: ");
	gets(nomeArq);
	
	printf("Entre com o numero: ");
	scanf("%d", &num);
	
	//Abrindo o Arquivo
	// W, R ou A;
	//nesse exemplo - Abrindo para Escrita
	arq = fopen(nomeArq, "w");
	
	//testanto se o arquivo foi aberto ou não
	if(arq == NULL)
	{
		printf("Erro ao tentar abrir o Arquivo\n");
	}
	else
		{
			for(i = 1; i <= num; i++)
			{
				fprintf(arq, "%d\n", i);
			}
			fclose (arq);		
		}
	
}

