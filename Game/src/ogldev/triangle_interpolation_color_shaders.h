#ifndef __GAME_OGLDEV_TRIANGLE_INTERPOLATION_COLOR_SHADERS_HPP__
#define __GAME_OGLDEV_TRIANGLE_INTERPOLATION_COLOR_SHADERS_HPP__

char * getTriangleInterpolationColorVertexShader()
{
	return
		"#version 100												\n"
		"precision mediump float;									\n"
		"attribute vec3 a_position;									\n"
		"															\n"
		"uniform mat4 u_scale;										\n"
		"															\n"
		"varying vec4 v_color;										\n"
		"															\n"
		"void main()												\n"
		"{															\n"
		"	vec4 colors[3];        									\n"
        "	colors[0] = vec4(1.0, 0.0, 0.0, 1.0);					\n"
        "	colors[1] = vec4(0.0, 1.0, 0.0, 1.0);					\n"
		"	colors[2] = vec4(0.0, 0.0, 1.0, 1.0);					\n"
		"															\n"
		"	gl_Position = u_scale * vec4(a_position, 1.0);			\n"
		"   int index = int(2.0 - mod(a_position, 3.0));		    \n"
		"	v_color = colors[index];							    \n"
		"}															\n";
}

char * getTriangleInterpolationColorFragmentShader()
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

#endif // __GAME_OGLDEV_TRIANGLE_INTERPOLATION_COLOR_SHADERS_HPP__