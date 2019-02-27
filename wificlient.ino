#include <ESP8266WiFi.h>

char ssid[] = "moto";
char password[] = "12345678";

char host[] = "192.168.43.142";
int httpPort= 6200;
int httpPort2 = 4500;
int hhtpPort3 = 5100;

boolean verificar=false;
int contador = 0;
WiFiClient client;

void setup() 
{
    Serial.begin(9600);
    delay(10);
    WiFi.begin(ssid, password);

    while(WiFi.status() != WL_CONNECTED){
      delay(300);
      Serial.print(". Wifi estatus");
      }
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP() );
  
    while(client.connect(host, httpPort) && verificar == false){
        delay(10);
        contador = contador + 1;
        if(contador >= 30){
          verificar = true;
          }
        Serial.println("connection falied 1");
      }
      while(!client.connect(host, httpPort2)){
        Serial.println("connection falied 2");
        }
    Serial.println("connection successs");

}
void loop() {

   while(client.connected()){
    Serial.println(".");
    while(client.connect(host, httpPort)){
      delay(250);
      Serial.print("onexion exitosa"); 
      }
      while(client.connect(host, httpPort2)){
      delay(250);
      Serial.print("conexion 2 exitosa"); 
      }
    while(!client.connected()){
        Serial.println(".");
    while(client.connect(host, httpPort)){
      delay(250);
      Serial.print("onexion exitosa"); 
      }
      while(client.connect(host, httpPort2)){
      delay(250);
      Serial.print("conexion 2 exitosa");
      }
      
    }
    }
delay(25);
}
