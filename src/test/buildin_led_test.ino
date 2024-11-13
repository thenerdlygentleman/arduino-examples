int buildinLED = 13;

void setup()
{
    Serial.begin(9600);
    pinMode(buildinLED, OUTPUT);
}

void loop()
{
    digitalWrite(buildinLED, HIGH);
    Serial.println("LED on");
    delay(1000);
    digitalWrite(buildinLED, LOW);
    Serial.println("LED off");
    delay(1000);
}
