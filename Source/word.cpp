#include "word.h"


dr::Word::Word()
	:
	_size{ 0 }
{

}

dr::Word::~Word()
{

}

void dr::Word::setup(int size, float x, float y)
{
	_size = size;
	_elem.resize(_size);
	for (size_t i = 0; i < _size; i++)
	{
		_elem[i].setup(i);
	}
	sf::Vector2f pos_temp = _elem[0].get_size();
	for (size_t i = 0; i < _size; i++)
	{
		_elem[i].set_Pos((pos_temp.x*i), 0);
	}
}



void dr::Word::update(sf::RenderWindow& window, sf::Event& event1,
					  std::string& str, dr::Levels& level, dr::Bool& b)
{

	for (size_t i = 0; i < _size; i++)
	{
		_elem[i].update(window, event1, str, level, b);
	}

	if (b._is_all_inserted)
	{
		if (level == dr::Levels::level_6)
		{
			b._is_won = true;
			for (size_t i = 0; i < _size; i++)
			{
				if (!_elem[i]._is_correct)
				{
					b._is_lose = true;
					b._is_won = false;
					return;
				}
			}
		}
		else
		{
			b._is_won = true;
			for (size_t i = 0; i < _size; i++)
			{
				if (!_elem[i]._is_correct)
				{
					b._is_won = false;
					//return;
				}
			}
		}

		if (b._is_won != true)
		{
			if (level != dr::Levels::level_6)
			{
				level = static_cast<dr::Levels>((static_cast<int>(level)) + 1);
			}
		}
		b._is_all_inserted = false;
	}
	else
	{
		for (size_t i = 0; i < _size; i++)
		{
			if (!_elem[i]._is_inserted)
			{
				b._is_all_inserted = false;
				return;
			}
		}
		b._is_all_inserted = true;
	}

}



void dr::Word::draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < _size; i++)
	{
		_elem[i].draw(window);
	}
}



void dr::Word::set_pos(float x, float y)
{
	sf::Vector2f pos_temp = _elem[0].get_size();
	for (size_t i = 0; i < _size; i++)
	{
		_elem[i].set_Pos(x + (i * 73), y);
	}
}


