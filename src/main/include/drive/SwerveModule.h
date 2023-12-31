// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonFX.h>

class SwerveModule : public frc2::SubsystemBase {
 public:
//   SwerveModule();
  SwerveModule(int driveMotorID, int turnMotorID, int encoderID, frc::Rotation2d angleOffset);
  void initDriveMotor(int driveMotorID);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
     
     // Components (e.g. motor controllers and sensors) should generally be
     // declared private and exposed only through public methods.
    ctre::phoenix::motorcontrol::can::WPI_TalonFX drive;
    ctre::phoenix::motorcontrol::can::WPI_TalonFX turn;
    ctre::phoenix::sensors::CANCoder turnEncoder;
    frc::Rotation2d angleOffset;
    frc::SimpleMotorFeedforward<units::voltage::volt_t> feedforward;

    int id;

    double lastAngle;
};
