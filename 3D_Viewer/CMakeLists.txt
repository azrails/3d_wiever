cmake_minimum_required(VERSION 3.5)

project(3D_Viewer VERSION 0.1 LANGUAGES CXX C)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
<<<<<<< HEAD
if(APPLE)
    set(CMAKE_CXX_FLAGS "-framework OpenGL")
else()
    set(CMAKE_CXX_FLAGS "-lGL -lGLU -lglut -lm ")
=======
if(LINUX)
    set(CMAKE_CXX_FLAGS "-lGL -lGLU -lglut -lm")
>>>>>>> refs/remotes/origin/main
endif()

list(APPEND CMAKE_PREFIX_PATH /home/diana/Qt/6.6.0/gcc_64)
list(APPEND CMAKE_PREFIX_PATH /Users/azrail/Qt/6.6.0/macos)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS OpenGLWidgets)


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        openglimpl.h openglimpl.cpp
        figure.h figure.c
        transforms.h transforms.c
        gif/giflib/dgif_lib.c
        gif/giflib/egif_lib.c
        gif/giflib/gif_err.c
        gif/giflib/gif_hash.c
        gif/giflib/gifalloc.c
        gif/giflib/quantize.c
        gif/giflib/gif_font.c
        gif/giflib/gif_hash.h
        gif/giflib/gif_lib.h
        gif/giflib/gif_lib_private.h
        gif/qgifimage.cpp
        gif/qgifglobal.h
        gif/qgifimage.h
        gif/qgifimage_p.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(3D_Viewer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET 3D_Viewer APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(3D_Viewer SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(3D_Viewer
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(3D_Viewer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(3D_Viewer PRIVATE Qt6::OpenGLWidgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.3D_Viewer)
endif()
set_target_properties(3D_Viewer PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS 3D_Viewer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(3D_Viewer)
endif()
