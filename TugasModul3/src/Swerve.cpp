#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

#include "Matrix.h"
#include "Swerve.h"

using namespace std;

void Swerve::velocityCommand(float vx, float vy, float omega){
    this->v_x = vx;
    this->v_y = vy;
    this->omega = omega;
    this->velocity = mat1*mat2;
};
void Swerve::updatePose(float deltaTime){
    Matrix copyPosition = Matrix(position);
    Matrix time = Matrix({{deltaTime}});
    this->position = copyPosition + (mat2*time);
};
void Swerve::set_v_x(float value){
    this->v_x = value;
};
void Swerve::set_v_y(float value){
    this->v_y = value;
};
void Swerve::set_omega(float value){
    this->omega = value;
};