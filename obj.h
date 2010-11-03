#ifndef OBJ_H
#define OBJ_H

typedef struct ObjVertex
{
  float x, y, z;
}ObjVertex;

typedef ObjVertex ObjNormal;

typedef struct ObjTexCoord
{
  float u, v;
}ObjTexCoord;

typedef struct ObjTriangle
{
  int Vertex[3];
  int Normal[3];
  int TexCoord[3];
}ObjTriangle;

typedef struct ObjModel
{
  int nVertex, nNormal, nTexCoord, nTriangle;
  ObjVertex *VertexArray;
  ObjNormal *NormalArray;
  ObjTexCoord *TexCoordArray;
  ObjTriangle *TriangleArray;
}ObjModel;

ObjModel *ObjLoadModel (char *, size_t);
size_t ObjLoadFile (char *, char **);

#endif
