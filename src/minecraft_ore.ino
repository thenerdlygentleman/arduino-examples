int red = 11;
int blue = 10;
int green = 9;
int delaytime = 10;
int button = 12;
int light;
int value;
int count = 0;
int low = 150;
int high = 255;

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void switch_light()
{
  if (digitalRead(button) == LOW)
  {
    count += 1;
    delay(250);
  }
  if (count == 0)
  {
    light = red;
  }
  if (count == 1)
  {
    light = blue;
  }
  if (count == 2)
  {
    light = green;
  }
  if (count == 3)
  {
    light = red;
    count = 0;
  }
  return light;
}

void loop()
{
  value = low;
  for (int i = low; i < high; i += 1)
  {
    value += 1;
    analogWrite(light, value);
    switch_light(); // change light color
    delay(delaytime);
  }
  value = high;
  for (int i = high; i > low; i -= 1)
  {
    value -= 1;
    analogWrite(light, value);
    switch_light(); // change light color
    delay(delaytime);
  }
}
