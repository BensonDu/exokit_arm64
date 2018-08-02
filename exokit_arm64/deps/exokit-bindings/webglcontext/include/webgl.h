/*
 * webgl.h
 *
 *  Created on: Dec 13, 2011
 *      Author: ngk437
 */

#ifndef _WEBGLCONTEXT_WEBGL_H_
#define _WEBGLCONTEXT_WEBGL_H_

#include <nan/nan.h>

#if _WIN32
#include <GL/glew.h>
#include <GLES2/gl2platform.h>
#include <GLES2/gl2ext.h>
#endif

#if __APPLE__
#if TARGET_OS_IPHONE
#include <OpenGLES/ES3/gl.h>
#include <OpenGLES/ES3/glext.h>
#include <OpenGLES/ES2/glext.h>
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT 0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT 0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT 0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT 0x83F3
#define GL_COMPRESSED_SRGB_S3TC_DXT1_EXT 0x8C4C
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT 0x8C4D
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT 0x8C4E
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT 0x8C4F
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ANGLE GL_VERTEX_ATTRIB_ARRAY_DIVISOR
#define GL_ETC1_RGB8_OES 0x8D64
#elif TARGET_OS_MAC
#include <GL/glew.h>
#include <GLES2/gl2platform.h>
#include <GLES2/gl2ext.h>
#else
#error "Unknown Apple platform"
#endif
#endif

#if __linux__
#include <GL/glew.h>
#include <GLES2/gl2platform.h>
#include <GLES2/gl2ext.h>
#endif

#if __ANDROID__
#include <GLES3/gl3.h>
#include <GLES2/gl2ext.h>
#endif

#define UNPACK_FLIP_Y_WEBGL 0x9240
#define UNPACK_PREMULTIPLY_ALPHA_WEBGL 0x9241
#define CONTEXT_LOST_WEBGL 0x9242
#define UNPACK_COLORSPACE_CONVERSION_WEBGL 0x9243
#define BROWSER_DEFAULT_WEBGL 0x9244
#define MAX_CLIENT_WAIT_TIMEOUT_WEBGL ((uint32_t)2e7)

#include <defines.h>
#include <glfw.h>

using namespace v8;
using namespace node;

void flipImageData(char *dstData, char *srcData, size_t width, size_t height, size_t pixelSize);

class WebGLRenderingContext : public ObjectWrap {
public:
  static Handle<Object> Initialize(Isolate *isolate);

  WebGLRenderingContext();
  ~WebGLRenderingContext();

  static NAN_METHOD(New);
  static NAN_METHOD(Destroy);
  static NAN_METHOD(GetWindowHandle);
  static NAN_METHOD(SetWindowHandle);
  static NAN_METHOD(SetDefaultVao);
  static NAN_METHOD(IsDirty);
  static NAN_METHOD(ClearDirty);

  static NAN_METHOD(Uniform1f);
  static NAN_METHOD(Uniform2f);
  static NAN_METHOD(Uniform3f);
  static NAN_METHOD(Uniform4f);
  static NAN_METHOD(Uniform1i);
  static NAN_METHOD(Uniform2i);
  static NAN_METHOD(Uniform3i);
  static NAN_METHOD(Uniform4i);
  static NAN_METHOD(Uniform1ui);
  static NAN_METHOD(Uniform2ui);
  static NAN_METHOD(Uniform3ui);
  static NAN_METHOD(Uniform4ui);
  static NAN_METHOD(Uniform1fv);
  static NAN_METHOD(Uniform2fv);
  static NAN_METHOD(Uniform3fv);
  static NAN_METHOD(Uniform4fv);
  static NAN_METHOD(Uniform1iv);
  static NAN_METHOD(Uniform2iv);
  static NAN_METHOD(Uniform3iv);
  static NAN_METHOD(Uniform4iv);

  static NAN_METHOD(Uniform1uiv);
  static NAN_METHOD(Uniform2uiv);
  static NAN_METHOD(Uniform3uiv);
  static NAN_METHOD(Uniform4uiv);
  static NAN_METHOD(UniformMatrix2fv);
  static NAN_METHOD(UniformMatrix3fv);
  static NAN_METHOD(UniformMatrix4fv);
  static NAN_METHOD(UniformMatrix3x2fv);
  static NAN_METHOD(UniformMatrix4x2fv);
  static NAN_METHOD(UniformMatrix2x3fv);
  static NAN_METHOD(UniformMatrix4x3fv);
  static NAN_METHOD(UniformMatrix2x4fv);
  static NAN_METHOD(UniformMatrix3x4fv);

