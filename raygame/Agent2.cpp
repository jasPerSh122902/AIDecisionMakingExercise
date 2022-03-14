#include "Agent2.h"
#include "SpriteComponent.h"
#include "Agent2SeekComponent.h"
#include "GameManager.h"
#include "Goal.h"
#include "Transform2D.h"
#include "Bullet.h"
#include "Engine.h"
#include "Agent2StateMachineComponent.h"

Agent2::Agent2(float x, float y, const char* name, float maxForce, float maxSpeed, float health) : Character(x, y, name, maxForce, maxSpeed, health)
{
	
	addComponent(new SpriteComponent("Images/enemy.png"));
}

void Agent2::onCollision(Actor* actor)
{
	if (actor->getName() == "Agent1")
		takeDamage();
	
	Character::onCollision(actor);
}

void Agent2::start()
{
	Character::start();
	//add steering behaviours here
	m_stateMachineComponent = addComponent<Agent2StateMachineComponent>();

	m_agent2SeekComponet = addComponent<Agent2SeekComponent>();
	//This is agents 2 seeking (its the movement)----------------
	m_agent2SeekComponet->setSteeringForce(100);
	m_agent2SeekComponet->setTarget(m_gameManager->getBall());
	//-----------------------------------------------------------

}

void Agent2::update(float deltaTime)
{
	Bullet* bullet = new Bullet(this->getTransform()->getWorldPosition().x, this->getTransform()->getWorldPosition().y ,"Bullet", 200, 200, 1,this);
	Character::update(deltaTime);
}

void Agent2::onDeath()
{
	Character::onDeath();

}