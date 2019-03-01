#include <ESP8266WiFi.h>

char ssid[] = "moto";
char password[] = "comatose2019";

char host[] = "redespolitecnica5.ddns.net";
int httpPort= 4000;
int httpPort2 = 5000;
int httpPort3 = 6000;

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
  
    while(!client.connect(host, httpPort)){
        delay(10);     
        Serial.println("connection falied 1");
         if(client.connect(host, httpPort2)){
            Serial.println("Connected to server2");
            client.write("server 2");
            Serial.println(client.readString());
            delay(250);
            break;
          }
          if(client.connect(host, httpPort3)){
            Serial.println("Connected to server3");
            client.write("server 3");
            Serial.println(client.readString());
            delay(250);
            break;
          }
      Serial.println("Failed to connect server2");
      }
      if(client.connect(host, httpPort)){
        Serial.println("Connected to server1");
        client.write("server 1");
        Serial.println(client.readString());
        delay(250);  
      }
    Serial.println("connection successs");

}
bool band = false;
void loop() {
  
    while(client.connected()){
    Serial.println(".");
    delay(500);
    }
    if(client.connected() == false){
      Serial.println("Cambiando de servidor...");
      band = false;
      delay(500);
    }
    while(band == false){
       while(!client.connect(host, httpPort)){
        delay(250);      
        Serial.print("conexion fallida"); 
         if(client.connect(host, httpPort2)){
          Serial.println("conexion al servidor 2 exitosa");          
          delay(500);
          break;
        }else{
          client.connect(host, httpPort3);
          Serial.println("conexion al servidor 3 exitosa");          
          delay(500);
          break;
        }
        Serial.println("conexion fallida al servidor 2");
        }
        if(!client.connect(host, httpPort2) && !client.connect(host, httpPort3)){
          client.connect(host, httpPort);
          Serial.println("conexion al servidor 1 exitosa");            
          delay(500);
          band = true;
        }
               
      }   
delay(25);
}
