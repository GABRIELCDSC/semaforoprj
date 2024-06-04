#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <string.h>
const char *ssid = "SemaforoGRAI";
const char *password = "87654321";
IPAddress local_IP(192, 168, 4, 22);
IPAddress gateway(192, 168, 4, 9);
IPAddress subnet(255, 255, 255, 0);

// Definição dos pinos dos LEDs
const int ledVerde1 = 25;
const int ledVerde2 = 14;
const int ledAmarelo1 = 13;
const int ledAmarelo2 = 27;
const int ledVermelho1 = 32;
const int ledVermelho2 = 33;
int tempoA = 2000;
int tempoV = 5000;

void luzVe() {
digitalWrite(ledVerde1, HIGH);
  digitalWrite(ledVerde2, LOW);
  digitalWrite(ledAmarelo1, LOW);
  digitalWrite(ledAmarelo2, LOW);
  digitalWrite(ledVermelho1, LOW);
  digitalWrite(ledVermelho2, HIGH);
  delay(tempoV);
}

void luzA() {
  digitalWrite(ledVerde1, LOW);
  digitalWrite(ledVerde2, LOW);
  digitalWrite(ledAmarelo1, HIGH);
  digitalWrite(ledAmarelo2, LOW);
  digitalWrite(ledVermelho1, LOW);
  digitalWrite(ledVermelho2, HIGH);
  delay(tempoA);
}

void luzVr() {
  digitalWrite(ledVerde1, LOW);
  digitalWrite(ledVerde2, HIGH);
  digitalWrite(ledAmarelo1, LOW);
  digitalWrite(ledAmarelo2, LOW);
  digitalWrite(ledVermelho1, HIGH);
  digitalWrite(ledVermelho2, LOW);
  delay(tempoV);
}

void luzAm(){
  digitalWrite(ledVerde1, LOW);
  digitalWrite(ledVerde2, LOW);
  digitalWrite(ledAmarelo1, LOW);
  digitalWrite(ledAmarelo2, HIGH);
  digitalWrite(ledVermelho1, HIGH);
  digitalWrite(ledVermelho2, LOW);
  delay(tempoA);
}
void AcendeMaster(){
  luzVe();
  luzA();
  luzVr();
  luzAm();
}

void setup() {
  // Configuração dos pinos como saída
  pinMode(ledVerde1, OUTPUT);
  pinMode(ledVerde2, OUTPUT);
  pinMode(ledAmarelo1, OUTPUT);
  pinMode(ledAmarelo2, OUTPUT);
  pinMode(ledVermelho1, OUTPUT);
  pinMode(ledVermelho2, OUTPUT);
  
  Serial.begin(115200);
  Serial.print("Configurando AP .....");
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet)? "OK" : "Erro");
  Serial.print("Iniciando o WiFi ......");
  Serial.println(WiFi.softAP(ssid, password));
  Serial.print("Endereço IP");
  Serial.println(WiFi.softAPIP());
}

void loop() {
 AcendeMaster();
}