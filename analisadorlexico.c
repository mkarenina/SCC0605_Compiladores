//SCC0605 - Teoria da Computacao e Copiladores
//Trabalho 1
//Analisador Lexico//SCC0605 - Teoria da Computacao e Copiladores
//Trabalho 1
//Analisador Lexico

//Alunos:
//Leonardo
//Marianna Karenina de Almeida Flores - 10821144
//Renan 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Tamanho_Maximo 50
#define Tamanho_Hash 17

char *lido;

void escreve_ArqSaida(char *palavra, FILE *saida){

    fputs(palavra, saida);
    fputs(", simb_", saida);
    fputs(palavra, saida);
    fprintf(saida, "\n");

    return;
}

void escreve_ArqSaida_TamMax(char *lido, FILE *saida){

    fputs(lido, saida);
	fputs(", Tamanho Maximo Atingido\n", saida);
	
    return;
}


//------------------------- Confere Palavras Reservadas -------------------------------- 
void palavras_reservadas(char *palavra, FILE *saida){


	if((strcmp(palavra, "program")) == 0){

		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "var")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "begin")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "to")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "do")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "else")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "then")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "if")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "procedure")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "begin")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "integer")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "const")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "while")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "for")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "read")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "write")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "end")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}
	
	fputs(palavra, saida);
	fputs(", id\n", saida);
	fputs(palavra, saida);

	return;
}



