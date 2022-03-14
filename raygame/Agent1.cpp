#include "Agent1.h"
#include "SpriteComponent.h"
#include "Goal.h"
#include "GameManager.h"
#include "SeekMLComponent.h"

Agent1::Agent1(float x, float y, const char* name, float maxForce, float maxSpeed, float health, Actor* ball) : Character(x, y, name, maxForce, maxSpeed, health)
{
	m_ball = ball;
	addComponent(new SpriteComponent("Images/player.png"));
}

void Agent1::onCollision(Actor* actor)
{
	if (actor->getName() == "Agent2" || actor->getName() == "Bullet")
	{
		takeDamage();
	}
	Character::onCollision(actor);
}

void Agent1::start()
{
	Character::start();

	GameManager* manager = GameManager::getInstance();
	m_goal = manager->getRightGoal();

	m_seekComponent = new SeekMLComponent();
	m_seekComponent->setSteeringForce(10);
	m_seekComponent->setTarget(m_ball);
	addComponent(m_seekComponent);
}

void Agent1::update(float deltaTime)
{
	Character::update(deltaTime);

	if (getHasBall())
		m_seekComponent->setTarget(m_goal);
}

void Agent1::onDeath()
{
	Character::onDeath();

}
