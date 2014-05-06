#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

#include "mesh.h"

using namespace std;

int main (int argc, char *argv []){
	
	if (argc != 3){
		fprintf(stderr, "./<name_of_the_program> <filename> <type>\n");
		exit (0);
	}

	int args = atoi(argv[2]);

/****************************************************/

	mesh* pmesh = New_Mesh();

	if (pmesh != NULL)
		cout << "Mesh allocated." << endl;

	Load_Mesh(pmesh, argv[1]);

	Resize_Mesh(pmesh);

	Translate_Mesh(pmesh);

    createWindow();

    displayRender(pmesh, args);

    Del_Mesh(pmesh);

    destroyWindow();

	return 0;

}