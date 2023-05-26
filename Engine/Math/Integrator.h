#pragma once
#include "../Body/Body.h"

namespace Integrator
{
	void ExplicitEuler(Body& body, float dt);
	void SemiImplicitEuler(Body& body, float dt);
}
