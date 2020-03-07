#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#define  led0 D0
#define  led1 D1
#define  led2 D2

const char* wifi_name = "Redmi";
const char* wifi_password = "Swarnava1";
 
void setup () {
  Serial.begin(115200);
  WiFi.begin(wifi_name, wifi_password);
  pinMode(led0,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}
 
void loop() {
 
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("http://swarnavabose.000webhostapp.com/data");
    int httpCode = http.GET();
    
    if(httpCode > 0){
    // start of fetching get process
      String response = "";
      response = http.getString();
      Serial.println(response);

      if(response[0]=='1')
      {digitalWrite(led0, 1);
      digitalWrite(led1, 0);
      digitalWrite(led2, 0);}
      else if(response[1]=='1')
      {digitalWrite(led1, 1);
      digitalWrite(led0, 0);
      digitalWrite(led2, 0);}
      else if(response[2]=='1')
      {digitalWrite(led2, 1);
      digitalWrite(led0, 0);
      digitalWrite(led1, 0);}
      else if(response[3]=='1')
      {digitalWrite(led0, 0);
      digitalWrite(led1, 0);
      digitalWrite(led2, 0);}

//      if(response[0]=='1')
//      {digitalWrite(led0, 1);}
//      else
//      {digitalWrite(led0, 0);}
//      if(response[1]=='1')
//      {digitalWrite(led1, 1);}
//      else
//      {digitalWrite(led1, 0);}
//      if(response[2]=='1')
//      {digitalWrite(led2, 1);}
//      else
//      {digitalWrite(led2, 0);}


//        digitalWrite(led0, response[0]);
//        digitalWrite(led1, response[1]);
//        digitalWrite(led2, response[2]);  
      
    }
    else
      Serial.println(httpCode);
      
    http.end();
    // end of fetching get process
  }
  else{
    delay(1000);
    Serial.print("Connecting..");
  }
  delay(500);
}
