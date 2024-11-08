#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

enum class LightState { RED, GREEN };

class TrafficLight {
private:
    LightState state;
    int greenDuration;
    int redDuration;
    sf::CircleShape shape;

public:
    TrafficLight(int greenDuration, int redDuration);
    void switchLight();
    void run(); // Thread function
    LightState getState() const;
    void draw(sf::RenderWindow& window);
};

#endif // TRAFFICLIGHT_H
