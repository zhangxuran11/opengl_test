#include <iostream>

#include <GL/gl.h>
#include <GLFW/glfw3.h>

using namespace std;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

const GLuint WIDTH = 800, HEIGHT = 600;

int main()
{
    cout << "Starting GLFW context, OpenGL3.3" << endl;
    glfwInit();
    /*
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
*/
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", NULL, NULL);
    if(window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
 //   glViewport(0, 0, WIDTH, HEIGHT);

    while(!glfwWindowShouldClose(window))
    {
        glBegin(GL_TRIANGLES);

        glColor3f(1.0, 0.0, 0.0);    // Red
        glVertex3f(0.0, 1.0, 0.0);

        glColor3f(0.0, 1.0, 0.0);    // Green
        glVertex3f(-1.0, -1.0, 0.0);

        glColor3f(0.0, 0.0, 1.0);    // Blue
        glVertex3f(1.0, -1.0, 0.0);

        glEnd();
        glfwSwapBuffers(window);
        glfwPollEvents();

//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);

    }

    glfwTerminate();

    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    std::cout << key << std::endl;
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
