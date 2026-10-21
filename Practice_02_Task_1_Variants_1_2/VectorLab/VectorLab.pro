QT += widgets
CONFIG += c++17
CONFIG -= console app_bundle
TEMPLATE = app
TARGET = VectorLab
SOURCES += main.cpp mainwindow.cpp vector_scene.cpp vector3d.cpp
HEADERS += mainwindow.h vector_scene.h vector3d.h
FORMS += mainwindow.ui
