// to build: g++ glfw.c -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#define WIDTH 640
#define HEIGHT 480

static void error_callback(int error, const char* description) {
    fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) glfwSetWindowShouldClose(window, GL_TRUE);
}

void render(GLFWwindow *window){
    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float) height;
    glViewport(0, 0, width, height);
    
    // do the rendering here. 

    glEnd();
    glfwSwapBuffers(window); // bring the rendered buffer from background to foreground
    glfwPollEvents(); // poll for window events
}

int main(void) {
    GLFWwindow* window;
    
    glfwSetErrorCallback(error_callback);
    
    if (!glfwInit()) exit(EXIT_FAILURE);
   
    window = glfwCreateWindow(WIDTH, HEIGHT, "Ray tracing", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    
    while (!glfwWindowShouldClose(window)) {
        render(window);
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

