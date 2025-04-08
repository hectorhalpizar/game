#ifndef __GAME_TEXTURED_SQUARE_SHADERS_H__
#define __GAME_TEXTURED_SQUARE_SHADERS_H__

#include "esUtil.h"

/// This vertex shader processes the vertex 
//  position and the texture coordinates.
GLbyte * TexturedSquareVertexShader()
{
	return
      "attribute vec4 a_position;   \n"
      "attribute vec2 a_texCoord;   \n"
      "varying vec2 v_texCoord;     \n"
      "void main()                  \n"
      "{                            \n"
      "   gl_Position = a_position; \n"
      "   v_texCoord = a_texCoord;  \n"
      "}                            \n";
}

/// Creates a texture with four colors.
GLbyte * TexturedSquareFragmentShader()
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

#endif // __GAME_TEXTURED_SQUARE_SHADERS_H__