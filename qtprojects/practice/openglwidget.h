//#ifndef OPENGLWIDGET_H
//#define OPENGLWIDGET_H
#include<QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class OpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit OpenGLWidget(QWidget *parent = nullptr);
    ~OpenGLWidget() override;

protected:
    QOpenGLShaderProgram shaderProgram;
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
};
