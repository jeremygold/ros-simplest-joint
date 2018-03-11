#include "RsjRobot.h"

RsjRobot::RsjRobot() {
  // connect and register the joint state interface
  hardware_interface::JointStateHandle state_handle_a("joint1", &pos, &vel,
                                                      &eff);
  jnt_state_interface.registerHandle(state_handle_a);
  registerInterface(&jnt_state_interface);

  // connect and register the joint position interface
  hardware_interface::JointHandle pos_handle_a(
      jnt_state_interface.getHandle("joint1"), &cmd);
  jnt_pos_interface.registerHandle(pos_handle_a);
  registerInterface(&jnt_pos_interface);
}

RsjRobot::~RsjRobot() {}

void RsjRobot::read() {}

void RsjRobot::write() {}
