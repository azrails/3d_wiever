
#include "openglimpl.h"

OpenGLImpl::OpenGLImpl(QWidget *parent) : QOpenGLWidget(parent) {
  setWindowTitle("Viewer");
  this->conf = new_config(nullptr);

  tmr = new QTimer(this);
  connect(tmr, SIGNAL(timeout()), this, SLOT(gif_figure()));
}

OpenGLImpl::~OpenGLImpl() {}

// вызывается один раз при создании окна
void OpenGLImpl::initializeGL() {
  glEnable(GL_DEPTH_TEST);  // глубина
  glEnable(GL_CULL_FACE);   // отсечение задних граний
}

// изменение размеров виджета
void OpenGLImpl::resizeGL(int w, int h) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
}

// перерисовка содерж. окна
void OpenGLImpl::paintGL() {
  float *c_f = this->conf->color_fon;
  glClearColor(c_f[0], c_f[1], c_f[2], c_f[3]);  // цвет фона
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  if (this->conf->type_projection == 1) {
    // центральная
    glFrustum(-2, 2, -2, 2, 2, 6);
    glTranslatef(0, 0, -3);
  } else {
    // параллельная проекция
    glOrtho(-3, 3, -3, 3, -4, 4);
  }

  figure *head = NULL;
  if (this->conf->fig) {
    // для рёбер
    head = this->conf->fig;
    float *c_l = this->conf->color_line;
    glEnableClientState(GL_VERTEX_ARRAY);
    while (head) {
      glVertexPointer(3, GL_FLOAT, 0, head->array_coords);
      glLineWidth(this->conf->line_width);
      glColor3f(c_l[0], c_l[1], c_l[2]);
      if (this->conf->type_line == 1) {
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(2, 0X00FF);
        glDrawArrays(GL_LINE_LOOP, 0, head->count_point);
        glDisable(GL_LINE_STIPPLE);
      } else
        glDrawArrays(GL_LINE_LOOP, 0, head->count_point);
      head = head->next;
    }
    // для вершин
    head = this->conf->fig;
    glEnable(GL_DEPTH_TEST);
    float *c_p = this->conf->color_point;
    while (head) {
      glVertexPointer(3, GL_FLOAT, 0, head->array_coords);
      glPointSize(this->conf->point_width);
      glColor3f(c_p[0], c_p[1], c_p[2]);
      if (this->conf->type_point == 1) {
        glEnable(GL_POINT_SMOOTH);
        glDrawArrays(GL_POINTS, 0, head->count_point);
        glDisable(GL_POINT_SMOOTH);
      } else if (this->conf->type_point == 2) {
        glDrawArrays(GL_POINTS, 0, head->count_point);
      }
      head = head->next;
    }
    glDisable(GL_DEPTH_TEST);
    glDisableClientState(GL_VERTEX_ARRAY);
  }
}

float OpenGLImpl::cos_distance(float *fst, float *snd) {
  float sum = 0;
  float len_first = 0;
  float len_second = 0;
  for (int i = 0; i < 3; i++) {
    sum += fst[i] * snd[i];
    len_first += (fst[i] * fst[i]);
    len_second += (snd[i] * snd[i]);
  }
  return sum / (std::sqrt(len_first) * std::sqrt(len_second));
}

void OpenGLImpl::mousePressEvent(QMouseEvent *mo) {
  mouse_position = mo->pos();  // запомнили коор. мышки
}

void OpenGLImpl::mouseMoveEvent(QMouseEvent *mo) {
  float delta_x = (mo->pos().x() - mouse_position.x()) * 0.001;
  float delta_y = -1.0 * (mo->pos().y() - mouse_position.y()) * 0.001;
  if (this->conf->fig) {
    float *center_before_rotate =
        figure_center(conf->fig);  //центры коор. фигуры
    transform_coordinates(conf->fig, center_before_rotate);
    rotation_figure(conf->fig, delta_y, delta_x, 0);  // поворот фигуры
    float *center_after_rotate =
        figure_center(conf->fig);  // новый центр фигуры
    for (int i = 0; i < 3; i++) {
      center_before_rotate[i] =
          -center_before_rotate[i] + center_after_rotate[i];
    }
    transform_coordinates(conf->fig, center_before_rotate);
    free(center_before_rotate);
    free(center_after_rotate);
  }
  this->update();
}

void OpenGLImpl::screen_widget(int index) {
  QImage image = grabFramebuffer();
  if (index == 0)
    image.save("screenshot.jpg", "JPEG");
  else
    image.save("screenshot.bmp", "BMP");
}

void OpenGLImpl::gif_figure() {
  if (num == 49) {
    tmr->stop();
    create_gif();
  }
    screencast[num] = grabFramebuffer();
    num += 1;

  //QImage image = grabFramebuffer();
  //QString a = QString::number(num);
  // перед пушем на гит изменить путь
  //image.save("photo/toGif" + a + ".png", "PNG");
}

void OpenGLImpl::create_gif() {
  QGifImage gif;
  for (int i = 0; i < 50; gif.addFrame(screencast[i++], 100)) {}
  QString str =
      QFileDialog::getSaveFileName(0, "Save as", "", "*.gif");
  gif.save(str);
}

















