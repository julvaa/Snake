
#include "waz.h"

Cialo::Cialo(int x, int y)
{
    setSize({50, 50});
    setPosition(x, y);
}

Cialo::Cialo()
{}

Waz::Waz()
{
    glowa.setPosition(300, 300);
    glowa.setSize({50, 50});
    glowa.setFillColor(sf::Color::Green);
}

void Waz::recMove()
{
    sf::Vector2f p = pos;
    for(int j = 0; j < ogon.size(); j++)
    {
        sf::Vector2f curr = {ogon[j].getPosition().x, ogon[j].getPosition().y};
        ogon[j].setPosition(p.x, p.y);
        ogon[j].pos = p;
        p = curr;
    }
}

void Waz::move(sf::RenderWindow &window)
{
    pos = sf::Vector2f(glowa.getPosition().x, glowa.getPosition().y);
    if (dir == sf::Keyboard::Key::Up)
    {
        glowa.move(0, -speed);
    }
    else if (dir == sf::Keyboard::Key::Right)
    {
        glowa.move(speed, 0);
    }
    else if (dir == sf::Keyboard::Key::Down)
    {
        glowa.move(0, speed);
    }
    else
    {
        glowa.move(-speed, 0);
    }
    recMove();
}

void Waz::press(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        if (dir != sf::Keyboard::Key::Down) dir = sf::Keyboard::Key::Up;
    }
    else if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        if (dir != sf::Keyboard::Key::Up) dir = sf::Keyboard::Key::Down;
    }
    else if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        if (dir != sf::Keyboard::Key::Right) dir = sf::Keyboard::Key::Left;
    }
    else if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        if (dir != sf::Keyboard::Key::Left) dir = sf::Keyboard::Key::Right;
    }
}

