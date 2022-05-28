//SCC0605 - Teoria da Computacao e Copiladores
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

char *lido

void escreve_ArqSaida(char *palavra, FILE *saida){

    fputs(palavra, saida);
    fputs(", simb_", saida);
    fputs(palavra, saida);
    fprintf(saida, "\n");

    return;
}

//------------------------- Confere Palavras Reservadas -------------------------------- 
void palavras_reservadas(char *palavra, FILE *saida){

    switch(palavra){

        case 'program':
            escreve_ArqSaida(palavra, saida);
            break;

        case 'var':
            escreve_ArqSaida(palavra, saida);
            break;
        
        case 'begin':
            escreve_ArqSaida(palavra, saida);
            break;
        
        case 'to':
            escreve_ArqSaida(palavra, saida);
            break;
        
        case 'do':
            escreve_ArqSaida(palavra, saida);
            break;

        case 'else':
            escreve_ArqSaida(palavra, saida);
            break;
        
        case 'then':
            escreve_ArqSaida(palavra, saida);
            break;
        
        case 'if':
            escreve_ArqSaida(palavra, saida);
            break;
        
        case 'procedure':
            escreve_ArqSaida(palavra, saida);
            break;

        case 'integer':
            escreve_ArqSaida(palavra, saida);
            break;
        
        case 'real':
            escreve_ArqSaida(palavra, saida);
            break;
        
        case 'const':
            escreve_ArqSaida(palavra, saida);
            break;
        
        case 'while':
            escreve_ArqSaida(palavra, saida);
            break;

        case 'for':
            escreve_ArqSaida(palavra, saida);
            break;
        
        case 'read':
            escreve_ArqSaida(palavra, saida);
            break;
        
        case 'write':
            escreve_ArqSaida(palavra, saida);
            break;
        
        case 'end':
            escreve_ArqSaida(palavra, saida);
            break;  

        default:
            fputs(palavra, saida);
	        fputs(", id\n", saida); 
    }

    return;

}

int lexico(FILE *entrada, FILE *saida){
    int lendo = 0;
    int i, j = 0;
    int flag_pos, flag_tamMax = 0;
    char aux;

//------------- Automato Identificador -----------------------
    if((lido[i]>64 && lido[i]<91) || (lido[i]>96 && lido[i]<123)){ //conferindo valor ASCII
			//i++;
			lido=fscanf(entrada, "%c", &lido[1]);
			while(((lido[i]>64 && lido[i]<91) || (lido[i]>96 && lido[i]<123) || (lido[i]>47 && lido[i]<58)) && flag_tamMax==0){
				
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

				aux = lido[i];
				memset(lido, 0, Tamanho_Maximo*sizeof(char));
				i=0;
				lido[i]=aux;
				flag_pos=0;
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
					if(s[t]==61){
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
					lendo=fscanf(ent, "%c", &lido[i]);
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