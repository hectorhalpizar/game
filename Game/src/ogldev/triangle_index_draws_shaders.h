#ifndef __GAME_OGLDEV_TRIANGLE_INDEX_DRAWS_SHADERS_HPP__
#define __GAME_OGLDEV_TRIANGLE_INDEX_DRAWS_SHADERS_HPP__

char * getTriangleIndexDrawsVertexShader()
{
	return
		"#version 100												\n"
		"precision mediump float;									\n"
		"attribute vec3 a_position;									\n"
		"attribute vec3 b_color;									\n"
		"															\n"
		"varying vec4 v_color;										\n"
		"															\n"
		"uniform mat4 u_world;										\n"
		"															\n"
		"void main()												\n"
		"{															\n"
		"															\n"
		"	gl_Position = u_world * vec4(a_position, 1.0);			\n"
		"	v_color = vec4(b_color, 1.0);							\n"
		"}															\n";
}

char * getTriangleIndexDrawsFragmentShader()
{
	return
		"#version 100					\n"
		"precision mediump float;		\n"
		"varying vec4 v_color;			\n"
		"								\n"
		"void main() {					\n"
		"	gl_FragColor = v_color;		\n"
		"}								\n";
}

#endif // __GAME_OGLDEV_TRIANGLE_INDEX_DRAWS_SHADERS_HPP__