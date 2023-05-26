#include "ForceTest.h"
#include "../Engine/Body/Body.h"
#include "../Physics/Gravity/GravForce.h"
#include "../Physics/Force/PointForce.h"
#include "../Physics/Force/AreaForce.h"
#include "../Physics/Force/DragForce.h"

//#define POINT_FORCE
//#define AREA_FORCE
#define DRAG_FORCE

void ForceTest::Initialize()
{
	Test::Initialize();

	m_user = new Body(new CircleShape(1, { 1, 1, 1, 1 }), { 0, 0 }, { 0, 0 }, 1, Body::KINEMATIC);
	m_world->AddBody(m_user);

#if defined(POINT_FORCE)
	auto body = new Body(new CircleShape(200, { 1, 1, 1, 0.2f }), { 400, 300 }, { 0, 0 }, 0, Body::STATIC);
	ForceGenerator* forceGenerator = new PointForce(body, 2000);
	m_world->AddForceGenerator(forceGenerator);
#elif defined(AREA_FORCE)
	auto body = new Body(new CircleShape(200, { 1, 1, 1, 0.2f }), { 400, 300 }, { 0, 0 }, 0, Body::STATIC);
	ForceGenerator* forceGenerator = new AreaForce(body, 2000, -90);
	m_world->AddForceGenerator(forceGenerator);
#elif defined(DRAG_FORCE)
	auto body = new Body(new CircleShape(200, { 1, 1, 1, 0.2f }), { 400, 300 }, { 0, 0 }, 0, Body::STATIC);
	ForceGenerator* forceGenerator = new DragForce(body, 0.5f);
	m_world->AddForceGenerator(forceGenerator);
#endif
}

void ForceTest::Update()
{
	Test::Update();

	glm::vec2 position = m_graphics->ScreenToWorld(m_input->GetMousePosition());
	m_user->velocity = position - m_user->position;
	m_user->position = position;

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity = { 0,0 };// randomUnitCircle() * randomf(100, 200);
		float size = randomf(0.1f, 0.2f);

		auto body = new Body( new CircleShape((size * 2), { randomf(), randomf(), randomf(), 1 }), position, velocity, size);
		body->damping = 0;
		body->gravityScale = 0.5f;
		body->restitution = 1;

		m_world->AddBody(body);
	}
}

void ForceTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void ForceTest::Render()
{
	m_world->Draw(m_graphics);
}
