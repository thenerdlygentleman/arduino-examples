// streamdeck v2

#include <Keyboard.h>

// potentiometer
int pot = A10;
int pot_value = 0; // value of potentiometer
int set_num = 0;   // number of the active set

// leds
int blue_led = 3;
int red_led = 5;
int green_led = 6;
int yellow_led = 9;
int value_led = 0;
int high_value = 255; // max led value
int low_value = 0;    // min led value

// buttons
int buttonA = A0;
int buttonB = A1;
int buttonC = A2;
int buttonD = A3;

// delaytimes
int boot_time = 1000;
int glow_time = 5;
int button_time = 250;

void setup()
{
    Serial.begin(9600);
    // led setup
    pinMode(blue_led, OUTPUT);
    pinMode(red_led, OUTPUT);
    pinMode(green_led, OUTPUT);
    pinMode(yellow_led, OUTPUT);
    // buttons
    pinMode(buttonA, INPUT_PULLUP);
    pinMode(buttonB, INPUT_PULLUP);
    pinMode(buttonC, INPUT_PULLUP);
    pinMode(buttonD, INPUT_PULLUP);
    // boot code
    boot();
}

// booting function
void boot()
{
    // turn on all leds
    digitalWrite(blue_led, HIGH);
    delay(boot_time);
    digitalWrite(red_led, HIGH);
    delay(boot_time);
    digitalWrite(green_led, HIGH);
    delay(boot_time);
    digitalWrite(yellow_led, HIGH);
    delay(boot_time);
    // turn off all leds
    digitalWrite(blue_led, LOW);
    digitalWrite(red_led, LOW);
    digitalWrite(green_led, LOW);
    digitalWrite(yellow_led, LOW);
}

// main loop
void loop()
{
    digitalWrite(blue_led, LOW);
    digitalWrite(red_led, LOW);
    digitalWrite(green_led, LOW);
    digitalWrite(yellow_led, LOW);
    pot_value = map(analogRead(pot), 0, 1023, 0, 255); // change range of pot to the range of the pmw, 255*4=1023
    // Serial.print(pot_value); // debugging
    // Serial.print('\n'); // debugging
    if ((0 <= pot_value) && (pot_value <= 64))
    {
        set_num = 0;
        light = blue_led;
    }
    if ((65 <= pot_value) && (pot_value <= 128))
    {
        set_num = 1;
        light = red_led;
    }
    if ((129 <= pot_value) && (pot_value <= 192))
    {
        set_num = 2;
        light = green_led;
    }
    if ((193 <= pot_value) && (pot_value <= 255))
    {
        set_num = 3;
        light = yellow_led;
    }
    digitalWrite(light, HIGH);
    active_set(set_num);
}

//
void active_set(int set_num)
{
    if (set_num == 0)
    {
        // Serial.write('0'); // debugging
        // Serial.write('\n'); // debugging
        if (digitalRead(buttonA) == LOW)
        {
            button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_F1, 'button0A');
        }
        if (digitalRead(buttonB) == LOW)
        {
            button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_F2, 'button0B');
        }
        if (digitalRead(buttonC) == LOW)
        {
            button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_F3, 'button0C');
        }
        if (digitalRead(buttonD) == LOW)
        {
            button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_F4, 'button0D');
        }
    }
    if (set_num == 1)
    {
        // Serial.write('1'); // debugging
        // Serial.write('\n'); // debugging
        if (digitalRead(buttonA) == LOW)
        {
            button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_F5, 'button1A');
        }
        if (digitalRead(buttonB) == LOW)
        {
            button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_F6, 'button1B');
        }
        if (digitalRead(buttonC) == LOW)
        {
            button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_F7, 'button1C');
        }
        if (digitalRead(buttonD) == LOW)
        {
            button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_F8, 'button1D');
        }
    }
    if (set_num == 2)
    {
        // Serial.write('2'); // debugging
        // Serial.write('\n'); // debugging
        if (digitalRead(buttonA) == LOW)
        {
            button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_F9, 'button2A');
        }
        if (digitalRead(buttonB) == LOW)
        {
            button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_F10, 'button2B');
        }
        if (digitalRead(buttonC) == LOW)
        {
            button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_F11, 'button2C');
        }
        if (digitalRead(buttonD) == LOW)
        {
            button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_F12, 'button2D');
        }
    }
    if (set_num == 3)
    {
        // Serial.write('3'); // debugging
        // Serial.write('\n'); // debugging
        if (digitalRead(buttonA) == LOW)
        {
            button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, 1, 'button3A');
        }
        if (digitalRead(buttonB) == LOW)
        {
            button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, 2, 'button3B');
        }
        if (digitalRead(buttonC) == LOW)
        {
            button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, 3, 'button3C');
        }
        if (digitalRead(buttonD) == LOW)
        {
            button(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, 4, 'button3D');
        }
    }
}

// function that press the buttons
void button(int button1, int button2, int button3, int button_name)
{
    if (button3 == 0) // if only two buttons are required
    {
        Keyboard.press(button1);
        Keyboard.press(button2);
        Serial.write(button_name); // debug
        Serial.write('\n');
        delay(button_time);
        Keyboard.releaseAll();
    }
    else if (button3 == 0 && button2 == 0) // if only one button is required
    {
        Keyboard.press(button1);
        Serial.write(button_name); // debug
        Serial.write('\n');
        delay(button_time);
        Keyboard.releaseAll();
    }
    else if (button3 == 0 && button2 == 0 && button1 == 0) // if no button is assigned
    {
        Serial.print("nothing");
        delay(button_time);
    }
    else
    {
        Keyboard.press(button1);
        Keyboard.press(button2);
        Keyboard.press(button3);
        Serial.write(button_name); // debug
        Serial.write('\n');
        delay(button_time);
        Keyboard.releaseAll();
    }
}
