//#include <GLFW/glfw3.h>
#include <iostream>
#include<GL/glut.h>

GLFWwindow* window;
int score = 0;

void renderScore() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 0, 600, -1, 1);  // Set up a 2D orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1.0f, 1.0f, 1.0f);  // Set color to white

    // Position the text
    glRasterPos2f(10.0f, 580.0f);

    // Convert the score to a string
    std::string scoreString = "Score: " + std::to_string(score);

    // Display each character of the string
    for (char c : scoreString) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
    }
}

void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Your game rendering code here

    // Render the score
    renderScore();

    glfwSwapBuffers(window);
    glfwPollEvents();
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    window = glfwCreateWindow(800, 600, "OpenGL Window", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        // Update game logic, handle input, etc.

        // For this example, let's increment the score
        score++;

        // Render the scene
        renderScene();
    }

    glfwTerminate();
    return 0;
}
