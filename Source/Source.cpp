#include <SFML/Graphics.hpp>
#include <iostream>
#include "box.h"
#include "word.h"
#include "wordle.h"
#include <fstream>
#include <random>
#include <time.h>


std::string	get_random_string(std::ifstream& input_file)
{
	std::string str;
	str.resize(5);
	int index = 0;
	int number_of_words = 0;
	//while (input_file>>str)
	//{
	//	number_of_words++;
	//}
	std::srand(time(0));
	index = rand() % 500;
	//std::string str2;
	//str2.resize(5);
	/*while (input_file >> str)
	{
		number_of_words++;
	}*/
	for (int i = 1; i <= index; i++)
		std::getline(input_file, str);
	return str;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(720, 960), "Wordle Copy by: Nikola", sf::Style::Titlebar | sf::Style::Close);

	std::ifstream input_file;
	input_file.open("bin/Debug/dictionary.txt");


	dr::Bool b;
	dr::Wordle _wordle;
	_wordle.setup(6, 0, 0);
	_wordle.set_pos(180, 300);


	std::string str = "";
	str = get_random_string(input_file);

	while (window.isOpen())
	{
		sf::Event _event;
		while (window.pollEvent(_event))
		{
			if (_event.type == sf::Event::Closed)
				window.close();
			//_box.update(window, _event, b);
			//_word.update(window, _event, str, b);
			_wordle.update(window, _event, str, b);
		}

		window.clear(sf::Color(255, 255, 255, 255));

		_wordle.draw(window, b);

		window.display();
	}

	input_file.close();
	return 0;
}


