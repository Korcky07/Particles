#include "Engine.h"


Engine::Engine()
{
	int pixelWidth = VideoMode::getDesktopMode().width;
	int pixelHeight = VideoMode::getDesktopMode().height;

	VideoMode vm(pixelWidth, pixelHeight);

	m_Window.create(vm, "Mandelbrot", Style::Default);
}


void Engine::run()
{
	Clock clock;
	Time time;

	cout << "Starting Particle unit tests..." << endl;
	Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
	p.unitTests();
	cout << "Unit tests complete.  Starting engine..." << endl;

	while (m_Window.isOpen())
	{
		time = clock.restart();
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

					Particle particle(m_Window, numPoints, Vector2i (event.mouseButton.x, event.mouseButton.y));
					m_particles.push_back(particle);

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
	for (auto it = m_particles.begin(); it != m_particles.end();) 
	{
		if (it->getTTL() > 0.0) 
		{
			it->update(dtAsSeconds);
			++it; 
		}
		else 
		{
			it = m_particles.erase(it); 
		}
	}
}


void Engine::draw()
{
	m_Window.clear();
	//cout << "engine draw outside";
	for (size_t i = 0; i < m_particles.size(); i++)
	{
		m_Window.draw(m_particles[i]);
	}
	m_Window.display();
}
