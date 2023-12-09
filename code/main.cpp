#include "Engine.h"
#include "Matrices.h"
#include "Particle.h"

#include <iostream>
using namespace Matrices;

int main()
{

	// Declare an instance of Engine
	Engine engine;
	// Start the engine
	engine.run();
	cin.get();
	

	// Quit in the usual way when the engine is stopped
	return 0;
}


/*int main() //Matrix Unit Test
{
	RenderWindow window;
	Matrices::RotationMatrix rm(90);
	Matrices::TranslationMatrix tm(2, 2, 4);
	Matrices::ScalingMatrix sm(4);
	Matrix a(2, 2);
	Matrix b(2, 2);
	a(0, 0) = 3;
	a(0, 1) = 2;
	a(1, 0) = 3;
	a(1, 1) = 2;
	b = a * sm;
	std::cout << a;
	std::cout << rm;
	std::cout << b;
	cin.get();
	Particle particle(window, 5, Vector2i(7, 5));
	particle.unitTests();
	cin.get();
	return 0;
}*/