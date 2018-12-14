#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <conio2.h>
#include <string.h>
#include <windows.h>
#include <time.h>   //função para mostrar data e hora
#include <locale.h> // Para colocar acentos, acrescenta-se o código abaixo dentro do int main setlocale(LC_ALL,"")

#define max  10

struct aluno{
	char nome[100];
	char RGA[13];
	char endereco[100];
	char email[100];
	char nome_pai[100];
	char nome_mae[100];
	char celular[12];
	char data[11];
	char cidade[60];
	char bairro[100];
	char curso[60];
	int semestre;
	char campus [60];
};


int main(){
	int i=0;
	/*Criando a variável aluno que será do
  tipo struct ficha_de_aluno */
  struct aluno cadastro[10];
  
  	printf("\n---------- Cadastro de aluno -----------\n\n\n");
  
  	printf("Nome do aluno ......: ");
  	fflush(stdin);
  	fgets(cadastro[i].nome, 100, stdin);
  
 	printf("RGA ......: ");
 	fflush(stdin);
  	fgets(cadastro[i].RGA, 13, stdin);
  
   	printf("Informe cidade ..: ");
 	fflush(stdin);
  	fgets(cadastro[i].cidade, 60, stdin);
  
   	printf("Informe o endereco..: ");
 	fflush(stdin);
  	fgets(cadastro[i].endereco, 100, stdin);
  	
	printf("Nome do bairro ......: ");
  	fflush(stdin);
  	fgets(cadastro[i].bairro, 100, stdin);
  	
	printf("Informe  o email..: ");
 	fflush(stdin);
  	fgets(cadastro[i].email, 100, stdin);
  
	printf("Nome do pai ......: ");
  	fflush(stdin);
  	fgets(cadastro[i].nome_pai, 100, stdin);
  
 	printf("Nome da mae ......: ");
  	fflush(stdin);
 	fgets(cadastro[i].nome_mae, 100, stdin);
  		
 	printf("Informe o celular ..: ");
  	fflush(stdin);
  	fgets(cadastro[i].celular, 12, stdin);
	  
 	printf("Informe data de nascimento..: ");
 	fflush(stdin);
 	fgets(cadastro[i].data, 11, stdin);
 	
 	printf("Curso ......: ");
  	fflush(stdin);
 	fgets(cadastro[i].curso, 60, stdin);
  		
 	printf("Informe o semestre ..: ");
	scanf("%d", &cadastro[i].semestre);
	  
 	printf("Informe o campus ..: ");
 	fflush(stdin);
 	fgets(cadastro[i].campus, 60, stdin);
  
  
  ///////////////////////////////
  
	printf("\n\n --------- Lendo os dados da struct ---------\n\n");
	printf("Nome ...........: %s\n", cadastro[i].nome);
	printf("RGA  .....: %s\n", cadastro[i].RGA);
	printf("Cidade ...........: %s\n", cadastro[i].cidade);
	printf("Endereco ...: %s\n" , cadastro[i].endereco);
	printf("Bairro .....: %s\n", cadastro[i].bairro);
	printf("Email ...: %s\n" , cadastro[i].email);
	printf("Nome Pai ...........: %s\n", cadastro[i].nome_pai);
	printf("Nome mae .....: %s\n", cadastro[i].nome_mae);
	printf("Celular ...: %s\n" , cadastro[i].celular);
	printf("Data de nascimento ...: %s\n" , cadastro[i].data);
	printf("Curso ...: %s\n" , cadastro[i].curso);
	printf("Semestre ...: %d\n" , cadastro[i].semestre);
	printf("Campus ...........: %s\n", cadastro[i].campus);
  
  getch();
  return(0);
}
