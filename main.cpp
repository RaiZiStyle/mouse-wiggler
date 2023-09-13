#include <Windows.h>
#include <time.h>
#include <iostream>



void makeCircle(int current_x, int current_y) {
    // int Height = GetSystemMetrics(SM_CYSCREEN);
    // int Width = GetSystemMetrics(SM_CXSCREEN);

    int count = 75;
    int movex, movey;
    float angle = 0.0f;

    // set mouse at center screen
    // SetCursorPos(Height / 2, Width / 2);
    
    // begin spiral! :)
    for (int i = 0; i <= count; i++) {
        angle = .3 * i;
        movex = (angle * cos(angle) * 2) + current_x;
        movey = (angle * sin(angle) * 2) + current_y;
        SetCursorPos(movex, movey);
        Sleep(1);
    }
}

void makeWigle() {
    srand(time(NULL));  // Initialize random number generator

    int wiggleTime = 500;  // 0.5 seconds in milliseconds
    int restTime = 2000;   // 20 seconds in milliseconds
    int totalTime = wiggleTime + restTime;

    while (1) {  // Infinite loop
        POINT cursor_pos;
        if (GetCursorPos(&cursor_pos)){
            printf("Current position.x : %d, position.y : %d\n", cursor_pos.x, cursor_pos.y);
        }

        // int xOffset = rand() % 21 - 10;  // Random horizontal offset between -10 and 10
        // int yOffset = rand() % 21 - 10;  // Random vertical offset between -10 and 10
        int xOffset = 0;
        int yOffset = 0;

        int currentX = cursor_pos.x  + xOffset;   // Adjust Width as needed
        int currentY = cursor_pos.y + yOffset;  // Adjust Height as needed
        printf("Make the Wigle \n");
        makeCircle(currentX, currentY);

        // SetCursorPos(currentX, currentY);  // Move cursor with random offset

        // Sleep(wiggleTime);  // Wait for 0.5 seconds
        printf("Sleeping for 20s\n");

        Sleep(restTime - wiggleTime);  // Wait for the remaining 19.5 seconds
    }
}

int main() {
    // makeCircle();
    makeWigle();
    return 0;
}