#ifndef OPENGLIMPL_H
#define OPENGLIMPL_H

#include <QObject>
#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QImage>
#include <limits>

extern "C" {
#include "figure.h"
#include "transforms.h"
}

class OpenGLImpl: public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit OpenGLImpl(QWidget *parent = nullptr);
    ~OpenGLImpl();
    config *conf;
    void screen_widget(int index);
private:
    float xRot, yRot, zRot;
    QPoint mouse_position;
    void initializeGL();
    void resizeGL(int w, int h); // принимает ширину и высоту
    void paintGL();
    float cos_distance(float *fst, float *snd);

    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
};

#endif // OPENGLIMPL_H
