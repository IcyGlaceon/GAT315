#pragma once
#include "Physics/ForceGenerator.h"

class GravGen : public ForceGenerator
{
public:
	GravGen(float strength) : m_strength{ strength } {}

	void Apply(std::list<class Body*> bodies) override;

private:
	float m_strength{ 0 };
};