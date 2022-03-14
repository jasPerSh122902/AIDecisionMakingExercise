#pragma once
#include "SteeringComponent.h"
#include <Vector2.h>
class Agent2SeekComponent :
	public SteeringComponent
{
public:
	MathLibrary::Vector2 calculateForce() override;
};

