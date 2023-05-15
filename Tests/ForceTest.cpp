#include "ForceTest.h"
#include "../Body/Body.h"
#include "../GravForce.h"

void ForceTest::Initialize()
{
	Test::Initialize();

	auto forceGenerator = new GravForce(400);
	m_world->AddForceGenerator(forceGenerator);
}

void ForceTest::Update()
{
	Test::Update();

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity = randomUnitCircle() * randomf(100, 200);

		float size = randomf(1, 8);
		auto body = new Body( new CircleShape((size * 2), { randomf(), randomf(), randomf(), 1 }), m_input->GetMousePosition(), velocity, size);
		body->damping = 1;
		//body->gravityScale = 30;

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
	m_graphics->DrawCircle(m_input->GetMousePosition(), 30, { randomf(), randomf(), randomf(), 1 });
}
