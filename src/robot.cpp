#include <frc/TimedRobot.h>
#include <iostream>

class Robot : public frc::TimedRobot {
public:
	Robot() {
		std::cout << "Initializing..." << std::endl;
	}

	void TeleopInit() {
		std::cout << "Teleop start!" << std::endl;
	}
};

int main() {
	frc::StartRobot<Robot>();

	return 0;
}
