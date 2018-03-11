#include "RsjRobot.h"
#include <controller_manager/controller_manager.h>
#include <ros/callback_queue.h>
#include <sensor_msgs/JointState.h>
#include <signal.h>
#include <unistd.h>

main() {
  RsjRobot robot;
  controller_manager::ControllerManager cm(&robot);

  while (true) {
    robot.read();
    cm.update(robot.get_time(), robot.get_period());
    robot.write();
    sleep();
  }
}