#include "ShieldML.h"
#include "SpriteComponent.h"
#include "Goal.h"
#include "Character.h"
#include "GameManager.h"
#include "Transform2D.h"
#include "SeekMLComponent.h"
#include "Agent2.h"
#include <string.h>

ShieldML::ShieldML(float x, float y, const char* name, float maxForce, float maxSpeed, float health, Actor* target) : Character(x, y, name, maxForce, maxSpeed, health)
{
	m_target = target;
	addComponent(new SpriteComponent("Images/ball.png"));
}

void ShieldML::onCollision(Actor* actor)
{
	if (strcmp(actor->getName(), "Ball") == 0 || strcmp(actor->getName(), "Agent1") == 0 || strcmp(actor->getName(), "Agent2") == 0 || strcmp(actor->getName(), "Goal") == 0 || strcmp(actor->getName(), "Agent1Bullet") == 0)
	{

	}
	else 
	{
		takeDamage();
	}
}

void ShieldML::start()
{
	Character::start();

	m_seekComponent = new SeekMLComponent();
	m_seekComponent->setSteeringForce(100);
	m_seekComponent->setTarget(m_target);
	addComponent(m_seekComponent);
}

void ShieldML::update(float deltaTime)
{
	Character::update(deltaTime);
}

void ShieldML::onDeath()
{
	Character::onDeath();

}