#pragma once
#ifndef WORDLE_H
#define WORDLE_H
#include "word.h"

namespace dr 
{
	class Wordle
	{
	public:

		Wordle();
		~Wordle();

		void setup(int size, float x, float y);
		void update(sf::RenderWindow& window, sf::Event& event1,
					std::string& str, dr::Bool& b);
		void draw(sf::RenderWindow& window, dr::Bool& b);
		void set_pos(float x, float y);

	private:
		dr::Levels _level;
		std::vector<dr::Word> _elem;
		int _size;
		sf::Text* _txt;
		sf::Font _font;
	};
};

#endif // !WORDLE_H
