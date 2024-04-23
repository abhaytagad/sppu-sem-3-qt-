#include "openglwidget.h"

//OpenGLWidget::OpenGLWidget(QWidget *parent) : QOpenGLWidget(parent)
//{
//}

//OpenGLWidget::~OpenGLWidget()
//{
//}

void OpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);

    // Set the clear color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Create and compile your shaders

    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vertexShader.glsl");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragmentShader.glsl");
    shaderProgram.link();

    // Use the shader program
    shaderProgram.bind();

    // Perform additional OpenGL initialization if needed

    // Release the shader program
    shaderProgram.release();
}


void OpenGLWidget::resizeGL(int w, int h)
{
    // Handle resize events
    glViewport(0, 0, w, h);
}

void OpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Use your shader program
    shaderProgram.bind();

    // Define your vertices for a simple colored triangle
    GLfloat vertices[] = {
        0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // Vertex 1: Position (x, y, z), Color (R, G, B)
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // Vertex 2
        0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f  // Vertex 3
    };

    // Vertex attribute locations (you'll need to set these in your shader)
    int vertexLocation = shaderProgram.attributeLocation("a_position");
    int colorLocation = shaderProgram.attributeLocation("a_color");

    // Enable vertex attributes
    shaderProgram.enableAttributeArray(vertexLocation);
    shaderProgram.enableAttributeArray(colorLocation);

    // Specify how the data is laid out in the vertex array
    shaderProgram.setAttributeBuffer(vertexLocation, GL_FLOAT, 0, 3, 6 * sizeof(GLfloat));
    shaderProgram.setAttributeBuffer(colorLocation, GL_FLOAT, 3 * sizeof(GLfloat), 3, 6 * sizeof(GLfloat));

    // Draw the triangle
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // Disable vertex attributes
    shaderProgram.disableAttributeArray(vertexLocation);
    shaderProgram.disableAttributeArray(colorLocation);

    // Release the shader program
    shaderProgram.release();
}

