#include "Input.h"

Input::Input() {
    // Constructor
}

Input::~Input() {
    // Destructor
}

void Input::update() {
    // Update input state based on user input
    // ...
}

bool Input::isKeyDown(int key) {
    // Return true if the specified key is currently pressed down, false otherwise
    // ...
    if(key)
        return true;
    return false;
}

bool Input::isKeyUp(int key) {
    // Return true if the specified key is currently not pressed down, false otherwise
    // ...
    if(key)
        return true;
    return false;
}

bool Input::isMouseDown(int button) {
    // Return true if the specified mouse button is currently pressed down, false otherwise
    // ...
    if(button)
        return true;
    return false;
}

bool Input::isMouseUp(int button) {
    // Return true if the specified mouse button is currently not pressed down, false otherwise
    // ...
    if(button)
        return true;
    return false;
}

int Input::getMouseX() {
    // Return the current x position of the mouse
    // ...
    return 0;
}

int Input::getMouseY() {
    // Return the current y position of the mouse
    // ...
    return 0;
}
