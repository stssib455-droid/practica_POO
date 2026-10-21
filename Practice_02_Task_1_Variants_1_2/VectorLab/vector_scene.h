#ifndef VECTOR_SCENE_H
#define VECTOR_SCENE_H
#include <QWidget>
#include "vector3d.h"
class VectorScene : public QWidget {
    Q_OBJECT
public:
    explicit VectorScene(QWidget* parent=nullptr);
    void setVectors(int mode,const Vector3D& first,const Vector3D& second,double factor);
    void setView(int projection,double yaw,double pitch);
protected:
    void paintEvent(QPaintEvent*) override;
private:
    int mode=0, projection=0;
    double yaw=325,pitch=25,factor=.8;
    Vector3D first{10,4,-1},second{2,-1,0};
};
#endif
