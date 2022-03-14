#include "Agent2.h"
#include "SpriteComponent.h"
#include "Agent2SeekComponent.h"
#include "GameManager.h"
#include "Goal.h"

Agent2::Agent2(float x, float y, const char* name, float maxForce, float maxSpeed, float health, Actor* ball) : Character(x, y, name, maxForce, maxSpeed, health)
{
	m_ball = ball;
	addComponent(new SpriteComponent("Images/enemy.png"));
}

void Agent2::onCollision(Actor* actor)
{
	Character::onCollision(actor);
}

void Agent2::start()
{
	Character::start();
	//add steering behaviours here
	GameManager* m_gameManager = GameManager::getInstance();

	m_goal = m_gameManager->getLeftGoal();

	m_agent2SeekComponet = addComponent<Agent2SeekComponent>();
	//This is agents 2 seeking (its the movement)----------------
	m_agent2SeekComponet->setSteeringForce(100);
	m_agent2SeekComponet->setTarget(m_ball);
	//-----------------------------------------------------------
}

void Agent2::update(float deltaTime)
{
	Character::update(deltaTime);
	if (getHasBall())
		m_agent2SeekComponet->setTarget(m_goal);

	
}

void Agent2::onDeath()
{
	Character::onDeath();

}