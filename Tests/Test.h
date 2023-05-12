#pragma once
#include "../Graphics/Graphics.h"
#include "../Input/Input.h"
#include "../Math/Time.h"
#include "../Math/Random.h"
#include "../World/World.h"
#include "../Shapes/CircleShape.h"

class Test
{
public:
	Test();
	~Test();

	virtual void Initialize();
	virtual void Run();


	virtual void Update();
	virtual void FixedUpdate() = 0;

	virtual void PreRender();
	virtual void Render() = 0;
	virtual void PostRender();

	bool IsQuit() { return m_quit; }

protected:
	void UpdateEvents();

protected:
	bool m_quit{ false };
	float m_fixedTime{ 0 };


	Graphics* m_graphics{ nullptr };
	Input* m_input{ nullptr };
	Time* m_time{ nullptr };
	World* m_world{ nullptr };
};
