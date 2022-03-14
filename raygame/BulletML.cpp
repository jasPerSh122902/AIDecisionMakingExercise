#include "BulletML.h"
#include "SpriteComponent.h"
#include "Goal.h"
#include "Character.h"
#include "GameManager.h"
#include "Transform2D.h"
#include "SeekMLComponent.h"
#include "Agent2.h"

BulletML::BulletML(float x, float y, const char* name, float maxForce, float maxSpeed, float health, Actor* target) : Character(x, y, name, maxForce, maxSpeed, health)
{
	m_target = target;
	addComponent(new SpriteComponent("Images/bullet.png"));
}

void BulletML::onCollision(Actor* actor)
{
	Agent2* agent = dynamic_cast<Agent2*>(actor);
	if (agent != nullptr) 
	{
		agent->takeDamage();
		//agent->getComponent<Agent2SeekComponent>()->setSteeringForce(agent->getComponent<Agent2SeekComponent>()->getSteeringForce()/2);
		onDeath();
	}
}

void BulletML::start()
{
	Character::start();

	m_seekComponent = new SeekMLComponent();
	m_seekComponent->setSteeringForce(200);
	m_seekComponent->setTarget(m_target);
	addComponent(m_seekComponent);
}

void BulletML::update(float deltaTime)
{
	Character::update(deltaTime);
}

void BulletML::onDeath()
{
	Character::onDeath();

}