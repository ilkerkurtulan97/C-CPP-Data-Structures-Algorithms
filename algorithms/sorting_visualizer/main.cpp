#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <unistd.h> //for usleep()

const int WIDTH = 800;
const int HEIGHT = 600;
const int NUM_BARS = 100;

void drawBars(sf::RenderWindow& window, const std::vector<int>& values) {
    window.clear();
    float barWidth = (float)WIDTH / NUM_BARS;

    for (int i = 0; i < NUM_BARS; ++i) {
        sf::RectangleShape bar;
        bar.setSize(sf::Vector2f(barWidth - 1, values[i]));
        bar.setPosition(i * barWidth, HEIGHT - values[i]);
        bar.setFillColor(sf::Color::Green);
        window.draw(bar);
    }

    window.display();
}

void bubbleSort(sf::RenderWindow& window, std::vector<int>& values) {
    for (int i = 0; i < NUM_BARS; ++i) {
        for (int j = 0; j < NUM_BARS - i - 1; ++j) {
            if (values[j] > values[j + 1]) {
                std::swap(values[j], values[j + 1]);
                drawBars(window, values);
                usleep(10000); //small delay
            }
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Bubble Sort Visualization");
    std::vector<int> values;

    for (int i = 0; i < NUM_BARS; ++i)
        values.push_back(rand() % HEIGHT);

    drawBars(window, values);
    sleep(1);
    bubbleSort(window, values);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}
