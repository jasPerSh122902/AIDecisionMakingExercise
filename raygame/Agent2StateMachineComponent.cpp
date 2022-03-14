#include "Agent2StateMachineComponent.h"
#include "Agent.h"

void Agent2StateMachineComponent::start()
{
	Component::start();
	m_seekComponet = getOwner()->getComponent<Agent2SeekComponent>();
	m_seekForce = m_seekComponet->getSteeringForce();

	m_currentState = SEEKING;
}

void Agent2StateMachineComponent::update(float deltaTime)
{
	switch (m_currentState)
	{
	default:
		break;
	}
}
