#include <stdio.h> //Biblioteca de comunicação com usuário.
#include <stdlib.h> //Biblioteca de alocação de espaço de memória.
#include <locale.h> //Biblioteca de alocações de texto por região.
#include <string.h> //Biblioteca responsável por cuidar das strings.

int registro(){ //Função para cadastrar usuarios no sistema.
	
	//criação das variaveis string.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); // %s = armazena strings.
	
	strcpy(arquivo, cpf); //Copia o valor da string, passando o valor do cpf para o arquivo.
	
	FILE *file; //cria um arquivo
	file = fopen(arquivo, "w"); // "w" = escrever no arquivo.
	fprintf(file,cpf); //Salva o valor da variavel.
	fclose(file); //fecha o arquivo.
	
	file = fopen(arquivo, "a"); // "a" = Atualiza o arquivo.
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");

}

int consulta(){ //Função para consultar os dados do sistema.
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" = Ler o arquivo cpf.

	if(file == NULL){ //Validação para arquivos não encotrados.
		printf("Arquivo não existe.");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar(){ //Função para deletar usuários.
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); //Deletar cpf.
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL){ //Validação para CPF's inexistentes.
		printf("CPF não encontrado! \n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0;
	int x=1;
	
	for(x=1; x=1;){
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");
		//Inicio Menu	
		printf("### Cartório da EBAC ###\n\n");                                   
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1- Registrar Nomes\n");
		printf("\t2- Consultar Nomes\n");
		printf("\t3- Deletar Nomes\n\n");
		printf("Opção:");
		//Fim Menu
		
		scanf("%d", &opcao); // "%d" armazena um valor do tipo inteiro
	
		system("cls"); //Limpa a tela
		
		switch(opcao){
			case 1:
			registro(); //Chamada de funções.
			break;
			
			case 2:
			consulta(); //Chamada de funções.
			break;
			
			case 3:
			deletar(); //Chamada de funções.
			break;
			
			default: //Validação para números fora do menu.
			printf("Erro: Escolha uma das opções apresentadas!\n");
			system("pause");
			break;
		}
	}
}
