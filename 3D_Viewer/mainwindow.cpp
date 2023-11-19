#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  glwidget = new OpenGLImpl(this);
  this->ui->openGLlayout->addWidget(glwidget);

  connect(this->ui->vertex_empty, SIGNAL(clicked()), this, SLOT(type_vertex()));
  connect(this->ui->vertex_circle, SIGNAL(clicked()), this,
          SLOT(type_vertex()));
  connect(this->ui->vertex_square, SIGNAL(clicked()), this,
          SLOT(type_vertex()));
  connect(this->ui->edg_line, SIGNAL(clicked()), this, SLOT(type_edg()));
  connect(this->ui->edg_dotted, SIGNAL(clicked()), this, SLOT(type_edg()));
}

MainWindow::~MainWindow() {
  delete ui;
  delete_node_config(&(this->glwidget->conf));
}

// после написания парсера нужно будет удалить
void mock_parser(const char *s, config *conf) {
  // рисуем пирамиду
  float arr1[12] = {0, 0, -1, 2, 0, -1, 2, 0, -2, 0, 0, -2};
  float arr2[9] = {2, 0, -1, 1, 2, -1.5, 0, 0, -1};
  float arr3[9] = {2, 0, -1, 1, 2, -1.5, 2, 0, -2};
  float arr4[9] = {0, 0, -1, 1, 2, -1.5, 0, 0, -2};
  float arr5[9] = {0, 0, -2, 1, 2, -1.5, 2, 0, -2};

  float *array1 = (float *)malloc(sizeof(float) * 12);
  float *array2 = (float *)malloc(sizeof(float) * 9);
  float *array3 = (float *)malloc(sizeof(float) * 9);
  float *array4 = (float *)malloc(sizeof(float) * 9);
  float *array5 = (float *)malloc(sizeof(float) * 9);
  for (int i = 0; i < 9; i++) {
    array2[i] = arr2[i];
    array3[i] = arr3[i];
    array4[i] = arr4[i];
    array5[i] = arr5[i];
  }
  for (int i = 0; i < 12; i++) array1[i] = arr1[i];

  figure *head = NULL;
  figure_push_back(&head, new_figure_node(4, array1));
  figure_push_back(&head, new_figure_node(3, array2));
  figure_push_back(&head, new_figure_node(3, array3));
  figure_push_back(&head, new_figure_node(3, array4));
  figure_push_back(&head, new_figure_node(3, array5));

  conf->fig = head;
  conf->edge_count = 8;
  conf->vertex_count = 5;
}

void MainWindow::on_fileDialogButton_clicked() {
  delete_node_config(&(this->glwidget->conf));
  glwidget->conf = new_config(nullptr);
  // Получение имени файла из диалога
  QString fileName = QFileDialog::getOpenFileName(
      this, tr("Chose a file"), "/home", tr("Model file (*.obj)"));
  QByteArray encodedName = fileName.toLocal8Bit();
  const char *nameToC = encodedName.data();
  // Здесь имя файла отправляется в си поидее
  // parser(const char *s, config *conf);
  mock_parser(nameToC, this->glwidget->conf);
  //
  ui->fileNameLabel->setText(encodedName);
  ui->vLabelCount->setText(
      QString::number(this->glwidget->conf->vertex_count));  // кол-во вершин
  ui->eLabelCount->setText(
      QString::number(this->glwidget->conf->edge_count));  // кол-во рёбер
  this->glwidget->update();
}

void MainWindow::type_vertex() {
  QPushButton *button = (QPushButton *)sender();
  if (button->text() == "Empty")
    this->glwidget->conf->type_point = 0;
  else if (button->text() == "Circle")
    this->glwidget->conf->type_point = 1;
  else if (button->text() == "Square")
    this->glwidget->conf->type_point = 2;
  this->glwidget->update();
}

void MainWindow::type_edg() {
  QPushButton *button = (QPushButton *)sender();
  if (button->text() == "Line")
    this->glwidget->conf->type_line = 0;
  else if (button->text() == "Dotted")
    this->glwidget->conf->type_line = 1;
  this->glwidget->update();
}

void MainWindow::on_slider_red_sliderMoved(int position) {
  if (ui->Color_B_V_E->currentIndex() == 0)
    glwidget->conf->color_fon[0] = position / 255.0;
  else if (ui->Color_B_V_E->currentIndex() == 1)
    glwidget->conf->color_point[0] = position / 255.0;
  else
    glwidget->conf->color_line[0] = position / 255.0;
  glwidget->update();
}

void MainWindow::on_slider_green_sliderMoved(int position) {
  if (ui->Color_B_V_E->currentIndex() == 0)
    glwidget->conf->color_fon[1] = position / 255.0;
  else if (ui->Color_B_V_E->currentIndex() == 1)
    glwidget->conf->color_point[1] = position / 255.0;
  else
    glwidget->conf->color_line[1] = position / 255.0;
  glwidget->update();
}

void MainWindow::on_slider_blue_sliderMoved(int position) {
  if (ui->Color_B_V_E->currentIndex() == 0)
    glwidget->conf->color_fon[2] = position / 255.0;
  else if (ui->Color_B_V_E->currentIndex() == 1)
    glwidget->conf->color_point[2] = position / 255.0;
  else
    glwidget->conf->color_line[2] = position / 255.0;
  glwidget->update();
}

