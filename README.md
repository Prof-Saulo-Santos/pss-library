# pss-library
Esta é uma biblioteca em C desenvolvida para otimizar a leitura de string de caracteres, números inteiros e de ponto flutuante. As funções evitam comportamentos inesperados e erros de leitura, overflow e buffer overflow.

A leitura via entrada padrão está disponível para os seguintes tipos de dados: 

int, long int, float, double, long double, char e char[].

1)Exemplos de uso:

	char c         = input_c("Digite um char: ");                 
	int  d         = input_d("Digite um inteiro: ");              
	long int ld    = input_ld("Digite um inteiro longo: ");       
	float    f     = input_f("Digite um float: ");                
	double lf      = input_lf("Digite um double: ");              
	long double Lf = input_Lf("Digite um long double: "); 
	char s[10];      input_s("Digite uma string: ",s,sizeof(s)); 

2)Ocorrendo overflow, os tipos retornarão:

	printf("int         %d   \n",INT_MAX);
	printf("long int    %ld  \n",LONG_MAX);
	printf("float       %f   \n",FLT_MAX);
	printf("double      %lf  \n",DBL_MAX);
	printf("long double %Lf  \n",LDBL_MAX);

3)As funções bloqueiam entradas inválidas de números inteiros e números flutuantes:

4)As funções limpam corretamente o buffer do teclado.

5)Impedem o buffer overflow na leitura de string de caracteres

6)Modo de uso:

	Copie e cole os arquivos pss.c e pss.h na pasta raiz de seu projeto.
	Insira #include "pss.h" no início do arquivo que fará uso das funções.
	Exemplo:

	#include <stdio.h>
	#include "pss.h"

	int main(){
		double lf = input_lf("Digite um double: "); 
		printf("O numero digitado foi: %lf", lf);
		return 0;
	}

	Se estiver usando o DEVC++ inclua os arquivos em seu projeto seguindo os passos:
		Vá na opção "Projeto -> Adicionar ao Projeto" e inclua os arquivos pss.c e pss.h
		Compile usando a opção: F12		

	Se estiver usando o CodeBlock inclua o arquivos em seu projeto seguindo os passos:
		Vá na opção "Projeto -> Adicionar Arquivo" e inclua os arquivos pss.c e pss.h
		Compile usando a opção: Ctrl+F9

	Se não estiver usando uma IDE, compile com:
	    gcc main.c pss.c pss.h -o teste.exe	



7)Contribuições são bem-vindas!

Sinta-se à vontade para contribuir com melhorias, correções de bugs ou novos recursos para esta biblioteca. Basta fazer um fork do repositório, fazer as alterações e enviar uma solicitação de pull.

8)Licença:

Este projeto é distribuído sob a Licença BSD 3-Clause. Consulte o arquivo LICENSE.md para obter mais informações.
