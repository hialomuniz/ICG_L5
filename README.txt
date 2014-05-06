Relatório 3 de Introdução a Computação Gráfica
Nome: Hialo Muniz Carvalho
Matrícula: 09/0116402

/************************************************************************************/

Arquivos:

- mesh.h
- mesh.cpp
- main.cpp

/************************************************************************************/

A solução consiste em um sistema contendo três arquivos principais:

	- mesh.h: Header contendo a implementação das principais estruturas de dados usadas para a modelagem da malha triangular: vertex, color, face e mesh.

	- mesh.cpp: Arquivo contendo a implementação das funções que compõem o sistema, desde a criação da janela SDL e da criação do viewport OpenGL, até as funções de leitura do arquivo, alocação da estrutura de dados da malha, redimensionamento, translação e modelagem da malha.

	- main.cpp - Arquivo principal, contendo a função principal do sistema.

	Juntamente com os arquivos que compõem o sistema, estão presentes diversos arquivos .OFF, para testes.

	Para a compilação do sistema, foi usada o seguinte comando:

	g++ main.cpp mesh.cpp -o exec -lglut -lGLU -lGL -lSDL2 -W -Wall -pedantic -ansi

	Como pode ser visto, para compilar o código é necessário ter as bibliotecas GLU, GLUT, GL e SDL2.0 presentes na máquina. O código foi compilado em uma máquina com Linux Ubuntu 12.04.

	Após a compilação, para executar código basta usar o seguinte comando:

	./exec <arquivo_texto><modo_de_modelagem>

	Aonde o modo de modelagem consiste em:

	Modo "1" -  A malha será modelada usando apenas linhas.
	Modo "2" - A malha será modelada usando triângulos e quadriláteros.

	EXEMPLO: ./exec dragon.off 1

