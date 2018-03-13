#include "RsjRobot.h"
#include <controller_manager/controller_manager.h>
#include <ros/callback_queue.h>
#include <sensor_msgs/JointState.h>
#include <signal.h>
#include <unistd.h>

bool g_quit = false;

void quitRequested(int sig) { g_quit = true; }

int main(int argc, char **argv) {
  ros::init(argc, argv, "rsj_control_node");
  ros::NodeHandle nh;

  ros::CallbackQueue queue;
  nh.setCallbackQueue(&queue);

  ros::AsyncSpinner spinner(4, &queue);
  spinner.start();

  // Add custom signal handlers
  signal(SIGTERM, quitRequested);
  signal(SIGINT, quitRequested);
  signal(SIGHUP, quitRequested);

  RsjRobot robot;
  controller_manager::ControllerManager cm(&robot);

  // subscribeToJointStates(&nh);

  ros::Time ts = ros::Time::now();
  ros::Rate rate(3);
  // while (ros::ok())
  while (!g_quit) {
    ros::Duration d = ros::Time::now() - ts;
    ts = ros::Time::now();

    robot.read();
    cm.update(ts, d);
    robot.write();

    rate.sleep();
  }

  spinner.stop();

  exit(0);
}
