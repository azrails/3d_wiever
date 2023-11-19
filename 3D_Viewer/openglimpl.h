#ifndef OPENGLIMPL_H
#define OPENGLIMPL_H

#include <QImage>
#include <QMouseEvent>
#include <QObject>
#include <QOpenGLWidget>
#include <QTimer>
#include <limits>
#include <QFileDialog>
#include "gif/qgifimage_p.h"

extern "C" {
#include "figure.h"
#include "transforms.h"
}

class OpenGLImpl : public QOpenGLWidget {
  Q_OBJECT
 public:
  explicit OpenGLImpl(QWidget *parent = nullptr);
  ~OpenGLImpl();
  config *conf;
  void screen_widget(int index);
  QImage screencast[50];
  int num;
  QTimer *tmr;

 private slots:
  void gif_figure();

 private:
  float xRot, yRot, zRot;
  QPoint mouse_position;
  void initializeGL();
  void resizeGL(int w, int h);  // принимает ширину и высоту
  void paintGL();
  float cos_distance(float *fst, float *snd);
  void mousePressEvent(QMouseEvent *);
  void mouseMoveEvent(QMouseEvent *);
  void create_gif();
};

#endif  // OPENGLIMPL_H
