#include "drone.h"

#include <cmath>
#include <iomanip>
#include <iostream>

namespace {
bool valid_position(double x, double y, double z) {
    return std::isfinite(x) && std::isfinite(y) && std::isfinite(z) && z >= 0.0;
}

double bounded_battery(double value) {
    if (!std::isfinite(value)) {
        return 0.0;
    }
    if (value < 0.0) {
        return 0.0;
    }
    if (value > 100.0) {
        return 100.0;
    }
    return value;
}
} // namespace

Drone::Drone()
    : id(0), x(0.0), y(0.0), z(0.0), battery(100.0), flying(false) {}

Drone::Drone(int drone_id, double initial_battery)
    : id(drone_id), x(0.0), y(0.0), z(0.0),
      battery(bounded_battery(initial_battery)), flying(false) {}

void Drone::set_position(double new_x, double new_y, double new_z) {
    if (!valid_position(new_x, new_y, new_z)) {
        std::cout << "Error: invalid position or altitude\n";
        return;
    }
    x = new_x;
    y = new_y;
    z = new_z;
}

void Drone::takeoff() {
    if (battery < 10.0) {
        std::cout << "Takeoff denied: low battery\n";
        return;
    }
    if (flying) {
        std::cout << "Drone is already flying\n";
        return;
    }
    flying = true;
    z = 1.0;
    battery -= 1.0;
    std::cout << "Drone took off\n";
}

void Drone::land() {
    if (!flying) {
        std::cout << "Drone is already on the ground\n";
        return;
    }
    flying = false;
    z = 0.0;
    std::cout << "Drone landed\n";
}

void Drone::emergency_land() {
    // An emergency landing resets the altitude and flight state immediately.
    z = 0.0;
    flying = false;
    std::cout << "WARNING: Emergency landing activated\n"
              << "Drone landed immediately\n";
}

void Drone::move_to(double new_x, double new_y, double new_z) {
    if (!flying) {
        std::cout << "Move denied: drone is not flying\n";
        return;
    }
    if (!valid_position(new_x, new_y, new_z)) {
        std::cout << "Move denied: invalid position or altitude\n";
        return;
    }
    if (battery < 5.0) {
        std::cout << "Move denied: critically low battery\n";
        return;
    }
    x = new_x;
    y = new_y;
    z = new_z;
    battery -= 1.0;
    std::cout << "Drone moved to new position\n";
}

void Drone::set_battery(double value) {
    battery = bounded_battery(value);
}

int Drone::get_id() const {
    return id;
}

double Drone::get_battery() const {
    return battery;
}

bool Drone::is_flying() const {
    return flying;
}

void Drone::print_info() const {
    std::cout << std::fixed << std::setprecision(2)
              << "Drone ID: " << id << '\n'
              << "Position: (" << x << ", " << y << ", " << z << ")\n"
              << "Battery: " << battery << "%\n"
              << "Status: " << (flying ? "Flying" : "On ground") << '\n';
}

double Drone::get_x() const { return x; }
double Drone::get_y() const { return y; }
double Drone::get_altitude() const { return z; }
