
#include "camera.h"

Camera::Camera(QWidget* widget)
    : widget(widget)
    , cameraPos(QVector3D(0.0f, 0.0f, 20.0f))
    , cameraUp(QVector3D(0.0f, 1.0f, 0.0f))
    , moveSpeed(0.5f)
    , timeId(0)
    , xtrans(0), ytrans(0), ztrans(0.0)
    , cameraDirection(QVector3D(0.0f, 0.0f, -1.0f))
{
}

float Camera::getMoveSpeed() const
{
    return moveSpeed;
}

void Camera::setMoveSpeed(float value)
{
    moveSpeed = value;
}

QVector3D Camera::getCameraPos() const
{
    return cameraPos;
}

void Camera::setCameraPos(const QVector3D& value)
{
    cameraPos = value;
}

void Camera::handle(QEvent* e)
{
}

void Camera::init()
{
    view.lookAt(cameraPos, cameraPos + cameraDirection, cameraUp); //鼠标输入
    qDebug() << cameraPos << cameraPos + cameraDirection << cameraUp << view;
    widget->activateWindow();                 //激活窗口
    widget->setFocus();
}

QMatrix4x4 Camera::getView() const
{
    return view;
}
