

// include the library code:
#include <LiquidCrystal.h>
#include <Keyboard.h>

// initialize the library with the numbers of the interface pins
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int buttonPin1 = A1;          // input pin for pushbutton
// int previousButtonState1 = LOW;
int buttonPin2 = A2;          // input pin for pushbutton
//int previousButtonState2 = LOW;
int buttonPin3 = 0;
// int previousButtonState3 = LOW;
int buttonPin4 = 1;
//int previousButtonState4 = LOW;
int buttonPin5 = 2;
// int previousButtonState5 = LOW;
int buttonPin6 = 3;
//int previousButtonState6 = LOW;
int buttonPin7 = 10;
//int previousButtonState7 = LOW;
int buttonPin8 = 11;
//int previousButtonState8 = LOW;
int buttonPin9 = 12;
//int previousButtonState9 = LOW;
int buttonPin10 = 13;
//int previousButtonState10 = LOW;

byte startAllowed = 1; // флаг разрешения играть снова

void setup() {

  // make the pushButton pin an input:
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
  pinMode(buttonPin6, INPUT_PULLUP);
  pinMode(buttonPin7, INPUT_PULLUP);
  pinMode(buttonPin8, INPUT_PULLUP);
  pinMode(buttonPin9, INPUT_PULLUP);
  pinMode(buttonPin10, INPUT_PULLUP);

  digitalWrite(buttonPin1, HIGH);
  digitalWrite(buttonPin2, HIGH);
  digitalWrite(buttonPin3, HIGH);
  digitalWrite(buttonPin4, HIGH);
  digitalWrite(buttonPin5, HIGH);
  digitalWrite(buttonPin6, HIGH);
  digitalWrite(buttonPin7, HIGH);
  digitalWrite(buttonPin8, HIGH);
  digitalWrite(buttonPin9, HIGH);
  digitalWrite(buttonPin10, HIGH);

  // initialize control over the keyboard:
  Keyboard.begin();
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("The game :)");
  delay(4000);
  lcd.setCursor(0, 0);
  lcd.print("SHOW MUST GO ON ");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  //  lcd.print(millis()/1000);

  if (!digitalRead(buttonPin1)) {
    delay(20);
    if (!digitalRead(buttonPin1)) {
      Keyboard.print("5");
      Serial.print("\82,153H");
      lcd.print("       5       ");
      startAllowed = 1; // разрешить снова играть
      delay(3000);

      lcd.setCursor(0, 1);
      lcd.print("      READY     ");

    }
  }
  else if (!digitalRead(buttonPin2)) {
    delay(20);
    if (!digitalRead(buttonPin2)) {
      Keyboard.print("A");
      Serial.print("\82,155H");
      lcd.print("       A       ");
      startAllowed = 1; // разрешить снова играть
      delay(3000);

      lcd.setCursor(0, 1);
      lcd.print("      READY     ");

    }
  }

  if (startAllowed == 1) { // если играть разрешено
    // постоянно запускаем процедуру опроса кнопок.
    // она будет возвращать ноль, если ничего не нажато
    // как только она вернет единичку, окончим раунд.
    if (game_process() == 1) {
      startAllowed = 0;
    }
  }// if startAllowed
  /* код выше обычно пишут так
      но это не очень читабельно пока нет скила в кодинге
        if (startAllowed && game_process()) startAllowed = 0;
  */
}//loop
