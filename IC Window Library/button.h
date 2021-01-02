#pragma once
#include "rectangle_shape_window.h"

template <class LambdaT>
class button final :
    public rectangle_shape_window
{
public:
	explicit button (LambdaT & on_click);

	bool on_mb_up(const sf::Event::MouseButtonEvent& event) override;

protected:
	LambdaT & on_click_;
};

template <class LambdaT>
button<LambdaT>::button(LambdaT& on_click) :
	rectangle_shape_window(),
	on_click_(on_click)
{
	
}

template <class LambdaT>
bool button<LambdaT>::on_mb_up(const sf::Event::MouseButtonEvent& event)
{
	on_click_();
	return true;
}

template <class LambdaT>
button<LambdaT> button_factory (LambdaT & on_click)
{
	return button<LambdaT>(on_click);
}

