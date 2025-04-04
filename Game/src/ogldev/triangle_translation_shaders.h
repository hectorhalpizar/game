#ifndef __GAME_OGLDEV_TRIANGLE_TRANSLATION_SHADERS_HPP__
#define __GAME_OGLDEV_TRIANGLE_TRANSLATION_SHADERS_HPP__ 

char * getTriangleTranslationVertexShader()
{
	return
		"attribute vec3 a_position;							\n"
		"uniform mat4 u_world;								\n"
		"void main()										\n"
		"{													\n"
		"   gl_Position = u_world * vec4(a_position, 1.0);	\n"
		"}													\n";
};

char * getTriangleTranslationFragmentShader()
{
	return
		"precision mediump float;\n"
		"void main()                                  \n"
		"{                                            \n"
		"  gl_FragColor = vec4 ( 1.0, 0.0, 0.0, 1.0 );\n"
		"}                                            \n";
};

#endif // __GAME_OGLDEV_TRIANGLE_TRANSLATION_SHADERS_HPP__ 