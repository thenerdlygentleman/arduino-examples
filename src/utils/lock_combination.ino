// requires 16x2 LCD display, RGB LED, 4 buttons and servo motor

#include <LiquidCrystal.h>
#include <Servo.h>

Servo servo; // create servo object

int button1 = A0; // combination button1
int button2 = A1; // combination button2
int button3 = A2; // combination button3
int button4 = A4; // combination button4

int servpos = 0; // servo position

int red = 2;   // red LED
int green = 4; // green LED
int blue = 5;  // blue LED

int rs = 6;  // LCD rs pin
int e = 7;   // LCD e pin
int d4 = 8;  // LCD d4 pin
int d5 = 9;  // LCD d5 pin
int d6 = 10; // LCD d6 pin
int d7 = 11; // LCD d7 pin

int code[] = {4, 1, 3, 2}; // code to open the lock
int input[4];              // code input of the user

LiquidCrystal lcd(rs, e, d4, d5, d6, d7); // pins of the LCD

void setup()
{
    Serial.begin(9600); // begin serial
    lcd.begin(16, 2);   // size of lcd
    servo.attach(3);    // servo on pin 3
    pinMode(red, OUTPUT);
    pinMode(blue, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(button1, INPUT_PULLUP);
    pinMode(button2, INPUT_PULLUP);
    pinMode(button3, INPUT_PULLUP);
    pinMode(button4, INPUT_PULLUP);
}

void print_array(int array[]) // debugging by printing the code
{
    Serial.print("\n"); // new line
    for (int x = 0; x < 4; x += 1)
    {
        Serial.print(array[x]);
    }
}

void blink_LED(int LED) // blinking LED function
{
    for (int i = 0; i < 3; i += 1) // blinks 3-times
    {
        digitalWrite(LED, HIGH); // turn on LED
        delay(250);              // wait
        digitalWrite(LED, LOW);  // turn off LED
        delay(250);              // wait
    }
}

void code_input() // generate input array
{

    for (int j = 0; j < 4;) // four inputs
    {
        if (digitalRead(button1) == LOW) // if button1 is pressed
        {
            input[j] = 1;           // set one in the position of input[j]
            Serial.print(input[j]); // debugging
            j += 1;                 // j = j + 1
            delay(250);             // wait
        }

        else if (digitalRead(button2) == LOW) // if button2 is pressed
        {
            input[j] = 2;           // set two in the position of input[j]
            Serial.print(input[j]); // debugging
            j += 1;                 // j = j + 1
            delay(250);             // wait
        }

        else if (digitalRead(button3) == LOW) // if button3 is pressed
        {
            input[j] = 3;           // set three in the position of input[j]
            Serial.print(input[j]); // debugging
            j += 1;                 // j = j + 1
            delay(250);             // wait
        }

        else if (digitalRead(button4) == LOW) // if button4 is pressed
        {
            input[j] = 4;           // set four in the position of input[j]
            Serial.print(input[j]); // debugging
            j += 1;                 // j = j + 1
            delay(250);             // wait
        }
    }
}

void check_code() // compare input with code
{
    if (code[0] == input[0] && code[1] == input[1] && code[2] == input[2] && code[3] == input[3]) // input is correct
    {
        lcd.print("access granted"); // right text
        blink_LED(green);           // green LED is blinking
        open_safe();
        lcd.clear(); // clear LCD display
    }

    else // input is wrong
    {
        lcd.print("access denied"); // false text
        blink_LED(red);            // red LED is blinking
        digitalWrite(blue, HIGH);
        delay(3000);
        digitalWrite(blue, LOW);
        lcd.clear(); // clear LCD
    }
}

void open_safe()
{
    digitalWrite(blue, HIGH);                      // turn blue LED on
    for (servpos = 0; servpos < 180; servpos += 1) // move servo for 180 degree
    {
        servo.write(servpos); // move the servo at servpos
        delay(15);            // wait
    }
    digitalWrite(blue, LOW); // turn off blue LED
}

void loop()
{
    code_input();       // input the code
    check_code();       // compare code with input
    print_array(code);  // print code - debugging
    print_array(input); // print input - debugging
    Serial.print("\n"); // new line - debugging
}
