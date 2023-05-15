#include "World.h"
#include "../Body/Body.h"
#include "../Physics/ForceGenerator.h"

glm::vec2 World::gravity{ 0, 9.8f };

World::~World()
{
	for (auto body : m_bodies) 
	{
		delete body;
	}
		m_bodies.clear();
}

void World::Step(float dt)
{
	if (!m_bodies.empty() && !m_forceGenerators.empty()) 
	{
		std::vector<Body*> bodies(m_bodies.begin(),m_bodies.end());

		for (auto forceGenerator : m_forceGenerators)
		{
			forceGenerator->Apply(bodies);
		}
	}

	for (auto body : m_bodies)
	{
		body->Step(dt);
	}
}

void World::Draw(Graphics* graphics)
{
	for (auto body : m_bodies)
	{
		body->Draw(graphics);
	}
}

void World::AddBody(Body* body)
{
	m_bodies.push_back(body);
}

void World::RemoveBody(Body* body)
{
}

void World::AddForceGenerator(ForceGenerator* forceGenerator)
{
	m_forceGenerators.push_back(forceGenerator);
}
