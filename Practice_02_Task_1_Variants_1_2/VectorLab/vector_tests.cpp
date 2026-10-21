#include "vector3d.h"
#include <cmath>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
int count=0, failed=0;
void check(bool ok,const char* name){++count; if(!ok){++failed;std::cerr << "FAIL: " << name << '\n';}}
bool close(double a,double b){return std::abs(a-b)<1e-9;}
template<class F> bool rejects(F f){try{f();return false;}catch(const std::exception&){return true;}}
int main(){
 Vector3D zero;check(zero.get_x()==0 && zero.get_y()==0 && zero.get_z()==0,"default origin");
 Vector3D air(10,4,-1),wind(2,-1,0);auto ground=air+wind;
 check(ground.get_x()==12 && ground.get_y()==3 && ground.get_z()==-1,"variant 1 ground speed");
 check(close(ground.length(),std::sqrt(154.0)),"variant 1 length sqrt154");
 auto control=ground*0.8;
 check(close(control.get_x(),9.6)&&close(control.get_y(),2.4)&&close(control.get_z(),-0.8),"autopilot correction");
 Vector3D start(0,0,100),finish(300,200,150);auto delta=finish-start;
 check(delta.get_x()==300 && delta.get_y()==200 && delta.get_z()==50,"variant 2 displacement");
 check(close(delta.length(),std::sqrt(132500.0)),"variant 2 spatial distance");
 check(start+delta==finish,"variant 2 endpoint identity");
 check(air.get_x()==10 && air.get_y()==4 && air.get_z()==-1,"operators preserve input");
 check((air-air).length()==0,"subtract itself");
 check((air*0).length()==0,"zero factor");
 check((air*-2).get_z()==2,"negative factor");
 check(Vector3D(0.1+0.2,0,0)==Vector3D(0.3,0,0),"floating comparison");
 check(!(Vector3D(1,2,3)==Vector3D(1.001,2,3)),"different vectors");
 check(close(Vector3D(3,4,12).length(),13),"3D norm");
 check(std::isfinite(Vector3D(1e200,1e200,0).length()),"stable norm large coordinates");
 check(rejects([]{Vector3D v(std::numeric_limits<double>::quiet_NaN(),0,0);}),"reject NaN");
 check(rejects([]{Vector3D v(0,std::numeric_limits<double>::infinity(),0);}),"reject infinity");
 check(rejects([&]{auto v=air*std::numeric_limits<double>::infinity();}),"reject nonfinite factor");
 check(rejects([]{auto v=Vector3D(1e308,0,0)*10;}),"reject overflow");
 std::ostringstream out;out<<ground;check(out.str()=="(12, 3, -1)","stream format");
 std::ostringstream capture;auto* old=std::cout.rdbuf(capture.rdbuf());ground.print();std::cout.rdbuf(old);
 check(capture.str()=="(12, 3, -1)\n","print uses stream");
 std::cout<<"Checks: "<<count<<", failed: "<<failed<<'\n';return failed?1:0;
}
