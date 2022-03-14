#include "Agent1.h"
#include "SpriteComponent.h"
#include "Goal.h"
#include "Transform2D.h"
#include "GameManager.h"
#include "SeekMLComponent.h"
#include "BulletML.h"
#include "ShieldML.h"
#include "Engine.h"
#include "Scene.h"

Agent1::Agent1(float x, float y, const char* name, float maxForce, float maxSpeed, float health, Actor* ball) : Character(x, y, name, maxForce, maxSpeed, health)
{
	m_ball = ball;
	addComponent(new SpriteComponent("Images/player.png"));
}

void Agent1::onCollision(Actor* actor)
{
	Character::onCollision(actor);
}

void Agent1::start()
{
	Character::start();

	//Get the manager to get the goal to target
	m_manager = GameManager::getInstance();
	m_goal = m_manager->getRightGoal();
	m_timer = 10000;
	m_seekComponent = new SeekMLComponent();
	m_seekComponent->setSteeringForce(100);
	m_seekComponent->setTarget(m_ball);
	addComponent(m_seekComponent);

	ShieldML* shield = new ShieldML(getTransform()->getWorldPosition().x, getTransform()->getWorldPosition().y, "Agent1Shield", 50, 50, 3, this);
	shield->getTransform()->setScale({ 200, 200 });
	Engine::getCurrentScene()->addActor(shield);
}

void Agent1::update(float deltaTime)
{
	m_timer++;
	Character::update(deltaTime);
	if (getHasBall())
		m_seekComponent->setTarget(m_goal);
	else
		m_seekComponent->setTarget(m_ball);
	if (m_timer >= 10000) 
	{
		m_timer = 0;
		BulletML* bullet = new BulletML(getTransform()->getWorldPosition().x, getTransform()->getWorldPosition().y, "Agent1Bullet", 100, 100, 1, m_manager->getAgent2());
		Engine::getCurrentScene()->addActor(bullet);
		
	}
}

void Agent1::onDeath()
{
	Character::onDeath();

}
