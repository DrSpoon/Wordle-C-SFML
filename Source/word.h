#pragma once
#ifndef WORD_H
#define WORD_H
#include "box.h"
#include <vector>
#include <string>

namespace dr
{
	class Word
	{
	public:
		Word();
		~Word();

		void setup(int size, float x, float y);
		void update(sf::RenderWindow& window, sf::Event& event1,
					std::string& str, dr::Levels& level, dr::Bool& b);
		void draw(sf::RenderWindow& window);
		void set_pos(float x, float y);
		/*void get_inout(sf::Event& event1, dr::Bool& b);*/
	private:
		std::vector<dr::Box> _elem;

		int _size;
	};
};


#endif // !WORD_H

