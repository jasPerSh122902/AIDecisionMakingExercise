#include "Agent2StateMachineComponent.h"
#include "Agent2SeekComponent.h"
#include "Agent.h"
#include "Goal.h"
#include "GameManager.h"
#include "Character.h"

void Agent2StateMachineComponent::start()
{
	Component::start();
	m_seekComponet = getOwner()->getComponent<Agent2SeekComponent>();
	m_seekForce = m_seekComponet->getSteeringForce();

	m_currentState = SEEKING;
}

void Agent2StateMachineComponent::update(float deltaTime)
{
	GameManager* m_gameManager = GameManager::getInstance();

	switch (m_currentState)
	{
	case SEEKING:

		if(m_gameManager->getAgent2()->getHasBall() == false)
		{
			m_seekComponet->setSteeringForce(m_seekForce);
			m_seekComponet->setTarget(m_gameManager->getBall());
			m_currentState = ATTACKING;
		}
		else if (m_gameManager->getAgent2()->getHasBall() == true)
			m_currentState = GOALING;
	case GOALING:
		if (m_gameManager->getAgent2()->getHasBall() == true)
		{
			m_seekComponet->setSteeringForce(m_seekForce);
			m_seekComponet->setTarget((Actor*)m_gameManager->getLeftGoal());
		}
	case ATTACKING:
		if (m_gameManager->getAgent1()->getHealth() != 0)
			m_seekComponet->setTarget(m_gameManager->getAgent1());
		
		else 
			m_currentState = SEEKING;
		
		
	case DEFENDING:
		break;
	}
}
