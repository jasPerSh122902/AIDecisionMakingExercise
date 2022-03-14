#pragma once
#include "Character.h"
#include "Scene.h"
#include "MoveComponent.h"
class Bullet :
	public Character
{
public:
	Bullet(float x, float y, const char* name, float maxForce, float maxSpeed, float health, Actor* owner);

    // Inherited from the Character class
    void onCollision(Actor* actor) override;
    void start() override;
    void update(float deltaTime) override;
private:
    Scene* m_scene;
    MoveComponent* m_moveComponet;
    float time = 0;
};

