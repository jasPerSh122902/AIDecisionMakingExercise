#include "Bullet.h"
#include "GameManager.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "CircleCollider.h"


Bullet::Bullet(float x, float y, const char* name, float maxForce, float maxSpeed, float health, Actor* owner) : Character(x, y, name, maxForce, maxSpeed, health)
{
	owner = GameManager::getInstance()->getAgent2();
	addComponent(new SpriteComponent("Images/bullet.png"));
}

void Bullet::onCollision(Actor* actor)
{
	if (actor->getName() == "Agent1") 
		delete this;
	
}

void Bullet::start()
{

	Character::start();
	m_moveComponet = addComponent<MoveComponent>();
	this->getTransform()->setScale({ 100,100 });
	this->setCollider(new CircleCollider(7, this));
}

void Bullet::update(float deltaTime)
{
	Character::update(deltaTime);
}
