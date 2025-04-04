#ifndef __GAME_OGLDEV_TRIANGLE_SCALE_SHADERS_HPP__
#define __GAME_OGLDEV_TRIANGLE_SCALE_SHADERS_HPP__

char * getTriangleScaleVertexShader()
{
	return
		"attribute vec3 a_position;								\n"
		"uniform mat4 u_scale;								    \n"
		"void main()											\n"
		"{														\n"
		"   gl_Position = u_scale * vec4(a_position, 1.0);	    \n"
		"}														\n";
};

char * getTriangleScaleFragmentShader()
{
	return
		"precision mediump float;\n"
		"void main()                                  \n"
		"{                                            \n"
		"  gl_FragColor = vec4 ( 1.0, 0.0, 0.0, 1.0 );\n"
		"}                                            \n";
};

#endif // __GAME_OGLDEV_TRIANGLE_SCALE_SHADERS_HPP__ 