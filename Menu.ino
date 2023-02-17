#define KEY_NONE 0
#define KEY_PREV 1
#define KEY_NEXT 2
#define KEY_SELECT 3
#define KEY_BACK 4
#include <DHT.h>
#include <DHT_U.h>
#define dhtPin 2
#define DHTTYPE DHT11
#include "U8glib.h"

U8GLIB_ST7920_128X64_4X u8g(13, 11, 10);  // SPI Com: SCK = en = 18, MOSI = rw = 16, CS = di = 17

int UVOUT = A0;    //Output from the sensor
int REF_3V3 = A3;  //3.3V power on the Arduino board
int refLevel;
int uvLevel;
int outputVoltage;
int uvIntensity;

int SensorPin = A1;
int humidity;
float tempC;
int Final2 = 0;
int Final1 = 0;
float tempF;

DHT dht(dhtPin, DHTTYPE);

uint8_t uiKeyPrev = A2; //abajjo
uint8_t uiKeyNext = 3; //subir
uint8_t uiKeySelect = 4; //selecct

uint8_t uiKeyCodeFirst = KEY_NONE;
uint8_t uiKeyCodeSecond = KEY_NONE;
uint8_t uiKeyCode = KEY_NONE;

void tanque() {
  Final1 = digitalRead(7);
  Final2 = digitalRead(6);

  if ( Final1 == 1, Final2 == 0) {
    /* encedido de bomba de agua cuando el taque tenga agua */
    digitalWrite(12, HIGH);
  }
  else {
    digitalWrite(12, LOW);
  }
}

void Limonero() {

  Serial.println("LIMONERO");

  int humedad = analogRead(SensorPin);
  Serial.println(humedad);
  Serial.println(tempC);


  Serial.print("Humedad Relativa: ");
  Serial.print(humidity);
  Serial.print("% / Temperatura: ");
  Serial.print(tempC);
  Serial.print("ºC / ");
  Serial.print(tempF);
  Serial.println("ºF");

  Serial.print("output: ");
  Serial.print(refLevel);
  Serial.print("ML8511 output: ");
  Serial.print(uvLevel);
  Serial.print(" / ML8511 voltage: ");
  Serial.print(outputVoltage);
  Serial.print(" / UV Intensity (mW/cm^2): ");
  Serial.print(uvIntensity);

  if (humedad >= 460)
  {
    digitalWrite(12, LOW);
  }
  else
  {
    tanque();
  }

  u8g.firstPage();
  do
  {

    u8g.setFont(u8g_font_5x7);

    u8g.drawStr(0, 0, "LIMONERO");

    u8g.drawStr(0, 10, "Humedad:");
    char texto[7];
    itoa(humedad, texto, 10);
    u8g.drawStr(55, 10, texto);
    u8g.drawStr(70, 10, "%");

    u8g.drawStr(0, 20, "Temp.:");
    char Ctemp[7];
    itoa(tempC, Ctemp, 10);
    u8g.drawStr(60, 20, Ctemp);
    u8g.drawStr(75, 20, "°C");


    u8g.drawStr(0, 30, "UV Ray Intensity");
    char uv[7];
    itoa(uvIntensity, uv, 10);
    u8g.drawStr(40, 30, uv);
    u8g.drawStr(80, 30, "mW/cm^2");

    if (tempC > -5 && tempC < 30)
    {
      u8g.drawStr(0, 50, "Dejar la planta");
    }
    else
    {
      u8g.drawStr(0, 60, "Entrar la planta");
    }

    delay(500);
  } while (u8g.nextPage());

}

