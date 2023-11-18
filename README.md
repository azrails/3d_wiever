## Инструкция по сбору и запуску проекта 3D_Viewer_v1

### Необходимые изменения перед сборкой:

1) в *Makefile*:
#### Изменить путь будущего местоположения приложения (`PATH_EXE`)

2) в *CMakeList.txt*:
#### Необходимо знать, где находится установка Qt. Изменить путь в строке `list(APPEND CMAKE_PREFIX_PATH /home/diana/Qt/6.6.0/gcc_64)`.


#### доп. инф. `https://doc.qt.io/qt-6/cmake-build-on-cmdline.html`

