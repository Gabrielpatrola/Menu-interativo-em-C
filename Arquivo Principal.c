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
#define T10 
#define TAMANHO_PILHA 10

//structs de cadastro dos alunos
typedef struct aluno{
	char nome[100];
	char RGA[13];
	char endereco[100];
	char email[100];
	char nome_pai[100];
	char nome_mae[100];
	char celular[12];
	char data[11];
	char cidade[100];
	char bairro[100];
	char curso[60];
	int semestre;
	char campus [60];
	int codigo;
}alunos;

typedef struct cadastro{ 
    alunos numero; 
    struct cadastro *proximo; 
}cadastros;


typedef struct Filas{ 
    cadastros *inicio; 
    cadastros *fim; 
}Fila;

//funcao para verificar se a fila de alunos esta vazia
int EstaVazia(Fila *fila){ 
    return fila->inicio == NULL; 
}

//funcao para realizar o cadastro dos alunos
void Inserir_Alunos(Fila *fila, int elemento){ 
    cadastros *novo; 
    novo = (cadastros *)malloc(sizeof(cadastros));  
	int aux;
    // -> Verifica se a mem?ria foi alocada com sucesso 
    if (novo != NULL){ 
    	system("cls");
        for(int i=24;i<95;i++){
			gotoxy(i,22);printf("-"); //For para o prenchimento da parte inferior do menu
		}        
		for(int i=6;i<22;i++){
			gotoxy(95,i);printf("|"); //For para o prenchimento da parte lateral do menu
		} 
		for(int i=6;i<22;i++){
			gotoxy(23,i);printf("|"); //For para o prenchimento da parte lateral do menu
		} 
    	fflush(stdin);
        novo->numero.codigo = elemento;
		gotoxy(24,5);printf("---------------------------- ALUNO ------------------------------------"); 
        gotoxy(24,6);printf("  Digite nome:");
        fgets(novo->numero.nome, 100, stdin);
        fflush(stdin);
        
        gotoxy(24,7);printf("  Digite a data de nascimento:");
        fgets(novo->numero.data, 11, stdin);
        fflush(stdin);
        
        gotoxy(24,8);printf("  Digite o RGA:");
        fgets(novo->numero.RGA, 13, stdin);
        fflush(stdin);
        
        gotoxy(24,9);printf("  Digite o e-mail:");
        fgets(novo->numero.email, 100, stdin);
        fflush(stdin);
        
       	gotoxy(24,10);printf("  Digite o numero de celular:");
        fgets(novo->numero.celular, 16, stdin);
        fflush(stdin);
        
        gotoxy(24,11);printf("  Digite o nome do pai:");
        fgets(novo->numero.nome_pai, 100, stdin);
        fflush(stdin);
        
       	gotoxy(24,12);printf("  Digite o nome da mãe:");
        fgets(novo->numero.nome_mae, 100, stdin);
        fflush(stdin);
        
        gotoxy(24,13);printf("  Digite o endereco:");
        fgets(novo->numero.endereco, 100, stdin);
        fflush(stdin);
        
        gotoxy(24,14);printf("  Digite a cidade:");
        fgets(novo->numero.cidade, 100, stdin);
        fflush(stdin);
        
        gotoxy(24,15);printf("  Digite o Bairro:");
        fgets(novo->numero.bairro, 100, stdin);
        fflush(stdin);
        
        gotoxy(24,16);printf("  Digite o Curso:");
        fgets(novo->numero.curso, 60, stdin);
        fflush(stdin);
        
        gotoxy(24,17);printf("  Digite o Semestre:");
        scanf("%d", &aux);
        novo->numero.semestre = aux;
        fflush(stdin);
        
        gotoxy(24,18);printf("  Digite o Campus:");
        fgets(novo->numero.campus, 60, stdin);
        fflush(stdin);
        novo->proximo = NULL;
        gotoxy(26,19);system("pause");
		
        if(EstaVazia(fila)){ 
            // -> Primeiro cadastro da Fila. 
            fila->inicio = novo; 
            fila->fim = novo; 
        } 
        else{ 
            // -> Ultimo cadastro da Fila 
            fila->fim->proximo = novo; 
            fila->fim=novo; 
        } 
    } 
}

//funcao para inicializar a fila de cadastro de alunos
void Inicializar(Fila **fila){ 
    // -> Recebe a fila por referencia 
    //    para inicializ?-la 
    *fila = (Fila *) malloc(sizeof(Fila)); 
    (*fila)->inicio = NULL; 
    (*fila)->fim = NULL; 
}

