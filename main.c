#include <stdlib.h>
#include <stdio.h>
#include "obj.h"

int main()
{
    char *memory = NULL;
    size_t bytes = ObjLoadFile("sophie.obj", &memory);
    ObjModel *model = ObjLoadModel(memory, bytes);

    printf("Object Model has: %d faces!\n", model->nTriangle);
    printf("Object Model has: %d vertex!\n", model->nVertex);
    printf("Object Model has: %d texcoord!\n", model->nTexCoord);
    printf("Object Model has: %d normal!\n", model->nNormal);

    free(model->NormalArray);
    free(model->TexCoordArray);
    free(model->TriangleArray);
    free(model->VertexArray);
    free(model);

    return 0;
}
