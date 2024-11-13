int red;        // red LED
int redValue;   // red LED value
int blue;       // blue LED
int blueValue;  // blue LED value
int green;      // green LED
int greenValue; // green LED value

void rgb(int redValue, int blueValue, int greenValue) // mix up the values of the LEDs
{
    analogWrite(red, redValue);
    analogWrite(blue, blueValue);
    analogWrite(green, greenValue);
}

void loop()
{
    rgb(0, 0, 0); // change the colour of the light by editing the values
}
