/*************************************************************************
Nome da Disciplina: EDD
Nome Professor: Leonair Neves Sousa
Nome Aluno: Gabriel Augusto Queiroz de Almeida
Turma: VE1
RGA: 201611901002
Data Entrega:
*************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <conio2.h>
#include <string.h>
#include <windows.h>
#include <time.h>   //função para mostrar data e hora
#include <locale.h> // Para colocar acentos, acrescenta-se o código abaixo dentro do int main setlocale(LC_ALL,"")

//defines para o controle nos menus
#define ACIMA 72
#define ABAIXO 80
#define ENTER 13
#define ESC 27

//defines para utilizacao das filas e pilhas
#define Tam 10 
#define TAMANHO_PILHA 10 

typedef struct aluno{
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
}cadastro;



void Inserir( int fila[], int *fim, int tam, int valor ){  
	fila[(*fim)] = valor;    
	*fim= (*fim)+1; 
} 
 
int Remover(int fila[], int *fim ){ 
	int excluido, posicaoAux;    
	excluido = fila[0];       
	*fim = (*fim-1);    
  		for ( posicaoAux=0; posicaoAux < *fim; posicaoAux++ ){        
  			fila[posicaoAux] = fila[ posicaoAux + 1 ];      
  	}    
  	 return excluido; 
} 
 
void inserirValorPilha( int pilha[], int *topoPilha, int tamanhoMaxPilha, int valor ){    
	if ( *topoPilha < tamanhoMaxPilha ){      
		pilha[*topoPilha] = valor;       
		*topoPilha = (*topoPilha)+1; 
	} 
} 

int removerValorPilha(int pilha[], int *topoPilha){     
	int retorno = -1;     
		if (*topoPilha > 0){        
			*topoPilha = (*topoPilha)-1;        
			retorno = pilha[*topoPilha];     
	}      
	return retorno; 
} 

int menu_principal();
int main()
{
	setlocale(LC_ALL,""); // acentuacao
	menu_principal(); // funcao para abrir o menu principal
	system("cls"); //limpar tela
	return 0;
}
//funcao para posicionamento dos menus
void gotoxy( int x, int y )
{
	COORD coord;
	coord.X = (short)x;
	coord.Y = (short)y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//funcao do menu "ALUNO"
int menu_aluno(){
	int j;
	int posicao = 6, tecla;
	struct cadastro *aux = malloc(sizeof(cadastro));
	
	inicio:
		do{
			system("cls");
			gotoxy(24,5);printf("------------- ALUNO ----------");
			gotoxy(23,6);printf("|        Cadastrar dados       |");
			gotoxy(23,7);printf("|        Listar dados          |");
			gotoxy(23,8);printf("|        Voltar                |");
				for(int i=24;i<54;i++){
					gotoxy(i,9);printf("-"); //For para o prenchimento da parte inferior do menu
				}
			gotoxy(24,posicao);printf("%c%c",62,62);gotoxy(52,posicao);printf("%c%c",60,60); //setinhas de seleção
			tecla=getch();
		
				if(tecla == ABAIXO){
					posicao=posicao+1;
					if(posicao==9){
						posicao=6;
					}	
				}
				
				if (tecla == ACIMA){
					posicao=posicao-1;
					if(posicao==5){
						posicao=8;
					}
				}

		}while(tecla!= ENTER);
			if(posicao == 6){
				system("cls");
				gotoxy(24,5);printf("------------- ALUNO ----------");
				gotoxy(23,6);printf("Escolha o numero do cadastro:");
				gotoxy(23,7);scanf("%d", &j);
				system("cls");
				
				gotoxy(24,5);printf("------------- ALUNO ----------");
				gotoxy(23,6);printf("Nome do aluno ......: ");
  				fflush(stdin);
  				fgets( aux ->, 100, stdin);
  				system("cls");
  				
  				gotoxy(24,5);printf("------------- ALUNO ----------");
 				gotoxy(23,6);printf("RGA ......: ");
 				fflush(stdin);
  				fgets(cadastro[aux].RGA, 13, stdin);
  				system("cls");
  				
  				gotoxy(24,5);printf("------------- ALUNO ----------");
   				gotoxy(23,6);printf("Informe cidade ..: ");
 				fflush(stdin);
  				fgets(cadastro[aux].cidade, 60, stdin);
  				system("cls");
  				
  				gotoxy(24,5);printf("------------- ALUNO ----------");
   				gotoxy(23,6);printf("Informe o endereco..: ");
 				fflush(stdin);
  				fgets(cadastro[aux].endereco, 100, stdin);
  				system("cls");
  				
  				gotoxy(24,5);printf("------------- ALUNO ----------");
				gotoxy(23,6);printf("Nome do bairro ......: ");
  				fflush(stdin);
  				fgets(cadastro[aux].bairro, 100, stdin);
  				system("cls");
  	
  				gotoxy(24,5);printf("------------- ALUNO ----------");
				gotoxy(23,6);printf("Informe  o email..: ");
 				fflush(stdin);
  				fgets(cadastro[aux].email, 100, stdin);
  				system("cls");
  				
  				gotoxy(24,5);printf("------------- ALUNO ----------");
				gotoxy(23,6);printf("Nome do pai ......: ");
  				fflush(stdin);
  				fgets(cadastro[aux].nome_pai, 100, stdin);
  				system("cls");
  				
  				gotoxy(24,5);printf("------------- ALUNO ----------");
 				gotoxy(23,6);printf("Nome da mae ......: ");
  				fflush(stdin);
 				fgets(cadastro[aux].nome_mae, 100, stdin);
  				system("cls");
  				
  				gotoxy(24,5);printf("------------- ALUNO ----------");
 				gotoxy(23,6);printf("Informe o celular ..: ");
  				fflush(stdin);
  				fgets(cadastro[aux].celular, 12, stdin);
  				system("cls");
	 		 	
	 		 	gotoxy(24,5);printf("------------- ALUNO ----------");
 				gotoxy(23,6);printf("Informe data de nascimento..: ");
 				fflush(stdin);
 				fgets(cadastro[aux].data, 11, stdin);
 				system("cls");
 					
 				gotoxy(24,5);printf("------------- ALUNO ----------");
 				gotoxy(23,6);printf("Curso ......: ");
  				fflush(stdin);
 				fgets(cadastro[aux].curso, 60, stdin);
 				system("cls");
  				
  				gotoxy(24,5);printf("------------- ALUNO ----------");
 				gotoxy(23,6);printf("Informe o semestre ..: ");
				scanf("%d", &cadastro[aux].semestre);
				system("cls");
  				
  				gotoxy(24,5);printf("------------- ALUNO ----------");
 				gotoxy(23,6);printf("Informe o campus ..: ");
 				fflush(stdin);
 				fgets(cadastro[aux].campus, 60, stdin);
 				system("cls"); 
 				goto inicio;
			}
			if(posicao == 7){
				system("cls");  
				gotoxy(24,5);printf("------------- ALUNOS ----------");
				gotoxy(24,4);printf("Digite o numero do cadastro:");
				gotoxy(24,6);scanf("%d", &aux);
				system("cls"); 
				if(aux <=10){
					system("cls"); 
					gotoxy(24,5);printf("------------- ALUNOS ----------");
					gotoxy(24,6);printf("Nome ...........: %s\n", cadastro[aux].nome);
					gotoxy(24,7);printf("RGA  .....: %s\n", cadastro[aux].RGA);
					gotoxy(24,8);printf("Cidade ...........: %s\n", cadastro[aux].cidade);
					gotoxy(24,9);printf("Endereco ...: %s\n" , cadastro[aux].endereco);
					gotoxy(24,10);printf("Bairro .....: %s\n", cadastro[aux].bairro);
					gotoxy(24,11);printf("Email ...: %s\n" , cadastro[aux].email);
					gotoxy(24,12);printf("Nome Pai ...........: %s\n", cadastro[aux].nome_pai);
					gotoxy(24,13);printf("Nome mae .....: %s\n", cadastro[aux].nome_mae);
					gotoxy(24,14);printf("Celular ...: %s\n" , cadastro[aux].celular);
					gotoxy(24,15);printf("Data de nascimento ...: %s\n" , cadastro[aux].data);
					gotoxy(24,16);printf("Curso ...: %s\n" , cadastro[aux].curso);
					gotoxy(24,17);printf("Semestre ...: %d\n" , cadastro[aux].semestre);
					gotoxy(24,18);printf("Campus ...........: %s\n", cadastro[aux].campus);
					gotoxy(24,19);system("Pause"); 
					system("cls"); 
					goto inicio;	
				}
				else{
					printf("numero de cadastro invalido.");
					system("Pause"); 
					goto inicio;
				}
			}
			if(posicao == 8){
					main(); //voltar para tela principal
				}
	return posicao;
}

int sobre(){
	
	int aux;
	int posicao = 6, tecla;
	
		do{
			system("cls");
			gotoxy(2,5);printf("------------------------------- SOBRE ---------------------------------------");
			gotoxy(1,6);printf("| O trabalho consiste na criação de um programa que permita que o usuário     |");
			gotoxy(1,7);printf("| faça a utilização das Estruturas de Pilha e Fila Estática.                  |");
			gotoxy(1,8);printf("| Nome do Programa: Trabalho 01                                               |");
			gotoxy(1,9);printf("| Nome do Aluno: Gabriel Augusto Queiroz de Almeida                           |");
			gotoxy(1,10);printf("|                                                                             |");
			gotoxy(1,11);printf("|                                                                             |");
			gotoxy(3,10);system ("  date /t" );
			gotoxy(3,11);system ("   time /t");
			gotoxy(1,12);printf("| Aperte enter para voltar ao menu principal....                              |");
				for(int i=2;i<79;i++){
					gotoxy(i,13);printf("-"); //For para o prenchimento da parte inferior do menu
				}
			tecla=getch();
				if(tecla == ENTER){
				main(); //voltar para tela principal
				}
		}while(tecla!= ENTER);
			return posicao;
}


int menu_pilha(){
	
	int pilha[TAMANHO_PILHA];
	int topoPilha = 0; //considera que uma a ser inciada tem valor de topo = 0
	int valor,cont,remo,op;
	int opcao, busca;
	int aux;
	int posicao = 6, tecla;
	inicio:
		do{
			system("cls");
			gotoxy(24,5);printf("----------------- Pilha ------------");
			gotoxy(23,6);printf("|                Inserir             |");
			gotoxy(23,7);printf("|                Excluir             |");
			gotoxy(23,8);printf("|                Listar              |");
			gotoxy(23,9);printf("|                Buscar              |");
			gotoxy(23,10);printf("|                Voltar              |");
				for(int i=24;i<60;i++){
					gotoxy(i,11);printf("-"); //For para o prenchimento da parte inferior do menu
				}
			gotoxy(24,posicao);printf("%c%c",62,62);gotoxy(58,posicao);printf("%c%c",60,60);  //setinhas de seleção
			tecla=getch();
				if(tecla == ABAIXO){ 
					posicao=posicao+1;
					if(posicao==11){
						posicao=6;
					}
				}	
				if (tecla == ACIMA){
					posicao=posicao-1;
					if(posicao==5){
						posicao=10; 
					}
				}
		}while(tecla!= ENTER);
			switch(posicao){
				case 6:{
					system("cls");
					if(topoPilha<10){
						gotoxy(24,5);printf("----------------- Pilha ------------");
						gotoxy(23,6);printf("Informe o valor a inserir:");
 						scanf("%d",&valor);
						inserirValorPilha(pilha,&topoPilha, TAMANHO_PILHA,valor);
					 }
					 else{
					 	gotoxy(24,5);printf("----------------- Pilha ------------");
					 	gotoxy(23,6);printf("Pilha Cheia");
 					}
 					gotoxy(23,7);system("Pause"); 
 					goto inicio;
 					break;
 				}
				case 7:{
					system("cls");
					if (topoPilha>0){
						remo=removerValorPilha(pilha,&topoPilha); 
						gotoxy(24,5);printf("----------------- Pilha ------------");
 						gotoxy(23,6);printf("Elemento [%d] Excluido da Pilha",remo);
 						gotoxy(23,7);system("Pause");
 					}
					else{
						gotoxy(24,5);printf("----------------- Pilha ------------");
 						gotoxy(23,6);printf("Pilha Vazia");
						gotoxy(23,7);system("Pause");
					}
						goto inicio;
						break;
				}		
				case 8:{
					system("cls");
					for(int i=24;i<60;i++){
						gotoxy(i,9);printf("-"); //For para o prenchimento da parte inferior do menu
					}
					gotoxy(24,4);printf("----------------- Pilha ------------");
					gotoxy(23,5);printf("| 1  - Ordem Crescente              |");
					gotoxy(23,6);printf("| 2  - Ordem Decrescente            |");
					gotoxy(23,7);printf("| Escolha a opcao:                  |");
					gotoxy(23,8);printf("|                                   |");
					gotoxy(25,8);scanf("%d",&op);
		
					switch(op){
						case 1:{
						system("cls");
						if (topoPilha>0){
							for (cont = 0;cont<topoPilha;cont++){
								gotoxy(24,4);printf("----------------- Pilha ------------");
								gotoxy(23,6+cont);
								printf("elemento [%d] ===== %d",cont, pilha[cont]);
							}
							gotoxy(23,5);system("Pause");
 						}
						else{
							gotoxy(24,4);printf("----------------- Pilha ------------");
							gotoxy(23,5);printf("Pilha Vazia");
 							gotoxy(23,6);system("Pause");
 						}
 						goto inicio;
 						break;
 					}
 						case 2:{
						system("cls");
						if (topoPilha>0){
							int aux = 0;
							for (cont = topoPilha-1;cont>=aux;aux++){
								gotoxy(24,4);printf("----------------- Pilha ------------");
								gotoxy(23,6+aux);
								printf("elemento [%d] ===== %d",cont-aux, pilha[cont-aux]);
							}
							gotoxy(23,5);system("Pause");
 						}
						else{
							gotoxy(24,4);printf("----------------- Pilha ------------");
							gotoxy(23,5);printf("Pilha Vazia");
 							gotoxy(23,6);system("Pause");
 						}
 						goto inicio;
 						break;
 					}
				}
 					goto inicio;
					break;
 				} 	
					case 9:{
				system("cls");
					for(int i=24;i<60;i++){
						gotoxy(i,9);printf("-"); //For para o prenchimento da parte inferior do menu
					}
					gotoxy(24,4);printf("----------------- Pilha ------------");
					gotoxy(23,5);printf("| 1  - Busca Sequencial             |");
					gotoxy(23,6);printf("| 2  - Ordem Binária                |");
					gotoxy(23,7);printf("| Escolha a opcao:                  |");
					gotoxy(23,8);printf("|                                   |");
					gotoxy(25,8);scanf("%d",&opcao);
					switch(opcao){
						case 1:{
						system("cls");
								gotoxy(24,4);printf("----------------- Pilha ------------");
								gotoxy(23,5);printf("Informe o número que deseja procurar:");
								gotoxy(23,6);printf("|                                   |");
								gotoxy(25,6);scanf("%d",&busca);
								if (topoPilha>0){
								system("cls");
									for(cont = 0; cont<topoPilha; cont++){
											if(pilha[cont] == busca){
												gotoxy(24,4);printf("----------------- Pilha ------------");
										 		gotoxy(23,5);printf("Elemento [%d] encontrado na posição [%d]", busca, cont);
										 		gotoxy(23,6);system("pause");
										 		goto inicio;
										 	}
								}
								gotoxy(24,4);printf("----------------- Pilha ------------");
								gotoxy(23,5);printf("Elemento [%d] não encontrado", busca);
								gotoxy(23,6);system("pause");
								}
								else{
								gotoxy(24,4);printf("----------------- Pilha ------------");
								gotoxy(23,5);printf("Pilha vazia");
								gotoxy(23,6);system("pause");
								goto inicio;
							}
						}
						goto inicio;
 						break;
 						case 2:{
						system("cls");
						if (topoPilha>0){
							int aux = 0;
							for (cont = topoPilha-1;cont>=aux;aux++){
								gotoxy(24,4);printf("----------------- Pilha ------------");
								gotoxy(23,6+aux);
								printf("elemento [%d] ===== %d",cont-aux, pilha[cont-aux]);
							}
							gotoxy(23,5);system("Pause");
 						}
						else{
							gotoxy(24,4);printf("----------------- Pilha ------------");
							gotoxy(23,5);printf("Pilha Vazia");
 							gotoxy(23,6);system("Pause");
 						}
 						goto inicio;
 						}
 					
 						
 					}
 					goto inicio;
					break;
 				}
				case 10:
					main(); //voltar para tela principal
				break;
		}
	return posicao;
}

int menu_fila(){
	int fila[10];
 	int fim = 0; //considera que uma fila a ser inciada tem valor de fim = 0
 	int valor,cont,op,excluido;int tam=10;
	int opcao,busca;
	int aux;
	int posicao = 6, tecla;
	inicio:
		do{
			system("cls");
			gotoxy(24,5);printf("----------------- Fila  ------------");
			gotoxy(23,6);printf("|                Inserir             |");
			gotoxy(23,7);printf("|                Excluir             |");
			gotoxy(23,8);printf("|                Listar              |");
			gotoxy(23,9);printf("|                Buscar              |");
			gotoxy(23,10);printf("|                Voltar              |");
				for(int i=24;i<60;i++){
					gotoxy(i,11);printf("-"); //For para o prenchimento da parte inferior do menu
				}
			gotoxy(24,posicao);printf("%c%c",62,62);gotoxy(58,posicao);printf("%c%c",60,60);  //setinhas de seleção
			tecla=getch();
				if(tecla == ABAIXO){
					posicao=posicao+1;
						if(posicao==11){
							posicao=6;
						}
				}
				if (tecla == ACIMA){
					posicao=posicao-1;
					if(posicao==5){
						posicao=10;
					}
				}
		}while(tecla!= ENTER);
			switch(posicao){
				case 6:{
					system("cls");
					if(fim<tam){
						gotoxy(24,5);printf("----------------- Fila ------------");
						gotoxy(23,6);printf("Informe o valor a inserir:");
 						scanf("%d",&valor);
						Inserir(fila,&fim,tam,valor);
					 }
					 else{
					 	gotoxy(24,5);printf("----------------- Fila ------------");
					 	gotoxy(23,6);printf("Fila Cheia");
 					}
 					gotoxy(23,7);system("Pause"); 
 					goto inicio;
 					break;
 				}
				case 7:{
					system("cls");
					if (fim>0){
						excluido=Remover(fila,&fim); 
						gotoxy(24,5);printf("----------------- Fila ------------");
 						gotoxy(23,6);printf("Elemento [%d] Excluido da Fila",excluido);
 						gotoxy(23,7);system("Pause");
 					}
					else{
						gotoxy(24,5);printf("----------------- Fila ------------");
 						gotoxy(23,6);printf("Fila Vazia");
						gotoxy(23,7);system("Pause");
					}
						goto inicio;
						break;
				}		
				case 8:{
					system("cls");
					for(int i=24;i<60;i++){
						gotoxy(i,9);printf("-"); //For para o prenchimento da parte inferior do menu
					}
					gotoxy(24,4);printf("----------------- Fila ------------");
					gotoxy(23,5);printf("| 1  - Ordem Crescente              |");
					gotoxy(23,6);printf("| 2  - Ordem Decrescente            |");
					gotoxy(23,7);printf("| Escolha a opcao:                  |");
					gotoxy(23,8);printf("|                                   |");
					gotoxy(25,8);scanf("%d",&op);
		
					switch(op){
						case 1:{
						system("cls");
						if (fim!=0){
							for (cont =0;cont<fim;cont++){
								gotoxy(24,4);printf("----------------- Fila ------------");
								gotoxy(23,6+cont);
								printf("elemento [%d] ===== %d",cont, fila[cont]);
							}
							gotoxy(23,5);system("Pause");
 						}
						else{
							gotoxy(24,4);printf("----------------- Fila ------------");
							gotoxy(23,5);printf("Fila Vazia");
 							gotoxy(23,6);system("Pause");
 						}
 						goto inicio;
 						break;
 					}
 						case 2:{
						system("cls");
						if (fim>0){
							int aux = 0;
							for (cont = fim-1;cont>=aux;aux++){
								gotoxy(24,4);printf("----------------- Fila ------------");
								gotoxy(23,6+aux);
								printf("elemento [%d] ===== %d",cont-aux, fila[cont-aux]);
							}
							gotoxy(23,5);system("Pause");
 						}
						else{
							gotoxy(24,4);printf("----------------- Fila ------------");
							gotoxy(23,5);printf("Fila Vazia");
 							gotoxy(23,6);system("Pause");
 						}
 						goto inicio;
 						break;
 					}
				}
 					goto inicio;
					break;
 				} 	
			case 9:{
				system("cls");
					for(int i=24;i<60;i++){
						gotoxy(i,9);printf("-"); //For para o prenchimento da parte inferior do menu
					}
					gotoxy(24,4);printf("----------------- Fila ------------");
					gotoxy(23,5);printf("| 1  - Busca Sequencial             |");
					gotoxy(23,6);printf("| 2  - Ordem Binária                |");
					gotoxy(23,7);printf("| Escolha a opcao:                  |");
					gotoxy(23,8);printf("|                                   |");
					gotoxy(25,8);scanf("%d",&opcao);
					switch(opcao){
						case 1:{
						system("cls");
								gotoxy(24,4);printf("----------------- Fila ------------");
								gotoxy(23,5);printf("Informe o número que deseja procurar:");
								gotoxy(23,6);printf("|                                   |");
								gotoxy(25,6);scanf("%d",&busca);
								if (fim>0){
								system("cls");
									for(cont = 0; cont<fim; cont++){
											if(fila[cont] == busca){
												gotoxy(24,4);printf("----------------- Fila ------------");
										 		gotoxy(23,5);printf("Elemento [%d] encontrado na posição [%d]", busca, cont);
										 		gotoxy(23,6);system("pause");
										 		goto inicio;
										 	}
								}
								gotoxy(24,4);printf("----------------- Fila ------------");
								gotoxy(23,5);printf("Elemento [%d] não encontrado", busca);
								gotoxy(23,6);system("pause");
								}
								else{
								gotoxy(24,4);printf("----------------- Fila ------------");
								gotoxy(23,5);printf("Lista vazia");
								gotoxy(23,6);system("pause");
								goto inicio;
							}
						}
						goto inicio;
 						break;
 						case 2:{
						system("cls");
						if (fim>0){
							int aux = 0;
							for (cont = fim-1;cont>=aux;aux++){
								gotoxy(24,4);printf("----------------- Fila ------------");
								gotoxy(23,6+aux);
								printf("elemento [%d] ===== %d",cont-aux, fila[cont-aux]);
							}
							gotoxy(23,5);system("Pause");
 						}
						else{
							gotoxy(24,4);printf("----------------- Fila ------------");
							gotoxy(23,5);printf("Fila Vazia");
 							gotoxy(23,6);system("Pause");
 						}
 						goto inicio;
 						}
 					
 						
 					}
 					goto inicio;
					break;
 				}
				case 10:
					main(); //voltar para tela principal
				break;
		}
	return posicao;
}

int menu_principal(){

	int aux;
	int posicao = 6, tecla;
		
		do{
			system("cls");
			gotoxy(24,5);printf("------------ MENU ----------");
			gotoxy(23,6);printf("|            Aluno           |");
			gotoxy(23,7);printf("|            Pilha           |");
			gotoxy(23,8);printf("|            Fila            |");
			gotoxy(23,9);printf("|            Sobre           |");
			gotoxy(23,10);printf("|            Sair            |");
				for(int i=24;i<52;i++){
					gotoxy(i,11);printf("-"); //For para o prenchimento da parte inferior do menu
				}
			gotoxy(24,posicao);printf("%c%c",62,62);gotoxy(50,posicao);printf("%c%c",60,60);  //setinhas de seleção
			tecla=getch();
				if(tecla == ABAIXO){
					posicao=posicao+1;
					if(posicao==11){
						posicao=6;
					}
				}
				if (tecla == ACIMA){
					posicao=posicao-1;
					if(posicao==5){
						posicao=10;
					}
				}
		}while(tecla!= ENTER);
			switch (posicao){
				case 6:
	 				menu_aluno(); //chamada para o sub menu "aluno"
				break;
				case 7:
					menu_pilha(); //chamada para o sub menu "pilha"
				break;
				case 8:
					menu_fila(); //chamada para o sub menu "fila"
				break;
				case 9:
					sobre(); //chamada para o sub menu "sobre"
				break;
				case 10:
					return 0; //sair do programa
				break;	
			}	
	return posicao;
} 
