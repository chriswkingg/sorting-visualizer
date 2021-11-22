#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include <thread>
#include <chrono>

#define SCREENWIDTH 600
#define SCREENHEIGHT 400

using namespace sf;
using namespace std::chrono_literals; //this is probably bad

void DrawBars(RenderWindow &window, int *barHeight) {
    for(int i = 0; i < 10; i++) {
        RectangleShape bar(Vector2f(100, barHeight[i]));
        bar.setPosition(SCREENWIDTH / 10 * i, SCREENHEIGHT - barHeight[i]);
        window.draw(bar);
    }
}

int main() {
    RenderWindow window(VideoMode(SCREENWIDTH, SCREENHEIGHT), "Bubble Sort");
    int barHeight[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        DrawBars(window, barHeight);
        window.display();
        std::this_thread::sleep_for(2000ms);
        barHeight[0] = 1000;
    }

    return 0;
}