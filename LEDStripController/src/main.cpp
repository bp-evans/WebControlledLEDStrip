#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <string.h>
#include <SPIFFS.h>
#include <iostream>
using namespace std;

#define DATA_PIN 14 // pin of dat line for neo pixel (SPI pin)
const int numOfLeds=30; // number of leds on strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numOfLeds, DATA_PIN, NEO_GRB + NEO_KHZ800);

int flag = 0;
int RED = 0;
int BLUE = 0;
int GREEN = 0;

const char* ssid = "iPhone";
const char* password = "bpevans99";

// Create Web Server
AsyncWebServer server(80);

void setup() {
  // put your setup code here, to run once:
  //delay(1000);
  Serial.begin(115200);
  Serial.print("Testing");

  strip.begin();
  strip.setBrightness(4);

  if(!SPIFFS.begin(true)){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println("Connected");
  Serial.println(WiFi.localIP());

  // Serve the color selector web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    Serial.println("Page Request");
    request->send(SPIFFS, "/index.html", String(), false);
  });

  server.on("/index.html", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", String(), false);
  });

  server.on("/ColorSelect.html", HTTP_GET, [](AsyncWebServerRequest *request){
    Serial.println("Page Request");
    request->send(SPIFFS, "/ColorSelect.html", String(), false);
  });

  server.on("/Patterns.html", HTTP_GET, [](AsyncWebServerRequest *request){
    Serial.println("Page Request");
    request->send(SPIFFS, "/Patterns.html", String(), false);
  });

  // Handle color input from web page
  server.on("/updateColor", HTTP_GET, [](AsyncWebServerRequest *request){
    strip.setBrightness(4);
    strip.show();
    flag = 0;
    Serial.println("update color");
    String inputRed = request->getParam("red")->value();
    String inputBlue = request->getParam("blue")->value();
    String inputGreen = request->getParam("green")->value();
    int r = inputRed.toInt();
    int g = inputGreen.toInt();
    int b = inputBlue.toInt();

    for (int i = 0;i < numOfLeds;i++)
    {
      strip.setPixelColor(i,r,g,b);
      strip.show();
    }
  });

  server.on("/updatePattern", HTTP_GET, [](AsyncWebServerRequest *request){
    strip.setBrightness(4);
    strip.show();
    flag = 0;
    Serial.println("Pattern Request");
    String pattern = request->getParam("pattern")->value();
    String inColorNum = request->getParam("colorPref")->value();
    String inputRed1 = request->getParam("red1")->value();
    String inputBlue1 = request->getParam("blue1")->value();
    String inputGreen1 = request->getParam("green1")->value();
    RED = inputRed1.toInt();
    BLUE = inputBlue1.toInt();
    GREEN = inputGreen1.toInt();
    if(pattern == "ripple") {
      if (inColorNum == "color") {
        flag = 1;
      } else {
        flag = 2;
      }
    } else if(pattern == "stars") {
      if(inColorNum == "color") {
        flag = 3;
      } else {
        flag = 4;
      }
    } else { // InAndOut
      if(inColorNum == "color") {
        flag = 5;
      } else {
        flag = 6;
      }
    }
  });

  server.begin();
}

void loop() {
  if (flag == 1) { // single color ripple selection
    for(int i = 0; i < numOfLeds; i++)
    {
      strip.setPixelColor(i,RED,GREEN,BLUE);
      strip.show();
      delay(50);
      strip.setPixelColor(i,0,0,0);
    }
  } else if (flag == 2) {
    for(int i = 0;i < numOfLeds; i++) {
      int g = random(0,255);
      int r = random(0,255);
      int b = random(0,255);
      strip.setPixelColor(i,r,g,b);
      strip.show();
      delay(50);
      strip.setPixelColor(i,0,0,0);
    }
  } else if (flag == 3) {
    int i = random(0,30);
    strip.setPixelColor(i,RED,GREEN,BLUE);
    strip.show();
    delay(100);
    strip.setPixelColor(i,0,0,0);
  } else if(flag == 4) {
    int i = random(0,30);
    int g = random(0,255);
    int r = random(0,255);
    int b = random(0,255);
    strip.setPixelColor(i,r,g,b);
    strip.show();
    delay(100);
    strip.setPixelColor(i,0,0,0);
  } else if(flag == 5) {
    for(int i = 0;i <= numOfLeds/2;i++) {
      strip.setPixelColor(i,RED,GREEN,BLUE);
      strip.setPixelColor(numOfLeds-i,RED,GREEN,BLUE);
      strip.show();
      delay(30);
    }
    for(int i = numOfLeds/2; i >= 0;i--) {
      strip.setPixelColor(i,0,0,0);
      strip.setPixelColor(numOfLeds-i,0,0,0);
      strip.show();
      delay(30);
    }
  } else if(flag == 6) {
    for(int i = 0;i <= numOfLeds/2;i++) {
      int g = random(0,255);
      int r = random(0,255);
      int b = random(0,255);
      strip.setPixelColor(i,r,g,b);
      strip.setPixelColor(numOfLeds-i,r,g,b);
      strip.show();
      delay(30);
    }
    for(int i = numOfLeds/2; i >= 0;i--) {
      strip.setPixelColor(i,0,0,0);
      strip.setPixelColor(numOfLeds-i,0,0,0);
      strip.show();
      delay(30);
    }
  }
  // put your main code here, to run repeatedly:
  // sample color loop

  /*
  Pattern Input Data Pattern:

  


  int option = 1;

  if(option == 1)
  {
    Serial.print("Color Selector");
    int g = 53;
    int r = 255;
    int b = 147;
    for (int i = 0;i < 30;i++)
    {
      strip.setPixelColor(i,r,g,b);
      strip.show();
    }
  }
  else if(option == 2)
  {
    Serial.print("Pattern Selector");
    for(int i = 0; i < numOfLeds; i++)
    {
      Serial.print("Running Through Loop");
      int g = random(0,255);
      int r = random(0,255);
      int b = random(0,255);
      strip.setPixelColor(i,g,r,b);
      strip.show();
      delay(50);
      strip.setPixelColor(i,0,0,0);
    }
  }
  
  /**
  for(int j = numOfLeds - 1; j >= 0; j++)
  {
    int g = random(0,255);
    int r = random(0,255);
    int b = random(0,255);
    strip.setPixelColor(j,g,r,b);
    strip.show();
    delay(25);
    strip.setPixelColor(j,0,0,0);
  }
  */
}