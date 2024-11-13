int potentiometer = A0;
int potentiometer_value = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(potentiometer, INPUT);
}

void loop()
{
    potentiometer_value = map(analogRead(potentiometer), 0, 1023, 0, 255);
    Serial.print("Potentiometer value: ");
    Serial.println(potentiometer_value);
    delay(250);
}
