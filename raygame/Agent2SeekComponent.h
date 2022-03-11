#pragma once
#include "Component.h"
#include <Vector2.h>
class Agent2SeekComponent :
	public Component
{
public:
	void calculateForce();
};

