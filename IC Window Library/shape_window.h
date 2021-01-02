#pragma once

#include "abstract_window.h"

class shape_window :
	public sf::Shape,
	public abstract_window
{
public:
	shape_window() = default;

	bool on_mb_down(const sf::Event::MouseButtonEvent& event) override;
	bool on_mb_up(const sf::Event::MouseButtonEvent& event) override;
	bool on_mouse_move(const sf::Event::MouseMoveEvent& event) override;

	bool contains(const sf::Vector2f& point) noexcept override;
	bool contains(float x, float y) noexcept override;
};