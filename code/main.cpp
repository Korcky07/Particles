#include "Engine.h"
#include "Matrices.h"
#include "Particle.h"

#include <iostream>
using namespace Matrices;

int main()
{
	RenderWindow window(VideoMode(1920, 1080), "window");
	// Declare an instance of Engine
	//Engine engine;
	// Start the engine
	//engine.run();
	Particle particle(window, 20, Vector2i(960, 540));
	Particle particle2(window, 30, Vector2i(700, 327));
	Particle particle3(window, 45, Vector2i(1020, 567));
	window.draw(particle);
	//window.draw(particle2);
	//window.draw(particle3);
	window.display();
	particle.unitTests();
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