  static NAN_METHOD(PixelStorei);
  static NAN_METHOD(BindAttribLocation);
  static NAN_METHOD(GetError);
  static NAN_METHOD(DrawArrays);
  static NAN_METHOD(DrawArraysInstanced);
  static NAN_METHOD(GenerateMipmap);
  static NAN_METHOD(GetAttribLocation);
  static NAN_METHOD(DepthFunc);
  static NAN_METHOD(Viewport);
  static NAN_METHOD(CreateShader);
  static NAN_METHOD(ShaderSource);
  static NAN_METHOD(CompileShader);
  static NAN_METHOD(GetShaderParameter);
  static NAN_METHOD(GetShaderInfoLog);
  static NAN_METHOD(CreateProgram);
  static NAN_METHOD(AttachShader);
  static NAN_METHOD(LinkProgram);
  static NAN_METHOD(GetProgramParameter);
  static NAN_METHOD(GetUniformLocation);
  static NAN_METHOD(ClearColor);
  static NAN_METHOD(ClearDepth);
  static NAN_METHOD(Disable);
  static NAN_METHOD(Enable);
  static NAN_METHOD(CreateTexture);
  static NAN_METHOD(BindTexture);
  static NAN_METHOD(FlipTextureData);
  static NAN_METHOD(TexImage2D);
  static NAN_METHOD(CompressedTexImage2D);
  static NAN_METHOD(TexParameteri);
  static NAN_METHOD(TexParameterf);
  static NAN_METHOD(Clear);
  static NAN_METHOD(UseProgram);
  static NAN_METHOD(CreateBuffer);
  static NAN_METHOD(BindBuffer);
  static NAN_METHOD(CreateFramebuffer);
  static NAN_METHOD(BindFramebuffer);
  static NAN_METHOD(FramebufferTexture2D);
  static NAN_METHOD(BlitFramebuffer);
  static NAN_METHOD(BufferData);
  static NAN_METHOD(BufferSubData);
  static NAN_METHOD(BlendEquation);
  static NAN_METHOD(BlendFunc);
  static NAN_METHOD(EnableVertexAttribArray);
  static NAN_METHOD(VertexAttribPointer);
  static NAN_METHOD(VertexAttribIPointer);
  static NAN_METHOD(ActiveTexture);
  static NAN_METHOD(DrawElements);
  static NAN_METHOD(DrawElementsInstanced);
  static NAN_METHOD(DrawRangeElements);
  static NAN_METHOD(Flush);
  static NAN_METHOD(Finish);

  static NAN_METHOD(VertexAttrib1f);
  static NAN_METHOD(VertexAttrib2f);
  static NAN_METHOD(VertexAttrib3f);
  static NAN_METHOD(VertexAttrib4f);
  static NAN_METHOD(VertexAttrib1fv);
  static NAN_METHOD(VertexAttrib2fv);
  static NAN_METHOD(VertexAttrib3fv);
  static NAN_METHOD(VertexAttrib4fv);
  
  static NAN_METHOD(VertexAttribI4i);
  static NAN_METHOD(VertexAttribI4iv);
  static NAN_METHOD(VertexAttribI4ui);
  static NAN_METHOD(VertexAttribI4uiv);
  
  static NAN_METHOD(VertexAttribDivisor);
  static NAN_METHOD(DrawBuffers);

  static NAN_METHOD(BlendColor);
  static NAN_METHOD(BlendEquationSeparate);
  static NAN_METHOD(BlendFuncSeparate);
  static NAN_METHOD(ClearStencil);
  static NAN_METHOD(ColorMask);
  static NAN_METHOD(CopyTexImage2D);
  static NAN_METHOD(CopyTexSubImage2D);
  static NAN_METHOD(CullFace);
  static NAN_METHOD(DepthMask);
  static NAN_METHOD(DepthRange);
  static NAN_METHOD(DisableVertexAttribArray);
  static NAN_METHOD(Hint);
  static NAN_METHOD(IsEnabled);
  static NAN_METHOD(LineWidth);
  static NAN_METHOD(PolygonOffset);
  static NAN_METHOD(SampleCoverage);

  static NAN_METHOD(Scissor);
  static NAN_METHOD(StencilFunc);
  static NAN_METHOD(StencilFuncSeparate);
  static NAN_METHOD(StencilMask);
  static NAN_METHOD(StencilMaskSeparate);
  static NAN_METHOD(StencilOp);
  static NAN_METHOD(StencilOpSeparate);
  static NAN_METHOD(BindRenderbuffer);
  static NAN_METHOD(CreateRenderbuffer);

