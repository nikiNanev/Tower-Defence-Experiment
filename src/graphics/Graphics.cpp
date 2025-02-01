#include "Graphics.h"

const Color Graphics::RED = Color(255, 0, 0);
const Color Graphics::GREEN = Color(0, 255, 0);
const Color Graphics::BLUE = Color(0, 0, 255);
const Color Graphics::YELLOW = Color(255, 255, 0);
const Color Graphics::WHITE = Color(255, 255, 255);
const Color Graphics::BLACK = Color(0, 0, 0);

Graphics::Graphics() {
    // Constructor
}

Graphics::~Graphics() {
    // Destructor
}

bool Graphics::init() {
    // Initialize graphics system
    // ...

    return true;
}

void Graphics::cleanup() {
    // Free graphics resources and shut down graphics system
    // ...
}

void Graphics::render() {
    // Clear screen
    // ...

    // // Render towers
    // for (auto& tower : towers) {
    //     // Render tower sprite at tower position
    //     // ...
    // }

    // // Render enemies
    // for (auto& enemy : enemies) {
    //     // Render enemy sprite at enemy position
    //     // ...
    // }

    // Update screen
    // ...
}

