#pragma once

#include<SFML/Graphics.hpp>
#include<vector>
using namespace std;
using namespace sf;

#define HEIGHT 28
#define WEIGHT 28

class Canvas
{
private:
    double size;
    const int way = 160;
    vector<vector<uint8_t>> colorField;
    Vector2f position;

public:
    Canvas(int size);

    vector<double> getMatrix();

    Vector2f getSize();

    void setPosition(float x, float y);

    void render(RenderWindow& window);
};