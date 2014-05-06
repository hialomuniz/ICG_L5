/*
 *mesh.h
 */
#ifndef MESH_H_
#define MESH_H_

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm> 

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

typedef struct{
    float x,y,z;
}vertex;

typedef struct{
    int v1,v2,v3,v4, vertex_quantity;
}face;

typedef struct{
    int R,G,B,alpha;
}color;

typedef struct{
    vertex *list_vertex;
    face *list_faces;
    color *list_color;
    int nvertex;
    int nface;
    int ncolor;
    float xmin, xmax, ymin, ymax, zmin, zmax;
}mesh;

int Load_Mesh(mesh *pmesh, char *File_Name);
mesh *New_Mesh();
int Del_Mesh(mesh *pmesh);
int Render_Mesh(mesh *pmesh, int args);
void RenderingUsingLines(color cfp, vertex vfp, color csp, vertex vsp);
void RenderingUsingTriangles(color cfp, vertex vfp, color csp, vertex vsp, color ctp, vertex vtp);
int gettingDelta (mesh *pmesh);
int Resize_Mesh(mesh *pmesh);
int Translate_Mesh(mesh *pmesh);
void RenderingUsingQuads(color cfp, vertex vfp, color csp, vertex vsp, color ctp, vertex vtp, color cqp, vertex vqp);
void destroyWindow();
void createWindow ();
void displayRender(mesh *pmesh, int args);
int setViewport(int width, int height);
void initGL();

#endif
