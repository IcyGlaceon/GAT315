#include "GravGen.h"
#include "Body/Body.h"

void GravGen::Apply(std::list<class Body*> bodies)
{
	for (auto body : bodies) 
	{
		body->ApplyForce({ 0, -m_strength });
	}
}
