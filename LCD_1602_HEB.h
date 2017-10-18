#include "LiquidCrystal_I2C.h"
#include "Print.h"

#define MAX_SYMBOL_COUNT 8  //Максимальное количество переназначаемых символов от 0 до 7
#define BYTE 0

class LCD_1602_HEB : public LiquidCrystal_I2C {
public:
	LCD_1602_HEB(uint8_t, uint8_t, uint8_t);
	void print(const wchar_t[]);
	void print(const char[]);
  void print(int, int = DEC);
  void print(unsigned int, int = DEC);
  void print(long, int = DEC);
  void print(unsigned long, int = DEC);
  void print(const String &);
  void print(char, int = BYTE);
  void print(unsigned char, int = BYTE);
  void print(double, int = 2);
  void clear();
	void setCursor(uint8_t, uint8_t); 
	uint8_t getCursorCol(); 
	uint8_t getCursorRow(); 
  wchar_t *asciiutf8(unsigned char);

private:
  void CharSetToLCD(uint8_t *, uint8_t *);
  void ResetAllIndex();
  void printwc(const wchar_t);
  uint8_t mbtowc(wchar_t *, char *, uint8_t);

  int symbol_index;//Индекс символа (от 0 до 7)
  uint8_t cursor_col;
  uint8_t cursor_row;
  //===אותיות====
  uint8_t index_heb_alef;
  uint8_t index_heb_bet;
  uint8_t index_heb_gimel;
  uint8_t index_heb_dalet;
  uint8_t index_heb_hey;
  uint8_t index_heb_vav;
  uint8_t index_heb_zain;
  uint8_t index_heb_het;
  uint8_t index_heb_tet;
  uint8_t index_heb_yod;
  uint8_t index_heb_kaf_sofit;
  uint8_t index_heb_kaf;
  uint8_t index_heb_lamed;
  uint8_t index_heb_mem_sofit;
  uint8_t index_heb_mem;
  uint8_t index_heb_nun_sofit;
  uint8_t index_heb_nun;
  uint8_t index_heb_samech;
  uint8_t index_heb_ayin;
  uint8_t index_heb_peh_sofit;
  uint8_t index_heb_peh;
  uint8_t index_heb_zadik_sofit;
  uint8_t index_heb_zadik;
  uint8_t index_heb_kuf;
  uint8_t index_heb_resh;
  uint8_t index_heb_shin;
  uint8_t index_heb_tav;
};

extern const byte heb_alef[];
extern const byte heb_bet[];
extern const byte heb_gimel[];
extern const byte heb_dalet[];
extern const byte heb_hey[];
extern const byte heb_vav[];
extern const byte heb_zain[];
extern const byte heb_het[];
extern const byte heb_tet[];
extern const byte heb_yod[];
extern const byte heb_kaf_sofit[];
extern const byte heb_kaf[];
extern const byte heb_lamed[];
extern const byte heb_mem_sofit[];
extern const byte heb_mem[];
extern const byte heb_nun_sofit[];
extern const byte heb_nun[];
extern const byte heb_samech[];
extern const byte heb_ayin[];
extern const byte heb_peh_sofit[];
extern const byte heb_peh[];
extern const byte heb_zadik_sofit[];
extern const byte heb_zadik[];
extern const byte heb_kuf[];
extern const byte heb_resh[];
extern const byte heb_shin[];
extern const byte heb_tav[];
extern wchar_t char_utf8[];
