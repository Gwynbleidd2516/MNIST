#include <SFML/Graphics.hpp>
#include<iostream>
#include"Canvas.h"
#include"Perceptron.h"
using namespace std;

#define BRAIN_PATH "brain\\brain"
#define FONT_PATH "Time-Roman-Normal-Font.ttf"

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 400), "MNIST", Style::Close);
    Canvas a(10);
    window.setFramerateLimit(60);

    vector<Perceptron> ans(20);
    for (int i = 0; i < 10; i++)
    {
        ans[i].setPerceptron(28 * 28);
        ans[i].loadWieghts(BRAIN_PATH + to_string(i));
    }

    Font font;
    font.loadFromFile(FONT_PATH);
    Text text("", font);
    Text text2("", font);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
        }

        window.clear();
        a.render(window);
        double m = 0;
        for (int i = 0; i < 10; i++)
        {
            text.setPosition(a.getSize().x + 10, 30 * i);
            text.setString(to_string(i));
            text2.setPosition(a.getSize().x + 40, 30 * i);
            text2.setString(to_string(ans[i].construct(a.getMatrix()) * (double)100));
            window.draw(text);
            window.draw(text2);
        }

        window.display();
    }

    return 0;
}