#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN A0 // Define a ligação ao pino de dados do sensor
#define DHTTYPE DHT11 // Define o tipo de sensor DHT utilizado

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);  // Inicializa o display no endereço 0x27
DHT dht(DHTPIN, DHTTYPE); // Inicializa o DHT11 na porta A0

// Array simbolo grau
byte grau[8] ={ B00001100,
                B00010010,
                B00010010,
                B00001100,
                B00000000,
                B00000000,
                B00000000,
                B00000000,};

void setup() {
  lcd.begin(16,2);
  lcd.setBacklight(HIGH);
  lcd.createChar(0, grau);  // Cria o caractere customizado com o símbolo do grau
  dht.begin();
}

void loop() {
  float h = dht.readHumidity(); // Lê o valor da umidade
  float t = dht.readTemperature();  // Lê o valor da temperatura

  if (isnan(h) || isnan(t)) {
    lcd.home();
    lcd.print("Failed to read");
    lcd.setCursor(0,1);
    lcd.print("from DHT sensor!");
  }

  else {
    lcd.clear(); // Limpa o LCD
    lcd.home();
    lcd.print("Temp: ");
    lcd.setCursor(6,0);
    lcd.print(t,2);
    lcd.setCursor(11,0);
    lcd.write((byte)0); // Mostra o simbolo do grau formado pelo array

    lcd.setCursor(0,1);
    lcd.print("Umid: ");
    lcd.setCursor(6,1);
    lcd.print(h,2);
    lcd.setCursor(11,1);
    lcd.print("%");
  }
 
  // Intervalo recomendado para leitura do sensor
  delay(2000);
}
