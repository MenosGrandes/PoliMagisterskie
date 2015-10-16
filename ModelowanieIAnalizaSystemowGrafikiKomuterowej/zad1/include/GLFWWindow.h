#ifndef GLFWWINDOW_H
#define GLFWWINDOW_H
#include "structs.hpp"
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
class GLFWWindow
{
public:
    GLFWWindow(d_type::Bint width,d_type::Bint height);
    virtual ~GLFWWindow();
    void  terminate();
    void  loop();
    static void keyCallback(GLFWwindow* window, d_type::Bint key, d_type::Bint scancode, d_type::Bint action, d_type::Bint mods);
    static  void error_callback(d_type::Bint error, const char* description);
protected:
private:
    GLFWwindow* window;
};

#endif // GLFWWINDOW_H
