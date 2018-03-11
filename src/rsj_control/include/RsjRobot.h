#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/robot_hw.h>

class RsjRobot : public hardware_interface::RobotHW {
public:
  RsjRobot();
  ~RsjRobot();
  void read();
  void write();

private:
  hardware_interface::JointStateInterface jnt_state_interface;
  hardware_interface::PositionJointInterface jnt_pos_interface;
  double cmd;
  double pos;
  double vel;
  double eff;
};