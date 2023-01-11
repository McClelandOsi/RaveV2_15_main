#include "main.h"
#include "pros/rtos.hpp"

bool firing;


void Catapult_Control(void *) {
  while (true) {
    Catapult.move_velocity(100);

    if (master.get_digital(DIGITAL_L2))
    {
      Holder_Angle.set_value(true);
    }
    else {
      Holder_Angle.set_value(false);
    }

    if (limit_switch.get_value() < 30) {
      Catapult.move_velocity(0);
    }

    if (master.get_digital(DIGITAL_L1)) {
      Catapult.move_velocity(100);
      Catapult.tare_position();
    }

    pros::delay(20);
  }
}

void Catapult_Down(void) {
  while (true) {

    if (firing)
    {
      Catapult.move_velocity(100);
      pros::delay(500);
      Catapult.tare_position();
      firing = false;
    }
    else {
      Catapult.move_velocity((-0.0135135135*Catapult.get_position() + 100));

      if (limit_switch.get_value() < 30)
      {
        Catapult.move_velocity(0);
      }
    }

    pros::delay(20);
  }
}

void Catapult_Fire(void) {
  firing = true;
}

