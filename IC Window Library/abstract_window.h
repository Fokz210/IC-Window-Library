#pragma once
#include <SFML/Graphics.hpp>

class abstract_window
{
public:
	abstract_window () = default;
	abstract_window (const abstract_window & other) = default;
	abstract_window (abstract_window && other) = default;

	abstract_window & operator = (const abstract_window & right) = default;
	abstract_window & operator = (abstract_window && right) = default;
	
	virtual ~abstract_window() = default;

	virtual bool contains (const sf::Vector2f & point) noexcept = 0;
	virtual bool contains (float x, float y) noexcept = 0;

	virtual bool on_mouse_move (const sf::Event::MouseMoveEvent & event) = 0;
	virtual bool on_mb_down (const sf::Event::MouseButtonEvent & event) = 0;
	virtual bool on_mb_up (const sf::Event::MouseButtonEvent & event) = 0;

protected:
	unsigned long long id_{static_cast<unsigned long long>(rand()) * static_cast<unsigned long long>(rand ())};
};

