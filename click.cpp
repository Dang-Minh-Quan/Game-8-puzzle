#include "include/click.h"

bool ClickButton(int squareX, int squareY, int squareWidth, int squareHeight, int mouseX, int mouseY, bool isActive)//Kiểm tra người chơi nhấn hitbox
{
    if (!isActive)
        return false; // Tắt Hitbox
    return mouseX >= squareX && mouseX <= squareX + squareWidth && mouseY >= squareY && mouseY <= squareY + squareHeight;
}

