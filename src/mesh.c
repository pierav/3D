/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "mesh.h"
#include "color.h"
#include "geo.h"
#include <stdio.h>
#include <stdlib.h>

/*******************************************************************************
 * Macros
 ******************************************************************************/

/*******************************************************************************
 * Types
 ******************************************************************************/

/*******************************************************************************
 * Internal function declaration
 ******************************************************************************/

/*
 * Initialise une mesh vide
 */
struct Mesh *MESH_Init() {
  struct Mesh *m = malloc(sizeof(struct Mesh));
  m->nb_vertices = 0;
  m->vertices = NULL;
  m->nb_faces = 0;
  m->faces = NULL;
  VECT_Set(&m->origin, 0, 0, 0);
  return m;
}

/*
 * Set une face
 */
void MESH_FACE_Set(struct MeshFace *mf, struct Vector *p0, struct Vector *p1,
                   struct Vector *p2, color c) {
  mf->p0 = p0;
  mf->p1 = p1;
  mf->p2 = p2;
  mf->color = c;
}

/*
 * Initialise un tetrahedre
 * https://en.wikipedia.org/wiki/Tetrahedron
 */
struct Mesh *MESH_InitTetrahedron(void) {
  struct Mesh *p = malloc(sizeof(struct Mesh));
  p->nb_vertices = 4;
  p->vertices = malloc(sizeof(struct Vector) * p->nb_vertices);
  VECT_Set(&p->vertices[0], 0, 0, 0);
  VECT_Set(&p->vertices[1], 1, 0, 0);
  VECT_Set(&p->vertices[2], 0, 1, 0);
  VECT_Set(&p->vertices[3], 0, 0, 1);
  p->nb_faces = 4;
  p->faces = malloc(sizeof(struct MeshFace) * p->nb_faces);
  MESH_FACE_Set(&p->faces[0], &p->vertices[0], &p->vertices[1], &p->vertices[2],
                CL_rgb(0, 0, 255));
  MESH_FACE_Set(&p->faces[1], &p->vertices[0], &p->vertices[1], &p->vertices[3],
                CL_rgb(0, 255, 0));
  MESH_FACE_Set(&p->faces[2], &p->vertices[0], &p->vertices[2], &p->vertices[3],
                CL_rgb(255, 0, 0));
  MESH_FACE_Set(&p->faces[3], &p->vertices[1], &p->vertices[2], &p->vertices[3],
                CL_rgb(100, 100, 100));
  return p;
}

void MESH_Print(struct Mesh *mesh) {
  printf("NB TR = %d\n", mesh->nb_faces);
  for (unsigned int i_face = 0; i_face < mesh->nb_faces; i_face++) {
    printf("TR[%d]:{", i_face);
    VECT_Print(mesh->faces[i_face].p0);
    VECT_Print(mesh->faces[i_face].p1);
    VECT_Print(mesh->faces[i_face].p2);
    printf("}\n");
  }
}
/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Public function
 ******************************************************************************/

/*******************************************************************************
 * Internal function
 ******************************************************************************/