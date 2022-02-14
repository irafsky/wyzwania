// czas przejazdu robota

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);   // ustawienie adresu LCD na magistrali I2C 0x27 dla wyświetlacza - 16 znaków w 2 liniach

int przycisk_reset = 7;             // numer pinu arduino do podłączenia przycisku reset
int czujnik_start = 8;              // numer pinu arduino do podłączenia czujnika laserowego na starcie
int czujnik_meta = 9;               // numer pinu arduino do podłączenia czujnika laserowego na mecie
unsigned long czas_start;           // zapisanie czasu początku przejazdu
unsigned long timeStart, timeStop, timeElapsed; // czasy w funkcji zmieniajacej czas z milisekund na czas zrozumiały dla człowieka
int w = 0;                          // zmienna pomocnicza ustawiona na 0

void setup()                        // ustawienia początkowe dla programu
{
  lcd.init();                       // inicjalizacja wyświetlacza LCD 
  lcd.backlight();                  // wygaszenie wyświetlacza LCD
  lcd.setCursor(0,0);               // ustawienie kursora w pierwszej pozycji w pierwszym wierszu
  lcd.print("Wyscig 2019");     // wypisanie komunikatu
  lcd.setCursor(0,1);               // ustawienie kursora w pierwszej pozycji w pierwszym wierszu
  lcd.print("00:00:000");            // wypisanie komunikatu
  pinMode(czujnik_start, INPUT);    // ustawienie pinów jako wejść
  pinMode(czujnik_meta, INPUT);     // ustawienie pinów jako wejść
}

void loop()                         // początek pętli programu
{
  if (digitalRead(czujnik_start) == HIGH && w == 0) // sprawdzenie warunku czy czujnik start otrzymał impuls i czy zmienna 'w' równa się 0
    { 
      czas_start = millis();        // przypisanie do zmiennej aktualnej wartości wewnętrznego licznika
      w = 1;                        // zmienna pomocnicza ustawiona na 1
    }
  if (digitalRead(czujnik_meta) == LOW && w == 1)   // sprawdzenie warunku czy czujnik meta nie otrzymał impulsu i czy zmienna 'w' równa się 1
    { 
      lcd.setCursor(0,3);           // ustawienie kursora w pierwszej pozycji w drugim wierszu
      wyswietl_wynik(czas_start, millis()); // uruchomienie funkcji zmieniającej czas z milisekund na czas zrozumiały dla człowieka
    }
      else
       { 
         w = 0;                     // zmienna pomocnicza ustawiona na 0
       }
  if (digitalRead(przycisk_reset) == HIGH)  // sprawdzenie warunku czy przycisk reset otrzymał impuls
    { 
      lcd.setCursor(0,2);           // ustawienie kursora w pierwszej pozycji w pierwszym wierszu
      lcd.print("Czas przejazdu:"); // wypisanie komunikatu
      lcd.setCursor(0,3);           // ustawienie kursora w pierwszej pozycji w drugim wierszu
      lcd.print("00:00:000");        // wypisanie komunikatu
      w = 0;                        // zmienna pomocnicza ustawiona na 0
    }
}

void wyswietl_wynik(long timeStart, long timeStop)  // funkcja zmieniająca czas z milisekund na czas zrozumiały dla człowieka
{
  float h,m,s,ms;
  unsigned long over;
    timeElapsed = timeStop-timeStart;
//    h=int(timeElapsed/3600000);
    over=timeElapsed%3600000;
    m=int(over/60000);
    over=over%60000;
    s=int(over/1000);
    ms=(over%1000);
//      if(h>=0 and h<=9){lcd.print("0");}
//      lcd.print(h,3);
//      lcd.print(":");
      lcd.setCursor(0,3);
      if(m>=0 and m<=9){lcd.print("0");}
      lcd.print(m,0);
      lcd.print(":");
      if(s>=0 and s<=9){lcd.print("0");}
      lcd.print(s,0);
      lcd.print(":");
      if(ms>=0 and ms<=9){lcd.print("0");}
      lcd.print(ms,0);
}
