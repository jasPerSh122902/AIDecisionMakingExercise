#pragma once
#include "Character.h"
#include "SeekMLComponent.h"

class Agent1 :
    public Character
{
public:
    /// <param name="x">The x position of the character</param>
    /// <param name="y">The y position of the character</param>
    /// <param name="name">The name of the character</param>
    /// <param name="maxForce">The maximum amount of force that can be applied to this character</param>
    /// <param name="maxSpeed">How fast this actor can go</param>
    /// <param name="health">The amount of health this character has</param>
    Agent1(float x, float y, const char* name, float maxForce, float maxSpeed, float health, Actor* ball);

    // Inherited from the Character class
    virtual void onCollision(Actor* actor) override;
    virtual void start() override;
    virtual void update(float deltaTime) override;
    virtual void onDeath();
    virtual void onDamageRecieved() {};
private:
    Actor* m_ball;
    Actor* m_goal;
    SeekMLComponent* m_seekComponent;
};

