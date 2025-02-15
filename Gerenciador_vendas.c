#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h> //necess�rio para usar setlocale


//VARI�VEIS GLOBAIS
int produto_dia[10][7], soma_produto_unidade[10], total_venda_produto_unidade[10], total_venda_de_todos_unidade, entrada_menu;
int escolha_produto, altera_opcao, dia_alterar, dia_exibir,produto_exibir,mais_vendido[1][1], menos_vendido[1][1],posicao_nome_mais, posicao_nome_menos,posicao_venda_mais, posicao_venda_menos,l,k;
float preco_produto[10], soma_produto_valor[10], total_venda_produto_valor[10], total_venda_de_todos_valor, mais_vendidoRS[1],menos_vendidoRS[1];
char nome_produto[10][20]={"FARINHA       : ",
                           "ARROZ         : ",
                           "FEIJ�O        : ",
                           "FRANGO        : ",
                           "CARNE         : ",
                           "SABONETE      : ",
                           "ESCOVA        : ",
                           "PASTA         : ",
                           "SHAMPOO       : ",
                           "CONDICIONADOR : "
                          };
char nome_produto_aux[10][20]={"FARINHA - ",
                               "ARROZ - ",
                               "FEIJ�O - ",
                               "FRANGO - ",
                               "CARNE - ",
                               "SABONETE - ",
                               "ESCOVA - ",
                               "PASTA - ",
                               "SHAMPOO - ",
                               "CONDICIONADOR - "
                               };
char matriz_dia_semana[8][20] = {"DOMINGO",
                          "SEGUNDA",
                          "TER�A",
                          "QUARTA",
                          "QUINTA",
                          "SEXTA",
                          "SABADO"
                          };
int i,j = 0, produto = 0, dia = 0, linha_preco =0;


//FUN��ES
void dia_semana(FILE *arq1){

printf("                  DOM  SEG  TER  QUA  QUI  SEX  SAB\n");
fprintf(arq1,"                  DOM  SEG  TER  QUA  QUI  SEX  SAB\n");

}

void menu(FILE *arq1){

    printf("\n\nESCOLHA UMA OP��O :");
    printf("\n1 - EXIBIR A TABELA DE VENDAS");
    printf("\n2 - EXIBIR DADOS DOS DIAS");
    printf("\n3 - EXIBIR DADOS DOS PRODUTOS");
    printf("\n4 - EXIBIR O PRE�O DE CADA ITEM");
    printf("\n5 - ALTERAR O DADO DE UM ITEM");
    printf("\n6 - GERAR RELAT�RIO");
    printf("\nRESPOSTA :   ");
    scanf("%i", &entrada_menu);

    switch (entrada_menu){
        case 1:
            system("cls");
            exibe_vendas(arq1);
            break;
        case 2:
            system("cls");
            exibe_dados_dia(arq1);
            break;
        case 3:
            system("cls");
            exibe_dados_produto(arq1);
            break;
        case 4:
            system("cls");
            exibe_preco(arq1);
            break;
        case 5:
            system("cls");
            corrije_dado(arq1);
            break;
        case 6:
        system("cls");
            gera_relatorio(arq1);
            break;
}

}

void corrije_dado(){

    system("cls");
    printf("QUAL PRODUTO VOC� DESEJA MODIFICAR? ");
    printf("\n1 - FARINHA");
    printf("\n2 - ARROZ");
    printf("\n3 - FEIJAO");
    printf("\n4 - FRANGO");
    printf("\n5 - CARNE");
    printf("\n6 - SABONETE");
    printf("\n7 - ESCOVA");
    printf("\n8 - PASTA");
    printf("\n9 - SHAMPOO");
    printf("\n10 - CONDICIONADOR\n");
    printf("\nRESPOSTA :   ");
    scanf("%i",&escolha_produto);

    system("cls");
    printf("\nVOC� DESEJA ALTERAR O VALOR (0) OU QUANTIDADE DO PRODUTO(1)?");
    printf("\nRESPOSTA :   ");
    scanf("%i",&altera_opcao);

    switch (altera_opcao){
        case 0:
            printf("\nQUAL O NOVO PRE�O DO PRODUTO?  ");
            scanf("%f",&preco_produto[escolha_produto-1]);
            break;
        case 1:
            printf("\nQUAL O DIA QUE DESEJA ALTERAR?  ");
            printf("\n1 - DOMINGO");
            printf("\n2 - SEGUNDA");
            printf("\n3 - TER�A");
            printf("\n4 - QUARTA");
            printf("\n5 - QUINTA");
            printf("\n6 - SEXTA");
            printf("\n7 - S�BADO");
            printf("\nRESPOSTA :   ");
            scanf("%i",&dia_alterar);
            printf("\nQUAL A NOVA QUANTIA DO PRODUTO?  ");
            scanf("%i",&produto_dia[escolha_produto-1][dia_alterar-1]);
            break;
    }


}