  static NAN_METHOD(DeleteBuffer);
  static NAN_METHOD(DeleteFramebuffer);
  static NAN_METHOD(DeleteProgram);
  static NAN_METHOD(DeleteRenderbuffer);
  static NAN_METHOD(DeleteShader);
  static NAN_METHOD(DeleteTexture);
  static NAN_METHOD(DetachShader);
  static NAN_METHOD(FramebufferRenderbuffer);
  static NAN_METHOD(GetVertexAttribOffset);
  static NAN_METHOD(GetShaderPrecisionFormat);

  static NAN_METHOD(IsBuffer);
  static NAN_METHOD(IsFramebuffer);
  static NAN_METHOD(IsProgram);
  static NAN_METHOD(IsRenderbuffer);
  static NAN_METHOD(IsShader);
  static NAN_METHOD(IsTexture);
  static NAN_METHOD(IsVertexArray);
  static NAN_METHOD(IsSync);

  static NAN_METHOD(RenderbufferStorage);
  static NAN_METHOD(GetShaderSource);
  static NAN_METHOD(ValidateProgram);

  static NAN_METHOD(TexSubImage2D);
  static NAN_METHOD(TexStorage2D);

  static NAN_METHOD(ReadPixels);
  static NAN_METHOD(GetTexParameter);
  static NAN_METHOD(GetActiveAttrib);
  static NAN_METHOD(GetActiveUniform);
  static NAN_METHOD(GetAttachedShaders);
  static NAN_METHOD(GetParameter);
  static NAN_METHOD(GetBufferParameter);
  static NAN_METHOD(GetFramebufferAttachmentParameter);
  static NAN_METHOD(GetProgramInfoLog);
  static NAN_METHOD(GetRenderbufferParameter);
  static NAN_METHOD(GetUniform);
  static NAN_METHOD(GetVertexAttrib);
  static NAN_METHOD(GetSupportedExtensions);
  static NAN_METHOD(GetExtension);
  static NAN_METHOD(CheckFramebufferStatus);

  static NAN_METHOD(CreateVertexArray);
  static NAN_METHOD(DeleteVertexArray);
  static NAN_METHOD(BindVertexArray);

  static NAN_METHOD(FenceSync);
  static NAN_METHOD(DeleteSync);
  static NAN_METHOD(ClientWaitSync);
  static NAN_METHOD(WaitSync);
  static NAN_METHOD(GetSyncParameter);

  static NAN_METHOD(FrontFace);

  static NAN_METHOD(IsContextLost);

  static NAN_GETTER(DrawingBufferWidthGetter);
  static NAN_GETTER(DrawingBufferHeightGetter);

  static NAN_METHOD(SetDefaultFramebuffer);

  void SetFramebufferBinding(GLenum target, GLuint framebuffer) {
    framebufferBindings[target] = framebuffer;
  }
  GLuint GetFramebufferBinding(GLenum target) {
    return framebufferBindings[target];
  }
  bool HasFramebufferBinding(GLenum target) {
    return framebufferBindings.find(target) != framebufferBindings.end();
  }

  void SetRenderbufferBinding(GLenum target, GLuint renderbuffer) {
    renderbufferBindings[target] = renderbuffer;
  }
  GLuint GetRenderbufferBinding(GLenum target) {
    return renderbufferBindings[target];
  }
  bool HasRenderbufferBinding(GLenum target) {
    return renderbufferBindings.find(target) != renderbufferBindings.end();
  }

  void SetTextureBinding(GLenum framebuffer, GLenum target, GLuint texture) {
    textureBindings[std::make_pair(framebuffer, target)] = texture;
  }
  GLuint GetTextureBinding(GLenum framebuffer, GLenum target) {
    return textureBindings[std::make_pair(framebuffer, target)];
  }
  bool HasTextureBinding(GLenum framebuffer, GLenum target) {
    return textureBindings.find(std::make_pair(framebuffer, target)) != textureBindings.end();
  }

  static Nan::Persistent<FunctionTemplate> s_ct;

  bool live;
  GLFWwindow *windowHandle;
  GLuint defaultVao;
  bool dirty;
  GLuint defaultFramebuffer;
  bool flipY;
  bool premultiplyAlpha;
  GLint packAlignment;
  GLint unpackAlignment;
  GLuint activeTexture;
  std::map<GLenum, GLuint> framebufferBindings;
  std::map<GLenum, GLuint> renderbufferBindings;
  std::map<std::pair<GLenum, GLenum>, GLuint> textureBindings;
};

class WebGL2RenderingContext : public WebGLRenderingContext {
public:
  WebGL2RenderingContext();
  ~WebGL2RenderingContext();

  static Handle<Object> Initialize(Isolate *isolate);

  static NAN_METHOD(New);

  static Nan::Persistent<FunctionTemplate> s_ct;
};

#endif
