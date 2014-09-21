#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>

#define WIDTH 640
#define HEIGHT 480

static void display_error(int error, const char* description) {
    fputs(description, stderr);
    fputs("\n", stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

void render(GLFWwindow *window) {
    float ratio = 0.0f;
    int width = 0;
    int  height = 0;

    // Set our viewport to the window's size
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float) height;
    glViewport(0, 0, width, height);

    // Prepare for rendering
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);

    // Draw the scene
    glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
    glEnd();

    // Swap the back and front buffers
    glfwSwapBuffers(window);

    // Continue checking for window events
    glfwPollEvents();
}

int main(void) {
    GLFWwindow* window = NULL;
    
    glfwSetErrorCallback(display_error);
    
    if(GL_FALSE == glfwInit()) {
        exit(EXIT_FAILURE);
    }
   
    window = glfwCreateWindow(WIDTH, HEIGHT, "Ray Tracer", NULL, NULL);
    if(NULL == window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    
    while(!glfwWindowShouldClose(window)) {
        render(window);
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