//funcao para retirar cadastro de alunos
void Retirar(Fila *fila){ 
    cadastros *cadastro;
    if(!EstaVazia(fila)){ 
        cadastro = fila->inicio; 
        fila->inicio = cadastro->proximo; 
        free(cadastro);

        // -> Se a fila acabou devemos atualizar o final 
        if (fila->inicio == NULL) 
            fila->fim = NULL; 
    } 
}

//funcao para mostrar a fila de alunos
void MostrarFila_Aluno(Fila *fila) {  
    int i = 0; 
    cadastros *cadastro; 
    if (EstaVazia(fila)){ 	
    system("cls");
    	printf ("A Fila esta vazia!\n"); 
    } 
    else{       
        cadastro = fila->inicio;
        while(cadastro != NULL){ 
            i++; 
            system("cls");
            for(int i=24;i<95;i++){
				gotoxy(i,22);printf("-"); //For para o prenchimento da parte inferior do menu
			}        
			for(int i=6;i<22;i++){
				gotoxy(95,i);printf("|"); //For para o prenchimento da parte lateral do menu
			}         
            gotoxy(24,5);printf("---------------------------- ALUNO -------------------------------------");
            gotoxy(24,6);printf( "| Cadastro [%i]",i); 
            gotoxy(24,7);printf("| Codigo-> %d", cadastro->numero.codigo); 
            gotoxy(24,8);printf("| Nome do Aluno-> %s", cadastro->numero.nome); 
            gotoxy(24,9);printf("| RGA -> %s", cadastro->numero.RGA); 
            gotoxy(24,10);printf("| Endereço -> %s", cadastro->numero.endereco); 
            gotoxy(24,11);printf("| E-mail -> %s", cadastro->numero.email); 
            gotoxy(24,12);printf("| Nome do Pai -> %s", cadastro->numero.nome_pai); 
            gotoxy(24,13);printf("| Nome da mãe -> %s", cadastro->numero.nome_mae); 
            gotoxy(24,14);printf("| Celular -> %s", cadastro->numero.celular); 
            gotoxy(24,15);printf("| Data de nascimento -> %s", cadastro->numero.data); 
            gotoxy(24,16);printf("| Cidade -> %s", cadastro->numero.cidade); 
            gotoxy(24,17);printf("| Bairro -> %s", cadastro->numero.bairro); 
            gotoxy(24,18);printf("| Curso -> %s", cadastro->numero.curso); 
            gotoxy(24,19);printf("| Semestre-> %d", cadastro->numero.semestre); 
            gotoxy(24,20);printf("| Campus -> %s", cadastro->numero.campus);  
			gotoxy(24,21);printf("|");
			gotoxy(26,21);system("pause");
			cadastro = cadastro->proximo; 
        } 
    }
}

//funcao para ordernar o vetor antes da busca binaria
void insertion_sort(int vetor[], int tamanhoVetor){
	int escolhido, j;
    for (int i = 1; i < tamanhoVetor; i++) {
			escolhido = vetor[i];
			j = i - 1;	
				while ((j >= 0) && (vetor[j] > escolhido)){
					vetor[j + 1] = vetor[j];
					j--;
				}
			vetor[j + 1] = escolhido;
	}
}

//funcao busca binaria
int buscaBinaria(int vet[], int n, int chave){
	int posIni = 0, posFim = n - 1, posMeio;
	/* enquanto o trecho do vetor considerado tiver pelo menos um elemento */
	while (posIni <= posFim){
		posMeio = (posIni + posFim) / 2;
		if (vet[posMeio] == chave)
			return posMeio;
		else if (vet[posMeio] > chave)
			posFim = posMeio - 1;
		else
			posIni = posMeio + 1;
}
return -1;
}

//funcao para inserir valor na fila
void Inserir( int fila[], int *fim, int tam, int valor ){  
	fila[(*fim)] = valor;    
	*fim= (*fim)+1; 
} 

//funcao para remover valor da fila
int Remover(int fila[], int *fim ){ 
	int excluido, posicaoAux;    
	excluido = fila[0];       
	*fim = (*fim-1);    
  		for ( posicaoAux=0; posicaoAux < *fim; posicaoAux++ ){        
  			fila[posicaoAux] = fila[ posicaoAux + 1 ];      
  	}    
  	 return excluido; 
} 
 
//funcao para inserir valor na pilha
void inserirValorPilha( int pilha[], int *topoPilha, int tamanhoMaxPilha, int valor ){    
	if ( *topoPilha < tamanhoMaxPilha ){      
		pilha[*topoPilha] = valor;       
		*topoPilha = (*topoPilha)+1; 
	} 
} 

