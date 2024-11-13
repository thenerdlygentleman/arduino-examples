int code[] = {1, 2, 3, 4};

void setup()
{
    Serial.begin(9600);
}

void print_array(int array[])

{
    Serial.print("\n"); // new line
    for (int x = 0; x < 4; x += 1)
    {
        Serial.print(array[x]);
    }
}

void loop()
{
    print_array(code); // print the code
    delay(5000);       // wait 5 seconds
}
