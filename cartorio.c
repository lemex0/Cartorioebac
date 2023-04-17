#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço de memoria
#include <locale.h> //biblioteca de alocação de texto ppor região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //funçao responsavel por cadastrar os usuarios nos sistema
{
	//inicio ciaçao das variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação das variaveis
	
	printf("Digite o CPF a ser cadastrado:");
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	file = fopen (arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // "fopen"para abrir o arquivo file /"a" atualizar 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consulta()
{
		setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
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
	char cpf[200];
	printf("DIgite o CPF do usuário a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
	printf("O usuario não se encontra no sistema!.\n");
	system("pause");	
	}
	
}


int main ()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	 
	for(laco=1;laco=1;)
	{

		system("cls");
		
		setlocale(LC_ALL, "Portuguese");
		//defenindo a linguagem
	
		printf ("###cartório da EBAC###!\n\n");
		printf ("Escolha as opções do menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n"); //fim do Menu
		printf("Qual opção deseja?");

		scanf("%d", &opcao); //armazenado a escolha do usuário
	
		system("cls"); //responsavel por limpar a tela
			
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro();
			break;
				
			case 2:
			consulta();
			break;
					
			case 3:
			deletar();
			break;
					
			default:
			printf("Essa opção nao está disponivel!\n");
			system("pause");
			break;
			//fim da seleção
		}

	} 
}	
