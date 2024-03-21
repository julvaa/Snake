
#include "wazSFML.h"


Button::Button(int x, int y, string txt)
{
    body.setSize({200, 75});
    body.setPosition(x, y);
    font.loadFromFile("../arialmt.ttf");
    text.setCharacterSize(30);
    text.setPosition(x+5, y+5);
    text.setFont(font);
    text.setString(txt);
    text.setFillColor(sf::Color::Black);
}

Button::Button(int x, int y, string txt, float sizeX, float sizeY)
{
    body.setSize({sizeX, sizeY});
    body.setPosition(x, y);
    font.loadFromFile("../arialmt.ttf");
    text.setCharacterSize(30);
    text.setPosition(x+3, y-5);
    text.setFont(font);
    text.setString(txt);
    text.setFillColor(sf::Color::Black);
}

void Button::draw(sf::RenderWindow &window)
{
    window.draw(body);
    window.draw(text);
}

Screen::Screen()
{
    font.loadFromFile("../arialmt.ttf");
    title.setCharacterSize(30);
    title.setFont(font);
    title.setString("SNAKE GAME");
    title.setPosition(500, 0);
}

MainScreen::MainScreen() : button1(300, 300, "Play"), button2(300, 400, "Exit"), latwy(550, 300, "1", 25, 25), sredni(550, 330, "2", 25, 25), trudny(550, 360, "3", 25, 25)
{
    latwy.text.setFillColor(sf::Color::Green);
    sredni.text.setFillColor(sf::Color::Blue);
    trudny.text.setFillColor(sf::Color::Red);
}

void MainScreen::drawScreen(sf::RenderWindow &window)
{
    button1.draw(window);
    button2.draw(window);
    latwy.draw(window);
    sredni.draw(window);
    trudny.draw(window);
    window.draw(title);
}
bool comp(int a, int b)
{
    if (a < b) return false;
    else return true;
}

GameScreen::GameScreen()
{
    title.setString("Gra");
    punktyText.setCharacterSize(30);
    punktyText.setFont(font);
    punktyText.setString("punkty:");
    J.respawn();
}

void GameScreen::drawScreen(sf::RenderWindow &window)
{
    punktyText.setString("punkty: " + to_string(punkty));
    window.draw(punktyText);
    window.draw(J.body);
    window.draw(waz.glowa);
    for(auto &v : sciany) window.draw(v);
    for(auto &v : waz.ogon) window.draw(v);
    window.draw(title);
}

void GameScreen::respawn()
{
    bool tmp = false;
    do
    {
        tmp = false;
        int respX = (rand() % 24)*50;
        int respY = (rand() % 14)*50;
        for(int i = 0; i < sciany.size(); i++)
        {
            if (sciany[i].getPosition().x == respX && sciany[i].getPosition().y == respY) tmp = true;
        }
        if (tmp == false) J.body.setPosition(respX, respY);
    }while (tmp == true);
}

EndScreen::EndScreen()
{
    title.setString("Koniec Gry");
    punktyText.setCharacterSize(30);
    punktyText.setFont(font);
    punktyText.setString("punkty: NAN");
    punktyText.setPosition(500, 100);
}


void EndScreen::loadLeaderboard(int pkt)
{
    punktyText.setString("punkty: " + to_string(pkt));
    fstream file;
    file.open("plik.txt", std::ios::in);
    if (file.is_open())
    {
        cout << "open" << endl;
        string line;
        while(getline(file, line))
        {
            val.emplace_back(stoi(line));
        }
    }
    file.close();
    bool ist = 0;
    for(auto &v : val)
    {
        if (pkt == v) ist = true;
    }
    if (ist != true) val.emplace_back(pkt);
    sort(val.begin(), val.end(), comp);
    if (val.size() > 10)
    {
        val.erase(val.begin()+val.size()-1);
    }
    for(int i = 0; i < val.size(); i++)
    {
        sf::Text t;
        t.setCharacterSize(30);
        t.setFont(font);
        t.setPosition(500, 150 + 40*i);
        t.setString("");
        t.setString(to_string(val[i]));
        leaderboard.emplace_back(t);
    }
    saveLeaderboard();
}

void EndScreen::saveLeaderboard()
{
    sort(val.begin(), val.end(), comp);

    fstream file;
    file.open("plik.txt", std::ios::out);
    if (file.is_open())
    {
        cout << "open" << endl;
        for(auto &v : val)
        {
            file << v << endl;
        }
    }
    file.close();
}

void EndScreen::drawScreen(sf::RenderWindow &window)
{
    window.draw(punktyText);
    window.draw(title);
    for(auto &v : leaderboard) window.draw(v);
}