int lexico(FILE *entrada, FILE *saida){
    int lendo = 0;
    int i = 0; 
	int j = 0;
    int flag_pos = 1;
    int flag_tamMax = 0;
	int int_ou_real = 0;

	printf("lido0: %c\n", lido[i]);

//------------- Automato Identificador -----------------------
    if((lido[i]>64 && lido[i]<91) || (lido[i]>96 && lido[i]<123)){ //conferindo valor ASCII
			i++;
			lendo =fscanf(entrada, "%c", &lido[1]);

			int flag_tamMaximo = 0;

			while(((lido[i]>64 && lido[i]<91) || (lido[i]>96 && lido[i]<123) || (lido[i]>47 && lido[i]<58)) && flag_tamMax == 0){
                i++;
				if(i<Tamanho_Maximo){
					lendo=fscanf(entrada, "%c", &lido[i]);
				}
				else{
					flag_tamMax=1; //informa que o tamanho máximo foi atingido
				}
			}

			printf("lido-1: %c\n", lido[i-1]);
			printf("lido: %c\n", lido[i]);

			if(flag_tamMax==0){
				char *palavra;
				palavra=malloc((i+1)*sizeof(char));
				for(j=0;j<i;j++){
					palavra[j]=lido[j];
				}
				palavra[i] = '\0';

				char aux = lido[i];
				memset(lido, 0, Tamanho_Maximo*sizeof(char));
				i=0;
				lido[i]=aux;
				flag_pos=0;
				printf("palavra: %s\n", palavra);
				palavras_reservadas(palavra, saida);
				free(palavra);
			}

			else{
				fputs(lido, saida);
				fputs(", Tamanho Máximo do Identificador Atingido\n", saida);
				memset(lido, 0, Tamanho_Maximo*sizeof(char));
				i=0;
			}
	}

//--------------------- Automato Numeral ---------------------------
if(lido[i]>47 && lido[i]<58){

			//printf("entrou numeral\n");
			
			flag_tamMax = 0;		

			while((lido[i]>47 && lido[i]<58) && flag_tamMax==0){
				i++;
				if(i<Tamanho_Maximo){
					lendo=fscanf(entrada, "%c", &lido[i]);
				}
				else{
					flag_tamMax=1;
				}
			}
			if(lido[i]==46){//caso .
				int_ou_real=1;
				i++;		//fla2
				if(i<Tamanho_Maximo){
					lendo=fscanf(entrada, "%c", &lido[i]);
				}
				else{
					flag_tamMax=1;
				}
				while((lido[i]>47 && lido[i]<58) && flag_tamMax==0){
					i++;
					if(i<Tamanho_Maximo){
						lendo=fscanf(entrada, "%c", &lido[i]);
					}
					else{
						flag_tamMax=1;
					}
				}
			}
			if(flag_tamMax==0){
				for(int j=0; j<i; j++){
					fprintf(saida, "%c", lido[j]);
				}
				char aux = lido[i];
				memset(lido, 0, Tamanho_Maximo*sizeof(char));
				i=0;
				lido[i]=aux;
				if(lido[i]==9 || lido[i]==10 || lido[i]==32 || (lido[i]>39 && lido[i]<48) || (lido[i]>57 && lido[i]<63) || lido[i]== 123){
					if(!int_ou_real){
						fputs(", numero_inteiro\n", saida);
					}
					else{
						fputs(", numero_real\n", saida);
					}
				}
				else{
					if((lido[i]>64 && lido[i]<91) || (lido[i]>96 && lido[i]<123)){
						fputs(", !!ERRO!! Caracter INVALIDO\n", saida);
					}
					else{
						fputs(", !!ERRO!! Formatado invalido\n", saida);
					}
					
				}
				flag_pos=0;
			}
			else{
				escreve_ArqSaida_TamMax(lido, saida);
				i=0;
			}
		}

//--------------------- Automato Operador --------------------------
		if((lido[i]>39 && lido[i]<48) || (lido[i]>57 && lido[i]<63)){

			switch(lido[i]){
				case 40:	//caso (
					fprintf(saida, "'(', simb_AbreParenteses\n");
					break;
				case 41:	//caso )
					fprintf(saida, "')', simb_AbreParenteses\n");
					break;
				case 42:	//caso *
					fprintf(saida, "'*', simb_Multiplicacao\n");
					break;
				case 43:	//caso +
					fprintf(saida, "'+', simb_Adicao\n");
					break;
				case 44:	//caso ,
					fprintf(saida, "',', simb_Virgula\n");
					break;
				case 45:	//caso -
					fprintf(saida, "'-', simb_Subtracao\n");
					break;
				case 46:	//caso .
					fprintf(saida, "'.', simb_Ponto\n");
					break;
				case 47:	//caso /
					fprintf(saida, "'/', simb_Divisao\n");
					break;
				case 58:	//caso :
					lendo=fscanf(entrada, "%c", &lido[i]);
					if(lido[i]==61){
						fprintf(saida, "':=', simb_Atribuicao\n");
					}
					else{
						fprintf(saida, "':', simb_DoisPontos\n");
						flag_pos = 0;
					}
					break;
				case 59:	//caso ;
					fprintf(saida, "';', simb_PontoVirgula\n");
					break;
				case 60:	//caso <
					lendo=fscanf(entrada, "%c", &lido[i]);
					if(lido[i]==62){
						fprintf(saida, "'<>', simb_Relacao\n");
					}
					else{
						if(lido[i]==61){
							fprintf(saida, "'<=', simb_Relacao\n");
						}
						else{
							fprintf(saida, "'<', simb_Menor\n");
							flag_pos = 0;
						}
					}
					break;
				case 61:	//caso =
					fprintf(saida, "'=', simb_Igual\n");
					break;
				case 62:	//caso >
					lendo=fscanf(entrada, "%c", &lido[i]);
					if(lido[i]==61){
						fprintf(saida, "'>=', simb_Relacao\n");
					}
					else{
						fprintf(saida, "'>', simb_Maior\n");
						flag_pos = 0;
					}
					break;
			}
		}

//--------------------Automato Comentarios -------------------------
    if(lido[i]=='{'){

		lendo=fscanf(entrada, "%c", &lido[i]);

			while(lido[i]!='}' && lido[i]!=10){
				lendo=fscanf(entrada, "%c", &lido[i]); //comentarios sao ignorados 
			}		
	}
//-------------- Tratamento de Caracter Invalido
	if((lido[i]>32 && lido[i]<40) || lido[i]== 63 || lido[i]== 64 || (lido[i]>90 && lido[i]<97) || lido[i]>124){
		
		//printf("entrou trata caracter\n");

		if(lido[i]==125){
			fprintf(saida, "%c, !!ERRO!! '}' sozinho. Comentario nao foi inicializado\n", lido[i]);
		}
		else{
			fprintf(saida, "%c, !!ERRO!! Caracter INValido \n", lido[i]);
			}
		flag_pos=1;
	} 

//------------ Fim
	if(flag_pos){	//flag_pos=1 ler novo caracter, flag_pos=0 caracter na memoria

		//printf("entrou fim\n");

		lendo=fscanf(entrada, "%c", &lido[i]);
	}
	
	return lendo;
}


//------------- main ------------------
int main(int argc, char *argv[]){
    int lendo = 0;
    FILE *entrada;
    FILE *saida;
    lido = calloc(Tamanho_Maximo, sizeof(char));
    entrada = fopen(argv[1], "rt");
    saida = fopen("saida.txt", "wt");

    if(entrada == NULL){
        fputs("Sem entrada\n", saida);
        return 0;
    }

    lendo = fscanf(entrada, "%c", &lido[0]);

    while(lendo != EOF){
        lendo = lexico(entrada, saida);
    }

    free(lido);
    fclose(entrada);
    fclose(saida);
    return 0;
}