void exibe_dados_dia(FILE *arq1){
    calculo_exibe_dados_dia();

    printf("\nQUAL O DIA QUE VOCE DESEJA VER AS VENDAS ?  ");
    printf("\n1 - DOMINGO");
    printf("\n2 - SEGUNDA");
    printf("\n3 - TER�A");
    printf("\n4 - QUARTA");
    printf("\n5 - QUINTA");
    printf("\n6 - SEXTA");
    printf("\n7 - S�BADO");
    printf("\n8 - TODA SEMANA");
    printf("\nRESPOSTA :   ");
    scanf("%i",&dia_exibir);

    if(dia_exibir>0 || dia_exibir<8){
       printf("\nTOTAL DE VENDAS POR DIA (EM UNIDADE) :%i", soma_produto_unidade[dia_exibir-1]);
       printf("\nTOTAL DE VENDAS POR DIA (EM REAIS) :%.2f", soma_produto_valor[dia_exibir-1]);
    }
    if(dia_exibir==8){
        //UNIDADE
        printf("\n\n\nTOTAL DE VENDAS POR DIA (EM UNIDADE)\n\n");
        printf("DOMINGO  SEGUNDA  TERCA  QUARTA  QUINTA  SEXTA  SABADO\n");
        for(i = 0; i<7; i++){
            printf("  %i    ",soma_produto_unidade[i]);
        }

        //VALOR
        printf("\n\n\nTOTAL DE VENDAS POR DIA (EM REAIS))\n\n");
        printf("DOMINGO   SEGUNDA    TERCA     QUARTA     QUINTA      SEXTA     SABADO\n");
        for(i = 0; i<7; i++){
            printf("%.2f     ",soma_produto_valor[i]);
        }
    }
}
void calculo_exibe_dados_produto(){
    //UNIDADE
    for(i = 0; i<10; i++){
        for(j = 0; j<7; j++){
            total_venda_de_todos_unidade+=produto_dia[i][j];
            total_venda_produto_unidade[i]+=produto_dia[i][j];
            if (i==0 && j==0){
                mais_vendido[1][1] = total_venda_produto_unidade[i];
                menos_vendido[1][1]=total_venda_produto_unidade[i];
            }
            if (total_venda_produto_unidade[i]<menos_vendido[1][1]){
                menos_vendido[1][1]= total_venda_produto_unidade[i];
                posicao_nome_menos = i;
            }
            if (total_venda_produto_unidade[i] > mais_vendido[1][1]){
                mais_vendido[1][1]= total_venda_produto_unidade[i];
                posicao_nome_mais = i;
                if (mais_vendido[1][1]= total_venda_produto_unidade[i]){

                    }
                }
            }
        }

    //VALOR
    for(i = 0; i<10; i++){
        total_venda_produto_valor[i]=total_venda_produto_unidade[i]*preco_produto[i];
        total_venda_de_todos_valor+=total_venda_produto_valor[i];
        if (i==0){
            mais_vendidoRS[1]=  total_venda_produto_valor[i];
            menos_vendidoRS[1]= total_venda_produto_valor[i];
        }
        if (total_venda_produto_valor[i] < menos_vendidoRS[1]){
            menos_vendidoRS[1]=total_venda_produto_valor[i];
            posicao_venda_menos = i;
            }
        if (total_venda_produto_valor[i] > mais_vendidoRS[1]){
            mais_vendidoRS[1]=total_venda_produto_valor[i];
            posicao_venda_mais = i;
            }
    }
}
void calculo_exibe_dados_dia(){
    //UNIDADE
    for(i = 0; i<7; i++){
            for(j=0; j<10; j++){
                soma_produto_unidade[i]+=produto_dia[j][i];
            }
    }

    //VALOR
    for(i = 0; i<7; i++){
        for(j=0; j<10; j++){
            soma_produto_valor[i]=soma_produto_valor[i]+(produto_dia[j][i]*preco_produto[j]);
        }
    }
}
void exibe_dados_produto(FILE *arq1){
    calculo_exibe_dados_produto();


    printf("\nQUAL O PRODUTO QUE VOCE DESEJA VER AS VENDAS ?  ");
    printf("\n1 - FARINHA");
    printf("\n2 - ARROZ");
    printf("\n3 - FEIJAO");
    printf("\n4 - FRANGO");
    printf("\n5 - CARNE");
    printf("\n6 - SABONETE");
    printf("\n7 - ESCOVA");
    printf("\n8 - PASTA");
    printf("\n9 - SHAMPOO");
    printf("\n10 - CONDICIONADOR\n");
    printf("\n11 - TODOS OS PRODUTOS");
    printf("\nRESPOSTA :   ");
    scanf("%i",&produto_exibir);

    if(produto_exibir>0 || produto_exibir<11){

        //printf("\nTOTAL DE VENDAS POR PRODUTO (EM UNIDADE)\n");
        printf("\n%s %i UNIDADES",nome_produto[produto_exibir-1],total_venda_produto_unidade[produto_exibir-1]);
        //printf("\nTOTAL DE VENDAS POR PRODUTO (EM REAIS)\n");
        printf("\n%s %.2f REAIS",nome_produto[produto_exibir-1],total_venda_produto_valor[produto_exibir-1]);

    }
    if(produto_exibir==11){
        //UNIDADE
        printf("\nTOTAL DE VENDAS POR PRODUTO (EM UNIDADE)\n");
        printf("\nTOTAL DE VENDAS POR PRODUTO (EM UNIDADE)\n");
        for(i = 0; i<10; i++){
            printf("\n%s %i",nome_produto[i],total_venda_produto_unidade[i]);
        }

        //VALOR
        printf("\nTOTAL DE VENDAS POR PRODUTO (EM REAIS)\n");
        for(i = 0; i<10; i++){
            printf("\n%s %.2f",nome_produto[i],total_venda_produto_valor[i]);
        }
    }
    //MAIS E MENOS VENDIDOS
    fprintf(arq1,"\nPRODUTO QUE MAIS VENDEU (EM REAIS): %sR$%.2f", nome_produto_aux[posicao_nome_mais], mais_vendidoRS[1]);
    fprintf(arq1,"\nPRODUTO QUE MAIS VENDEU (UNIDADE):  %s%i ",nome_produto_aux[posicao_venda_mais], mais_vendido[1][1]);
    fprintf(arq1,"\n");
    //MAIS E MENOS VENDIDOS UNIDADE
    fprintf(arq1,"\nPRODUTO QUE MENOS VENDEU (EM REAIS): %sR$%.2f",nome_produto_aux[posicao_venda_menos], menos_vendidoRS[1]);
    fprintf(arq1,"\nPRODUTO QUE MENOS VENDEU (UNIDADE):  %s%i",nome_produto_aux[posicao_venda_menos], menos_vendido[1][1]);

}

