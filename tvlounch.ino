#include <ESP8266WiFi.h>
#include <ThingESP.h>
ThingESP8266 thing("YOUR_USERNAME", "YOUR_DEVICE_NAME", "YOUR_DEVICE_KEY");


const int LED_PIN_1 = D5;     // D5 or GPIO 14
const int FAN_PIN_1 = D6;     // D6 or GPIO 12
const int LED_PIN_2 = D7;     // D7 or GPIO 13
const int FAN_PIN_2 = D8;     // D8 or GPIO 15
int S[4] = {0,0,0,0};
String Status[4] = {"","","",""},past="";

void setup()
{

  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(FAN_PIN_1, OUTPUT);
  pinMode(FAN_PIN_2, OUTPUT);
  Serial.begin(74880);
  thing.SetWiFi("YOUR_WIFI_SSID", "YOUR_WIFI_PASSWORD");
  thing.initDevice();
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

String HandleResponse(String query)
{
  Serial.println(query);
   if (query == "hello!") {
    past="";
    return("*Hello Mr/Mrs,👋*\n\nWelcome to *HAM.t* 🤖 Family! We're delighted to have you with us.🎉 How can I help you? Options for controlling : \n\t*TL*. TV Launch \n\t*B1*. Bad Room 1 \n\t*S*. For Status \nChoose options .");
  }

  else if (query == "tl") {
    past="TL";
    return("\n\t\t*TV Launch* \n\t*L1 ON*. LED 1 *ON* 💡\n\t*L1 OFF*.  LED 1 *OFF* 💡\n\t*L2 ON*.  LED 2 *ON* 💡\n\t*L2 OFF*.  LED 2 *OFF* 💡\n\t*F1 ON*.  Fan 1 *ON* 🪭\n\t*F1 OFF*.  Fan 1 *OFF* 🪭\n\t*F2 ON*.  Fan 2 *ON* 🪭\n\t*F2 OFF*.  Fan 2 *OFF* 🪭 \nChoose options .");
  }
    else if (query == "l1 on" && past=="TL") {
    S[0]=1;
    
    return("*TV Launch LED 1 ON 💡*");
  }  
  else if (query == "l1 off" && past=="TL") {
              digitalWrite(LED_PIN_1, LOW);
              S[0]=0;
              
            return("*TV Launch LED 1 OFF 💡*");
          }  
  else if (query == "l2 on" && past=="TL") {
            S[2]=1;
            
            return("*TV Launch LED 2 ON 💡*");
          }  
  else if (query == "l2 off" && past=="TL") {
              digitalWrite(LED_PIN_2, LOW);
              S[2]=0;
              
            return("*TV Launch LED 2 OFF 💡*");
          }
  else if (query == "f1 on" && past=="TL") {
            S[1]=1;
            
            return("*TV Launch FAN 1 ON 🪭*");
          }  
  else if (query == "f1 off" && past=="TL") {
              digitalWrite(FAN_PIN_1, LOW); 
            S[1]=0;
            
            return("*TV Launch FAN 1 OFF 🪭*");
          }  
  else if (query == "f2 on" && past=="TL") {
            S[3]=1;
            
            return("*TV Launch FAN 2 ON 🪭*");
          }  
  else if (query == "f2 off" && past=="TL") {
              digitalWrite(FAN_PIN_2, LOW);
              S[3]=0;
              
            return("*TV Launch FAN 2 OFF 🪭*");
          }
else if (query == "s") {
  return("*status for TV launch*\n*status for Bad Room 1*");
}
  else if(query =="status for tv launch"){
    Status[0] = S[0] ? "*ON*" : "*OFF*";
    Status[2] = S[2] ? "*ON*" : "*OFF*";
    Status[1] = S[1] ? "*ON*" : "*OFF*";
    Status[3] = S[3] ? "*ON*" : "*OFF*";
    
    return "*TV Launch LED 1 is* " + Status[0] + " 💡\n" +
       "*TV Launch LED 2 is* " + Status[1] + " 💡\n" +
       "*TV Launch FAN 1 is* " + Status[2] + " 🪭 \n" +
       "*TV Launch FAN 2 is* " + Status[3] + " 🪭 \n";
}
else {
     return "*⚠Your query was invalid*";
}
}
void loop()
{
  Serial.print("S[0]: ");
  Serial.println(S[0]);
  delay(200);

  if (S[0] == 1 ) {
    digitalWrite(LED_PIN_1, HIGH);
    Serial.println(LED_PIN_1);
  } else {
    digitalWrite(LED_PIN_1, LOW);
  }

  if (S[2] == 1 ) {
    digitalWrite(LED_PIN_2, HIGH);
  } else {
    digitalWrite(LED_PIN_2, LOW);
  }

  if (S[1] == 1 ) {
    digitalWrite(FAN_PIN_1, HIGH);
  } else {
    digitalWrite(FAN_PIN_1, LOW);
  }

  if (S[3] == 1 ) {
    digitalWrite(FAN_PIN_2, HIGH);
  } else {
    digitalWrite(FAN_PIN_2, LOW);
  }

  thing.Handle();
}
