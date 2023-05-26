#include "ParticleTest.h"
#include "../Engine/Body/Body.h"

void ParticleTest::Initialize()
{
	Test::Initialize();

	m_user = new Body(new CircleShape(1, { 1, 0, 0, 1 }), { 0, 0 }, { 0, 0 }, 1, Body::KINEMATIC);
	m_world->AddBody(m_user);

	glm::vec2 extents = m_graphics->GetWorldExtents();

	auto body = new Body(new CircleShape(200, glm::vec4{ 1.0f }), { 0, -(200 + extents.y) }, { 0, 0 }, 1, Body::STATIC);
	body->restitution = 0;
	m_world->AddBody(body);

	body = new Body(new CircleShape(200, glm::vec4{ 1.0f }), { 200 + extents.x, 0.0 }, { 0, 0 }, 1, Body::STATIC);
	body->restitution = 0;
	m_world->AddBody(body);

	body = new Body(new CircleShape(200, glm::vec4{ 1.0f }), { -(200 + extents.x), 0.0 }, { 0, 0 }, 1, Body::STATIC);
	body->restitution = 0;
	m_world->AddBody(body);
}

void ParticleTest::Update()
{
	Test::Update();

	glm::vec2 position = m_graphics->ScreenToWorld(m_input->GetMousePosition());
	m_user->velocity = position - m_user->position;
	m_user->position = position;

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity = { 0,0 };//randomUnitCircle() * randomf(100, 200);
		float size = randomf(0.1f, 0.2f);

		auto body = new Body(new CircleShape(size, { randomf(), randomf(), randomf(), 1 }), position, velocity);
		body->damping = 0;
		body->gravityScale = 0.5f;
		body->restitution = 1;

		m_world->AddBody(body);
	}
}

void ParticleTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void ParticleTest::Render()
{
	m_world->Draw(m_graphics);
	//m_graphics->DrawCircle(m_input->GetMousePosition(), 30, { randomf(), randomf(), randomf(), 1 });
}
