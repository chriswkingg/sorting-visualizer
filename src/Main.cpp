#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <random>
#include <iostream>

#define SCREENWIDTH 1000
#define SCREENHEIGHT 400

using namespace sf;

RenderWindow window(VideoMode(SCREENWIDTH, SCREENHEIGHT), "Bubble Sort");
int numBars = 100;
int currentBar = 0;
int compareBar = 0;

void DrawBars(int *barHeight) {
    window.clear();
    for(int i = 0; i < numBars; i++) {
        RectangleShape bar(Vector2f(SCREENWIDTH / numBars, barHeight[i]));
        bar.setPosition((SCREENWIDTH / numBars) * i, SCREENHEIGHT - barHeight[i]);
        bar.setFillColor(i == compareBar + 1 ? Color::Red : i == compareBar ? Color::Green : Color::White);
        window.draw(bar);
    }
    window.display();
}

void BubbleSort(int *arr) {
    int size = (int) sizeof(arr)/sizeof(int);
    for(currentBar = 0; currentBar < numBars; currentBar++) {
        for(compareBar = 0; compareBar < numBars - currentBar - 1; compareBar++) {
            if(arr[compareBar] > arr[compareBar + 1]){
                int temp = arr[compareBar];
                arr[compareBar] = arr[compareBar + 1];
                arr[compareBar + 1] = temp;
                
            }
            sleep(microseconds(1000));
        }
    }
}

int main() {
    window.setFramerateLimit(60);
    int *barHeight = (int *) malloc(sizeof(int) * numBars);
    //randomize array
    for(int j = 0; j < numBars; j++) {
        barHeight[j] = rand() % SCREENHEIGHT;
    }
    Thread sort(&BubbleSort, barHeight);
    sort.launch(); 
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        DrawBars(barHeight);  
    }
    return 0;
}