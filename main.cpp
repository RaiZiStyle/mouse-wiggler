#include <Windows.h>
#include <iostream>

void moveMouse(){
    int Height = GetSystemMetrics(SM_CYSCREEN);
    int Width = GetSystemMetrics(SM_CXSCREEN);

    int count = 800;
    int movex, movey;
    float angle = 0.0f;

    // set mouse at center screen
    SetCursorPos(Height/2, Width/2); 

    

    // begin spiral! :)
    for(int i = 0; i <= count; i++){
        angle = .3 * i;
        movex = (angle * cos(angle) * 2) + Height/2;
        movey = (angle * sin(angle) * 2) + Width/2;
        SetCursorPos(movex, movey);
        Sleep(1);
    }

}

int main(){
    moveMouse();
    return 0;
}