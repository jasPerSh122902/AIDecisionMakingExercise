#include "Agent2SeekComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include "Agent.h"
#include "MoveComponent.h"

MathLibrary::Vector2 Agent2SeekComponent::calculateForce()
{
	if (!getTarget())
		return{ 0,0 };

	MathLibrary::Vector2 directionToTarget = ( getTarget()->getTransform()->getWorldPosition()
											  - getOwner()->getTransform()->getWorldPosition());
	MathLibrary::Vector2 desiredVelocity = directionToTarget.normalize() * getSteeringForce();

	MathLibrary::Vector2 seekForce = desiredVelocity - getAgent()->getMoveComponent()->getVelocity();

	return seekForce;
}
