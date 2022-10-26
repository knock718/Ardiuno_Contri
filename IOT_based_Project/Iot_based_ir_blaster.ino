/*************************************************************
  Emulate a physical remote via an iOS and Android App.
  Copyright Gaurav Barwalia 2020
  Edited by Naman Kansal
  

  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************/

#define BLYNK_PRINT Serial

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#else
#include <WiFi.h>
#endif  // ESP8266
#if defined(ESP32)
#include <BlynkSimpleEsp32.h>
#endif  // ESP32

// IR library
#include <IRremoteESP8266.h>
#include <IRsend.h>

const uint16_t kIrLed = 4;  // ESP8266 GPIO pin to use. Recommended: 4 (D2).
IRsend irsend(kIrLed);  // Set the GPIO to be used to sending the message.


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "";
char pass[] = "";

void setup() {
  
irsend.begin();

#if ESP8266
  Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);
#else  // ESP8266
  Serial.begin(115200, SERIAL_8N1);
#endif  // ESP8266

#if defined(BLYNK_PRINT)
  // Debug console
  Serial.begin(115200);
#endif  // BLYNK_PRINT

  Blynk.begin(auth, ssid, pass);
  
}

  BLYNK_WRITE(V0) {  // Power button
    if (param.asInt() == 1) {
      Serial.println("starplus");
      irsend.sendNEC(0x80BF49B6);
      delay(1000);
      
      irsend.sendNEC(0x80BFE11E);
      delay(1000);

      irsend.sendNEC(0x80BF49B6);
      delay(1000);

    }
    
    else if (param.asInt()==2) {
      Serial.println("colours");
      irsend.sendNEC(0x80BF49B6);
      delay(1000);
      irsend.sendNEC(0x80BFE11E);
      delay(1000);
      irsend.sendNEC(0x80BF33CC);
      delay(1000);
    }
    
    else if (param.asInt()==3) {
      Serial.println("sony");
      irsend.sendNEC(0x80BF49B6);
      delay(1000);
      irsend.sendNEC(0x80BFE11E);
      delay(1000);
      irsend.sendNEC(0x80BFF10E);
      delay(1000);
    }
    
    else if (param.asInt()==4) {
      Serial.println("SAB");
      irsend.sendNEC(0x80BF49B6);
      delay(1000);
      irsend.sendNEC(0x80BFE11E);
      delay(1000);
      irsend.sendNEC(0x80BFD12E);
      delay(1000);
    }
    
    else if (param.asInt()==5) {
      Serial.println("STAR GOLD");
      irsend.sendNEC(0x80BF49B6);
      delay(1000);
      irsend.sendNEC(0x80BF13EC);
      delay(1000);
      irsend.sendNEC(0x80BF49B6);
      delay(1000);
    }
    
    else if (param.asInt()==6) {
      Serial.println("ZEE CLASSIC");
      irsend.sendNEC(0x80BF49B6);
      delay(1000);
      irsend.sendNEC(0x80BF13EC);
      delay(1000);
      irsend.sendNEC(0x80BFD12E);
      delay(1000);
    }
    
    else if (param.asInt()==7) {
      Serial.println("ABP");
      irsend.sendNEC(0x80BF33CC);
      delay(1000);
      irsend.sendNEC(0x80BFE11E);
      delay(1000);
      irsend.sendNEC(0x80BFC936);
      delay(1000);
    }
    
    else if (param.asInt()==8) {
      Serial.println("NEWS");
      irsend.sendNEC(0x80BF33CC);
      delay(1000);
      irsend.sendNEC(0x80BFE11E);
      delay(1000);
      irsend.sendNEC(0x80BF49B6);
      delay(1000);
    }
    
    else if (param.asInt()==9) {
      Serial.println("SPORTS");
      irsend.sendNEC(0x80BF718E);
      delay(1000);
      irsend.sendNEC(0x80BFE11E);
      delay(1000);
      irsend.sendNEC(0x80BF718E);
      delay(1000);
    }
    
    else if (param.asInt()==10) {
      Serial.println("CARTOON");
      irsend.sendNEC(0x80BF718E);
      delay(1000);
      irsend.sendNEC(0x80BFC936);
      delay(1000);
      irsend.sendNEC(0x80BF13EC);
      delay(1000);
    }
    
    else if (param.asInt()==11) {
      Serial.println("MTV");
      irsend.sendNEC(0x80BF718E);
      delay(1000);
      irsend.sendNEC(0x80BFF10E);
      delay(1000);
      irsend.sendNEC(0x80BF49B6);
      delay(1000);
    }
    
    else if (param.asInt()==12) {
      Serial.println("9XM");
      irsend.sendNEC(0x80BF718E);
      delay(1000);
      irsend.sendNEC(0x80BFF10E);
      delay(1000);
      irsend.sendNEC(0x80BF718E);
      delay(1000);
    }
    
    // else if (param.asInt()==13) {
    //   Serial.println("SONGS");
    //   irsend.sendNEC(0x80BF718E);
    //   delay(1000);
    //   irsend.sendNEC(0x80BFF10E);
    //   delay(1000);
    //   irsend.sendNEC(0x80BF49B6);
    //   delay(1000);
    // }
    
    else if (param.asInt()==14) {
      Serial.println("HISTORY");
      irsend.sendNEC(0x80BFF10E);
      delay(1000);
      irsend.sendNEC(0x80BFE11E);
      delay(1000);
      irsend.sendNEC(0x80BFC936);
      delay(1000);
    }
    
    else if (param.asInt()==15) {
      Serial.println("DIVYA");
      irsend.sendNEC(0x80BFD12E);
      delay(1000);
      irsend.sendNEC(0x80BF51AE);
      delay(1000);
      irsend.sendNEC(0x80BFD12E);
      delay(1000);
    }
    
    else if (param.asInt()==16) {
      Serial.println("FORWARD");
      irsend.sendNEC(0x80BF19E6);
      
    }
    
    else if (param.asInt()==17) {
      Serial.println("BACKWARD");
      irsend.sendNEC(0x80BFE916);
    }
    
    else if (param.asInt()==18) {
      Serial.println("BACK+");
      irsend.sendNEC(0x80BF43BC);
      
    }
    
    else if (param.asInt()==19) {
      Serial.println("VOLUME-");
      irsend.sendNEC(0x80BF31CE);
    }
     
    
    else if (param.asInt()==20) {
      Serial.println("VOLUME+");
      irsend.sendNEC(0x80BFBB44);
      
    }
    
    else if (param.asInt()==21) {
      Serial.println("MUTE");
      irsend.sendNEC(0x80BF39C6);
      
    }
    
    
   
    
   
    
    
   
  }

  



void loop() {
  Blynk.run();
}
  