void Cerezo() {

  Serial.println("Cerezo");
  int humedad = analogRead(SensorPin);
  Serial.println(humedad);

  if (humedad >= 375)
  {
    digitalWrite(12, LOW);
  }
  else
  {
    tanque();
  }

  Serial.print("Humedad Relativa: ");
  Serial.print(humidity);
  Serial.print("% / Temperatura: ");
  Serial.print(tempC);
  Serial.print("ºC / ");
  Serial.print(tempF);
  Serial.println("ºF");

  Serial.print("output: ");
  Serial.print(refLevel);
  Serial.print("ML8511 output: ");
  Serial.print(uvLevel);
  Serial.print(" / ML8511 voltage: ");
  Serial.print(outputVoltage);
  Serial.print(" / UV Intensity (mW/cm^2): ");
  Serial.print(uvIntensity);


  u8g.firstPage();
  do {
    u8g.setFont(u8g_font_5x7);

    u8g.drawStr(0, 0, "Cerezo");

    u8g.drawStr(0, 10, "Humedad: ");
    char texto[7];
    itoa(humedad, texto, 10);
    u8g.drawStr(50, 10, texto);
    u8g.drawStr(60, 10, "%");

    u8g.drawStr(0, 20, "Temp.: ");
    char Ctemp[7];
    itoa(tempC, Ctemp, 10);
    u8g.drawStr(45, 20, Ctemp);
    u8g.drawStr(65, 20, "*C");

    u8g.drawStr(0, 30, "UV Ray Intensity");
    char uv[7];
    itoa(uvIntensity, uv, 10);
    u8g.drawStr(40, 30, uv);
    u8g.drawStr(80, 30, "mW/cm^2");

    if (tempC > 7 && tempC < 28)
    {
      u8g.drawStr(0, 50, "Dejar la planta");
    }
    else
    {
      u8g.drawStr(0, 60, "Entrar la planta");
    }

    delay(200);
  } while (u8g.nextPage());
}

void Lavanda() {

  Serial.println("Lavanda");
  int humedad = analogRead(SensorPin);
  Serial.println(humedad);


  Serial.print("Humedad Relativa: ");
  Serial.print(humidity);
  Serial.print("% / Temperatura: ");
  Serial.print(tempC);
  Serial.print("ºC / ");
  Serial.print(tempF);
  Serial.println("ºF");


  Serial.print("output: ");
  Serial.print(refLevel);
  Serial.print("ML8511 output: ");
  Serial.print(uvLevel);
  Serial.print(" / ML8511 voltage: ");
  Serial.print(outputVoltage);
  Serial.print(" / UV Intensity (mW/cm^2): ");
  Serial.print(uvIntensity);

  if (humedad >= 120) {
    digitalWrite(12, LOW);
  }
  else {
    tanque();
  }

  u8g.firstPage();
  do
  {
    u8g.setFont(u8g_font_5x7);

    u8g.drawStr(0, 10, "Lavanda");

    u8g.drawStr(0, 20, "Humedad: ");
    char texto[7];
    itoa(humedad, texto, 10);
    u8g.drawStr(50, 20, texto);
    u8g.drawStr(60, 20, "%");

    u8g.drawStr(0, 30, "Temp.:");
    char Ctemp[7];
    itoa(tempC, Ctemp, 10);
    u8g.drawStr(60, 30, Ctemp);
    u8g.drawStr(75, 30, "°C");

    u8g.drawStr(0, 30, "UV Ray Intensity");
    char uv[7];
    itoa(uvIntensity, uv, 10);
    u8g.drawStr(40, 30, uv);
    u8g.drawStr(80, 30, "mW/cm^2");

    if (tempC > -15 && tempC < 30) {
      u8g.drawStr(0, 50, "Dejar la planta");
    }
    else  {
      u8g.drawStr(0, 60, "Entrar la planta");
    }
    delay(100);
  } while (u8g.nextPage());
}

