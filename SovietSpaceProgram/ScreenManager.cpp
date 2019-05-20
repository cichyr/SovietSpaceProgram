#include "ScreenManager.h"


ScreenManager::ScreenManager(Screen* screen)
{
	addScreen(screen);
	current_screen = screens[0];
}

void ScreenManager::addScreen(Screen* screen)
{
	screens.push_back(screen);
}

void ScreenManager::displayScreen()
{
	current_screen->draw();
}

void ScreenManager::update(int choice)
{
	current_screen = screens[choice];
}

void ScreenManager::draw()
{
	current_screen->draw();
}

void ScreenManager::onKeyPress()
{
	
}

void ScreenManager::onKeyRelease()
{

}

void ScreenManager::onMousePress(sf::RenderWindow* window, sf::Event event)
{
	current_screen->onMousePress(window, event);
}

void ScreenManager::onMouseDrag()
{

}
