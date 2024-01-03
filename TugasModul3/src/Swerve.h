#ifndef __SWERVE
#define __SWERVE

#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

#include "Matrix.h"

using namespace std;

class Swerve{
    public:
        float x = 0;
        float y = 5;
        float theta = 0;
        float v_x;
        float v_y;
        float omega;
        float r_1x = 0.26363;
        float r_1y = 0.26363;
        float r_2x = 0.26363;
        float r_2y = 0.26363;
        float r_3x = 0.26363;
        float r_3y = 0.26363;
        float r_4x = 0.26363;
        float r_4y = 0.26363;
        float v_1x;
        float v_1y;
        float v_2x;
        float v_2y;
        float v_3x;
        float v_3y;
        float v_4x;
        float v_4y;
        Matrix mat1 = Matrix({{1,0,-r_1y},
                                {0,1, r_1x},
                                {1,0,-r_2y},
                                {0,1, r_2x},
                                {1,0,-r_3y},
                                {0,1, r_3x},
                                {1,0,-r_4y},
                                {0,1, r_4x}});
        Matrix mat2 = Matrix({{v_x},{v_y},{this->omega}});
        Matrix position = Matrix({{x},{y},{theta}});
        Matrix velocity = Matrix({{v_1x},
                                    {v_1y},
                                    {v_2x},
                                    {v_2y},
                                    {v_3x},
                                    {v_3y},
                                    {v_4x},
                                    {v_4y},});
        
    public:
        void velocityCommand(float, float, float);
        void updatePose(float);
        void set_v_x(float);
        void set_v_y(float);
        void set_omega(float);
};

#endif