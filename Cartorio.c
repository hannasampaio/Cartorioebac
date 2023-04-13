#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usúario
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,","); //salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando informação do usúario
	scanf("%s",nome); // %s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,nome); //salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,","); //salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usúario
	scanf("%s",sobrenome); // %s refere-se a string
	
	file = fopen(arquivo, "a");//cria o arquivo
	fprintf(file,sobrenome);//salvo o valor da variável
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");//cria o arquivo
	fprintf(file,",");//salvo o valor da variável
	fclose(file);// fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação do usúario
	scanf("%s",cargo); // %s refere-se a string
	
	file = fopen(arquivo, "a");//cria o arquivo
	fprintf(file,cargo);//salvo o valor da variável
	fclose(file);// fecha o arquivo
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//início criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//final criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf); // %s refere-se a string
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
//início criação de variáveis/string
	char cpf[40];
//início criação de variáveis/string
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
	}
	
}

int main()
	{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");//responsável por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); // Armazenamento a escolha do usuário
	
		system("cls");//responsável por limpar a tela
		
		
		switch(opcao)
		{
			case 1:
			registro();//chamada de função
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
				
		}
	
	}
}
