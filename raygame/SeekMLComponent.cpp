#include "SeekMLComponent.h"
#include "Actor.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Agent.h"

MathLibrary::Vector2 SeekMLComponent::calculateForce() 
{
	if (!getTarget())
		return { 0, 0 };

	MathLibrary::Vector2 directionToTarget = (getTarget()->getTransform()->getWorldPosition()
		- getOwner()->getTransform()->getWorldPosition());
	MathLibrary::Vector2 desriedVelocity = directionToTarget.normalize() * getSteeringForce();

	MathLibrary::Vector2 seekForce = desriedVelocity - getAgent()->getMoveComponent()->getVelocity();

	return seekForce;
}