#pragma once
#include "Component.h"
#include "Agent2SeekComponent.h"

enum State
{
	SEEKING,
	GOALING
};
class Agent2StateMachineComponent :
	public Component
{
public:
	void start() override;
	void update(float deltaTime) override;
	State getCurrentState() { return m_currentState; }
	void setCurretnState(State currentState) { m_currentState = currentState; }
private:
	State m_currentState;
	Agent2SeekComponent* m_seekComponet;
	float m_seekRange = 150;
	float m_seekForce;
};

