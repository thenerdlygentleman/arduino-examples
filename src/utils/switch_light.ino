int red;   // red LED
int blue;  // blue LED
int green; // green LED
int count; // counts how often the button is pushed
int light; // gives back the colour of the LED

void switch_light()
{
  if (digitalRead(button) == LOW)
  {
    count += 1; // count = count + 1
    delay(250); // wait
  }
  else if (count == 0)
  {
    light = red;
  }
  else if (count == 1)
  {
    light = blue;
  }
  else if (count == 2)
  {
    light = green;
  }
  else // if the button is pushed 3 times, it begins with red again
  {
    count = 0;
  }
  return light; // return light to the loop
}

void loop()
{
  switch_light(); // change light of RGB LED
  digitalWrite(light);
}
