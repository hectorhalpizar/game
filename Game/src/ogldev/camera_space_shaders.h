#ifndef __GAME_OGLDEV_CAMERA_SPACE_SHADERS_HPP__
#define __GAME_OGLDEV_CAMERA_SPACE_SHADERS_HPP__

char * getCameraSpaceVertexShader()
{
	return
		"#version 100												\n"
		"precision mediump float;									\n"
		"attribute vec3 a_position;									\n"
		"attribute vec3 a_color;									\n"
		"															\n"
		"varying vec4 v_color;										\n"
		"															\n"
		"uniform mat4 u_wvp;										\n"
		"															\n"
		"void main()												\n"
		"{															\n"
		"															\n"
		"	gl_Position = u_wvp * vec4(a_position, 1.0);			\n"
		"	v_color = vec4(a_color, 1.0);							\n"
		"}															\n";
}

char * getCameraSpaceFragmentShader()
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

#endif // __GAME_OGLDEV_CAMERA_SPACE_SHADERS_HPP__