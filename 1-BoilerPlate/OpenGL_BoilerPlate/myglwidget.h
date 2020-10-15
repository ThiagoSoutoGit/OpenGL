#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <C:/LIBS/glew-2.2.0/include/GL/Glew.h>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QWidget>
#include <QSurfaceFormat>



class MyGLWidget : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
public:
    MyGLWidget(QWidget* parent=nullptr);

protected:
    //It is a virtual function
    void initializeGL() override;

    //It is also a virtual function
    void paintGL() override;
};

#endif // MYGLWIDGET_H
