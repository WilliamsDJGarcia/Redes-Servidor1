#include <ESP8266WiFi.h>

char ssid[] = "moto";
char password[] = "comatose2019";

char host[] = "redespolitecnica5.ddns.net";
//<<<<<<< HEAD:wificlient.ino
int httpPort= 4000;
int httpPort2 = 5000;
int hhtpPort3 = 6000;
//=======
//int httpPort= 6200;
//int httpPort2 = 4500;
//int httpPort3 = 5100;
//>>>>>>> 4dbcafcde0f01460495fa8f34c901d9624d069b6:wificlient/wificlient.ino

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
      client.write("Server 1")
      Serial.print("conexion exitosa"); 
      }
      while(client.connect(host, httpPort2)){
      client.write("Server 2")
      delay(250);
      Serial.print("conexion 2 exitosa"); 
      }    
      while(client.connect(host, httpPort3)){
      client.write("Server 3")
      delay(250);
      Serial.print("conexion 3 exitosa"); 
      }    
    }
    while(!client.connected()){
      Serial.println(".");
    while(client.connect(host, httpPort)){
      client.write("Server 1")
      delay(250);
      Serial.print("conexion exitosa"); 
      }
      while(client.connect(host, httpPort2)){
      client.write("Server 2")
      delay(250);
      Serial.print("conexion 2 exitosa");
      }     
      while(client.connect(host, httpPort3)){
      client.write("Server 3")
      delay(250);
      Serial.print("conexion 3 exitosa");
      }     
    }
delay(25);
}