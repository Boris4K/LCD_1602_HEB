#include <LCD_1602_HEB.h>

LCD_1602_HEB lcd(0x27, 16, 2);
//some displays are 0x3F

void setup()
{
  lcd.init();                      // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(6,0);
  lcd.print(L"ךרע סנכה");
  // initialize the serial communications:
  Serial.begin(9600);
}

void loop() {
  unsigned char str;
  
  // when characters arrive over the serial port...
  if (Serial.available())
  {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    lcd.setCursor(0,0);
    // read all the available characters
    while (Serial.available() > 0)
    {
      // display each character to the LCD
      str = Serial.read();
      lcd.print(lcd.asciiutf8(str));//print to lcd by convert from ascii to utf
    }
    Serial.println();
  }
}
