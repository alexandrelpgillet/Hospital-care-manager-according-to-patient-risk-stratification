#include <stdio.h>
#include <stdlib.h>
#include <string>
#define quant_paciente  900
#define ano 2024

using namespace std;

struct Identificao {
    
    char Nome_Completo[100] , Queixa_principal[1000] , Sintomas[1000] , CPF[12];
    int Idade_dia , Idade_mes, Idade_ano , numero_CID;
    
};

void flush_in()
{
    int ch;

    do
    {
        ch = fgetc(stdin);

    }while(ch!=EOF && ch!='\n');
}

void entrada_dados(Identificao dados[quant_paciente], int *posicao)

{

int posicao_dados=*posicao;

char espaco;  

//Leitura do nome

 printf("Nome completo do paciente:\n");

 fgets (dados[posicao_dados].Nome_Completo , 100 , stdin);
 
 
 printf("\n");

 

 //Leitura da idade

 printf("Digite a data de nascimento do paciente (Dia/Mes/Ano)(00/00/0000):\n");
 
 
 scanf("%d%c%d%c%d" , &dados[posicao_dados].Idade_dia , &espaco , &dados[posicao_dados].Idade_mes , &espaco , &dados[posicao_dados].Idade_ano);
 
 flush_in();

 //Validacao idade

 while(dados[posicao_dados].Idade_dia >31 || dados[posicao_dados].Idade_dia<1 || dados[posicao_dados].Idade_mes<1 || dados[posicao_dados].Idade_mes>12 || dados[posicao_dados].Idade_ano>ano)
 {
    
    printf("Data de nascimento invalido, digite novamente\n");
    scanf("%d%c%d%c%d" , &dados[posicao_dados].Idade_dia , &espaco , &dados[posicao_dados].Idade_mes , &espaco , &dados[posicao_dados].Idade_ano);

    flush_in();

    
 }

 //Entrada CPF do paciente

 printf("\nCPF do paciente:\n");


 fgets(dados[posicao_dados].CPF , 12 , stdin);

 
 printf("\n");

 
 //Queixa principal do paciente

 printf("Queixa principal:\n");
 flush_in();


 fgets(dados[posicao_dados].Queixa_principal , 1000 , stdin);
 
 
 printf("\n");

 
//Sintomas do paciente

 printf("Sintomas do paciente:\n");
 

 
 fgets(dados[posicao_dados].Sintomas , 1000 , stdin);


 printf("\n");
 
 
//CID do paciente

 printf("CID Sugestivo do paciente:\n");
 
 scanf("%d" , &dados[posicao_dados].numero_CID);
 
 printf("\n");

 flush_in();


 *posicao+=1;

 

}




int main()
{
    
    int posicao_dados, *pont;
    
    posicao_dados=0;
    
    pont  = &posicao_dados;

    Identificao dados[quant_paciente];

    
    entrada_dados(dados, pont);

    printf("%s\n" , dados[0].Nome_Completo); // Nome
    printf("%d/%d/%d\n" , dados[0].Idade_dia , dados[0].Idade_mes , dados[0].Idade_ano);// Idade
    printf("%s\n" , dados[0].CPF); // CPF
    printf("%s\n" , dados[0].Queixa_principal); // Queixa 
    printf("%s\n" , dados[0].Sintomas); // Sintomas
    printf("%d\n", dados[0].numero_CID); // CID
    printf("%d\n" , posicao_dados);



    return 0;

   

    




}