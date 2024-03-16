#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define quant_paciente  900 //quantidade maxima de pacientes que pode ser armazenada simultaneamente
#define ano 2024

using namespace std;



struct Identificao {
    
    char Nome_Completo[100] , Queixa_principal[1000] , Sintomas[1000] , CPF[12] , numero_CID[6];
    int Idade_dia , Idade_mes, Idade_ano ;
    
}dados[quant_paciente];




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

int validacao_CID(char numero_CID[6], int posicao_dados)
{   
    

   

    if(numero_CID[0]== 'A' , 'B', 'C' , 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' )
    {

        if(numero_CID[1]=='0', '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' && numero_CID[2]=='0', '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' && numero_CID[5]=='0', '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9'   && numero_CID[3]=='.' )
        {

            return 0;

        }
        else 
        {   
            
            printf("Numero CID invalido digite novamente:\n");
            
            

            fgets(numero_CID , 6 , stdin);
            

            return validacao_CID(numero_CID, posicao_dados);
        }

    }
    else 
    {   
        
        printf("Numero CID invalido digite novamente:\n");
        
       

        fgets(numero_CID, 6 , stdin);

        return validacao_CID(numero_CID , posicao_dados);
    }

}


void entrada_dados(Identificao dados[quant_paciente], int *posicao)

{

int posicao_dados=*posicao , item, correcao;


char espaco , confirmacao[1] ; 



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
 
 fgets(dados[posicao_dados].numero_CID, 6 , stdin );

 

 validacao_CID(dados[posicao_dados].numero_CID , posicao_dados);

 
 printf("\n");

 flush_in();

 //PAINEL DE CONFIRMACAO DOS DADOS DO PACIENTE CADASTRADO

 printf("DADOS DO PACIENTE\n");
 printf("1)NOME : %s\n" , dados[*posicao].Nome_Completo); // Nome
 printf("2)DATA DE NASCIMENTO :%d/%d/%d\n" , dados[*posicao].Idade_dia , dados[0].Idade_mes , dados[0].Idade_ano);// Idade
 printf("3)CPF = %s\n" , dados[*posicao].CPF); // CPF
 printf("4)QUEIXA PRINCIPAL =%s\n" , dados[*posicao].Queixa_principal); // Queixa 
 printf("5)SINTOMAS =%s\n" , dados[*posicao].Sintomas); // Sintomas
 printf("6)CID SUGESTIVO=%s\n", dados[*posicao].numero_CID); // CID
 printf("\n\n");

 printf("Confirma os dados do paciente, caso estejam corretos digite S , caso queira editar algum dos dados digite N\n");


 scanf("%c" , &confirmacao[0]);

 while(confirmacao[0]!='S' && confirmacao[0]!='s' && confirmacao[0]!='N' && confirmacao[0]!='n')
 {
    printf("\nOpcao invalida, digite S ou N\n");
    scanf("%c" , &confirmacao[0]);
 }

//Caso os dados estejam certos 
 if((confirmacao[0]=='S'|| confirmacao[0]=='s'))
 {  
    printf("Dados gravados com suscesso\nAperte alguma tecla para o programa retornar ao menu\n");
    system("pause");
    system("cls");
    *posicao+=1;
 }
 else
 {  
    //Qual dos itens o usuario deseja alterar, somente um item pode ser alterado , em caso de multiplos dados incorrectos , apague a ficha e reescreva novamente
    printf("Digite o numero do item que deseja editar (1 ao 6)");
    scanf("%d" , &item);

    while(item<1 || item>6)
    {
        printf("Numero do item invalido , digite novamente (1 ao 6)\n");
        scanf("%d" , &item);
    }

    if(item==1)
    {  
       flush_in();
       printf("\nNovo nome:");
       fgets(dados[*posicao].Nome_Completo , 100 , stdin);
       printf("\n");

    }
    else
    {
        if(item==2)
        {
            printf("DATA DE NASCIMENTO:\n");
            
            scanf("%d%c%d%c%d" , &dados[posicao_dados].Idade_dia , &espaco , &dados[posicao_dados].Idade_mes , &espaco , &dados[posicao_dados].Idade_ano);

            while(dados[posicao_dados].Idade_dia >31 || dados[posicao_dados].Idade_dia<1 || dados[posicao_dados].Idade_mes<1 || dados[posicao_dados].Idade_mes>12 || dados[posicao_dados].Idade_ano>ano)
            {
    
            printf("Data de nascimento invalido, digite novamente\n");
            scanf("%d%c%d%c%d" , &dados[posicao_dados].Idade_dia , &espaco , &dados[posicao_dados].Idade_mes , &espaco , &dados[posicao_dados].Idade_ano);

            flush_in();

            printf("\n");

    
            }
        }
        else 
        {
            if(item==3)
            {   
                flush_in();
                printf("CPF  = ");
                fgets(dados[posicao_dados].CPF , 12 , stdin);
                validacao_CPF(dados[posicao_dados].CPF , posicao_dados );
                printf("\n");
            }
            else
            {
                if(item==4)
                {

                    flush_in();
                    printf("QUEIXA PRINCIPAL=");

                    
                    
                    fgets(dados[posicao_dados].Queixa_principal , 1000 , stdin);

                    printf("\n");

                }
                else 
                {
                    if(item==5)
                    {   
                        flush_in();
                        printf("SINTOMAS=");
                        
                        fgets(dados[posicao_dados].Sintomas , 1000 , stdin);
                        
                        printf("\n");
 
                    }
                    else
                    {   
                        flush_in();
                        printf("CID =");
                        fgets(dados[posicao_dados].numero_CID, 6 , stdin );

                        validacao_CID(dados[posicao_dados].numero_CID , posicao_dados);

                        printf("\n");
                    }
                }
            }
        }
    }

//MENU COM DADOS CORRIGIDOS

    printf("DADOS DO PACIENTE CORRIGIDO\n");
    printf("1)NOME : %s\n" , dados[*posicao].Nome_Completo); // Nome
    printf("2)DATA DE NASCIMENTO :%d/%d/%d\n" , dados[*posicao].Idade_dia , dados[0].Idade_mes , dados[0].Idade_ano);// Idade
    printf("3)CPF = %s\n" , dados[*posicao].CPF); // CPF
    printf("4)QUEIXA PRINCIPAL =%s\n" , dados[*posicao].Queixa_principal); // Queixa 
    printf("5)SINTOMAS =%s\n" , dados[*posicao].Sintomas); // Sintomas
    printf("6)CID SUGESTIVO=%s\n", dados[*posicao].numero_CID); // CID
    printf("\n\n");
    
    printf("Para salvar essas dados digite 1, caso queira apagar digite 2\n");

    scanf("%d" , &correcao);

    while(correcao<1 || correcao>2)
    {
        printf("Escolha invalida digite 1 para salvar esses dados ou 2 caso queira apagar\n");
        scanf("%d" , &correcao);
    }

    if(correcao==1)
    {   
        printf("Dados gravado com suscesso!\nAperte alguma tecla para retornar ao MENU\n");
        system("pause");
        system("cls");
        *posicao+=1;
    }
    else
    {
         printf("Dados apagados com suscesso!\nAperte alguma tecla para retornar ao MENU\n");
         system("pause");
         system("cls");
         
         
    }
    
   
    
 }


 

 



 

 

}

int busca_nome(int *num_paciente)
{
    
    char nome_paciente[100];
    int i ;

    
    printf("DIGITE O NOME DO PACIENTE A SER BUSCADO\n");
    fgets(nome_paciente , 100 , stdin);


    for(i =0 ; i<*num_paciente && strcmp(nome_paciente , dados[i].Nome_Completo) ; i++)
    {}

    if(i==*num_paciente)
    {
        printf("Nome do paciente nao encontrado na base de dados\n");
      
        system("pause");
        system("cls");

    }
    else
    {
        printf("Paciente encontrado na base de dados do sistema\n");
        printf("\n");

        printf("NOME: %s\n" ,dados[i].Nome_Completo );
        printf("DATA DE NASCIMENTO: %d/%d/%d\n" , dados[i].Idade_dia , dados[i].Idade_mes , dados[i].Idade_ano);
        printf("CPF: %s\n" , dados[i].CPF );
        printf("QUEIXA PRINCIPAL: %s\n" , dados[i].Queixa_principal);
        printf("SINTOMAS: %s\n" , dados[i].Sintomas);
        printf("CID: %s" , dados[i].numero_CID);
        
        
        
        system("pause");
        system("cls");
    
        
    }
    
    return 0;
    

}

int menu(int *p)
{
    
    char pagina[12][21] , resposta_usuario_menu ;
    
    
    //formatação da pagina do MENU 
    for(int i = 0 ; i<12 ; i++)
    {

        for(int i2=0 ; i2<21; i2++)
        {
            if(i==0 || i==11)
            {   

                pagina[i][i2]='#';
            }
            else
            {
                if(i2==0 || i2==20)
                {
                pagina[i][i2]='#';

                }
                else 
                {
                   pagina [i][i2]=' ';
                }
            }
           
        }
        

    }
    
    //Opcoes do menu 
    pagina[1][8]='M';
    pagina[1][9]='E';
    pagina[1][10]='N';
    pagina[1][11]='U';
    
    pagina[10][6]='4';
    pagina[10][7]=')';
    pagina[10][8]='S';
    pagina[10][9]='A';
    pagina[10][10]='I';
    pagina[10][11]='R';

    pagina[3][1]='1';
    pagina[3][2]=')';
    pagina[3][3]='F';
    pagina[3][4]='I';
    pagina[3][5]='L';
    pagina[3][6]='A';
    pagina[3][7]=' ';
    pagina[3][8]='A';
    pagina[3][9]='T';
    pagina[3][10]='E';
    pagina[3][11]='N';
    pagina[3][12]='D';
    pagina[3][13]='I';
    pagina[3][14]='M';
    pagina[3][15]='E';
    pagina[3][16]='N';
    pagina[3][17]='T';
    pagina[3][18]='O';


    pagina[5][1]='2';
    pagina[5][2]=')';
    pagina[5][3]='C';
    pagina[5][4]='A';
    pagina[5][5]='D';
    pagina[5][6]='A';
    pagina[5][7]='S';
    pagina[5][8]='T';
    pagina[5][9]='R';
    pagina[5][10]='O';
    pagina[5][11]=' ';
    pagina[5][12]='P';
    pagina[5][13]='A';
    pagina[5][14]='C';
    pagina[5][15]='I';
    pagina[5][16]='E';
    pagina[5][17]='N';
    pagina[5][18]='T';
    pagina[5][19]='E';


    pagina[7][1]='3';
    pagina[7][2]=')';
    pagina[7][3]='B';
    pagina[7][4]='U';
    pagina[7][5]='S';
    pagina[7][6]='C';
    pagina[7][7]='A';
    pagina[7][8]='R';
    pagina[7][9]=' ';
    pagina[7][10]='P';
    pagina[7][11]='A';
    pagina[7][12]='C';
    pagina[7][13]='I';
    pagina[7][14]='E';
    pagina[7][15]='N';
    pagina[7][16]='T';
    pagina[7][17]='E';



    for(int i= 0 ; i<12; i++)
    {
        for(int i2 = 0 ; i2<21; i2++)
        {
            printf("%c" , pagina[i][i2]);
        }

        printf("\n");
    }

    printf("\n");

    printf("Digite o numero para acessar determinado aplicacao (1-Fila de atendimento , 2-Cadastro Paciente , 3-Buscar Paciente , 4-Desligar o programa\n)");

    scanf("%c" , &resposta_usuario_menu);
    
    //Validacao da resposta do usuario

    while(resposta_usuario_menu!='1' && resposta_usuario_menu!='2' && resposta_usuario_menu!='3' && resposta_usuario_menu!='4')
    {  
       flush_in();
       printf("Numero escolhido invalido , digite novamente\n");
       scanf("%c" , &resposta_usuario_menu);
    }
   
   //Switch case para cada opcao de escolha do usuario
   switch(resposta_usuario_menu)
   {

    case '1':
       

    case '2':
        
        flush_in();

        system("cls");

        entrada_dados(dados, p);

        flush_in();

        return menu (p);

    case '3':
        
        flush_in();
        system("cls");

        busca_nome(p);

        
        return menu(p);

       
    
    case '4':
        
        return 0;
       
    
   }
    
      

}





int main()
{
    
    int posicao_dados, *pont;
    
    posicao_dados=0;
    
    pont  = &posicao_dados;

    //Identificao dados[quant_paciente];

    menu(pont);

    

    printf("%d", posicao_dados);
    
    /*    
    entrada_dados(dados, pont);
   
   
    printf("%s\n" , dados[0].Nome_Completo); // Nome
    printf("%d/%d/%d\n" , dados[0].Idade_dia , dados[0].Idade_mes , dados[0].Idade_ano);// Idade
    printf("%s\n" , dados[0].CPF); // CPF
    printf("%s\n" , dados[0].Queixa_principal); // Queixa 
    printf("%s\n" , dados[0].Sintomas); // Sintomas
    printf("%s\n", dados[0].numero_CID); // CID
    printf("%d\n" , posicao_dados);
    
    */



    return 0;

   

    




}
