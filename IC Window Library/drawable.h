#pragma once
#include <SFML/Graphics.hpp>

class drawable
{
public:
	drawable () = default;
	drawable (const drawable & other) = default;
	drawable (drawable && other) noexcept = default;

	drawable & operator = (const drawable & other) = default;
	drawable & operator = (drawable && other) noexcept = default;
	
	virtual ~drawable() = default;

	virtual void render (sf::RenderTarget & target) = 0;
	explicit virtual operator sf::Drawable & () = 0;
	explicit virtual operator const sf::Drawable & () = 0;
};

