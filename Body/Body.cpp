#include "Body.h"
#include "../Integrator.h"
#include "../World/World.h"
#include "../Shapes/Shape.h"

void Body::ApplyForce(const glm::vec2& force)
{
	this->force += force;
}

void Body::Step(float dt)
{	
	if (type != DYNAMIC) return;

	//gravity
	ApplyForce(World::gravity * gravityScale * mass);

	Integrator::ExplicitEuler(*this, dt);
	ClearForce();

	//damping
	velocity *= (1.0f / (1.0f + dt * damping));
}

void Body::Draw(Graphics* graphics)
{
	shape->Draw(graphics, position);
}
