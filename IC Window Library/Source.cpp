#include <iostream>

#include "rect_window.h"
#include "button.h"

class test_button :
	public rect_window
{
public:
	explicit test_button (sf::RectangleShape shape);

	bool on_mb_up(const sf::Event::MouseButtonEvent& event) override;
};

test_button::test_button(sf::RectangleShape shape) :
	rect_window(std::move(shape))
{
}

bool test_button::on_mb_up(const sf::Event::MouseButtonEvent& event)
{
	std::cout << "Test!\n";

	return true;
}

int main ()
{
	sf::RenderWindow window (sf::VideoMode (800, 600), "Window Library");

	sf::Event event{};

	sf::RectangleShape shape;

	auto func = [] {std::cout << "UP!\n"; };

	auto button = button_factory(func);

	button.setSize(sf::Vector2f(150, 100));
	button.setPosition(200, 200);
	button.setFillColor(sf::Color::Red);
	button.setRotation (30);

	while (window.isOpen ())
	{
		while (window.pollEvent ((event)))
		{
			if (event.type == sf::Event::Closed)
				window.close ();

			if (event.type == sf::Event::MouseMoved && button.contains (static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y)))
				button.on_mouse_move (event.mouseMove);

			if (event.type == sf::Event::MouseButtonReleased && button.contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
				button.on_mb_up(event.mouseButton);
		}

		window.draw (button);
		window.display();
	}
	
	return EXIT_SUCCESS;
}
