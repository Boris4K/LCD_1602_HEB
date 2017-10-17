#include "LCD_1602_HEB.h"

LCD_1602_HEB lcd(0x27, 16, 2);

void setup()
{
  lcd.init();                      // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print(L"םלוע םולש");
}

void loop()
{
}
