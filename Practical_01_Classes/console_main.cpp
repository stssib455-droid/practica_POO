#include "drone.h"

#include <iostream>

int main() {
    Drone drone_1;
    std::cout << "--- Initial state ---\n";
    drone_1.print_info();

    std::cout << "\n--- Flight ---\n";
    drone_1.takeoff();
    drone_1.move_to(10.0, 20.0, 50.0);
    drone_1.print_info();
    drone_1.land();
    drone_1.print_info();

    std::cout << "\n--- Emergency landing ---\n";
    Drone emergency_drone(2, 80.0);
    emergency_drone.takeoff();
    emergency_drone.move_to(5.0, 6.0, 30.0);
    emergency_drone.emergency_land();
    emergency_drone.print_info();

    std::cout << "\n--- Input and state checks ---\n";
    Drone low_battery_drone(3, 5.0);
    low_battery_drone.takeoff();
    low_battery_drone.move_to(1.0, 2.0, 10.0);
    drone_1.takeoff();
    drone_1.takeoff();
    drone_1.move_to(1.0, 2.0, -1.0);
    drone_1.set_battery(4.0);
    drone_1.move_to(1.0, 2.0, 10.0);
    drone_1.emergency_land();

    Drone bounded_drone(4, 150.0);
    std::cout << "Battery after 150% input: " << bounded_drone.get_battery() << "%\n";
    bounded_drone.set_battery(-10.0);
    std::cout << "Battery after -10% input: " << bounded_drone.get_battery() << "%\n";
    return 0;
}
