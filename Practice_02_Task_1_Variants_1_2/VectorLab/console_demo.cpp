#include "vector3d.h"
#include <iostream>
#include <iomanip>
int main(){
    std::cout<<std::fixed<<std::setprecision(6);
    const Vector3D drone_velocity(10,4,-1),wind_velocity(2,-1,0);
    const Vector3D ground_velocity=drone_velocity+wind_velocity;
    const Vector3D correction=ground_velocity*0.8;
    std::cout<<"VARIANT 1: UAV velocity\nAir velocity: "<<drone_velocity
        <<"\nWind: "<<wind_velocity<<"\nGround velocity: "<<ground_velocity
        <<"\nGround speed: "<<ground_velocity.length()<<" m/s\nCorrection: "<<correction
        <<"\nCorrection length: "<<correction.length()<<" m/s\n\n";
    const Vector3D start(0,0,100),finish(300,200,150);
    const Vector3D displacement=finish-start;
    const Vector3D check=start+displacement;
    std::cout<<"VARIANT 2: Route displacement\nStart: "<<start<<"\nFinish: "<<finish
        <<"\nDisplacement: "<<displacement<<"\nSpatial distance: "<<displacement.length()
        <<" m\nCheck: "<<check<<"\nCheck == finish: "<<std::boolalpha<<(check==finish)<<'\n';
}
