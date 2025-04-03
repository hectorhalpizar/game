#ifndef __GAME_OGLDEV_TRIANGLE_UNIFORM_VARIABLES_SHADERS_HPP__
#define __GAME_OGLDEV_TRIANGLE_UNIFORM_VARIABLES_SHADERS_HPP__ 

char * getTriangleUniformVariablesVertexShader()
{
	return
		"attribute vec4 a_position;																	\n"
		"uniform float u_scale;																		\n"
		"void main()																				\n"
		"{																							\n"
		"   gl_Position = vec4(u_scale * a_position.x, u_scale * a_position.y, a_position.z, 1.0);	\n"
		"}																							\n";
};

char * getTriangleUniformVariablesFragmentShader()
{
	return
		"precision mediump float;\n"
		"void main()                                  \n"
		"{                                            \n"
		"  gl_FragColor = vec4 ( 1.0, 0.0, 0.0, 1.0 );\n"
		"}                                            \n";
};

#endif // __GAME_OGLDEV_TRIANGLE_UNIFORM_VARIABLES_SHADERS_HPP__ 