#include "code/Engine.h"

Engine::Engine()
{
	int pixelWidth = VideoMode::getDesktopMode().width;
	int pixelHeight = VideoMode::getDesktopMode().height;

	VideoMode vm(pixelWidth, pixelHeight);

	RenderWindow m_Window(vm, "Mandelbrot", Style::Default);
}


void Engine::run()
{
	Clock clock;
	Time time;
	Particle particle;

	cout << "Starting Particle unit tests..." << endl;
	Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
	p.unitTests();
	cout << "Unit tests complete.  Starting engine..." << endl;

	while (m_Window.isOpen())
	{
		clock.restart();

		time = clock.getElapsedTime();

		float dtAsSeconds = time.asSeconds();
		
		input();
		update(dtAsSeconds);
		draw();
	}

}

void Engine::input()
{
	Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) m_Window.close();
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				cout << "the left button was pressed" << std::endl;
				cout << "mouse x: " << event.mouseButton.x << std::endl;
				cout << "mouse y: " << event.mouseButton.y << std::endl;

				for (int i = 0; i < 5; i++)
				{
					int numPoints = rand() % (50 - 25 + 1);

					Particle(event.mouseButton);
				}
				
			}
			

		}

	}
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		m_Window.close();
	}

}

void Engine::update(float dtAsSeconds)
{

}


void Engine::draw()
{

}
