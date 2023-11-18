#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QFileDialog>
#include <QMainWindow>
#include <QtOpenGL>

#include "openglimpl.h"

extern "C" {
#include "figure.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_fileDialogButton_clicked();
  void type_vertex();
  void type_edg();

  void on_slider_red_sliderMoved(int position);
  void on_slider_green_sliderMoved(int position);
  void on_slider_blue_sliderMoved(int position);
  void on_Color_B_V_E_activated(int index);

  void on_rotateButton_clicked();
  void on_slider_size_v_e_sliderMoved(int position);

  void on_translateButton_clicked();
  void on_scaleButton_clicked();
  void on_button_screenshot_clicked();

  void on_type_projection_activated(int index);

 private:
  Ui::MainWindow *ui;
  OpenGLImpl *glwidget;
};
#endif  // MAINWINDOW_H
