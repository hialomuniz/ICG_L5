#include "mesh.h"

#define OK 0
#define ERROR -1

/***********************************************************************************/

SDL_Window *window;
SDL_Renderer *renderer;

/***********************************************************************************/

int Load_Mesh(mesh *mesh, char *File_Name){
	ifstream myfile(File_Name);

	int i;

	string input, file_type;

	cout << "Reading mesh..." << endl;

	if (myfile.is_open()){

		getline(myfile, file_type);
		getline(myfile, input);

		stringstream iss (input);

		iss >> mesh->nvertex >> mesh->nface >> mesh->ncolor;

		mesh->list_vertex = (vertex*) malloc (sizeof(vertex)*mesh->nvertex);
		mesh->list_faces = (face*) malloc (sizeof(face)*mesh->nface);
		mesh->list_color = (color*) malloc (sizeof(color)*mesh->nvertex);

		for (i = 0; i < mesh->nvertex; i++){
			mesh->list_color[i].R = 127;
			mesh->list_color[i].G = 127;
			mesh->list_color[i].B = 127;
			mesh->list_color[i].alpha = 127;

			getline(myfile, input);
			stringstream ss (input);

			ss >> mesh->list_vertex[i].x >> mesh->list_vertex[i].y >> mesh->list_vertex[i].z 
					>> mesh->list_color[i].R >> mesh->list_color[i].G >> mesh->list_color[i].B 
					>> mesh->list_color[i].alpha;
		}

		for (i = 0; i < mesh->nface; i++){
			getline(myfile, input);
			stringstream ss (input);

			ss >> mesh->list_faces[i].vertex_quantity >> mesh->list_faces[i].v1 
			   >> mesh->list_faces[i].v2 >> mesh->list_faces[i].v3 >> mesh->list_faces[i].v4;

		}

	return OK;

	}

	else
		return ERROR;
}

/***********************************************************************************/

mesh *New_Mesh(){
	mesh* pmesh = (mesh*) malloc(sizeof(mesh)*1);

	if (pmesh == NULL){
		cout << "Error! Unable to allocate memory!" << endl;
		exit(1);
	}

	else
		return pmesh;
}

/***********************************************************************************/

int Del_Mesh(mesh *pmesh){
	free (pmesh);

	return OK;
}

/***********************************************************************************/
int gettingDelta (mesh *pmesh){
	vector<float> temp_x, temp_y, temp_z;
	int i;

	for (i = 0; i < pmesh->nvertex; i++){
		temp_x.push_back(pmesh->list_vertex[i].x);
		temp_y.push_back(pmesh->list_vertex[i].y);
		temp_z.push_back(pmesh->list_vertex[i].z);
	}

	sort(temp_x.begin(), temp_x.end());
	sort(temp_y.begin(), temp_y.end());
	sort(temp_z.begin(), temp_z.end());

	pmesh->xmin = temp_x[0];
	pmesh->ymin = temp_y[0];
	pmesh->zmin = temp_z[0];

	pmesh->xmax = temp_x[temp_x.size() - 1];
	pmesh->ymax = temp_y[temp_y.size() - 1];
	pmesh->zmax = temp_z[temp_z.size() - 1];

	return OK;
}

/***********************************************************************************/


int Resize_Mesh(mesh *pmesh){
	gettingDelta(pmesh);

	for (int i = 0; i < pmesh->nvertex; i++){
		pmesh->list_vertex[i].x /= (pmesh->xmax - pmesh->xmin);
		pmesh->list_vertex[i].y /= (pmesh->ymax - pmesh->ymin);
		pmesh->list_vertex[i].z /= (pmesh->zmax - pmesh->zmin);
	}

	return OK;
}

/***********************************************************************************/

int Translate_Mesh(mesh *pmesh){
	float cx, cy, cz;

	gettingDelta(pmesh);

	cx = pmesh->xmin + ((pmesh->xmax - pmesh->xmin)/2);
	cy = pmesh->ymin + ((pmesh->ymax - pmesh->ymin)/2);
	cz = pmesh->zmin + ((pmesh->zmax - pmesh->zmin)/2);


	for (int i = 0; i < pmesh->nvertex; i++){
		pmesh->list_vertex[i].x -= cx;
		pmesh->list_vertex[i].y -= cy;
		pmesh->list_vertex[i].z -= cz;
	}


	return OK;
}

/***********************************************************************************/


