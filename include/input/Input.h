#ifndef INPUT_H
#define INPUT_H

#pragma once

#include <unordered_map>
#include <SDL2/SDL.h>

class Input
{
public:
    Input();
    ~Input();

    void update();

    bool isKeyDown(int key);
    bool isKeyUp(int key);

    bool isMouseDown(int button);
    bool isMouseUp(int button);
    int getMouseX();
    int getMouseY();

    void beginNewFrame();
    void keyUpEvent(const SDL_Event &event);
    void keyDownEvent(const SDL_Event &event);

    bool wasKeyPressed(SDL_Scancode key);
    bool wasKeyReleased(SDL_Scancode key);
    bool isKeyHeld(SDL_Scancode key);

    bool init()
    {
        m_heldKeys = std::unordered_map<SDL_Scancode, bool>();
        m_pressedKeys = std::unordered_map<SDL_Scancode, bool>();
        m_releasedKeys = std::unordered_map<SDL_Scancode, bool>();
        return true;
    }

    bool quitRequested() const { return m_quitRequested; } // added member function

private:
    std::unordered_map<SDL_Scancode, bool> m_heldKeys;
    std::unordered_map<SDL_Scancode, bool> m_pressedKeys;
    std::unordered_map<SDL_Scancode, bool> m_releasedKeys;

    bool m_quitRequested = false;
};

#endif // INPUT_H
