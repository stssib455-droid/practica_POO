#include "vector_scene.h"
#include <QPainter>
#include <QPainterPath>
#include <QFontMetricsF>
#include <QPolygonF>
#include <array>
#include <algorithm>
#include <cmath>
#include <vector>
namespace {
const QColor blue("#246ac4"),orange("#db8b26"),teal("#008d89"),purple("#8561c5");
constexpr double pi=3.14159265358979323846;
}
VectorScene::VectorScene(QWidget* parent):QWidget(parent){
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    setAccessibleName("Схема трёхмерных векторов");
}
void VectorScene::setVectors(int m,const Vector3D& a,const Vector3D& b,double k){mode=m;first=a;second=b;factor=k;update();}
void VectorScene::setView(int p,double y,double e){projection=p;yaw=y;pitch=e;update();}
void VectorScene::paintEvent(QPaintEvent*){
    QPainter painter(this);painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(rect(),QColor("#f8fafd"));
    if(width()<100 || height()<80)return;
    const Vector3D origin;
    const Vector3D result=mode?second-first:first+second;
    const Vector3D control=mode?second:result*factor;
    std::array<Vector3D,5> points{origin,first,second,mode?second:result,control};
    double xmin=0,xmax=0,ymin=0,ymax=0,zmin=0,zmax=0;
    for(const auto& v:points){
        xmin=std::min(xmin,v.get_x());xmax=std::max(xmax,v.get_x());
        ymin=std::min(ymin,v.get_y());ymax=std::max(ymax,v.get_y());
        zmin=std::min(zmin,v.get_z());zmax=std::max(zmax,v.get_z());
    }
    const double span=std::max({xmax-xmin,ymax-ymin,zmax-zmin,1.0});
    const double margin=span*.18;
    xmin-=margin;xmax+=margin;ymin-=margin;ymax+=margin;zmin-=margin;zmax+=margin;
    const double a=yaw*pi/180.0,e=pitch*pi/180.0;
    auto raw=[&](const Vector3D& v)->QPointF{
        if(projection==1)return {v.get_x(),-v.get_y()};
        if(projection==2)return {v.get_x(),-v.get_z()};
        if(projection==3)return {v.get_y(),-v.get_z()};
        const double horizontal=std::cos(a)*v.get_x()-std::sin(a)*v.get_y();
        const double depth=std::sin(a)*v.get_x()+std::cos(a)*v.get_y();
        return {horizontal,std::sin(e)*depth-std::cos(e)*v.get_z()};
    };
    QRectF bounds;bool initialized=false;
    std::vector<Vector3D> fitPoints(points.begin(),points.end());
    // Fit the geometry actually drawn, rather than unused corners of a 3D box.
    if(projection==0 || projection==1){
        for(double x:{xmin,xmax})for(double y:{ymin,ymax})fitPoints.emplace_back(x,y,0);
    }else if(projection==2){
        for(double x:{xmin,xmax})for(double z:{zmin,zmax})fitPoints.emplace_back(x,0,z);
    }else{
        for(double y:{ymin,ymax})for(double z:{zmin,zmax})fitPoints.emplace_back(0,y,z);
    }
    fitPoints.emplace_back(xmin,0,0);fitPoints.emplace_back(xmax,0,0);
    fitPoints.emplace_back(0,ymin,0);fitPoints.emplace_back(0,ymax,0);
    if(projection!=1){fitPoints.emplace_back(0,0,zmin);fitPoints.emplace_back(0,0,zmax);}
    for(const auto& v:fitPoints){
        const auto point=raw(v);
        if(!initialized){bounds=QRectF(point,QSizeF(0,0));initialized=true;}
        else bounds=QRectF(QPointF(std::min(bounds.left(),point.x()),std::min(bounds.top(),point.y())),
                          QPointF(std::max(bounds.right(),point.x()),std::max(bounds.bottom(),point.y())));
    }
    const QRectF area=QRectF(rect()).adjusted(38,28,-38,-28);
    const double scale=std::min(area.width()/std::max(bounds.width(),.001),area.height()/std::max(bounds.height(),.001));
    auto project=[&](const Vector3D& v){return area.center()+(raw(v)-bounds.center())*scale;};
    painter.setPen(QPen(QColor("#e1e8f3"),1));
    for(int i=0;i<=8;++i){
        const double t=i/8.;
        if(projection==0 || projection==1){
            double x=xmin+(xmax-xmin)*t,y=ymin+(ymax-ymin)*t;
            painter.drawLine(project(Vector3D(x,ymin,0)),project(Vector3D(x,ymax,0)));
            painter.drawLine(project(Vector3D(xmin,y,0)),project(Vector3D(xmax,y,0)));
        }else if(projection==2){
            double x=xmin+(xmax-xmin)*t,z=zmin+(zmax-zmin)*t;
            painter.drawLine(project(Vector3D(x,0,zmin)),project(Vector3D(x,0,zmax)));
            painter.drawLine(project(Vector3D(xmin,0,z)),project(Vector3D(xmax,0,z)));
        }else{
            double y=ymin+(ymax-ymin)*t,z=zmin+(zmax-zmin)*t;
            painter.drawLine(project(Vector3D(0,y,zmin)),project(Vector3D(0,y,zmax)));
            painter.drawLine(project(Vector3D(0,ymin,z)),project(Vector3D(0,ymax,z)));
        }
    }
    // Draw in screen coordinates so arrowheads stay legible at any model scale.
    auto arrow=[&](const Vector3D& from,const Vector3D& to,QColor color,double width,Qt::PenStyle style){
        const QPointF start=project(from),end=project(to),d=end-start;
        const double length=std::hypot(d.x(),d.y());
        painter.setPen(QPen(color,width,style,Qt::RoundCap));
        if(length<2){painter.setBrush(color);painter.drawEllipse(end,3,3);return;}
        painter.drawLine(start,end);
        const QPointF along=d/length,normal(-along.y(),along.x());
        const double head=std::min(10.,length*.3);
        const QPolygonF triangle{end,end-along*head+normal*head*.42,end-along*head-normal*head*.42};
        painter.setPen(Qt::NoPen);painter.setBrush(color);painter.drawPolygon(triangle);
    };
    const QColor axis("#a1afc3");
    if(projection!=3)arrow(Vector3D(xmin,0,0),Vector3D(xmax,0,0),axis,1,Qt::SolidLine);
    if(projection!=2)arrow(Vector3D(0,ymin,0),Vector3D(0,ymax,0),axis,1,Qt::SolidLine);
    if(projection!=1)arrow(Vector3D(0,0,zmin),Vector3D(0,0,zmax),axis,1,Qt::SolidLine);
    QFont font=painter.font();font.setPointSizeF(8);painter.setFont(font);
    QList<QRectF> placed;
    auto tag=[&](QPointF point,const QString& text,QColor color){
        const QFontMetricsF fm(painter.font());
        const QSizeF size=fm.boundingRect(text).size()+QSizeF(10,6);
        const std::array<QPointF,8> offsets{QPointF(10,-size.height()-6),QPointF(10,8),
            QPointF(-size.width()-10,-size.height()-6),QPointF(-size.width()-10,8),
            QPointF(-size.width()/2,-size.height()-28),QPointF(-size.width()/2,28),QPointF(24,-10),QPointF(-size.width()-24,-10)};
        QRectF chosen;
        for(const auto& offset:offsets){
            QRectF candidate(point+offset,size);
            candidate.moveLeft(std::clamp(candidate.left(),4.,std::max(4.,width()-size.width()-4)));
            candidate.moveTop(std::clamp(candidate.top(),22.,std::max(22.,height()-size.height()-4)));
            bool collides=false;for(const auto& other:placed)if(candidate.intersects(other)){collides=true;break;}
            chosen=candidate;if(!collides)break;
        }
        placed.append(chosen.adjusted(-2,-2,2,2));
        painter.setPen(Qt::NoPen);painter.setBrush(QColor(255,255,255,235));painter.drawRoundedRect(chosen,3,3);
        painter.setPen(color);painter.drawText(chosen,Qt::AlignCenter,text);
    };
    const QString unit=mode?"м":"м/с";
    painter.setPen(QColor("#7c8da6"));
    painter.drawText(QRectF(10,5,width()-20,18),Qt::AlignLeft|Qt::AlignVCenter,
        projection==0?"Пространственный вид · оси X, Y, Z · "+unit:
        "Ортогональная проекция · "+unit+" · длины в таблице всегда трёхмерные");
    if(projection!=3)tag(project(Vector3D(xmax,0,0)),"X",axis);
    if(projection!=2)tag(project(Vector3D(0,ymax,0)),"Y",axis);
    if(projection!=1)tag(project(Vector3D(0,0,zmax)),"Z",axis);
    if(mode==0){
        arrow(origin,first,blue,2.5,Qt::SolidLine);
        arrow(origin,second,orange,2.5,Qt::SolidLine);
        arrow(first,result,orange,2,Qt::DashLine);
        arrow(origin,control,purple,5,Qt::DashLine);
        arrow(origin,result,teal,2.5,Qt::SolidLine);
        tag(project(first),first.length()==0?"Vбпла = 0":"Vбпла",blue);
        tag(project(second),second.length()==0?"Vветра = 0":"Vветра",orange);
        tag(project(result),result.length()==0?"Vзем = 0":"Vзем",teal);
        tag(project(control),control.length()==0?"C = 0":"C = k · Vзем",purple);
    }else{
        for(const auto& v:{first,second}){
            painter.setPen(QPen(QColor("#c3cedd"),1,Qt::DashLine));
            painter.drawLine(project(v),project(Vector3D(v.get_x(),v.get_y(),0)));
        }
        arrow(origin,first,blue,1.5,Qt::DashLine);
        arrow(origin,second,orange,1.5,Qt::DashLine);
        arrow(first,second,teal,3,Qt::SolidLine);
        painter.setPen(QPen(blue,2));painter.setBrush(Qt::white);painter.drawEllipse(project(first),5,5);
        painter.setPen(QPen(orange,2));painter.drawEllipse(project(second),5,5);
        tag(project(first),"S · начало",blue);tag(project(second),"F · конец",orange);
        tag(project(first+result*.5),result.length()==0?"D = 0":"D = F − S",teal);
    }
    painter.setPen(Qt::NoPen);painter.setBrush(axis);painter.drawEllipse(project(origin),2.5,2.5);
    tag(project(origin),"O",QColor("#8091a8"));
}