//funcao para remover valor da pilha
int removerValorPilha(int pilha[], int *topoPilha){     
	int retorno = -1;     
		if (*topoPilha > 0){        
			*topoPilha = (*topoPilha)-1;        
			retorno = pilha[*topoPilha];     
	}      
	return retorno; 
} 

int menu_principal(); //funcao que desenha o menu na tela
int main(){	
	system("Color 30");
	setlocale(LC_ALL,""); // acentuacao
	menu_principal(); // funcao para abrir o menu principal
	system("cls"); //limpar tela
	return 0;
}

//funcao para posicionamento dos menus
void gotoxy( int x, int y ){
	COORD coord;
	coord.X = (short)x;
	coord.Y = (short)y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//funcao contendo o menu aluno e seus sub menus
int menu_aluno(){
	system("Color 30");	
	Fila *fila = NULL; 
	Inicializar(&fila);
	int aux, numero;
	int posicao = 6, tecla;
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
			if (tecla == ESC){
				main();
			}
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
				gotoxy(23,6);printf("| Digite um numero:            |"); 
				gotoxy(24,7);printf("------------------------------");
                gotoxy(42,6);scanf("%d", &numero);
                Inserir_Alunos(fila, numero); 
                MostrarFila_Aluno(fila);
                system("cls");
 				goto inicio;
			}
			if(posicao == 7){
					system("cls");
	                MostrarFila_Aluno(fila);
					system("cls");
					goto inicio;
				}
			if(posicao == 8){
				main();
				}
	return posicao;
}

//funcao contendo o sub menu Sobre
int sobre(){
	system("Color 30");	
	int aux;
	int posicao = 6, tecla;	
		do{
			system("cls");
			gotoxy(25,5);printf("------------------------------ SOBRE ----------------------------------------");
			gotoxy(24,6);printf("| O trabalho consiste na criação de um programa que permita que o usuário     |");
			gotoxy(24,7);printf("| faça a utilização das Estruturas de Pilha e Fila Estática.                  |");
			gotoxy(24,8);printf("| Nome do Programa: Trabalho 01                                               |");
			gotoxy(24,9);printf("| Nome do Aluno: Gabriel Augusto Queiroz de Almeida                           |");
			gotoxy(24,10);printf("|                                                                             |");
			gotoxy(24,11);printf("|                                                                             |");
			gotoxy(26,10);system ("  date /t" );
			gotoxy(26,11);system ("   time /t");
			gotoxy(24,12);printf("| Aperte enter para voltar ao menu principal....                              |");
				for(int i=25;i<102;i++){
					gotoxy(i,13);printf("-"); //For para o prenchimento da parte inferior do menu
				}
			tecla=getch();
				if(tecla == ENTER){
				main(); //voltar para tela principal
				}
			if (tecla == ESC){
				main();
			}	
		}while(tecla!= ENTER);
			return posicao;
}

