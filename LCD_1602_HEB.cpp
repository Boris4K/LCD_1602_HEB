#include <arduino.h>
#include <avr/pgmspace.h>
#include "LCD_1602_HEB.h"

LCD_1602_HEB :: LCD_1602_HEB(uint8_t lcd_Addr,uint8_t lcd_cols,uint8_t lcd_rows) : LiquidCrystal_I2C (lcd_Addr, lcd_cols, lcd_rows)
{
   symbol_index = 0;
   ResetAllIndex();//Сброс значений индексов (неинициализированы = 255)
}
void LCD_1602_HEB::clear()
{
    LiquidCrystal_I2C::clear();
    ResetAllIndex();
}
void LCD_1602_HEB::setCursor(uint8_t col, uint8_t row)
{
    cursor_col = col;
    cursor_row = row;
    LiquidCrystal_I2C::setCursor(cursor_col, cursor_row);
}
uint8_t LCD_1602_HEB::getCursorCol()
{
  return cursor_col;
}
uint8_t LCD_1602_HEB::getCursorRow()
{
  return cursor_row;
}
void LCD_1602_HEB::print(const char *str){
	cursor_col += LiquidCrystal_I2C::print(str);
}
void LCD_1602_HEB::print(int val, int base){
  cursor_col += LiquidCrystal_I2C::print(val, base);
}
void LCD_1602_HEB::print(unsigned int val, int base){
  cursor_col += LiquidCrystal_I2C::print(val, base);
}
void LCD_1602_HEB::print(long val, int base){
  cursor_col += LiquidCrystal_I2C::print(val, base);
}
void LCD_1602_HEB::print(unsigned long val, int base){
  cursor_col += LiquidCrystal_I2C::print(val, base);
}
void LCD_1602_HEB::print(char val, int base){
  cursor_col += LiquidCrystal_I2C::print(val, base);
}
void LCD_1602_HEB::print(unsigned char val, int base){
  cursor_col += LiquidCrystal_I2C::print(val, base);
}
void LCD_1602_HEB::print(const String &str){
  cursor_col += LiquidCrystal_I2C::print(str);
}
void LCD_1602_HEB::print(double val, int base){
  cursor_col += LiquidCrystal_I2C::print(val, base);
}
void LCD_1602_HEB::print(const wchar_t *_str){
  uint8_t heb_[8];
  int current_char  = 0;
  int size = 0;
 
  //Определяем длину строки (количество символов)
  while(_str[size] != NULL)
  {
    size++;
  }
  
  while(current_char < size)
  {
    switch(_str[current_char])
    {
      //Русский алфавит, требующий новых символов
      //Единовременно может быть заменено только 8 символов
      case 0x05D0: //א
        memcpy_PF(heb_, (uint32_t)heb_alef, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_alef);
      break;
      case 0x05D1: //ב
        memcpy_PF(heb_, (uint32_t)heb_bet, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_bet);
      break;
      case 0x05D2: //ג
        memcpy_PF(heb_, (uint32_t)heb_gimel, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_gimel);
      break;
      case 0x05D3: //ד
        memcpy_PF(heb_, (uint32_t)heb_dalet, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_dalet);
      break;
      case 0x05D4: //ה
        memcpy_PF(heb_, (uint32_t)heb_hey, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_hey);
      break;
      case 0x05D5: //ו
        memcpy_PF(heb_, (uint32_t)heb_vav, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_vav);
      break;
      case 0x05D6: //ז
        memcpy_PF(heb_, (uint32_t)heb_zain, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_zain);
      break;
      case 0x05D7: //ח
        memcpy_PF(heb_, (uint32_t)heb_het, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_het);
      break;
      case 0x05D8: //ט
        memcpy_PF(heb_, (uint32_t)heb_tet, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_tet);
      break;
      case 0x05D9: //י
        memcpy_PF(heb_, (uint32_t)heb_yod, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_yod);
      break;
      case 0x05DA: //ך
        memcpy_PF(heb_, (uint32_t)heb_kaf_sofit, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_kaf_sofit);
      break;
      case 0x05DB: //כ
        memcpy_PF(heb_, (uint32_t)heb_kaf, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_kaf);
      break;
      case 0x05DC: //ל
        memcpy_PF(heb_, (uint32_t)heb_lamed, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_lamed);
      break;
      case 0x05DD: //ם
        memcpy_PF(heb_, (uint32_t)heb_mem_sofit, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_mem_sofit);
      break;
      case 0x05DE: //מ
        memcpy_PF(heb_, (uint32_t)heb_mem, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_mem);
      break;
      case 0x05DF: //ן nun sofit
        memcpy_PF(heb_, (uint32_t)heb_nun_sofit, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_nun_sofit);
      break;
      case 0x05E0: //נ
        memcpy_PF(heb_, (uint32_t)heb_nun, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_nun);
      break;
      case 0x05E1: //ס
        memcpy_PF(heb_, (uint32_t)heb_samech, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_samech);
      break;
      case 0x05E2: //ע
        memcpy_PF(heb_, (uint32_t)heb_ayin, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_ayin);
      break;
      case 0x05E3: //ף
        memcpy_PF(heb_, (uint32_t)heb_peh_sofit, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_peh_sofit);
      break;
      case 0x05E4: //פ
        memcpy_PF(heb_, (uint32_t)heb_peh, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_peh);
      break;
      case 0x05E5: //zadik sofit
        memcpy_PF(heb_, (uint32_t)heb_zadik_sofit, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_zadik_sofit);
      break;
      case 0x05E6: //צ
        memcpy_PF(heb_, (uint32_t)heb_zadik, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_zadik);
      break;
      case 0x05E7: //ק
        memcpy_PF(heb_, (uint32_t)heb_kuf, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_kuf);
      break;
      case 0x05E8: //ר
        memcpy_PF(heb_, (uint32_t)heb_resh, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_resh);
      break;
      case 0x05E9: //ש
        memcpy_PF(heb_, (uint32_t)heb_shin, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_shin);
      break;
      case 0x05EA: //ת
        memcpy_PF(heb_, (uint32_t)heb_tav, 8);
        CharSetToLCD((uint8_t *)heb_, &index_heb_tav);
      break;
      case 0x00B0: //Знак градуса
        LiquidCrystal_I2C::write(223);
      break;
      //Английский алфавит без изменения
      default:
        LiquidCrystal_I2C::print((char)_str[current_char]);
      break;
    }
    current_char++;
    cursor_col++;
  }
 
}
void LCD_1602_HEB::CharSetToLCD(uint8_t *array, uint8_t *index)
{
  uint8_t x,y;

  if(*index == 255)// Если символ еще не создан, то создаем
  {
    x = getCursorCol();
    y = getCursorRow();
    createChar(symbol_index, (uint8_t *)array);// Создаем символ на текущем (по очереди) месте в знакогенераторе (от 0 до MAX_SYMBOL_COUNT)
    setCursor(x,y);
    write(symbol_index);// Выводим символ на экран
    //Запомианем, что букве соответствует определенный индекс
    *index = symbol_index;
    symbol_index++;
    if(symbol_index >= MAX_SYMBOL_COUNT)
    	symbol_index = 0;
  }
  else   //Иначе печатаем уже существующий
    write(*index);
}
void LCD_1602_HEB::ResetAllIndex()
{
  index_heb_alef=255;
  index_heb_bet=255;
  index_heb_gimel=255;
  index_heb_dalet=255;
  index_heb_hey=255;
  index_heb_vav=255;
  index_heb_zain=255;
  index_heb_het=255;
  index_heb_tet=255;
  index_heb_yod=255;
  index_heb_kaf_sofit=255;
  index_heb_kaf=255;
  index_heb_lamed=255;
  index_heb_mem_sofit=255;
  index_heb_mem=255;
  index_heb_nun_sofit=255;
  index_heb_nun=255;
  index_heb_samech=255;
  index_heb_ayin=255;
  index_heb_peh_sofit=255;
  index_heb_peh=255;
  index_heb_zadik_sofit=255;
  index_heb_zadik=255;
  index_heb_kuf=255;
  index_heb_resh=255;
  index_heb_shin=255;
  index_heb_tav=255;
}
//Б
const byte heb_alef[8] PROGMEM = {
  0b00000,
  0b10010,
  0b01010,
  0b10100,
  0b10010,
  0b10001,
  0b10001,
  0b00000
};
//Г
const byte heb_bet[8] PROGMEM = {
  0b00000,
  0b11110,
  0b00010,
  0b00010,
  0b00010,
  0b00010,
  0b11111,
  0b00000
};
//Д
const byte heb_gimel[8] PROGMEM = {
  0b00000,
  0b01110,
  0b00010,
  0b00110,
  0b01010,
  0b10010,
  0b10010,
  0b00000
};
//Ж
const byte heb_dalet[8] PROGMEM = {
  0b00000,
  0b11111,
  0b00010,
  0b00010,
  0b00010,
  0b00010,
  0b00010,
  0b00000
};
//З
const byte heb_hey[8] PROGMEM = {
  0b00000,
  0b11111,
  0b00001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b00000
};
//И
const byte heb_vav[8] PROGMEM = {
  0b00000,
  0b01100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00000
};
//Й
const byte heb_zain[8] PROGMEM = {
  0b11000,
  0b00110,
  0b00101,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00000
};
//Л
const byte heb_het[8] PROGMEM = {
  0b00000,
  0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b00000
};
//П
const byte heb_tet[8] PROGMEM = {
  0b00000,
  0b10111,
  0b10101,
  0b10001,
  0b10001,
  0b10001,
  0b11111,
  0b00000
};
//У
const byte heb_yod[8] PROGMEM = {
  0b00000,
  0b01110,
  0b00010,
  0b00010,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
//Ф
const byte heb_kaf_sofit[8] PROGMEM = {
  0b00000,
  0b11111,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001
};
//Ц
const byte heb_kaf[8] PROGMEM = {
  0b00000,
  0b11111,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b11111,
  0b00000
};
//Ч
const byte heb_lamed[8] PROGMEM = {
  0b01000,
  0b01000,
  0b01111,
  0b00001,
  0b00001,
  0b00001,
  0b01110,
  0b00000
};
//Щ
const byte heb_mem_sofit[8] PROGMEM = {
  0b00000,
  0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b11111,
  0b00000
};
//Ъ
const byte heb_mem[8] PROGMEM = {
  0b01000,
  0b00111,
  0b01001,
  0b10001,
  0b00001,
  0b00001,
  0b11111,
  0b00000
};
//Ы
const byte heb_nun_sofit[8] PROGMEM = {
  0b00000,
  0b00111,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001
};
//Ь
const byte heb_nun[8] PROGMEM = {
  0b00000,
  0b00111,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b11111,
  0b00000
};
//Э
const byte heb_samech[8] PROGMEM = {
  0b00000,
  0b01110,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b01110,
  0b00000
};
//Ю
const byte heb_ayin[8] PROGMEM = {
  0b00000,
  0b01001,
  0b01001,
  0b01001,
  0b01001,
  0b01001,
  0b11111,
  0b00000
};
//Я
const byte heb_peh_sofit[8] PROGMEM = {
  0b00000,
  0b11111,
  0b10001,
  0b11101,
  0b00001,
  0b00001,
  0b00001,
  0b00001
};
const byte heb_peh[8] PROGMEM = {
  0b00000,
  0b11111,
  0b10001,
  0b11101,
  0b00001,
  0b00001,
  0b11111,
  0b00000
};//б
const byte heb_zadik_sofit[8] PROGMEM = {
  0b00000,
  0b10001,
  0b01010,
  0b00100,
  0b00010,
  0b00001,
  0b00001,
  0b00001
};//в
const byte heb_zadik[8] PROGMEM = {
  0b00000,
  0b10001,
  0b01010,
  0b00100,
  0b00010,
  0b00001,
  0b11111,
  0b00000
};//в
const byte heb_kuf[8] PROGMEM = {
  0b00000,
  0b11111,
  0b00001,
  0b01001,
  0b01001,
  0b01000,
  0b01000,
  0b01000
};//г
const byte heb_resh[8] PROGMEM = {
  0b00000,
  0b11111,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00000
};//д
const byte heb_shin[8] PROGMEM = {
  0b00000,
  0b10101,
  0b10101,
  0b10101,
  0b10101,
  0b10101,
  0b11111,
  0b00000
};//ё
const byte heb_tav[8] PROGMEM = {
  0b00000,
  0b01111,
  0b01001,
  0b01001,
  0b01001,
  0b01001,
  0b11001,
  0b00000
};//ж
