#include "wordle.h"


dr::Wordle::Wordle()
	:
	_size{ 0 }
{
	_txt = new sf::Text;
	if (!_font.loadFromFile("bin/Debug/ariblk.ttf"))
	{
		printf("font failed to load\n");
	}
}

dr::Wordle::~Wordle()
{
	delete _txt;
}

void dr::Wordle::setup(int size, float x, float y)
{
	_level = dr::Levels::level_1;
	_size = size;
	_elem.resize(size);
	for (size_t i = 0; i < _size; i++)
	{
		_elem[i].setup(5, 0, 0);
		_elem[i].set_pos(0, i * 73);
	}
	_txt->setFont(_font);

	_txt->setFillColor(sf::Color::White);
    _txt->setString("WORDLE");
    _txt->setCharacterSize(80);

	//_txt->setString("Press on the box to start writing :) ");
	//_txt->setCharacterSize(20);

	_txt->setFillColor(sf::Color::Black);
	//_text->setStyle(sf::Text::Regular);
	_txt->setPosition(175, 100);

}


void dr::Wordle::update(sf::RenderWindow& window, sf::Event& event1,
						std::string& str, dr::Bool& b)
{
	if (b._is_won)
	{
		_txt->setFillColor(sf::Color::Green);
		_txt->setString("You Win :)");
		_txt->setCharacterSize(50);
	}
	else if (b._is_lose)
	{
	    _txt->setPosition(100, 90);
		_txt->setFillColor(sf::Color::Red);
		_txt->setString("       You Lost :( \nThe word was: "+str);
		_txt->setCharacterSize(50);
	}
	else
	{
		switch (_level)
		{
			case(dr::Levels::level_1):
			{
				_elem[_level].update(window, event1, str, _level, b);
				break;
			}
			case(dr::Levels::level_2):
			{
				_elem[_level].update(window, event1, str, _level, b);
				break;
			}
			case(dr::Levels::level_3):
			{
				_elem[_level].update(window, event1, str, _level, b);
				break;
			}
			case(dr::Levels::level_4):
			{
				_elem[_level].update(window, event1, str, _level, b);
				break;
			}
			case(dr::Levels::level_5):
			{
				_elem[_level].update(window, event1, str, _level, b);
				break;
			}
			case(dr::Levels::level_6):
			{
				_elem[_level].update(window, event1, str, _level, b);
				break;
			}
			default:
				break;
		}
	}
}





void dr::Wordle::draw(sf::RenderWindow& window, dr::Bool& b)
{
	for (size_t i = 0; i < _level + 1; i++)
	{
		_elem[i].draw(window);
	}
	window.draw(*_txt);
}



void dr::Wordle::set_pos(float x, float y)
{
	for (size_t i = 0; i < _size; i++)
	{
		_elem[i].set_pos(x, y + (i * 73));
	}
}
