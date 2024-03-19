#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar dos string
int registro()
{
	//incio da criação de variaveis/string
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis/string
	
	printf("Digite o cpf a ser cadastrado: ");  //coletando informação do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por criar os valores da string[]
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); //salva o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" serve para atualizar sem precisar abrir o arquivo
	fprintf(file, ","); //a "," serve para pular uma linha para a informação de cima não ficar colada com a de baixo
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s" , sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado:");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //para definir a linguagem que o usuario vai ler 
	
	//inicio das variaveis/string
	char cpf[40];
	char conteudo[200];
	//final das variaveis/string
	
	printf("Digite o CPF a ser localizado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //o "r" serve para ler a string e trazer a informação da mesma
	
	if(file == NULL) //se o arquivo for = a nulo/nao existe, ele vai aparecer a mensagem abaixo
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n ");
	}
	
	while(fgets(conteudo, 200, file) != NULL); //enquanto o sistema procura no arquivo e na variavel/string 200x no arquivo diferente de nulo, vai aparecer a mensagem abaixo
	{
		printf("\nEssas são as informações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");		
	}
	system("pause");
}

int deletar()
{
	//inicio da string/variavel
	char cpf[40];
	//final da string/variavel
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);

	
	FILE *file;  //abre e acessa o arquivo
	file = fopen(cpf, "r");  //esse R serve para ler a string e trazer as informações
	fclose(file);
	
	if(file == NULL) //se o arquivo for igual a nada/nulo, vai aparecer a mensagem abaixo
	{
		printf("Esse usuário não se encontra no sistema!.\n");
		system("pause");		
	}
	remove(cpf); //ele vai ate a string/variavel e vai deletar a informação
	
	if(file != NULL) //se o arquivo for diferente de nulo, vai parecer a mensagem abaixo
	{
		printf("Usuario deletado com sucesso!\n\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
		printf("### Cartorio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - deletar nomes\n\n");
		printf("opcao: "); //fim do menu
		
		scanf("%d", &opcao); //arnazenando a escolha do usuario
    
    	system("cls");
    	
    	switch(opcao) //inicio da seleção
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
			printf("Essa opção não está disponivel\n\n");
			system("pause");
			break;	
			
			printf("Esse software é de livre uso dos alunos!\n");
			
		}
    	
	printf("Esse software é de livre uso dos alunos\n");
		
	}
 } 
 
