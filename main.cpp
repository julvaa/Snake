#include <iostream>
#include <ctime>
#include "wazSFML.h"
using namespace std;

int main()
{
    sf::Clock c;
    int speed = 500;
    srand(time(NULL));
    MainScreen main;
    GameScreen game;
    EndScreen end;
    main.active = true;
    sf::RenderWindow window(sf::VideoMode(1200, 700), "Snake");
    window.setFramerateLimit(60);
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (game.active == true) game.waz.press(event);

            if (main.active == true)
            {
                if (event.type == sf::Event::MouseButtonPressed && main.button1.body.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                {
                    main.active = false;
                    game.active = true;
                }
                if (event.type == sf::Event::MouseButtonPressed && main.button2.body.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                {
                    window.close();
                }
                if (event.type == sf::Event::MouseButtonPressed && main.latwy.body.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                {
                    game.poziom = 1;

                }
                if (event.type == sf::Event::MouseButtonPressed && main.sredni.body.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                {
                    game.poziom = 2;
                    for(int i = 0; i < 5; i++) game.sciany.emplace_back(Sciana());
                }
                if (event.type == sf::Event::MouseButtonPressed && main.trudny.body.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                {
                    game.poziom = 3;
                    for(int i = 0; i < 7; i++) game.sciany.emplace_back(Sciana());
                }
            }
        }
        if (game.active == true)
        {
            if (game.waz.glowa.getPosition().x+game.waz.glowa.getGlobalBounds().width > 1280 || game.waz.glowa.getPosition().x < 0 || game.waz.glowa.getPosition().y+game.waz.glowa.getGlobalBounds().height > 720 || game.waz.glowa.getPosition().y < 0)
            {
                game.active = false;
                game.waz.glowa.setPosition(300, 300);
                game.waz.dir = sf::Keyboard::Key::Right;
                end.loadLeaderboard(game.punkty);
                game.waz.ogon.clear();
                game.poziom = 1;
                game.sciany.clear();
                speed = 500;
                game.waz.nastepny = NULL;
                game.punkty = 0;
                end.active = true;
            }
            for (int i = 0; i < game.waz.ogon.size();i++) if (game.waz.glowa.getPosition() == game.waz.ogon[i].getPosition())
                {
                    game.active = false;
                    game.waz.glowa.setPosition(300, 300);
                    game.waz.dir = sf::Keyboard::Key::Right;
                    end.loadLeaderboard(game.punkty);
                    game.waz.ogon.clear();
                    game.poziom = 1;
                    game.sciany.clear();
                    speed = 500;
                    game.waz.nastepny = NULL;
                    game.punkty = 0;
                    end.active = true;
                }
            for (int i = 0; i < game.sciany.size();i++) if (game.waz.glowa.getPosition() == game.sciany[i].getPosition())
                {
                    game.active = false;
                    game.waz.glowa.setPosition(300, 300);
                    game.waz.dir = sf::Keyboard::Key::Right;
                    end.loadLeaderboard(game.punkty);
                    game.waz.ogon.clear();
                    game.poziom = 1;
                    game.sciany.clear();
                    speed = 500;
                    game.waz.nastepny = NULL;
                    game.punkty = 0;
                    end.active = true;
                }
            if (game.waz.glowa.getGlobalBounds().intersects(game.J.body.getGlobalBounds()))
            {
                game.respawn();
                game.punkty++;
                if (speed > 100) speed -= 50;
                if (game.waz.ogon.size() == 0)
                {
                    game.waz.ogon.emplace_back(Cialo(game.waz.pos.x, game.waz.pos.y));
                    game.waz.nastepny = &game.waz.ogon[0];
                }
                else
                {
                    Cialo *curr = &game.waz.ogon[0];
                    while (curr->nastepny != NULL)
                    {
                        curr = curr->nastepny;
                    }
                    game.waz.ogon.emplace_back(Cialo(curr->pos.x, curr->pos.y));
                    curr->nastepny = &game.waz.ogon[game.waz.ogon.size()-2];
                }
            }
        }
        if (end.active == true)
        {
            if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                end.active = false;
                main.active = true;
                end.val.clear();
                end.leaderboard.clear();
            }
        }
        if(c.getElapsedTime().asMilliseconds() > speed)
        {
            if (game.active == true) game.waz.move(window);
            c.restart();
        }


        window.clear(sf::Color::Black);

        if (main.active == true) main.drawScreen(window);
        else if (game.active == true) game.drawScreen(window);
        else if (end.active == true) end.drawScreen(window);

        window.display();
    }
    return 0;
}

