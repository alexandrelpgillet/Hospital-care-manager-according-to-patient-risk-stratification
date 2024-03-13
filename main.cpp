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


int validacao_CPF(char CPF[12] , int posicao_dados )
{
    unsigned short int   d1_cpf, d2_cpf, d3_cpf , d4_cpf , d5_cpf , d6_cpf , d7_cpf, d8_cpf , d9_cpf , d10_cpf , d11_cpf  , Resto , Resto2;

    //Digitos do CPF
 
    d11_cpf=CPF[10] -'0';

    d10_cpf=CPF[9] - '0';
 
    d9_cpf=CPF[8] - '0';
 
    d8_cpf=CPF[7] - '0';
 
    d7_cpf=CPF[6] - '0';
 
    d6_cpf=CPF[5] - '0';
 
    d5_cpf=CPF[4] -'0';
 
    d4_cpf=CPF[3]-'0';
 
    d3_cpf=CPF[2]-'0';
 
    d2_cpf=CPF[1]-'0';
 
    d1_cpf=CPF[0]-'0';


    

    

    Resto=(d1_cpf*10+d2_cpf*9+d3_cpf*8+d4_cpf*7+d5_cpf*6+d6_cpf*5+d7_cpf*4+d8_cpf*3+d9_cpf*2)*10%11;

    if(Resto==10)
    {
        Resto=0;
    }

    if(Resto==d10_cpf)
    {
       
       
       
       Resto2=(d1_cpf*11+d2_cpf*10+d3_cpf*9+d4_cpf*8+d5_cpf*7+d6_cpf*6+d7_cpf*5+d8_cpf*4+d9_cpf*3+d10_cpf*2)*10%11;

       if(Resto2==10)
       {
        Resto2=0;
       }

       if(Resto2==d11_cpf)
       {
        return 0;
       }
       else 
       {

        printf("CPF invalido digite novamente\n");
        flush_in();
        fgets(CPF,12, stdin);

        return validacao_CPF(CPF, posicao_dados);
       }
    }
    else
    {
        printf("CPF invalido digite novamente:\n");
        flush_in();
        fgets(CPF,12,stdin);

        return validacao_CPF(CPF, posicao_dados);


    }


   

    



}
void entrada_dados(Identificao dados[quant_paciente], int *posicao)

{

int posicao_dados=*posicao ;



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
 validacao_CPF(dados[posicao_dados].CPF , posicao_dados );
 


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