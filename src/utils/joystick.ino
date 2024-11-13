#include <Keyboard.h>

int SW_pin = 2; // digital pin connected to switch output
int X_pin = A0; // analog pin connected to X output
int Y_pin = A1; // analog pin connected to Y output
int x;
int y;
int var = 200;

void setup()
{
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
  Keyboard.begin();
  joystick_x(); // sets the start value for x, so it cannot be changed
  joystick_y(); // like x
}

void joystick_debug()
{
  Serial.print("B: ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y: ");
  Serial.print(analogRead(Y_pin));
  Serial.print("\n\n");
  delay(1000);
}

void joystick_x() // start value for the x-axis, value if there is no movement on the x- axis
{
  x = analogRead(X_pin);
  return x;
}

void joystick_y()
{
  y = analogRead(Y_pin); // start value like x
  return y;
}

void move(int x, int y, int var)
{
  if (x + var <= analogRead(X_pin)) // analogRead above 500, joystick up
  {
    Keyboard.press('w');
  }
  if (x - var >= analogRead(X_pin)) // analogRead below 500; joystick down
  {
    Keyboard.press('s');
  }
  if (y + var <= analogRead(Y_pin)) // analogRead above 500,  joystick right
  {
    Keyboard.press('d');
  }
  if (y - var >= analogRead(Y_pin)) // analog Read below 500, joystick left
  {
    Keyboard.press('a');
  }
}

void loop()
{
  move();
  Serial.print("x: ");
  Serial.print(x);
  Serial.print("\n");
  Serial.print("y: ");
  Serial.print(y);
  Serial.print("\n");
  joystick_debug();
}
