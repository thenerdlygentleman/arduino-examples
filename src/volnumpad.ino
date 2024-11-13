int col0 = 16;
int col1 = 15;
int col2 = 14;
int row0 = 8;
int row1 = 7;
int row2 = 6;

int column[3] = {col0, col1, col2};
int row[3] = {row0, row1, row2};

int matrix[3][3] = {{1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}};

int act_col;
int act_row;

int pause = 250;

void setup()
{
  Serial.begin(9600);
  pinMode(col0, OUTPUT);
  pinMode(col1, OUTPUT);
  pinMode(col2, OUTPUT);
  pinMode(row0, OUTPUT);
  pinMode(row1, OUTPUT);
  pinMode(row2, OUTPUT);
}

void loop()
{
  key_matrix();
}

void key_matrix() // function for finding our, which pins are active (--> button in the column/row is pressed)
{
  for (int i = 0; i < 3; i = i + 1) // loop for set column-pins in the state of HIGH
  {
    pinMode(column[i], INPUT_PULLUP); // set the current column as input --> makes it possible for the buttons in that column to begin pressed
    act_col = i;                      // variable which column is INPUT
    for (int j = 0; j < 3; j = j + 1) // second loop for checking which row is on high (--> button in this row is pressed)
    {
      if (digitalRead(row[j]) == HIGH)
      {
        act_row = j;                            // variable which row is HIGH
        Serial.print(matrix[act_row][act_col]); // debugging
        Serial.print('\n');
        delay(pause); // pause between the button pressed
      }
    }
    pinMode(column[i], OUTPUT); // deactives the current column
  }
}