void Cactus() {

  Serial.println("Cactus");
  int humedad = analogRead(SensorPin);
  Serial.println(humedad);


  Serial.print("Humedad Relativa: ");
  Serial.print(humidity);
  Serial.print("% / Temperatura: ");
  Serial.print(tempC);
  Serial.print("ºC / ");
  Serial.print(tempF);
  Serial.println("ºF");

  Serial.print("output: ");
  Serial.print(refLevel);
  Serial.print("ML8511 output: ");
  Serial.print(uvLevel);
  Serial.print(" / ML8511 voltage: ");
  Serial.print(outputVoltage);
  Serial.print(" / UV Intensity (mW/cm^2): ");
  Serial.print(uvIntensity);


  if (humedad >= 50) {
    digitalWrite(12, LOW);
  } else {
    tanque();
  }

  u8g.firstPage();
  do
  {
    u8g.setFont(u8g_font_5x7);

    u8g.drawStr(0, 0, "Cactus");

    u8g.drawStr(0, 10, "Humedad: ");
    char texto[7];
    itoa(humedad, texto, 10);
    u8g.drawStr(50, 10, texto);
    u8g.drawStr(60, 10, "%");

    u8g.drawStr(0, 20, "Temp.:");
    char Ctemp[7];
    itoa(tempC, Ctemp, 10);
    u8g.drawStr(60, 20, Ctemp);
    u8g.drawStr(75, 20, "°C");

    u8g.drawStr(0, 30, "UV Ray Intensity");
    char uv[7];
    itoa(uvIntensity, uv, 10);
    u8g.drawStr(40, 30, uv);
    u8g.drawStr(80, 30, "mW/cm^2");

    if (tempC > 7) {
      u8g.drawStr(0, 50, "Dejar la planta");
    }
    else  {
      u8g.drawStr(0, 60, "Entrar la planta");
    }

    delay(100);

  } while (u8g.nextPage());
}

void Frutillas() {

  Serial.println("Frutillas");
  int humedad = analogRead(SensorPin);
  Serial.println(humedad);


  Serial.print("Humedad Relativa: ");
  Serial.print(humidity);
  Serial.print("% / Temperatura: ");
  Serial.print(tempC);
  Serial.print("ºC / ");
  Serial.print(tempF);
  Serial.println("ºF");

  Serial.print("output: ");
  Serial.print(refLevel);
  Serial.print("ML8511 output: ");
  Serial.print(uvLevel);
  Serial.print(" / ML8511 voltage: ");
  Serial.print(outputVoltage);
  Serial.print(" / UV Intensity (mW/cm^2): ");
  Serial.print(uvIntensity);


  if (humedad >= 120) {
    digitalWrite(12, LOW);
  }
  else {
    tanque();
  }

  u8g.firstPage();
  do {
    u8g.setFont(u8g_font_5x7);

    u8g.drawStr(0, 10, "Frutillas");

    u8g.drawStr(0, 20, "Humedad: ");
    char texto[7];
    itoa(humedad, texto, 10);
    u8g.drawStr(50, 20, texto);
    u8g.drawStr(60, 20, "%");

    u8g.drawStr(0, 30, "Temp.:");
    char Ctemp[7];
    itoa(tempC, Ctemp, 10);
    u8g.drawStr(60, 30, Ctemp);
    u8g.drawStr(75, 30, "°C");


    u8g.drawStr(0, 30, "UV Ray Intensity");
    char uv[7];
    itoa(uvIntensity, uv, 10);
    u8g.drawStr(40, 30, uv);
    u8g.drawStr(80, 30, "mW/cm^2");


    if (tempC > -15 && tempC < 30) {
      u8g.drawStr(0, 40, "Dejar la planta");
    }
    else  {
      u8g.drawStr(0, 50, "Entrar la planta");
    }
    delay(150);
  } while (u8g.nextPage());

}


void uiSetup(void) {
  // configure input keys

  pinMode(uiKeyPrev, INPUT_PULLUP);    // set pin to input with pullup
  pinMode(uiKeyNext, INPUT_PULLUP);    // set pin to input with pullup
  pinMode(uiKeySelect, INPUT_PULLUP);  // set pin to input with pullup
}

