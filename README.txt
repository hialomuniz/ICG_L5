Relat�rio 3 de Introdu��o a Computa��o Gr�fica
Nome: Hialo Muniz Carvalho
Matr�cula: 09/0116402

/************************************************************************************/

Arquivos:

- mesh.h
- mesh.cpp
- main.cpp

/************************************************************************************/

A solu��o consiste em um sistema contendo tr�s arquivos principais:

	- mesh.h: Header contendo a implementa��o das principais estruturas de dados usadas para a modelagem da malha triangular: vertex, color, face e mesh.

	- mesh.cpp: Arquivo contendo a implementa��o das fun��es que comp�em o sistema, desde a cria��o da janela SDL e da cria��o do viewport OpenGL, at� as fun��es de leitura do arquivo, aloca��o da estrutura de dados da malha, redimensionamento, transla��o e modelagem da malha.

	- main.cpp - Arquivo principal, contendo a fun��o principal do sistema.

	Juntamente com os arquivos que comp�em o sistema, est�o presentes diversos arquivos .OFF, para testes.

	Para a compila��o do sistema, foi usada o seguinte comando:

	g++ main.cpp mesh.cpp -o exec -lglut -lGLU -lGL -lSDL2 -W -Wall -pedantic -ansi

	Como pode ser visto, para compilar o c�digo � necess�rio ter as bibliotecas GLU, GLUT, GL e SDL2.0 presentes na m�quina. O c�digo foi compilado em uma m�quina com Linux Ubuntu 12.04.

	Ap�s a compila��o, para executar c�digo basta usar o seguinte comando:

	./exec <arquivo_texto><modo_de_modelagem>

	Aonde o modo de modelagem consiste em:

	Modo "1" -  A malha ser� modelada usando apenas linhas.
	Modo "2" - A malha ser� modelada usando tri�ngulos e quadril�teros.

	EXEMPLO: ./exec dragon.off 1

