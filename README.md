# LCD_1602_HEB
Library for hebrew font text on LCD 16x2 for Arduino, via I2C.
Based on Sergey Sorotik library.

# LCD_1602_RUS
(Original Readme file)
Arduino LCD 16x02 display with I2C interface RUSSIAN with NO CYRILLIC symbols set

Библиотека позволяет использовать русские символы при использовании LCD дисплеев, подключенных по интерфейсу I2C, без встроенной кириллицы.
Максимально возможно отображение 8 уникальных по начертанию русских символа (например Ж, Д, И, Ю и т.п.)
Символы, одинаковые по начертанию с английскими (A, B, C, O, P и т.п.) используются из английского набора символов.
Дополнительно встроена возможность печати знака градуса Цельсия. Для этого в тексте программы необходимо набрать
код UTF-8 (Alt+0176)

Должна быть установелна базовая библиотека LiquidCrystal_I2C: https://github.com/marcoschwartz/LiquidCrystal_I2C

(c) Сергей Сироткин
По вопросам обращаться:
ssilver2007@rambler.ru
