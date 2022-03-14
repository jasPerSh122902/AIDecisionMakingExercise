#pragma once
#include "Character.h"
#include "SeekMLComponent.h"
class ShieldML :
	public Character
{
public:
    /// <param name="x">The x position of the character</param>
    /// <param name="y">The y position of the character</param>
    /// <param name="name">The name of the character</param>
    /// <param name="maxForce">The maximum amount of force that can be applied to this character</param>
    /// <param name="maxSpeed">How fast this actor can go</param>
    /// <param name="health">The amount of health this character has</param>
    ShieldML(float x, float y, const char* name, float maxForce, float maxSpeed, float damage, Actor* target);

    // Inherited from the Character class
    virtual void onCollision(Actor* actor) override;
    virtual void start() override;
    virtual void update(float deltaTime) override;
    virtual void onDeath();
private:
    Actor* m_target;
    SeekMLComponent* m_seekComponent;
};

