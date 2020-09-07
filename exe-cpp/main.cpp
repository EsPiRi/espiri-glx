#include <iostream>
#include <Context.h>
#include <Window.h>

int main()
{
    Window window(1920,1080);
    Window window2(1024,768);
    Window window3(800,600);
    Window::render();
    
    return 0;
}


