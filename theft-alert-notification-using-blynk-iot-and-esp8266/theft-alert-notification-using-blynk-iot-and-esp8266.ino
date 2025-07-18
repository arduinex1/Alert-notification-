#define BLYNK_TEMPLATE_ID "TMPL3N0oCyca7"
#define BLYNK_TEMPLATE_NAME "security system"
#define BLYNK_AUTH_TOKEN "18YYcrl039V_YYYYiBivhuHpBBC0YuPH"


#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>


char auth[] = BLYNK_AUTH_TOKEN;


char ssid[] = "vishnu";      // your WiFi name
char pass[] = "8445200@$";   // your WiFi password


#define IR_SENSOR  4        // GPIO pin for IR sensor
BlynkTimer timer;


void notifyOnTheft() {
  int isTheftAlert = digitalRead(IR_SENSOR);
  Serial.println(isTheftAlert);
  if (isTheftAlert == 1) {
    Serial.println("Theft Alert in Home");
    Blynk.logEvent("security_system", "Theft Alert in Home");
  }
}


void setup() {
  pinMode(IR_SENSOR, INPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(5000L, notifyOnTheft);
}


void loop() {
  Blynk.run();
  timer.run();
}
