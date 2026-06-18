#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>

#define DHTPIN 2
#define DHTTYPE DHT22
#define MQ135PIN A0
#define CHUVAPIN A1
#define VENTOPIN A2

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Adafruit_BME280 bme;

unsigned long ultimaAtualizacao = 0;
int ecraAtual = 0;
const long intervalo = 3000;

void setup() {
  Serial.begin(9600);
  dht.begin();

  lcd.init();
  lcd.backlight();

  if (!bme.begin(0x76)) {
    lcd.setCursor(0, 0);
    lcd.print("BME280 erro!");
    while (1);
  }

  lcd.setCursor(0, 0);
  lcd.print("Atmosense");
  lcd.setCursor(0, 1);
  lcd.print("A iniciar...");
  delay(3000);
  lcd.clear();
}

void loop() {
  unsigned long agora = millis();

  if (agora - ultimaAtualizacao >= intervalo) {
    ultimaAtualizacao = agora;

    // Lê todos os sensores
    float humidade = dht.readHumidity();
    float temperatura = dht.readTemperature();
    int valorAr = analogRead(MQ135PIN);
    float pressao = bme.readPressure() / 100.0F;
    int valorChuva = analogRead(CHUVAPIN);
    int rawVento = analogRead(VENTOPIN);
    int valorBase = 519;
int rawCorrigido = rawVento - valorBase;
if (rawCorrigido < 0) rawCorrigido = 0;
float velocidade = (rawCorrigido / 504.0) * 30.0;

    // Qualidade do ar
    String qualidade;
    if (valorAr < 200) qualidade = "Mto limpo";
    else if (valorAr < 400) qualidade = "Bom";
    else if (valorAr < 600) qualidade = "Moderado";
    else if (valorAr < 800) qualidade = "Mau";
    else qualidade = "Mto mau!";

// Classificação da chuva ajustada para o teu sensor
String chuva;
if (valorChuva > 650) chuva = "Sem chuva";
else if (valorChuva > 450) chuva = "Chuva leve";
else if (valorChuva > 250) chuva = "Chuva media";
else chuva = "Chuva forte";

    lcd.clear();

    if (ecraAtual == 0) {
      // Ecrã 1: Temperatura e Humidade
      lcd.setCursor(0, 0);
      if (isnan(temperatura)) {
        lcd.print("Temp: Erro");
      } else {
        lcd.print("Temp: ");
        lcd.print(temperatura, 1);
        lcd.print((char)223);
        lcd.print("C");
      }
      lcd.setCursor(0, 1);
      if (isnan(humidade)) {
        lcd.print("Hum: Erro");
      } else {
        lcd.print("Hum: ");
        lcd.print(humidade, 1);
        lcd.print("%");
      }

    } else if (ecraAtual == 1) {
      // Ecrã 2: Qualidade do ar
      lcd.setCursor(0, 0);
      lcd.print("Ar: ");
      lcd.print(valorAr);
      lcd.setCursor(0, 1);
      lcd.print(qualidade);

    } else if (ecraAtual == 2) {
      // Ecrã 3: Pressão atmosférica
      lcd.setCursor(0, 0);
      lcd.print("Pressao:");
      lcd.setCursor(0, 1);
      lcd.print(pressao, 1);
      lcd.print(" hPa");

    } else if (ecraAtual == 3) {
      // Ecrã 4: Chuva
      lcd.setCursor(0, 0);
      lcd.print("Chuva: ");
      lcd.print(valorChuva);
      lcd.setCursor(0, 1);
      lcd.print(chuva);

    } else {
      // Ecrã 5: Vento
      lcd.setCursor(0, 0);
      lcd.print("Vento:");
      lcd.setCursor(0, 1);
      lcd.print(velocidade, 1);
      lcd.print(" m/s");
    }

    // Serial Monitor
    Serial.print("Temperatura: "); Serial.print(temperatura); Serial.println(" C");
    Serial.print("Humidade: "); Serial.print(humidade); Serial.println(" %");
    Serial.print("Qualidade ar: "); Serial.println(valorAr);
    Serial.print("Pressao: "); Serial.print(pressao); Serial.println(" hPa");
    Serial.print("Chuva: "); Serial.println(valorChuva);
    Serial.print("Vento: "); Serial.print(velocidade); Serial.println(" m/s");
    Serial.println("---");

    // Alterna ecrã
    ecraAtual = (ecraAtual + 1) % 5;
  }
}
