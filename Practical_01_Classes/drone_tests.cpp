#include "drone.h"
#include <iostream>
#include <limits>
#include <stdexcept>
#include <sstream>
int main() {
    int checks = 0;
    auto check = [&](bool result, const char* name) {
        ++checks; if (!result) throw std::runtime_error(name);
    };
    try {
        Drone d;
        check(d.get_id() == 0 && d.get_battery() == 100 && !d.is_flying(), "default state");
        check(d.get_x() == 0 && d.get_y() == 0 && d.get_altitude() == 0, "default coordinates");
        Drone low(3, 9.99); low.takeoff();
        check(!low.is_flying(), "takeoff below ten rejected");
        Drone edge(4, 10); edge.takeoff();
        check(edge.is_flying() && edge.get_battery() == 9 && edge.get_altitude() == 1, "takeoff threshold");
        d.move_to(10, 20, 30);
        check(d.get_x() == 0 && d.get_battery() == 100, "movement on ground rejected");
        d.takeoff(); d.takeoff();
        check(d.get_battery() == 99 && d.get_altitude() == 1, "repeated takeoff no extra cost");
        d.move_to(10, 20, 50);
        check(d.get_x() == 10 && d.get_y() == 20 && d.get_altitude() == 50 && d.get_battery() == 98, "movement");
        d.move_to(1, 2, -1);
        check(d.get_x() == 10 && d.get_altitude() == 50 && d.get_battery() == 98, "negative altitude atomic rejection");
        d.set_position(std::numeric_limits<double>::infinity(), 2, 3);
        check(d.get_x() == 10, "infinite coordinate rejected");
        d.set_battery(5); d.move_to(-2, -3, 10);
        check(d.get_battery() == 4 && d.get_x() == -2, "move at five percent");
        d.move_to(9, 9, 9);
        check(d.get_x() == -2 && d.get_altitude() == 10 && d.get_battery() == 4, "critical charge movement denied");
        d.set_battery(0); d.emergency_land();
        check(!d.is_flying() && d.get_altitude() == 0 && d.get_x() == -2 && d.get_battery() == 0, "emergency at zero charge");
        d.emergency_land(); check(!d.is_flying() && d.get_altitude() == 0, "repeated emergency safe");
        d.set_battery(150); check(d.get_battery() == 100, "upper clamp");
        d.set_battery(-10); check(d.get_battery() == 0, "lower clamp");
        d.set_battery(std::numeric_limits<double>::quiet_NaN());
        check(d.get_battery() == 0, "original nonfinite battery policy");
        d.set_battery(80); d.takeoff(); d.land(); d.land();
        check(!d.is_flying() && d.get_altitude() == 0 && d.get_battery() == 79, "normal landing");
        Drone named(7, 150);
        check(named.get_id() == 7 && named.get_battery() == 100, "parameterized constructor clamp");
        std::cout << "PASS: " << checks << " checks\n";
    } catch (const std::exception& e) { std::cerr << "FAIL: " << e.what() << '\n'; return 1; }
}
