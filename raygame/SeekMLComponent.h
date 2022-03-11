#pragma once
#include "SteeringComponent.h"
class SeekMLComponent :
	public SteeringComponent
{
public:
	MathLibrary::Vector2 calculateForce() override;
};