//Alunos:
//Leonardo
//Marianna Karenina de Almeida Flores - 10821144
//Renan 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Tamanho_Maximo 50
#define Tamanho_Hash 17

char *lido;

void escreve_ArqSaida(char *palavra, FILE *saida){

    fputs(palavra, saida);
    fputs(", simb_", saida);
    fputs(palavra, saida);
    fprintf(saida, "\n");

    return;
}

void escreve_ArqSaida_TamMax(char *lido, FILE *saida){

    fputs(lido, saida);
	fputs(", Tamanho Maximo Atingido\n", saida);
	
    return;
}


//------------------------- Confere Palavras Reservadas -------------------------------- 
void palavras_reservadas(char *palavra, FILE *saida){


	if((strcmp(palavra, "program")) == 0){

		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "var")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "begin")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "to")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "do")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "else")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "then")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "if")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "procedure")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "begin")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "integer")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "const")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "while")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "for")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "read")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "write")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}

	if((strcmp(palavra, "end")) == 0){
		escreve_ArqSaida(palavra, saida);
		return;
	}
	
	fputs(palavra, saida);
	fputs(", id\n", saida);
	fputs(palavra, saida);

	return;
}



int lexico(FILE *entrada, FILE *saida){
    int lendo = 0;
    int i = 0; 
	int j = 0;
    int flag_pos = 1;
    int flag_tamMax = 0;
	int int_ou_real = 0;

//------------- Automato Identificador -----------------------
    if((lido[i]>64 && lido[i]<91) || (lido[i]>96 && lido[i]<123)){ //conferindo valor ASCII
			i++;
			lendo =fscanf(entrada, "%c", &lido[1]);

			int flag_tamMaximo = 0;

			while(((lido[i]>64 && lido[i]<91) || (lido[i]>96 && lido[i]<123) || (lido[i]>47 && lido[i]<58)) && flag_tamMax == 0){
				
                i++;

				if(i<Tamanho_Maximo){
					lendo=fscanf(entrada, "%c", &lido[i]);
				}
				else{
					flag_tamMax=1; //informa que o tamanho máximo foi atingido
				}
			}

			if(flag_tamMax==0){
				char *palavra;
				palavra=malloc((i)*sizeof(char));
				for(j=0;j<i;j++){
					palavra[j]=lido[j];
				}

				char aux = lido[i];
				memset(lido, 0, Tamanho_Maximo*sizeof(char));
				i=0;
				lido[i]=aux;
				flag_pos=0;
				//printf("palavra: %s", palavra)
				palavras_reservadas(palavra, saida);
				free(palavra);
			}

			else{
				fputs(lido, saida);
				fputs(", Tamanho Máximo do Identificador Atingido\n", saida);
				memset(lido, 0, Tamanho_Maximo*sizeof(char));
				i=0;
			}
	}

//--------------------- Automato Numeral ---------------------------
if(lido[i]>47 && lido[i]<58){

			//printf("entrou numeral\n");
			
			flag_tamMax = 0;		

			while((lido[i]>47 && lido[i]<58) && flag_tamMax==0){
				i++;
				if(i<Tamanho_Maximo){
					lendo=fscanf(entrada, "%c", &lido[i]);
				}
				else{
					flag_tamMax=1;
				}
			}
			if(lido[i]==46){//caso .
				int_ou_real=1;
				i++;		//fla2
				if(i<Tamanho_Maximo){
					lendo=fscanf(entrada, "%c", &lido[i]);
				}
				else{
					flag_tamMax=1;
				}
				while((lido[i]>47 && lido[i]<58) && flag_tamMax==0){
					i++;
					if(i<Tamanho_Maximo){
						lendo=fscanf(entrada, "%c", &lido[i]);
					}
					else{
						flag_tamMax=1;
					}
				}
			}
			if(flag_tamMax==0){
				for(int j=0; j<i; j++){
					fprintf(saida, "%c", lido[j]);
				}
				char aux = lido[i];
				memset(lido, 0, Tamanho_Maximo*sizeof(char));
				i=0;
				lido[i]=aux;
				if(lido[i]==9 || lido[i]==10 || lido[i]==32 || (lido[i]>39 && lido[i]<48) || (lido[i]>57 && lido[i]<63) || lido[i]== 123){
					if(!int_ou_real){
						fputs(", numero_inteiro\n", saida);
					}
					else{
						fputs(", numero_real\n", saida);
					}
				}
				else{
					if((lido[i]>64 && lido[i]<91) || (lido[i]>96 && lido[i]<123)){
						fputs(", !!ERRO!! Caracter INVALIDO\n", saida);
					}
					else{
						fputs(", !!ERRO!! Formatado invalido\n", saida);
					}
					
				}
				flag_pos=0;
			}
			else{
				escreve_ArqSaida_TamMax(lido, saida);
				i=0;
			}
		}

//--------------------- Automato Operador --------------------------
		if((lido[i]>39 && lido[i]<48) || (lido[i]>57 && lido[i]<63)){

			switch(lido[i]){
				case 40:	//caso (
					fprintf(saida, "'(', simb_AbreParenteses\n");
					break;
				case 41:	//caso )
					fprintf(saida, "')', simb_AbreParenteses\n");
					break;
				case 42:	//caso *
					fprintf(saida, "'*', simb_Multiplicacao\n");
					break;
				case 43:	//caso +
					fprintf(saida, "'+', simb_Adicao\n");
					break;
				case 44:	//caso ,
					fprintf(saida, "',', simb_Virgula\n");
					break;
				case 45:	//caso -
					fprintf(saida, "'-', simb_Subtracao\n");
					break;
				case 46:	//caso .
					fprintf(saida, "'.', simb_Ponto\n");
					break;
				case 47:	//caso /
					fprintf(saida, "'/', simb_Divisao\n");
					break;
				case 58:	//caso :
					lendo=fscanf(entrada, "%c", &lido[i]);
					if(lido[i]==61){
						fprintf(saida, "':=', simb_Atribuicao\n");
					}
					else{
						fprintf(saida, "':', simb_DoisPontos\n");
						flag_pos = 0;
					}
					break;
				case 59:	//caso ;
					fprintf(saida, "';', simb_PontoVirgula\n");
					break;
				case 60:	//caso <
					lendo=fscanf(entrada, "%c", &lido[i]);
					if(lido[i]==62){
						fprintf(saida, "'<>', simb_Relacao\n");
					}
					else{
						if(lido[i]==61){
							fprintf(saida, "'<=', simb_Relacao\n");
						}
						else{
							fprintf(saida, "'<', simb_Menor\n");
							flag_pos = 0;
						}
					}
					break;
				case 61:	//caso =
					fprintf(saida, "'=', simb_Igual\n");
					break;
				case 62:	//caso >
					lendo=fscanf(entrada, "%c", &lido[i]);
					if(lido[i]==61){
						fprintf(saida, "'>=', simb_Relacao\n");
					}
					else{
						fprintf(saida, "'>', simb_Maior\n");
						flag_pos = 0;
					}
					break;
			}
		}

//--------------------Automato Comentarios -------------------------
    if(lido[i]=='{'){

		lendo=fscanf(entrada, "%c", &lido[i]);

			while(lido[i]!='}' && lido[i]!=10){
				lendo=fscanf(entrada, "%c", &lido[i]); //comentarios sao ignorados 
			}		
	}
//-------------- Tratamento de Caracter Invalido
	if((lido[i]>32 && lido[i]<40) || lido[i]== 63 || lido[i]== 64 || (lido[i]>90 && lido[i]<97) || lido[i]>124){
		
		//printf("entrou trata caracter\n");

		if(lido[i]==125){
			fprintf(saida, "%c, !!ERRO!! '}' sozinho. Comentario nao foi inicializado\n", lido[i]);
		}
		else{
			fprintf(saida, "%c, !!ERRO!! Caracter INValido \n", lido[i]);
			}
		flag_pos=1;
	} 

//------------ Fim
	if(flag_pos){	//flag_pos=1 ler novo caracter, flag_pos=0 caracter na memoria

		//printf("entrou fim\n");

		lendo=fscanf(entrada, "%c", &lido[i]);
	}
	
	return lendo;
}


//------------- main ------------------
int main(int argc, char *argv[]){
    int lendo = 0;
    FILE *entrada;
    FILE *saida;
    lido = calloc(Tamanho_Maximo, sizeof(char));
    entrada = fopen(argv[1], "rt");
    saida = fopen("saida.txt", "wt");

    if(entrada == NULL){
        fputs("Sem entrada\n", saida);
        return 0;
    }

    lendo = fscanf(entrada, "%c", &lido[0]);

    while(lendo != EOF){
        lendo = lexico(entrada, saida);
    }

    free(lido);
    fclose(entrada);
    fclose(saida);
    return 0;
}
