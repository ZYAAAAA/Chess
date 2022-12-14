#ifndef WIDGET_H
#define WIDGET_H

#include "camera.h"
#include "model.h"

#include <QOpenGLExtraFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <QTimer>
#include <QWidget>
#include<QMutex>

class MyGLWidget : public QOpenGLWidget, public QOpenGLExtraFunctions
{
    Q_OBJECT
public:
    MyGLWidget(QWidget* parent = 0);
    ~MyGLWidget();
protected:
    virtual void initializeGL() override;
    virtual void paintGL() override;
    virtual void resizeGL(int w, int h) override;
    virtual bool event(QEvent* e) override;


private:
    QOpenGLShaderProgram shaderProgram;
    Model* PLATFORM = nullptr;
    Camera camera;
    QTimer timer;
    QMatrix4x4 projection;

};

#endif // WIDGET_H
