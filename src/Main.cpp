#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include <thread>
#include <chrono>

#define SCREENWIDTH 1000
#define SCREENHEIGHT 400

using namespace sf;

int numBars = 100;
int currentBar = 0;
int compareBar = 0;

void DrawBars(RenderWindow &window, int *barHeight) {
    for(int i = 0; i < numBars; i++) {
        RectangleShape bar(Vector2f(SCREENWIDTH / numBars, barHeight[i]));
        bar.setPosition((SCREENWIDTH / numBars) * i, SCREENHEIGHT - barHeight[i]);
        bar.setFillColor(i == compareBar + 1 ? Color::Green : i == compareBar ? Color::Red : Color::White);
        window.draw(bar);
    }
}

int main() {
    RenderWindow window(VideoMode(SCREENWIDTH, SCREENHEIGHT), "Bubble Sort");
    window.setFramerateLimit(60);
    int *barHeight = (int *) malloc(sizeof(int) * numBars);
    for(int j = 0; j < numBars; j++) {
        barHeight[j] = rand() % SCREENHEIGHT;
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
        //sort
        if(currentBar < numBars - 1) {
            if(compareBar < numBars - currentBar - 1) {
                if(barHeight[compareBar] > barHeight[compareBar + 1]) {
                    int temp = barHeight[compareBar];
                    barHeight[compareBar] = barHeight[compareBar + 1];
                    barHeight[compareBar + 1] = temp;
                } 
                compareBar++;
            } else {
                compareBar = 0;
                currentBar++;
            }
        }
    }
    return 0;
}