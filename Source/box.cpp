#include "Box.h"


dr::Box::Box()
{
	/*_text = new sf::Text;*/
	//_box = new sf::RectangleShape;

	if (!_font.loadFromFile("bin/Debug/arial.ttf"))
	{
		printf("font failed to load\n");
	}
	_index = 0;
}



void dr::Box::setup(short index)
{
	_index = index;
	_box.setPosition(0, 0);
	_box.setSize(sf::Vector2f(73.f, 73.f));
	_box.setFillColor(sf::Color::White);
	_box.setOutlineColor(sf::Color(200,200,200,255));
	_box.setOutlineThickness(2.f);


	_text.setFont(_font);
	_text.setString(" ");
	_text.setCharacterSize(65);

	_text.setFillColor(sf::Color::Black);
	//_text->setStyle(sf::Text::Regular);
	_text.setPosition((_box.getPosition().x + 13),
					  _box.getPosition().y - 8);

};




void dr::Box::update(sf::RenderWindow& window,
					 sf::Event& event1,
					 std::string& str,
					 dr::Levels& level,
					 dr::Bool& b)
{
	if (b._is_update)
	{

		if (_is_update)
		{

			int mouse_X = sf::Mouse::getPosition(window).x;
			int mouse_Y = sf::Mouse::getPosition(window).y;
			if (!_is_input)
			{
				if (mouse_X <= _box.getGlobalBounds().left + _box.getGlobalBounds().width - 10 &&
					mouse_X >= _box.getGlobalBounds().left + 10 &&
					mouse_Y <= _box.getGlobalBounds().top + _box.getGlobalBounds().height - 10 &&
					mouse_Y >= _box.getGlobalBounds().top + 10)
				{

					switch (event1.type)
					{
						case sf::Event::MouseButtonPressed:
						{
							_is_mouse_pressed = true;
							_is_mouse_released = false;
							_is_mouse_hovered = false;
							_is_mouse_idle = false;
							_box.setFillColor(sf::Color(125, 125, 125));
							break;
						}
						case sf::Event::MouseButtonReleased:
						{
							_is_mouse_pressed = false;
							_is_mouse_released = true;
							_is_mouse_hovered = false;
							_is_mouse_idle = false;
							if (!_is_inserted)
							{
								_is_input = true;
								b._is_update = true;
							}
							_box.setFillColor(sf::Color::White);
							break;
						}
						default:
						{
							_is_mouse_pressed = false;
							_is_mouse_released = false;
							_is_mouse_hovered = true;
							_is_mouse_idle = false;
							_box.setFillColor(sf::Color(200, 200, 200));
							break;
						}
					}
				}
				else
				{
					_is_mouse_idle = true;
					_box.setFillColor(sf::Color::White);
				}
			}
			//return _status;
			get_input(event1, b, str);
			if (_is_inserted)
			{
				check_character(str);
				if (_is_correct)
				{
					_box.setFillColor(sf::Color::Green);
				}
				else if (_is_exists)
				{
					_box.setFillColor(sf::Color::Yellow);
				}
				else
				{
					_box.setFillColor(sf::Color(125, 125, 125));
				}
				_is_update = false;

			}
		}
	}
}





void dr::Box::check_character(std::string &str)
{

	if (str[_index] == _text.getString()[0])
	{
		_is_correct = true;
		return;
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == _text.getString()[0])
		{
			_is_exists = true;
			return;
		}
	}
	_is_wrong = true;
}




void dr::Box::get_input(sf::Event& event1, dr::Bool& b, std::string &str)
{
    char tmp = str[_index];

    if ((tmp >= 'a' && tmp <= 'z') || (tmp >= 'A' && tmp <= 'Z')){
        if (_is_input)
        {
            switch (event1.type)
            {
                case sf::Event::TextEntered:
                {
                    _text.setString((char)event1.text.unicode);
                    _box.setFillColor(sf::Color(125, 125, 125));
                    _is_input = false;
                    _is_inserted = true;
                    b._is_update = true;
                    break;
                }
                default:
                {
                    break;
                }
            }
        }
    }
}




void dr::Box::draw(sf::RenderWindow& window)
{
	//window.clear();

	window.draw(_box);
	window.draw(_text);

	//window.display();
}

dr::Box::~Box()
{
	//delete _text;
	//delete _box;
};


void dr::Box::set_Pos(float x, float y)
{
	_box.setPosition(x, y);
	_text.setPosition((_box.getPosition().x + 13),
					  _box.getPosition().y - 8);
}

sf::Vector2f dr::Box::get_pos(void)
{
	return _box.getPosition();
}

sf::Vector2f dr::Box::get_size()
{
	return _box.getSize();
}