int Render_Mesh(mesh *pmesh, int args){
	unsigned int index = pmesh->nface;

	cout << "Rendering mesh. Number of faces: " << index << endl;
	//glScalef(2.5, 2.5, 2.5);

	switch (args){
		case 1:
			for (unsigned int i = 0; i < index; i++){
				if (pmesh->list_faces[i].vertex_quantity == 4){
					RenderingUsingLines(pmesh->list_color[pmesh->list_faces[i].v1], 
			    						pmesh->list_vertex[pmesh->list_faces[i].v1],
			    						pmesh->list_color[pmesh->list_faces[i].v2],
			    						pmesh->list_vertex[pmesh->list_faces[i].v2]);

			    	RenderingUsingLines(pmesh->list_color[pmesh->list_faces[i].v2], 
			    						pmesh->list_vertex[pmesh->list_faces[i].v2],
			    						pmesh->list_color[pmesh->list_faces[i].v3],
			    						pmesh->list_vertex[pmesh->list_faces[i].v3]);

			    	RenderingUsingLines(pmesh->list_color[pmesh->list_faces[i].v3], 
			    						pmesh->list_vertex[pmesh->list_faces[i].v3],
			    						pmesh->list_color[pmesh->list_faces[i].v4],
			    						pmesh->list_vertex[pmesh->list_faces[i].v4]);

			    	RenderingUsingLines(pmesh->list_color[pmesh->list_faces[i].v4], 
			    						pmesh->list_vertex[pmesh->list_faces[i].v4],
			    						pmesh->list_color[pmesh->list_faces[i].v1],
			    						pmesh->list_vertex[pmesh->list_faces[i].v1]);
				}

				else {
			    	RenderingUsingLines(pmesh->list_color[pmesh->list_faces[i].v1], 
			    						pmesh->list_vertex[pmesh->list_faces[i].v1],
			    						pmesh->list_color[pmesh->list_faces[i].v2],
			    						pmesh->list_vertex[pmesh->list_faces[i].v2]);

			    	RenderingUsingLines(pmesh->list_color[pmesh->list_faces[i].v2], 
			    						pmesh->list_vertex[pmesh->list_faces[i].v2],
			    						pmesh->list_color[pmesh->list_faces[i].v3],
			    						pmesh->list_vertex[pmesh->list_faces[i].v3]);

			    	RenderingUsingLines(pmesh->list_color[pmesh->list_faces[i].v3], 
			    						pmesh->list_vertex[pmesh->list_faces[i].v3],
			    						pmesh->list_color[pmesh->list_faces[i].v1],
			    						pmesh->list_vertex[pmesh->list_faces[i].v1]);
		    	}
		    }
	    break;

	    case 2:
			for (unsigned int i = 0; i < index; i++){
				if (pmesh->list_faces[i].vertex_quantity == 4){
			    	RenderingUsingQuads(pmesh->list_color[pmesh->list_faces[i].v1], 
			    						    pmesh->list_vertex[pmesh->list_faces[i].v1],
			    					 	    pmesh->list_color[pmesh->list_faces[i].v2],
			    						    pmesh->list_vertex[pmesh->list_faces[i].v2],
			    						    pmesh->list_color[pmesh->list_faces[i].v3],
			    						    pmesh->list_vertex[pmesh->list_faces[i].v3],
											pmesh->list_color[pmesh->list_faces[i].v4],
			    						    pmesh->list_vertex[pmesh->list_faces[i].v4]);	

		    	}
		    	else {
			    	RenderingUsingTriangles(pmesh->list_color[pmesh->list_faces[i].v1], 
			    						    pmesh->list_vertex[pmesh->list_faces[i].v1],
			    					 	    pmesh->list_color[pmesh->list_faces[i].v2],
			    						    pmesh->list_vertex[pmesh->list_faces[i].v2],
			    						    pmesh->list_color[pmesh->list_faces[i].v3],
			    						    pmesh->list_vertex[pmesh->list_faces[i].v3]);
		    	}



		    }
	    break;

	    default:
	    	cout << "Incorrect value for plotting! 1 - lines, 2 - triangles." << endl;
	    	break;
	    }

	return OK;
}

/***************************************************************/

void RenderingUsingTriangles(color cfp, vertex vfp, color csp, vertex vsp, color ctp, vertex vtp){

	glBegin(GL_TRIANGLES);
		glColor4d(cfp.R, cfp.G, cfp.B, cfp.alpha);
	 	glVertex3f(vfp.x, vfp.y, vfp.z);
		glColor4d(csp.R, csp.G, csp.B, csp.alpha);
	 	glVertex3f(vsp.x, vsp.y, vsp.z);
	 	glColor4d(ctp.R, ctp.G, ctp.B, ctp.alpha);
	 	glVertex3f(vtp.x, vtp.y, vtp.z);
	glEnd();
}

/***************************************************************/

void RenderingUsingQuads(color cfp, vertex vfp, color csp, vertex vsp, 
						 color ctp, vertex vtp, color cqp, vertex vqp){

	glBegin(GL_QUADS);
		glColor4d(cfp.R, cfp.G, cfp.B, cfp.alpha);
	 	glVertex3f(vfp.x, vfp.y, vfp.z);
		glColor4d(csp.R, csp.G, csp.B, csp.alpha);
	 	glVertex3f(vsp.x, vsp.y, vsp.z);
	 	glColor4d(ctp.R, ctp.G, ctp.B, ctp.alpha);
	 	glVertex3f(vtp.x, vtp.y, vtp.z);
	 	glColor4d(cqp.R, cqp.G, cqp.B, cqp.alpha);
	 	glVertex3f(vqp.x, vqp.y, vqp.z);
	glEnd();
}

/***************************************************************/

void RenderingUsingLines(color cfp, vertex vfp, color csp, vertex vsp) {

	glBegin(GL_LINES);
		glColor4d(cfp.R, cfp.G, cfp.B, cfp.alpha);
	 	glVertex3f(vfp.x, vfp.y, vfp.z);
		glColor4d(csp.R, csp.G, csp.B, csp.alpha);
	 	glVertex3f(vsp.x, vsp.y, vsp.z);
	glEnd();

}

/***************************************************************/

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

}

/***************************************************************/

int setViewport(int width, int height) {

    glViewport(0, 0, (GLsizei) width, (GLsizei) height);

    return OK;
}

/***************************************************************/

void displayRender(mesh *pmesh, int args) {
	cout << "Displaying render..." << endl;

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Render_Mesh(pmesh, args);

    SDL_GL_SwapWindow(window);

    SDL_Delay (3000);
}


/***************************************************************/

void createWindow (){
    
    SDL_Init(SDL_INIT_VIDEO);

    int flags = SDL_WINDOW_OPENGL;

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    SDL_CreateWindowAndRenderer(800, 600, flags, &window, &renderer);

    SDL_GL_CreateContext(window);

    initGL();

    setViewport(800, 600);
}

/***************************************************************/

void destroyWindow(){
    SDL_DestroyWindow(window);
    
    SDL_Quit();
}
