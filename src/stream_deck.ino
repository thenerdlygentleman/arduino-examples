#include <Keyboard.h>

int buttonA = 2; // mikrophone
int buttonB = 3; // sound
int buttonC = 4; // none
int buttonD = 5; // none
int buttonE = 6; // none
int buttonF = 7; // none
int button = 8; // none
int buttonH = 9; // none
int pause = 250; // none

void setup()
{
    pinMode(buttonA, INPUT_PULLUP);
    pinMode(buttonB, INPUT_PULLUP);
    pinMode(buttonC, INPUT_PULLUP);
    pinMode(buttonD, INPUT_PULLUP);
    pinMode(buttonE, INPUT_PULLUP);
    pinMode(buttonF, INPUT_PULLUP);
    pinMode(button, INPUT_PULLUP);
    pinMode(buttonH, INPUT_PULLUP);
    Keyboard.begin();
}

void button(int button1, int button2, int button3, int button_name)
{
    if (button3 == 0) // if only two buttons are required
    {
        Keyboard.press(button1);
        Keyboard.press(button2);
        Serial.print(button_name); // debug
        Serial.print('\n');
        delay(pause);
        Keyboard.releaseAll();
    }
    else if (button3 == 0 && button2 == 0) // if only one button is required
    {
        Keyboard.press(button1);
        Serial.print(button_name); // debug
        Serial.print('\n');
        delay(pause);
        Keyboard.releaseAll();
    }
    else if (button3 == 0 && button2 == 0 && button1 == 0) // if no button is assigned
    {
        Serial.print("nothing");
        delay(pause);
    }
    else
    {
        Keyboard.press(button1);
        Keyboard.press(button2);
        Keyboard.press(button3);
        Serial.print(button_name); // debug
        Serial.print('\n');
        delay(pause);
        Keyboard.releaseAll();
    }
}

void loop()
{
    if (digitalRead(buttonA) == LOW)
    {
        button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_F1, buttonA);
    }
    if (digitalRead(buttonB) == LOW)
    {
        button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_F2, buttonB);
    }
    if (digitalRead(buttonC) == LOW)
    {
        button(0, 0, 0, buttonC);
    }
    if (digitalRead(buttonD) == LOW)
    {
        button(0, 0, 0, buttonD);
    }
    if (digitalRead(buttonE) == LOW)
    {
        button(0, 0, 0, buttonE);
    }
    if (digitalRead(buttonF) == LOW)
    {
        button(0, 0, 0, buttonF);
    }
    if (digitalRead(button) == LOW)
    {
        button(0, 0, 0, button);
    }
    if (digitalRead(buttonH) == LOW)
    {
        button(0, 0, 0, buttonH);
    }
}
