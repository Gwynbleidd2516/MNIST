#include"Canvas.h"

Canvas::Canvas(int size)
{
    this->size = size;
    colorField.resize(WEIGHT, vector<uint8_t>(HEIGHT));
    for (int i = 0; i < WEIGHT; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            colorField[i][j] = 0;
        }
    }

}

vector<double> Canvas::getMatrix()
{
    vector<double> field;
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WEIGHT; x++)
        {
            field.push_back((double)colorField[x][y] / 255);
        }
    }
    return field;
}

void Canvas::setPosition(float x, float y) { position = Vector2f(x, y); }

Vector2f Canvas::getSize() { return Vector2f(size * WEIGHT + 20, size * HEIGHT + 20); }

void Canvas::render(RenderWindow& window)
{
    RectangleShape cube(Vector2f(size, size));
    RectangleShape backGround(Vector2f(size * WEIGHT + 20, size * HEIGHT + 20));
    backGround.setFillColor(Color(100, 100, 100, 255));
    backGround.setPosition(position);
    vector<vector<FloatRect>> mouseSense;
    mouseSense.resize(WEIGHT, vector<FloatRect>(HEIGHT));

    if (Keyboard::isKeyPressed(Keyboard::C))
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WEIGHT; x++)
            {
                colorField[x][y] = 0;
            }
        }
    }

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WEIGHT; x++)
        {
            mouseSense[x][y] = FloatRect(Vector2f(size * x, size * y), cube.getSize());
        }

    }

    window.draw(backGround);

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WEIGHT; x++)
        {
            cube.setPosition(backGround.getPosition().x + 10 + size * x, backGround.getPosition().y + 10 + size * y);
            if (mouseSense[x][y].contains((Vector2f)Mouse::getPosition(window)))
            {
                cube.setFillColor(Color(255, 255, 255, 255));
                if (Mouse::isButtonPressed(Mouse::Left))
                {
                    if (colorField[x][y] + way <= 255)
                        colorField[x][y] += way;
                    else
                        colorField[x][y] = 255;
                }
                else if (Mouse::isButtonPressed(Mouse::Right))
                {
                    colorField[x][y] = 0;
                }
            }
            else
            {
                cube.setFillColor(Color(colorField[x][y], colorField[x][y], colorField[x][y], 255));
            }
            window.draw(cube);
        }
    }
}