//funcao contem o Menu pilha e seus sub menus
int menu_pilha(){	
	system("Color 30");	
	int pilha[TAMANHO_PILHA];
	int topoPilha = 0; //considera que uma a ser inciada tem valor de topo = 0
	int valor,cont,remo,op;
	int opcao, busca;
	int aux;
	int x;
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
			if (tecla == ESC){
				main();
			}	
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
							insertion_sort(pilha, 10);
							system("cls");
							gotoxy(24,4);printf("----------------- Pilha ------------");
							gotoxy(24,5);printf("digite o valor que deseja procurar:");
							gotoxy(24,6);scanf("%d", &x);
							int pos = buscaBinaria(pilha, 10,x);
							system("cls");
							
							if (pos != -1){
								gotoxy(24,4);printf("----------------- Pilha ------------");
								gotoxy(24,5);printf("Elemento [%d] encontrado na posição [%d]\n",x, pos);
								gotoxy(24,6);system("pause");
							}
							else{
								gotoxy(24,4);printf("----------------- Pilha ------------");
								gotoxy(24,5);printf("Elemento [%d]não encontra-se no vetor!\n", x);
								gotoxy(24,6);system("pause");
							}
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

//funcao contem o menu fila e seus sub menus
int menu_fila(){
	system("Color 30");	
	int fila[10];
 	int fim = 0; //considera que uma fila a ser inciada tem valor de fim = 0
 	int valor,cont,op,excluido;int tam=10;
	int opcao,busca;
	int aux;
	int posicao = 6, tecla;
	int x;
	inicio:
		do{
			system("cls");
			gotoxy(24,5);printf("--------------------- Fila ----------------------");
			gotoxy(23,6);printf("|                     Inserir                     |");
			gotoxy(23,7);printf("|                     Excluir                     |");
			gotoxy(23,8);printf("|                     Listar                      |");
			gotoxy(23,9);printf("|                     Buscar                      |");
			gotoxy(23,10);printf("|                     Voltar                      |");
			for(int i=24;i<73;i++){
				gotoxy(i,11);printf("-"); //For para o prenchimento da parte inferior do menu
			}  
			gotoxy(24,posicao);printf("%c%c",62,62);gotoxy(71,posicao);printf("%c%c",60,60);  //setinhas de seleção
			tecla=getch();
			if (tecla == ESC){
				main();
			}	
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
						for(int i=24;i<73;i++){
							gotoxy(i,8);printf("-"); //For para o prenchimento da parte inferior do menu
						}
						gotoxy(73,6);printf("|");
						gotoxy(73,7);printf("|");
						gotoxy(23,7);printf("|");
						gotoxy(24,5);printf("--------------------- Fila ----------------------");
						gotoxy(23,6);printf("| Informe o valor a inserir:");
 						scanf("%d",&valor);
						Inserir(fila,&fim,tam,valor);
					 }
					 else{
					 	for(int i=24;i<73;i++){
							gotoxy(i,8);printf("-"); //For para o prenchimento da parte inferior do menu
						}
						gotoxy(73,6);printf("|");
						gotoxy(73,7);printf("|");
						gotoxy(23,7);printf("|");
						gotoxy(24,5);printf("--------------------- Fila ----------------------");
					 	gotoxy(23,6);printf("| Fila Cheia");
 					}
 					gotoxy(25,7);system("Pause"); 
 					goto inicio;
 					break;
 				}
				case 7:{
					system("cls");
					if (fim>0){
						excluido=Remover(fila,&fim); 
						for(int i=24;i<73;i++){
							gotoxy(i,8);printf("-"); //For para o prenchimento da parte inferior do menu
						}
						gotoxy(73,6);printf("|");
						gotoxy(73,7);printf("|");
						gotoxy(23,7);printf("|");
						gotoxy(24,5);printf("--------------------- Fila ----------------------");
 						gotoxy(23,6);printf("| Elemento [%d] Excluido da Fila                  ",excluido);
 						gotoxy(25,7);system("Pause");
 					}
					else{
						for(int i=24;i<73;i++){
							gotoxy(i,8);printf("-"); //For para o prenchimento da parte inferior do menu
						}

						gotoxy(73,7);printf("|");
						gotoxy(23,7);printf("|");
						gotoxy(24,5);printf("--------------------- Fila ----------------------");
 						gotoxy(23,6);printf("| Fila Vazia                                      |");
						gotoxy(25,7);system("Pause");
					}
						goto inicio;
						break;
				}		
				case 8:{
					system("cls");
					for(int i=24;i<73;i++){
							gotoxy(i,10);printf("-"); //For para o prenchimento da parte inferior do menu
					}  
					gotoxy(24,5);printf("--------------------- Fila ----------------------");
					gotoxy(23,6);printf("| 1  - Ordem Crescente                            |");
					gotoxy(23,7);printf("| 2  - Ordem Decrescente                          |");
					gotoxy(23,8);printf("| Escolha a opcao:                                |");
					gotoxy(23,9);printf("|                                                 |");
					gotoxy(25,9);scanf("%d",&op);
		
					switch(op){
						case 1:{
						system("cls");
						if (fim!=0){
							       for(int i=24;i<73;i++){
										gotoxy(i,22);printf("-"); //For para o prenchimento da parte inferior do menu
									}        
									for(int i=6;i<22;i++){
										gotoxy(72,i);printf("|"); //For para o prenchimento da parte lateral do menu
									} 
									for(int i=6;i<22;i++){
										gotoxy(23,i);printf("|"); //For para o prenchimento da parte lateral do menu
									} 
							for (cont =0;cont<fim;cont++){
								gotoxy(24,4);printf("--------------------- Fila --------------------");
								gotoxy(25,6+cont);
								printf("elemento [%d] ===== %d",cont, fila[cont]);
							}
							gotoxy(25,5);system("Pause");
 						}
						else{
							for(int i=24;i<71;i++){
								gotoxy(i,7);printf("-"); //For para o prenchimento da parte inferior do menu
							}      
							gotoxy(23,6);printf("|                                               |");
							gotoxy(24,4);printf("--------------------- Fila ----------------------");
							gotoxy(23,5);printf("| Fila Vazia                                    |");
 							gotoxy(25,6);system("Pause");
 						}
 						goto inicio;
 						break;
 					}
 						case 2:{
						system("cls");
						if (fim>0){
							int aux = 0;
							for (cont = fim-1;cont>=aux;aux++){
								gotoxy(23,5);printf("|");
								gotoxy(24,4);printf("--------------------- Fila ----------------------");
								gotoxy(23,6+aux);printf("elemento [%d] ===== %d",cont-aux, fila[cont-aux]);
							}
							gotoxy(25,5);system("Pause");
 						}
						else{
							for(int i=24;i<71;i++){
								gotoxy(i,7);printf("-"); //For para o prenchimento da parte inferior do menu
							}      
							gotoxy(23,6);printf("|                                               |");
							gotoxy(24,4);printf("--------------------- Fila ----------------------");
							gotoxy(23,5);printf("| Fila Vazia                                    |");
 							gotoxy(25,6);system("Pause");
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
					for(int i=24;i<73;i++){
						gotoxy(i,10);printf("-"); //For para o prenchimento da parte inferior do menu
					}
					gotoxy(24,5);printf("--------------------- Fila ----------------------");
					gotoxy(23,6);printf("| 1  - Busca Sequencial                           |");
					gotoxy(23,7);printf("| 2  - Ordem Binária                              |");
					gotoxy(23,8);printf("| Escolha a opcao:                                |");
					gotoxy(23,9);printf("|                                                 |");
					gotoxy(25,9);scanf("%d",&opcao);
					switch(opcao){
						case 1:{
						system("cls");
								gotoxy(24,4);printf("--------------------- Fila ----------------------");
								gotoxy(23,5);printf("Informe o número que deseja procurar:");
								gotoxy(23,6);printf("|                                   |");
								gotoxy(25,6);scanf("%d",&busca);
								if (fim>0){
									system("cls");
									for(cont = 0; cont<fim; cont++){
											if(fila[cont] == busca){
												gotoxy(24,4);printf("--------------------- Fila ----------------------");
										 		gotoxy(23,5);printf("Elemento [%d] encontrado na posição [%d]", busca, cont);
										 		gotoxy(23,6);system("pause");
										 		goto inicio;
										 	}
								}
									gotoxy(24,4);printf("--------------------- Fila ----------------------");
									gotoxy(23,5);printf("Elemento [%d] não encontrado", busca);
									gotoxy(23,6);system("pause");
								}
								else{
									gotoxy(24,4);printf("--------------------- Fila ----------------------");
									gotoxy(23,5);printf("Lista vazia");
									gotoxy(23,6);system("pause");
									goto inicio;
							}
						}
						goto inicio;
 						break;
 						case 2:{
 							insertion_sort(fila, 10);
							system("cls");
							gotoxy(24,4);printf("--------------------- Fila ----------------------");
							gotoxy(24,5);printf("digite o valor que deseja procurar:");
							gotoxy(24,6);scanf("%d", &x);
							int pos = buscaBinaria(fila, 10,x);
							system("cls");
							if (pos != -1){
								gotoxy(24,4);printf("--------------------- Fila ----------------------");
								gotoxy(24,5);printf("Elemento [%d] encontrado na posição [%d]\n",x, pos);
								gotoxy(24,6);system("pause");
							}
							else{
								gotoxy(24,4);printf("--------------------- Fila ----------------------");
								gotoxy(24,5);printf("Elemento [%d] não encontra-se no vetor!\n", x);
								gotoxy(24,6);system("pause");
							}
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

//funcao do menu principal contem as chamadas para os submenus
int menu_principal(){
	int posicao = 6, tecla;		
		do{
			system("cls");
			gotoxy(24,5);printf("--------------------- MENU ----------------------");
			gotoxy(23,6);printf("|                     Aluno                       |");
			gotoxy(23,7);printf("|                     Pilha                       |");
			gotoxy(23,8);printf("|                     Fila                        |");
			gotoxy(23,9);printf("|                     Sobre                       |");
			gotoxy(23,10);printf("|                     Sair                        |");
				for(int i=24;i<73;i++){
					gotoxy(i,11);printf("-"); //For para o prenchimento da parte inferior do menu
				}
			gotoxy(24,posicao);printf("%c%c",62,62);gotoxy(71,posicao);printf("%c%c",60,60);  //setinhas de seleção
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