void exibe_produto_semana(FILE *arq1){
    printf("\nTOTAL DAS VENDAS (EM UNIDADE): %i",total_venda_de_todos_unidade);
    printf("\nTOTAL DAS VENDAS (EM UNIDADE): R$%.2f",total_venda_de_todos_valor);
}

void gera_relatorio(FILE *arq1){
    printf("....RELAT�RIO CRIADO");
    fprintf(arq1,"TABELA DE VENDAS\n");
    fprintf(arq1,"                  DOM  SEG  TER  QUA  QUI  SEX  SAB\n");
    //EXIBE VENDAS
    for( produto = 0; produto < 10 ; produto++){
        fprintf(arq1,"     \n %s", nome_produto[produto]);
        for( dia = 0; dia < 7 ; dia++){
            fprintf(arq1,"  %i  ",produto_dia[produto][dia]);
        }
    }
    //EXIBIR DADOS DIAS
    calculo_exibe_dados_dia();
    //UNIDADE
    fprintf(arq1,"\n\n\nTOTAL DE VENDAS POR DIA (EM UNIDADE)\n\n");
    fprintf(arq1,"DOMINGO  SEGUNDA  TERCA  QUARTA  QUINTA  SEXTA  SABADO\n");
    for(i = 0; i<7; i++){
        fprintf(arq1,"  %i    ",soma_produto_unidade[i]);
    }
    //VALOR
    fprintf(arq1,"\n\n\nTOTAL DE VENDAS POR DIA (EM REAIS))\n\n");
    fprintf(arq1,"DOMINGO   SEGUNDA    TERCA     QUARTA     QUINTA      SEXTA     SABADO\n");
    for(i = 0; i<7; i++){
        fprintf(arq1,"%.2f     ",soma_produto_valor[i]);
    }

    //EXIBIR DADOS PRODUTOS
    calculo_exibe_dados_produto();
    //UNIDADE
    fprintf(arq1,"\n\nTOTAL DE VENDAS POR PRODUTO (EM UNIDADE)\n");
    for(i = 0; i<10; i++){
        fprintf(arq1,"\n%s %i",nome_produto[i],total_venda_produto_unidade[i]);
    }
    //VALOR
    fprintf(arq1,"\n\nTOTAL DE VENDAS POR PRODUTO (EM REAIS)\n");
    for(i = 0; i<10; i++){
        fprintf(arq1,"\n%s %.2f",nome_produto[i],total_venda_produto_valor[i]);
    }

    //INFORMA��ES SEMANA
    fprintf(arq1,"\n\nTOTAL DAS VENDAS (EM UNIDADE): %i",total_venda_de_todos_unidade);
    fprintf(arq1,"\nTOTAL DAS VENDAS (EM REAIS): R$%.2f",total_venda_de_todos_valor);

    fprintf(arq1,"\n");
     //MAIS E MENOS VENDIDOS

    fprintf(arq1,"\nPRODUTO QUE MAIS VENDEU (EM REAIS): %sR$%.2f", nome_produto_aux[posicao_nome_mais], mais_vendidoRS[1]);
    fprintf(arq1,"\nPRODUTO QUE MAIS VENDEU (UNIDADE):  %s%i ",nome_produto_aux[posicao_nome_mais], mais_vendido[1][1]);

    fprintf(arq1,"\n");
    //MAIS E MENOS VENDIDOS UNIDADE
    fprintf(arq1,"\nPRODUTO QUE MENOS VENDEU (EM REAIS): %sR$%.2f",nome_produto_aux[posicao_venda_menos], menos_vendidoRS[1]);
    fprintf(arq1,"\nPRODUTO QUE MENOS VENDEU (UNIDADE):  %s%i",nome_produto_aux[posicao_venda_menos], menos_vendido[1][1]);

}



