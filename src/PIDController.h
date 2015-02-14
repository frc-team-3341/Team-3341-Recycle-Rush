#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

class PIDController {
public:
    PIDController(double Kp, double Ki, double Kd, double setPoint);
    double Tick(double measuredValue);
    void SetSetPoint(double setPoint);
    double GetSetPoint();
    void SetKp(double Kp);
    double GetKp();
    void SetKi(double Ki);
    double SetKi();
    void SetKd(double Kd);
    double GetKd();
private:
    double Kp;
    double Ki;
    double Kd;
    double setPoint;
    double previousError;
    double integral;
};

#endif
