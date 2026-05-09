#pragma once

class ParticuleNeige;
class ParticuleRoche;
class Obstacle;

class Agent {
public:
    virtual void opere_sur(ParticuleNeige& p) = 0;
    virtual void opere_sur(ParticuleRoche& p) = 0;
    virtual void opere_sur(Obstacle& o) = 0; 
    virtual ~Agent() = default;
};
