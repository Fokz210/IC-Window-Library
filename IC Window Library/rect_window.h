#pragma once

#include "abstract_window.h"
#include "drawable.h"

class rect_window :
	public abstract_window,
	public drawable
{
public:
	rect_window () = default;
	rect_window (const rect_window & other) = default;
	rect_window (rect_window && other) = default;

	rect_window & operator = (const rect_window & right) = default;
	rect_window & operator = (rect_window && other) = default;
	
	explicit rect_window (sf::RectangleShape shape);
	rect_window (sf::FloatRect rect, sf::Color fill_color, sf::Color color = sf::Color::Transparent);
	rect_window (float x, float y, float width, float height, sf::Color fill_color, sf::Color color = sf::Color::Transparent);

	~rect_window() override = default;

	explicit operator sf::Drawable & () override;
	explicit operator const sf::Drawable & () override;
	
	void render (sf::RenderTarget & target) override;

	bool on_mouse_move(const sf::Event::MouseMoveEvent& event) override;
	bool on_mb_down(const sf::Event::MouseButtonEvent& event) override;
	bool on_mb_up(const sf::Event::MouseButtonEvent& event) override;
	
	bool contains(const sf::Vector2f & point) noexcept override;
	bool contains(float x, float y) noexcept override;
	
protected:
	sf::RectangleShape shape_;
};

inline rect_window::rect_window (sf::RectangleShape shape) :
	shape_{std::move(shape)}
{
	
}

inline rect_window::rect_window (const sf::FloatRect rect, const sf::Color fill_color, const sf::Color color) 
{
	shape_.setSize (sf::Vector2f(rect.width, rect.height));
	shape_.setPosition (rect.left, rect.top);
	shape_.setFillColor (fill_color);
	shape_.setOutlineColor (color);
}

inline rect_window::rect_window (const float x, const float y, const float width, const float height, const sf::Color fill_color, const sf::Color color)
{
	shape_.setSize (sf::Vector2f (width, height));
	shape_.setPosition (x, y);
	shape_.setFillColor (fill_color);
	shape_.setOutlineColor (color);
}

inline rect_window::operator sf::Drawable & ()
{
	return shape_;
}

inline rect_window::operator const sf::Drawable & () 
{
	return shape_;
}

inline void rect_window::render (sf::RenderTarget& target)
{
	target.draw (shape_);
}

inline bool rect_window::on_mouse_move (const sf::Event::MouseMoveEvent& event)
{
	return false;
}

inline bool rect_window::on_mb_down (const sf::Event::MouseButtonEvent& event)
{
	return false;
}

inline bool rect_window::on_mb_up (const sf::Event::MouseButtonEvent& event)
{
	return false;
}

inline bool rect_window::contains (const sf::Vector2f & point) noexcept
{
	return shape_.getGlobalBounds ().contains (point);
}

inline bool rect_window::contains (const float x, const float y) noexcept
{ 
	return shape_.getGlobalBounds ().contains (x, y);
}



