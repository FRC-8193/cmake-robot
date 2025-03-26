#include <frc/TimedRobot.h>
#include <iostream>

class Robot : public frc::TimedRobot {
public:
	Robot() {
		std::cout << "Robot Start!" << std::endl;
	}

	void RobotPeriodic() {
	}

	void AutonomousInit() {
		std::cout << "Autonomous Start!" << std::endl;
	}

	void AutonomousPeriodic() {
	}

	void TeleopInit() {
		std::cout << "Teleop Start!" << std::endl;
	}

	void TeleopPeriodic() {
	}

	void DisabledInit() {
		std::cout << "Disabled Start!" << std::endl;
	}

	void DisabledPeriodic() {
	}

	void TestInit() {
	}

	void TestPeriodic() {
	}

	void SimulationInit() {
	}

	void SimulationPeriodic() {
	}
};

int main() {
	return frc::StartRobot<Robot>();
}
