bool game_process(void) {
  if (!digitalRead(buttonPin3)) {
    delay(20);
    if (!digitalRead(buttonPin3)) {
      Serial.print("\82,133H");
      lcd.print("       1       ");
      startAllowed = 0; // запрет на новую игру
      return 1;

    }
  }
  if (!digitalRead(buttonPin4)) {
    delay(20);
    if (!digitalRead(buttonPin4)) {
      Serial.print("\82,123H");
      lcd.print("       2       ");
      startAllowed = 0; // запрет на новую игру
      return 1;

    }
  }
  if (!digitalRead(buttonPin5)) {
    delay(20);
    if (!digitalRead(buttonPin5)) {
      Serial.print("\82,113H");
      lcd.print("       3       ");
      startAllowed = 0; // запрет на новую игру
      return 1;

    }
  }
  if (!digitalRead(buttonPin6)) {
    delay(20);
    if (!digitalRead(buttonPin6)) {
      Serial.print("\82,103H");
      lcd.print("       4       ");
      startAllowed = 0; // запрет на новую игру
      return 1;

    }
  }
  if (!digitalRead(buttonPin7)) {
    delay(20);
    if (!digitalRead(buttonPin7)) {
      Serial.print("\82,135H");
      lcd.print("       6       ");
      startAllowed = 0; // запрет на новую игру
      return 1;

    }
  }
  if (!digitalRead(buttonPin8)) {
    delay(20);
    if (!digitalRead(buttonPin8)) {
      Serial.print("\82,125H");
      lcd.print("       7       ");
      startAllowed = 0; // запрет на новую игру
      return 1;

    }
  }
  if (!digitalRead(buttonPin9)) {
    delay(20);
    if (!digitalRead(buttonPin9)) {
      Serial.print("\82,115H");
      lcd.print("       8       ");
      startAllowed = 0; // запрет на новую игру
      return 1;

    }
  }
  if (!digitalRead(buttonPin10)) {
    delay(20);
    if (!digitalRead(buttonPin10)) {
      Serial.print("\82,105H");
      lcd.print("       9       ");
      startAllowed = 0; // запрет на новую игру
      return 1;

    }
  }
  return 0;
}//game_process()
