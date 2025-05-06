#ifndef __GAME_OGLDEV_CAMERA_CONTROL_PART_1_SHADERS_HPP__
#define __GAME_OGLDEV_CAMERA_CONTROL_PART_1_SHADERS_HPP__

char * getCameraControlPart1VertexShader()
{
	return
		"#version 100												\n"
		"precision mediump float;									\n"
		"attribute vec3 a_position;									\n"
		"															\n"
		"varying vec4 v_color;										\n"
		"															\n"
		"uniform mat4 u_wvp;										\n"
		"															\n"
		"void main()												\n"
		"{															\n"
		"															\n"
		"	gl_Position = u_wvp * vec4(a_position, 1.0);			\n"
		"	v_color = vec4(clamp(a_position, 0.0, 1.0), 1.0);		\n"
		"}															\n";
}

char * getCameraControlPart1FragmentShader()
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

#endif // __GAME_OGLDEV_CAMERA_CONTROL_PART_1_SHADERS_HPP__