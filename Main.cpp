#include "Tests/CollisionTest.h"
#include "Tests/ForceTest.h"
#include "Tests/JointTest.h"
#include "Tests/ParticleTest.h"

//#define Collision
//#define Force
#define Joint
//#define Particle

int main(int argc, char* argv[]) 
{
#if defined(Collision)
	Test* test = new CollisionTest();
#elif defined(Force)
	Test* test = new ForceTest();
#elif defined(Joint)
	Test* test = new JointTest();
#elif defined(Particle)
	Test* test = new ParticleTest();
#endif
	test->Initialize();

	while (!test->IsQuit()) 
	{ test->Run(); }
	delete test;

	return 0;
}