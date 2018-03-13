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

void RsjRobot::read() {
  printf("Reading Robot State - ");
  printf("Pos: %0.2f; Vel: %0.2f; Eff:%0.2f\n", pos, vel, eff);
}

void RsjRobot::write() {
  printf("Writing Robot State - ");
  printf("Cmd: %0.2f\n", cmd);
}
