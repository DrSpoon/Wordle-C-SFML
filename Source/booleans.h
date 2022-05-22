#pragma once
#ifndef BOOLEANS_H
#define	BOOLEANS_H


namespace dr
{
	enum Levels
	{
		level_1, level_2, level_3, level_4, level_5, level_6
	};
	struct Bool
	{
		/*bool _is_mouse_pressed = false;
		bool _is_mouse_released = false;
		bool _is_mouse_hovered = false;
		bool _is_mouse_idle = false;
		bool _is_input = false;*/

		bool _is_level_1 = true;
		bool _is_level_2 = true;
		bool _is_level_3 = true;
		bool _is_level_4 = true;
		bool _is_level_5 = true;
		bool _is_level_6 = true;
		bool _is_won = false;
		bool _is_lose = false;
		bool _is_last_index = false;
		bool _is_all_inserted = false;

		bool _is_update = true;
	};
};

#endif // !BOOLEANS
