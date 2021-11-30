#include "Theomer.h"
#include <iostream>

Theomer::Theomer() {
    reset();
    _timeScale = 1.0f;
    //_deltaTime = std::chrono::duration<float>(0.0f);
    _deltaTime = 0;
}
Theomer::~Theomer() {

}

void Theomer::reset() {
    _startTime = std::chrono::system_clock::now();
}
double oldT = clock();
void Theomer::FPS() {
    std::cout << "FPS: " << 1.0f / deltaTime() << std::endl;
}
float Theomer::deltaTime() {
    return _deltaTime;
}

void Theomer::setTimeScale(float t) {
    _timeScale = t;
}
float Theomer::getTimeScale() {
    return _timeScale;
}

float Theomer::getSeconds() {
    return 0;
}

void Theomer::startTime() {
}
void Theomer::tick() {
    double t = clock();
    _deltaTime = (float)((t - oldT) / 1000.0f);
    oldT = t;
}
void Theomer::calculateFps() {
    _elapsedTime += deltaTime();
    frames++;
    if (_elapsedTime >= 1.0f) {
        fps = frames / _elapsedTime;
        frames = 0;
        _elapsedTime = 0;
    }
}
float Theomer::getFPS() {
    return fps;
}