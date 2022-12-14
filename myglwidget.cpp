#include "MyGLWidget.h"
void myMessageOutput(QtMsgType type, const QMessageLogContext& context, const QString& msg);
MyGLWidget::MyGLWidget(QWidget* parent)
    : QOpenGLWidget(parent)
    , camera(this)
{
    // 安装消息处理程序
    // qInstallMessageHandler(myMessageOutput);
    timer.setInterval(18);
    connect(&timer, &QTimer::timeout, this, static_cast<void (MyGLWidget::*)()>(&MyGLWidget::update));
    timer.start();
    QSurfaceFormat format;
    format.setSamples(50);
    setFormat(format);
}
MyGLWidget::~MyGLWidget()
{
    if(!isValid())
    {
        return;
    }
    makeCurrent();
    shaderProgram.destroyed();
    doneCurrent();
    PLATFORM->destroy();
    PLATFORM = nullptr;
}

void MyGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/Res/model.vert");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/Res/model.frag");
    shaderProgram.link();
    PLATFORM = Model::createModel("F:/STL/skeleton_Fixed.stl", context(), &shaderProgram);
    glEnable(GL_DEPTH_TEST);
    camera.init();
}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    shaderProgram.setUniformValue("projection", projection);
    shaderProgram.setUniformValue("view", camera.getView());
    PLATFORM->draw();
}

void MyGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    projection.setToIdentity();
    projection.perspective(60.0f, (GLfloat)w / (GLfloat)h, 0.001f, 100.0f); //视角-宽高比例-zNear-zFar
}

bool MyGLWidget::event(QEvent* e)
{
    camera.handle(e);
    return QWidget::event(e);
}
void myMessageOutput(QtMsgType type, const QMessageLogContext& context, const QString& msg)
{
    // 加锁
    static QMutex mutex;
    mutex.lock();
    QByteArray localMsg = msg.toLocal8Bit();
    QString strMsg("");
    switch(type)
    {
        case QtDebugMsg:
            strMsg = QString("Debug:");
            break;
        case QtWarningMsg:
            strMsg = QString("Warning:");
            break;
        case QtCriticalMsg:
            strMsg = QString("Critical:");
            break;
        case QtFatalMsg:
            strMsg = QString("Fatal:");
            break;
    }
    // 设置输出信息格式
    QString strDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    QString strMessage = QString("Message:%1 File:%2  Line:%3  Function:%4  DateTime:%5")
                         .arg(localMsg.constData()).arg(context.file).arg(context.line).arg(context.function).arg(strDateTime);
    // 输出信息至文件中（读写、追加形式）
    QFile file("log.txt");
    file.open(QIODevice::ReadWrite | QIODevice::Append);
    QTextStream stream(&file);
    stream << strMessage << "\r\n";
    file.flush();
    file.close();
    // 解锁
    mutex.unlock();
}

