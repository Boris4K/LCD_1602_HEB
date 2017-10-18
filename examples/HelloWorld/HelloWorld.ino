#include <LCD_1602_HEB.h>

LCD_1602_HEB lcd(0x27, 16, 2);
//some displays are 0x3F

void setup()
{
  lcd.init();                      // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(4, 0);
  lcd.print(L"םלוע םולש");
}

void loop()
{
}
