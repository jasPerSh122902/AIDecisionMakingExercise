#pragma once
#include "Character.h"
#include "Agent2SeekComponent.h"
class Bullet;
class Actor;
class Agent2StateMachineComponent;

class Agent2 :
    public Character
{
public:
    /// <param name="x">The x position of the character</param>
    /// <param name="y">The y position of the character</param>
    /// <param name="name">The name of the character</param>
    /// <param name="maxForce">The maximum amount of force that can be applied to this character</param>
    /// <param name="maxSpeed">How fast this actor can go</param>
    /// <param name="health">The amount of health this character has</param>
    Agent2(float x, float y, const char* name, float maxForce, float maxSpeed, float health);

    // Inherited from the Character class
    virtual void onCollision(Actor* actor) override;
    virtual void start() override;
    virtual void update(float deltaTime) override;
    virtual void onDeath();
    virtual void onDamageRecieved() {};

private:
    Bullet* m_bullet;
    Actor* m_goal;
    Agent2SeekComponent* m_agent2SeekComponet;
    GameManager* m_gameManager = GameManager::getInstance();
    Agent2StateMachineComponent* m_stateMachineComponent;
    Actor* m_actor;
};


