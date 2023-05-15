#pragma once
#include "Physics/ForceGenerator.h"

class GravForce : public ForceGenerator
{
public:
	GravForce(float strength) : m_strength{ strength } {}

	void Apply(std::vector<class Body*> bodies) override;

private:
	float m_strength{ 0 };
};