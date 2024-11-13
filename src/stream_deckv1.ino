#include <Keyboard.h>

int buttonA = 9; // mikrophone
int buttonB = 8; // sound
int buttonC = 7; // camera
int buttonD = 6; // stream
int buttonE = 5; // record
int buttonF = 4; // none
int button = 3; // none
int buttonH = 2; // none
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
        button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_F1, buttonA); // microphone
    }
    if (digitalRead(buttonB) == LOW)
    {
        button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_F2, buttonB); // sound
    }
    if (digitalRead(buttonC) == LOW)
    {
        button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_F3, buttonC); // camera
    }
    if (digitalRead(buttonD) == LOW)
    {
        button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_F4, buttonD); // stream
    }
    if (digitalRead(buttonE) == LOW)
    {
        button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_F5, buttonE); // record
    }
    if (digitalRead(buttonF) == LOW)
    {
        button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_F6, buttonF);
    }
    if (digitalRead(button) == LOW)
    {
        button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_F7, button);
    }
    if (digitalRead(buttonH) == LOW)
    {
        button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_F8, buttonH);
    }
}
