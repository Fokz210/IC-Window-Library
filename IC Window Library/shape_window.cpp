#include "shape_window.h"

bool shape_window::on_mb_down(const sf::Event::MouseButtonEvent& event)
{
	return false;
}

bool shape_window::on_mb_up(const sf::Event::MouseButtonEvent& event)
{
	return false;
}

bool shape_window::on_mouse_move(const sf::Event::MouseMoveEvent& event)
{
	return false;
}

bool shape_window::contains(const sf::Vector2f& point) noexcept
{
	return getGlobalBounds().contains(point);
}

bool shape_window::contains(const float x, const float y) noexcept
{
	return getGlobalBounds().contains(x, y);
}