void MainWindow::on_Color_B_V_E_activated(int index) {
  if (index == 0) {
    ui->slider_red->setValue(
        static_cast<int>(glwidget->conf->color_fon[0] * 255));
    ui->slider_green->setValue(
        static_cast<int>(glwidget->conf->color_fon[1] * 255));
    ui->slider_blue->setValue(
        static_cast<int>(glwidget->conf->color_fon[2] * 255));
    ui->slider_size_v_e->setValue(1);
  } else if (index == 1) {
    ui->slider_red->setValue(
        static_cast<int>(glwidget->conf->color_point[0] * 255));
    ui->slider_green->setValue(
        static_cast<int>(glwidget->conf->color_point[1] * 255));
    ui->slider_blue->setValue(
        static_cast<int>(glwidget->conf->color_point[2] * 255));
    ui->slider_size_v_e->setValue(glwidget->conf->point_width);
  } else {
    ui->slider_red->setValue(
        static_cast<int>(glwidget->conf->color_line[0] * 255));
    ui->slider_green->setValue(
        static_cast<int>(glwidget->conf->color_line[1] * 255));
    ui->slider_blue->setValue(
        static_cast<int>(glwidget->conf->color_line[2] * 255));
    ui->slider_size_v_e->setValue(glwidget->conf->line_width);
  }
  glwidget->update();
}

void MainWindow::on_rotateButton_clicked() {
  bool ok = false;
  float angle = this->ui->rotateField->text().toFloat(&ok);
  if (ok && this->glwidget->conf->fig) {
    int index = this->ui->rotateAx->currentIndex();
    float *center_before_rotate =
        figure_center(glwidget->conf->fig);  //центры коор. фигуры
    transform_coordinates(glwidget->conf->fig, center_before_rotate);
    if (index == 0)
      rotation_figure(this->glwidget->conf->fig, angle, 0, 0);
    else if (index == 1)
      rotation_figure(this->glwidget->conf->fig, 0, angle, 0);
    else
      rotation_figure(this->glwidget->conf->fig, 0, 0, angle);
    float *center_after_rotate =
        figure_center(glwidget->conf->fig);  // новый центр фигуры
    for (int i = 0; i < 3; i++) {
      center_before_rotate[i] =
          -center_before_rotate[i] + center_after_rotate[i];
    }
    transform_coordinates(glwidget->conf->fig, center_before_rotate);
    free(center_before_rotate);
    free(center_after_rotate);

    this->ui->rotateField->clear();
    glwidget->update();
  }
}

void MainWindow::on_slider_size_v_e_sliderMoved(int position) {
  if (ui->Color_B_V_E->currentIndex() == 1)
    glwidget->conf->point_width = position;
  else if (ui->Color_B_V_E->currentIndex() == 2)
    glwidget->conf->line_width = position;
  glwidget->update();
}

void MainWindow::on_translateButton_clicked() {
  bool ok = false;
  float value = this->ui->translateField->text().toFloat(&ok);
  if (ok && this->glwidget->conf->fig) {
    int index = this->ui->translateAx->currentIndex();
    if (index == 0)
      translate_figure(this->glwidget->conf->fig, value, 0, 0);
    else if (index == 1)
      translate_figure(this->glwidget->conf->fig, 0, value, 0);
    else
      translate_figure(this->glwidget->conf->fig, 0, 0, value);
    this->ui->translateField->clear();
    this->glwidget->update();
  }
}

void MainWindow::on_scaleButton_clicked() {
  bool ok = false;
  float value = this->ui->scaleField->text().toFloat(&ok);
  if (ok && this->glwidget->conf->fig) {
    int index = this->ui->scaleAx->currentIndex();
    float *center_before_scaling =
        figure_center(glwidget->conf->fig);  //центры коор. фигуры
    transform_coordinates(glwidget->conf->fig, center_before_scaling);
    if (index == 0)
      scale_figure(this->glwidget->conf->fig, value, 1, 1);
    else if (index == 1)
      scale_figure(this->glwidget->conf->fig, 1, value, 1);
    else
      scale_figure(this->glwidget->conf->fig, 1, 1, value);
    float *center_after_scaling =
        figure_center(glwidget->conf->fig);  // новый центр фигуры
    for (int i = 0; i < 3; i++) {
      center_before_scaling[i] =
          -center_before_scaling[i] + center_after_scaling[i];
    }
    transform_coordinates(glwidget->conf->fig, center_before_scaling);
    free(center_before_scaling);
    free(center_after_scaling);
    this->ui->scaleField->clear();
    this->glwidget->update();
  }
}

void MainWindow::on_button_screenshot_clicked() {
  int index = this->ui->format_screenshot->currentIndex();
  glwidget->screen_widget(index);
}

void MainWindow::on_type_projection_activated(int index) {
  if (index == 0)
    glwidget->conf->type_projection = 0;  // orto
  else
    glwidget->conf->type_projection = 1;  // frustrum
  this->glwidget->update();
}

void MainWindow::on_button_gif_clicked() {
    glwidget->num = 0;
    glwidget->tmr->start(100);
}

