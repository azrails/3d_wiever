#include "openglimpl.h"

OpenGLImpl::OpenGLImpl(QWidget *parent) : QOpenGLWidget(parent) {
    setWindowTitle("Viewer");
    this->conf = new_config(nullptr);
}

OpenGLImpl::~OpenGLImpl() {}

// вызывается один раз при создании окна
void OpenGLImpl::initializeGL() {
    glEnable(GL_DEPTH_TEST); // глубина
    glEnable(GL_CULL_FACE); // отсечение задних граний
}

// изменение размеров виджета
void OpenGLImpl::resizeGL(int w, int h) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

// перерисовка содерж. окна
void OpenGLImpl::paintGL() {
    glClearColor(this->conf->color_fon[0],
                 this->conf->color_fon[1],
                 this->conf->color_fon[2],
                 this->conf->color_fon[3]); // фон
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // параллельная проекция
//    glOrtho(conf->box[0], conf->box[1],
//            conf->box[2], conf->box[3],
//            conf->box[4], conf->box[5]); // left - rigth, down - up
    glFrustum(-2,2, -2,2, 2, 6);
    glTranslatef(0, 0, -3);

    figure *head = NULL;
    if (this->conf->fig) {
        // Для линий
        head = this->conf->fig;
        glEnableClientState(GL_VERTEX_ARRAY);
        while (head) {
            glVertexPointer(3, GL_FLOAT, 0, head->array_coords);
            glLineWidth(this->conf->line_width);
            glColor3f(this->conf->color_line[0],
                      this->conf->color_line[1],
                      this->conf->color_line[2]);
            if (this->conf->type_line == 1) {
                glEnable(GL_LINE_STIPPLE);
                glLineStipple(2, 0X00FF);
                glDrawArrays(GL_LINE_LOOP, 0, head->count_point);
                glDisable(GL_LINE_STIPPLE);
            } else
                glDrawArrays(GL_LINE_LOOP, 0, head->count_point);
            head = head->next;
        }
        head = this->conf->fig;
        glEnable(GL_DEPTH_TEST);
        while (head) {
            glVertexPointer(3, GL_FLOAT, 0, head->array_coords);
            glPointSize(this->conf->point_width);
            glColor3f(this->conf->color_point[0],
                      this->conf->color_point[1],
                      this->conf->color_point[2]);
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
    for (int i=0; i < 3; i++){
        sum += fst[i] * snd[i];
        len_first += (fst[i] * fst[i]);
        len_second += (snd[i] * snd[i]);
    }
    return sum / (std::sqrt(len_first) * std::sqrt(len_second));
}

void OpenGLImpl::mousePressEvent(QMouseEvent *mo) {
    mouse_position = mo->pos(); // запомнили коор. мышки
}

void OpenGLImpl::mouseMoveEvent(QMouseEvent *mo) {
    float delta_x = (mo->pos().x() - mouse_position.x()) * 0.001;
    float delta_y = -1.0 * (mo->pos().y() - mouse_position.y()) * 0.001;
    if (this->conf->fig){
        float *center_before_rotate = figure_center(conf->fig); //центры коор. фигуры
        transform_coordinates(conf->fig, center_before_rotate);
        rotation_figure(conf->fig, delta_y, delta_x, 0); // поворот фигуры
        float *center_after_rotate = figure_center(conf->fig); // новый центр фигуры
        for (int i = 0; i < 3; i++) {
            center_before_rotate[i] = -center_before_rotate[i] + center_after_rotate[i];
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
        image.save("/home/diana/School_21/screenshot.jpg", "JPEG");
    else
        image.save("/home/diana/School_21/screenshot.bmp", "BMP");
}





























