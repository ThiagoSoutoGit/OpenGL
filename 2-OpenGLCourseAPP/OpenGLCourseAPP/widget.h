#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <stdio.h>
#include <iostream>

#include <C:/LIBS/GLEW/include/GL/glew.h>
#include <C:/LIBS/GLFW/include/GLFW/glfw3.h>

const GLint WIDTH = 800, HEIGHT = 600;


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
