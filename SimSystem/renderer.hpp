#ifndef RENDERER_RENDERER_H_
#define RENDERER_RENDERER_H_

#include <iostream>
//#include <unistd.h>

#include <GL/glew.h>

#include <OpenGL/gl.h>
#include <GLUT/glut.h>

#include <glm/glm.hpp>

#include <OVR_CAPI_0_5_0.h>
#include <OVR_CAPI_GL.h>

#include <SDL2/SDL.h>
#include <opencv2/highgui/highgui.hpp>

#include "../util/imageutil.hpp"

#define OVR_OS_MAC

class Renderer {
  public:
    Renderer(int w, int h);
    void displayStereoImage(const cv::Mat& image);

  private:
    SDL_Window* win;
    SDL_GLContext ctx;

    ovrHmd hmd;
    ovrSizei eyeRes[2];
    ovrEyeRenderDesc eyeDesc[2];
    ovrSizei fovSize;
    ovrGLTexture ovrTex[2];
    ovrGLTexture* prTargetTex;

    GLuint texture[2];

    int windowWidth, windowHeight;
    int fbTexWidth, fbTexHeight;
    unsigned int fbo, fbTex, fbDepth;
    ovrGLConfig glCfg;
    unsigned int distortCaps, hmdCaps;

    void updateRenderTarget();
    static GLuint loadTexture(const cv::Mat& image);
    static unsigned int nextPow2(unsigned int x);
};

#endif
