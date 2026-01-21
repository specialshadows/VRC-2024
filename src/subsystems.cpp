#include "subsystems.h"
using namespace vex;

// scoring subsystem implementation
ScoringSubsystem::ScoringSubsystem(
    motor &motor1,
    motor &miniMotor1,
    motor &miniMotor2
) : _motor1(motor1),
    _miniMotor1(miniMotor1),
    _miniMotor2(miniMotor2) {}

// Stop all motors
void ScoringSubsystem::system_default() {
    _motor1.stop();
    _miniMotor1.stop();
    _miniMotor2.stop();
}

// Score top goal (R1)
void ScoringSubsystem::intakeTop() {
    _miniMotor1.spin(reverse, 100, percent);
    _motor1.spin(forward, 67, percent);  
    _miniMotor2.spin(forward, 100, percent);
}

// Score middle goal (R2)
void ScoringSubsystem::intakeMiddle() {
    _miniMotor2.spin(forward, 100, percent); 
    _motor1.spin(forward, 67, percent);      
    _miniMotor1.spin(forward, 100, percent);
}

// Eject (B)
void ScoringSubsystem::eject() {
    _miniMotor1.spin(forward, 73, percent);
    _miniMotor2.spin(reverse, 73, percent);  
    _motor1.spin(reverse, 67, percent);    
}

// descore subsystem implementation
DescoreSubsystem::DescoreSubsystem(digital_out &piston) :
    _piston(piston) {}

void DescoreSubsystem::up() {
    _piston.set(true);
}

void DescoreSubsystem::down() {
    _piston.set(false);
}
