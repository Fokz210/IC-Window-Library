#pragma once

#include "shape_window.h"

class rectangle_shape_window :
	public sf::RectangleShape,
	public abstract_window
{
public:
	rectangle_shape_window () = default;
	explicit rectangle_shape_window (sf::RectangleShape shape);
	sf::Vector2f getPoint(std::size_t index) const override;
	std::size_t getPointCount() const override;

	bool on_mb_up(const sf::Event::MouseButtonEvent& event) override {return false;}
	bool on_mb_down(const sf::Event::MouseButtonEvent& event) override {return false;}
	bool on_mouse_move (const sf::Event::MouseMoveEvent & event) override { return false; }

	bool contains(const sf::Vector2f& point) noexcept override {return getLocalBounds().contains(getTransform().transformPoint(point));}
	bool contains(float x, float y) noexcept override {return contains(sf::Vector2f(x, y));}
};

inline sf::Vector2f rectangle_shape_window::getPoint(std::size_t index) const
{
	return sf::RectangleShape::getPoint(index);
}

inline std::size_t rectangle_shape_window::getPointCount() const
{
	return sf::RectangleShape::getPointCount();
}
