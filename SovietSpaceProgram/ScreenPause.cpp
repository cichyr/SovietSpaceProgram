#include "ScreenPause.h"
#include <iostream>
#include <Windows.h>


ScreenPause::ScreenPause(float x, float y)
{
	if (!background.loadFromFile("menu_background_3.png"))
	{
		std::cout << "ERROR:\tCan't load menu background\n";
	}
	width = x;
	height = y;
	scaleX = (float)(width / 320.0f);
	scaleY = (float)(height / 180.0f);
	addButton(14, 30, "Resume");
	addButton(14, 75, "Exit to menu");
}

void ScreenPause::update()
{

}

void ScreenPause::draw()
{
	/*
		30x112
		scale_text(2)
		14/30	14/75	14/120
	*/
	ctx::save();

	ctx::scale(scaleX, scaleY);
	ctx::drawImage(background, 0, 0, 320, 180, 0, 0, 320, 180);

	drawButtons();

	ctx::restore();
}

void ScreenPause::onKeyPress()
{
	if (game::getKey(36))
		manager->update(0);
}

void ScreenPause::onKeyRelease()
{

}

void ScreenPause::onMousePress()
{
	if (game::isClicked()
		&& game::getMouseKey() == 0
		&& game::getX() >= buttons[1].x * scaleX
		&& game::getX() <= (buttons[1].x + 320) * scaleX
		&& game::getY() >= buttons[1].y * scaleY
		&& game::getY() <= (buttons[1].y + 180) * scaleY)
			manager->update(1);
	else if (game::isClicked()
		&& game::getMouseKey() == 0
		&& game::getX() >= buttons[0].x * scaleX
		&& game::getX() <= (buttons[0].x + 320) * scaleX
		&& game::getY() >= buttons[0].y * scaleY
		&& game::getY() <= (buttons[0].y + 180) * scaleY)
	{
		manager->update(0);
		game::startGame();
	}
}

void ScreenPause::addButton(int x, int y, std::string content)
{
	button tmp;
	tmp.x = x;
	tmp.y = y;
	tmp.content = content;
	buttons.push_back(tmp);
}

void ScreenPause::drawButtons()
{
	ctx::save();

	for (int i = 0; i < 2; i++)
	{
		ctx::fillStyle(60, 60, 60);
		ctx::fillRect(buttons[i].x, buttons[i].y, 112, 30);
		ctx::save();
		ctx::translate(
			((112 * 0.65) - (buttons[i].content.length() * 4)),
			(float)(10 + buttons[i].y));
		txt::printText(buttons[i].content);
		ctx::restore();
	}


	ctx::restore();
}

void ScreenPause::setManager(ScreenManager * manager)
{
	this->manager = manager;
}

void ScreenPause::changeScreen(int choice)
{
	manager->update(choice);
}