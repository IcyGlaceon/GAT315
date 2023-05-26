#pragma once
#include "../../Physics/Force/ForceGenerator.h"
#include "../../Engine/Body/Body.h"

class DragForce : public ForceGenerator
{
public:
	DragForce(Body* body, float drag) :
		ForceGenerator{ body },
		m_drag{ drag }
	{}
	void Apply(std::vector<class Body*> bodies) override;
private:
	float m_drag{ 0 };
};