#include "ForceGenerator.h"
#include "../../Engine/Body/Body.h"

void ForceGenerator::Draw(Graphics* graphics)
{
	if (m_body) m_body->Draw(graphics);
}