void exibe_vendas(FILE *arq1){
    dia_semana(arq1);
for( produto = 0; produto < 10 ; produto++){
printf("     \n %s", nome_produto[produto]);
fprintf(arq1,"     \n %s", nome_produto[produto]);
for( dia = 0; dia < 7 ; dia++){
   	printf("  %i  ",produto_dia[produto][dia]);
   	fprintf(arq1,"  %i  ",produto_dia[produto][dia]);
}
}
}

void exibe_preco(void){
printf("\n\n");
for(j=0; j<10; j++){
   printf("\n%s  %.2f", nome_produto[j],preco_produto[j]);
}

}

int main(){

    setlocale(LC_ALL, "Portuguese");
FILE *arq, *arq1;
char Linha[100];
char *result;
arq = fopen("Entrada.txt", "rt");             // LEITURA
arq1 = fopen("Relatorio (saida).txt", "wt");  // GRAVA��O

if (arq == NULL){
        // ERRO NA ABERTURA
   printf("Problemas na abertura do arquivo\n");
   return;
}

i = 1;


while (!feof(arq)){
 	// L� UMA LINHA (INCLUSIVE COM O '\N')
   // O 'FGETS' L� AT� 99 CARACT�RES OU AT� O '\N']

 	if (result){  // SE FOI POSS�VEL LER
 	result = fgets(Linha, 100, arq);
     	//printf("Linha %d : %s",i,Linha);
     	//result = fprintf(arq1,"Linha %d\n",i);
     	produto_dia[produto][dia] = atoi(Linha); //Str pra Int

     	i++;
     	dia++;

     	if(dia>6){
       	dia=0;
       	produto++;
     	}
     	if(i>70){
     	fscanf(arq,"%s",&Linha);
       	preco_produto[linha_preco]=atof(Linha); //Str pra Float
       	linha_preco++;
     	}
   }
}

    while(entrada_menu!=6){
        menu(arq1);

    }

fclose(arq);

return 0;
}
