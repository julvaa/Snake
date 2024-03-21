
#ifndef SNEK_WAZ_H
#define SNEK_WAZ_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

class Cialo : public sf::RectangleShape
{
public:
    sf::Vector2f pos;
    Cialo *nastepny = NULL;
    Cialo(int x, int y);
    Cialo();
};

class Waz
{
public:;
    sf::RectangleShape glowa;
    vector<Cialo> ogon;
    Cialo *nastepny = NULL;
    sf::Vector2f pos;
    sf::Keyboard::Key dir = sf::Keyboard::Key::Right;
    float speed = 50;

    Waz();
    void recMove();
    void move(sf::RenderWindow &window);
    void press(sf::Event &event);
};




#endif //SNEK_WAZ_H
