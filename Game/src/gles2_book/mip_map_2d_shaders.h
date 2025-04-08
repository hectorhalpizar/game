#ifndef __GAME_MIP_MAP_2D_SHADERS_H__
#define __GAME_MIP_MAP_2D_SHADERS_H__

#include "esUtil.h"

// TODO: Add documentation
GLbyte * getMipMap2dVertexShader()
{
	return
      "uniform float u_offset;      \n"
      "attribute vec4 a_position;   \n"
      "attribute vec2 a_texCoord;   \n"
      "varying vec2 v_texCoord;     \n"
      "void main()                  \n"
      "{                            \n"
      "   gl_Position = a_position; \n"
      "   gl_Position.x += u_offset;\n"
      "   v_texCoord = a_texCoord;  \n"
      "}                            \n";
}

// TODO: Add documentation
GLbyte * getMipMap2dFragmentShader()
{
	return
      "precision mediump float;                            \n"
      "varying vec2 v_texCoord;                            \n"
      "uniform sampler2D s_texture;                        \n"
      "void main()                                         \n"
      "{                                                   \n"
      "  gl_FragColor = texture2D( s_texture, v_texCoord );\n"
      "}                                                   \n";
}

#endif // __GAME_MIP_MAP_2D_SHADERS_H__