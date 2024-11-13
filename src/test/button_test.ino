// pin 2 -> 10 k ohm resistor -> push button -> ground

int button = 2;
int led = 17;
int led_state = 1;

void setup()
{
    Serial.begin(9600);
    pinMode(button, INPUT_PULLUP);
    pinMode(led, OUTPUT);
    digitalWrite(led, HIGH);
    Serial.println("Initiate");
}

void loop()
{
    if (led_state < 0)
    {
        digitalWrite(led, LOW);
        Serial.println("Current state: ");
        Serial.println(led_state);
    }
    else if (led_state > 0)
    {
        digitalWrite(led, HIGH);
        Serial.println("Current state: ");
        Serial.println(led_state);
    }
    if (digitalRead(button == HIGH))
    {
        led_state = led_state * (-1);
        Serial.println("Button was pressed");
    }
    delay(500);
}
