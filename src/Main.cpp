#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include <thread>
#include <chrono>

#define SCREENWIDTH 1000
#define SCREENHEIGHT 400

using namespace sf;

int numBars = 100;

void DrawBars(RenderWindow &window, int *barHeight) {
    for(int i = 0; i < numBars; i++) {
        RectangleShape bar(Vector2f(SCREENWIDTH / numBars, barHeight[i]));
        bar.setPosition((SCREENWIDTH / numBars) * i, SCREENHEIGHT - barHeight[i]);
        window.draw(bar);
    }
}

int main() {
    RenderWindow window(VideoMode(SCREENWIDTH, SCREENHEIGHT), "Bubble Sort");
    window.setFramerateLimit(60);
    int *barHeight = (int *) malloc(sizeof(int) * numBars);
    int i = 0;
    for(int j = 0; j < numBars; j++) {
        barHeight[j] = rand() % 100 + 100;
    }
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
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        //sort
        if(i < numBars) {
            for(int j = i; j < numBars; j++) {
                if(barHeight[i] > barHeight[j]) {
                    int temp = barHeight[i];
                    barHeight[i] = barHeight[j];
                    barHeight[j] = temp;
                }
            }
            i++;
        }
    }
    return 0;
}