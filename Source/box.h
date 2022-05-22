#pragma once
#ifndef BOX_H_INCLUDED
#define BOX_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>
#include "booleans.h"
#include <string>


namespace dr
{
	class Box
	{
	public:
		Box();
		~Box();
		sf::Vector2f get_size();

		void set_Pos(float x, float y);
		sf::Vector2f get_pos(void);

		void setup(short index);

		void update(sf::RenderWindow& window,
					sf::Event& event1,
					std::string& str,
					dr::Levels& level,
					dr::Bool& b);

		void draw(sf::RenderWindow& window);

		void get_input(sf::Event& event1, dr::Bool& b,std::string &str);

		void check_character(std::string &str);

		bool _is_input = false;
		bool _is_mouse_pressed = false;
		bool _is_mouse_released = false;
		bool _is_mouse_hovered = false;
		bool _is_mouse_idle = true;
		bool _is_inserted = false;
		bool _is_correct = false;
		bool _is_exists = false;
		bool _is_wrong = false;
		bool _is_update = true;

		short _index;

	private:
		sf::Text _text;
		sf::Font _font;
		sf::RectangleShape _box;
	};
};
#endif // BOX_H_INCLUDED
