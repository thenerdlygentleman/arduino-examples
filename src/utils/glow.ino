int low = 0;       // how dark the LED is
int high = 255;    // how light the LED is
int delaytime = 5; // how fast the LED glows
int red;           // red LED
int redValue;      // red LED value
int blue;          // blue LED
int blueValue;     // blue LED Value
int green;         // green LED
int greenValue;    // green LED value

void glow(int light, int value)
{
  value = low; // set value to low
  for (int i = low; i < high; i += 1)
  {
    value += 1;
    analogWrite(light, value);
    delay(delaytime);
  }
  value = high; // set value to high
  for (int i = high; i > low; i -= 1)
  {
    value -= 1;
    analogWrite(light, value);
    delay(delaytime);
  }
}

void loop()
{
  glow(red, redValue) // change colour
}
