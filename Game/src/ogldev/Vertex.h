#ifndef __GAME_OGLDEV_VERTEX_H__
#define __GAME_OGLDEV_VERTEX_H__

struct Vertex {
	GLfloat pos[3];
	GLfloat color[3];

	Vertex() {}

	Vertex(float x, float y)
	{
		pos[0] = x; pos[1] = y; pos[2] = 1.f;

		float red   = (float)rand() / (float)RAND_MAX;
		float green = (float)rand() / (float)RAND_MAX;
		float blue  = (float)rand() / (float)RAND_MAX;
		color[0] = red; color[1] = green; color[2] = blue;
	}
};

#endif // __GAME_OGLDEV_VERTEX_H__