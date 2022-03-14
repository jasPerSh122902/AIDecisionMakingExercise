#pragma once
#include "Component.h"
enum State
{
	SEEKING,
	GOALING,
	ATTACKING,
	DEFENDING
};

class Agent2SeekComponent;
class Character;

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
	Character* m_character;
	Agent2SeekComponent* m_seekComponet;
	float m_seekForce;
};

