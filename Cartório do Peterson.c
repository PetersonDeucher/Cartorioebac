#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro() // função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string é um conjunto de variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refece-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //Criar o arquivo
	file = fopen(arquivo, "w"); //Criar o arquivo e o "w" significa escrever
	fprintf(file,cpf); //Salva o arquivo da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); // criar o arquivo
	fprintf(file,","); // Salva o arquino da variavél
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",nome); //%s refece-se a string
	
	file = fopen(arquivo, "a"); // criar o arquivo
	fprintf(file,nome); // Salva o arquino da variavél
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a");  // criar arquivo
	fprintf(file,","); //salva o arquivo da variavél
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coleta informação do usuário
	scanf("%s",sobrenome); // refere-se a uma string
	
	file = fopen(arquivo, "a");// criar o arquivo
	fprintf(file,sobrenome); // Salva o arquino da variavél
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // criar o arquivo
	fprintf(file,","); // Salva o arquino da variavél
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coleta informação do usuário
	scanf("%s",cargo); //refere-se a uma string
	
	file = fopen(arquivo, "a"); //criar arquivo
	fprintf(file,cargo); //salva o arquivio na variável
	fclose(file);	// fecha o arquivo
	
    system("pause"); // Onde fica a tela parada

}

int consulta() //função responsavél por consultar o usuário no sistema
{
	
	setlocale (LC_ALL, "Portuguese_Brazil.1252"); //Definindo a linguagem
	
    char cpf[40]; //"char" armazenar um  caractere
    char conteudo[200];//"char" armazenar um  caractere
	
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
  	
    FILE *file; // criar um arquivo
    file = fopen(cpf,"r"); // criar um arquivo e "r" significa ler
  	
    if(file == NULL) //"if" faça isso,"se"
{
	  printf("Não foi possivel abrir o arquivo, não localizado!.\n");
}
	
    while(fgets(conteudo, 200, file) != NULL)
{
	printf("\nEssas são as informações do usuário: ");
	printf("%s", conteudo);
	printf("\n\n");
}
  	
    system ("pause");
}

int deletar() // função reponsável por deletar o usuário do sistema
{
	char cpf[40];//"char" armazenar um  caractere
	
	printf("Digite o cpf do usuário a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!. \n");
		printf("Usuário deletado com sucesso! \n");
		
		system("pause");
	}
}
int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	  system("cls");
	
	  setlocale (LC_ALL, "Portuguese_Brazil.1252"); //Definindo s linguagem
	
 	  printf("### cartório da EBAC ###\n\n"); //início do menu
	  printf("Escolha a opção desejada do menu:\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar nomes\n");
	  printf("\t3 - Deletar nomes\n\n"); 
	  printf("\t4 - Sair do Sistema\n\n");
	  printf("Opção: "); //\Fim do mnu
	  
	  scanf("%d", &opcao); //Armazenado a escolha do usuário
	
	  system("cls"); // responsavél por limpar a tela
	  
	  switch(opcao) //inicio da seleção
	  {
	  	case 1:
	  	registro(); // chamada de funcões
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");
		return 0; //significa retorna ao valor 0, sair do sistema.
		break;
		
		default:
		printf("Essa opção não está disponivel!\n");
		system("pause");
		break;
	  }
	  	
	}
}
