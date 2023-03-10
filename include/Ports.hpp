#include "api.h"
#include "pros/adi.hpp"

//Extra Motor Ports
extern pros::Motor Catapult;
extern pros::Motor intake1;
extern pros::Motor intake2;
extern pros::Motor roller;

//ADI Ports
extern pros::ADIDigitalOut Intake_Actuate;
extern pros::ADIAnalogIn limit_switch;
extern pros::ADIDigitalOut Holder_Angle;
extern pros::ADIDigitalOut Endgame;