void uiStep(void) {

  uiKeyCodeSecond = uiKeyCodeFirst;
  if (digitalRead(uiKeyPrev) == LOW)
    uiKeyCodeFirst = KEY_PREV;
  else if (digitalRead(uiKeyNext) == LOW)
    uiKeyCodeFirst = KEY_NEXT;
  else if (digitalRead(uiKeySelect) == LOW)
    uiKeyCodeFirst = KEY_SELECT;
  else
    uiKeyCodeFirst = KEY_NONE;

  if (uiKeyCodeSecond == uiKeyCodeFirst)
    uiKeyCode = uiKeyCodeFirst;
  else
    uiKeyCode = KEY_NONE;
}


#define MENU_ITEMS 5
const char *menu_strings[MENU_ITEMS] = { "Limonero", "Cerezo", "Cactus", "Lavanda", "Frutillas" };
uint8_t menu_redraw_required = 0;

uint8_t menu_current = 0;
uint8_t last_key_code = KEY_NONE;


void drawMenu(void) {
  uint8_t i, h;
  uint8_t w, d;  //u8g_font_6x13 ; u8g_fntpgm_uint8_t[] ; u8g_font_unifont
  u8g.setFont(u8g_font_6x13);
  u8g.setFontRefHeightText();
  u8g.setFontPosTop();
  h = u8g.getFontAscent() - u8g.getFontDescent();
  w = u8g.getWidth();

  for (i = 0; i < MENU_ITEMS; i++)
  {
    d = (w - u8g.getStrWidth(menu_strings[i])) / 2;
    u8g.setDefaultForegroundColor();
    if (i == menu_current) {
      u8g.drawBox(0, i * h + 1, w, h);
      u8g.setDefaultBackgroundColor();
    }
    u8g.drawStr(d, i * h, menu_strings[i]);


  }

}

void updateMenu(void) {

  if (uiKeyCode != KEY_NONE && last_key_code == uiKeyCode) {
    return;
  }

  last_key_code = uiKeyCode;

  switch (uiKeyCode)
  {
    case KEY_NEXT:
      menu_current++;
      if (menu_current >= MENU_ITEMS)
        menu_current = 0;
      menu_redraw_required = 1;
      break;
    case KEY_PREV:
      if (menu_current == 0)
        menu_current = MENU_ITEMS;
      menu_current--;
      menu_redraw_required = 1;
      break;

    case KEY_SELECT:
      menu_redraw_required = 1;
      while (1)
      {

        switch (menu_current)
        {
          case 0:
            Limonero();
            break;

          case 1:
            Cerezo();
            break;

          case 2:
            Cactus();
            break;

          case 3:
            Lavanda();
            break;

          case 4:
            Frutillas();
            break;
        }
      }
      break;
  }
}



void setup() {
  pinMode(12, OUTPUT);
  pinMode(7, INPUT);
  pinMode(6, INPUT);

  pinMode(UVOUT, INPUT);
  pinMode(REF_3V3, INPUT);

  Serial.begin(9600);
  Serial.println("Hola");
  uiSetup();  // setup key detection and debounce algorithm
  menu_redraw_required = 1;
  dht.begin();  // force initial redraw
}

void loop()
{
  int uvLevel = analogRead(UVOUT);
  int refLevel = analogRead(REF_3V3);
  //Use the 3.3V power pin as a reference to get a very accurate output value from sensor
  float outputVoltage = 3.3 / refLevel * uvLevel;
  float uvIntensity = map (outputVoltage, 0.99, 2.8, 0.0, 15.0);  //Convert the voltage to a UV intensity level

  humidity = dht.readHumidity();
  tempC = dht.readTemperature();
  uiStep();  // check for key press
  updateMenu();
  if (menu_redraw_required != 0)
  {
    u8g.firstPage();
    do {

      drawMenu();

    } while (u8g.nextPage());
    menu_redraw_required = 0;
  }


}
