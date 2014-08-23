#ifndef TRIANGLE_DATA_H
#define TRIANGLE_DATA_H

static const GLfloat gTriangleVertices[] = {
	-1,	-1,	0,
	1,	-1,	0,
	1,	1,	0,
};

static const GLfloat gTriangleNormals[] = {
	0,	0,	1,
	0,	0,	1,
	0,	0,	1,
};

static const int TRIANGLE_VERTEX_COUNT = sizeof(gTriangleVertices)/(3*sizeof(GLfloat));

#endif
