
#include "plansza.h"


Jedzenie::Jedzenie()
{
    //body.setSize({50, 50});
    body.setRadius({20});
    body.setPosition((rand() % 24)*50, (rand() % 14)*50);
    body.setFillColor(sf::Color::Yellow);
}

void Jedzenie::respawn()
{
    body.setPosition((rand() % 24)*50, (rand() % 14)*50);
}

Sciana::Sciana()
{
    setSize({50, 50});
    setPosition((rand() % 24)*50, (rand() % 14)*50);
    setFillColor(sf::Color::Red);
}

