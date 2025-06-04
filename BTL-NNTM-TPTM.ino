#include <SharpGP2Y10.h>
//#include <WiFi.h>
//#include <String.h>
//#include <PubSubClient.h>

//
//#define wifi_ssid "13 08 21"
//#define wifi_password "12345679"
//#define mqtt_server "broker.mqttdashboard.com"
//#define mqtt_user "thuy"
//#define mqtt_password "123456"
//#define topic "sensorData"

//WiFiClient espClient;
//PubSubClient client(espClient);

//DUST Sensor
int voPin = D2;
int ledPin = D7;
float dustDensity = 0;
 
SharpGP2Y10 dustSensor(voPin, ledPin);
 
void setup() 
{
//    setup_wifi();
//  client.setServer(mqtt_server, 1883);
//  client.setCallback(callback);
  Serial.begin(115200);
}

//void setup_wifi() {
//  delay(10);
//  Serial.println();
//  Serial.print("Connecting to ");
//  Serial.println(wifi_ssid);
//  WiFi.begin(wifi_ssid, wifi_password);
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(500);
//    Serial.print(".");
//  }
//  Serial.println("");
//  Serial.println("WiFi connected");
//}

//void reconnect() {
//  while (!client.connected()) {
//    Serial.print("Attempting MQTT connection...");
//    String clientName = "thuy";
//    if (client.connect(clientName.c_str(), mqtt_user, mqtt_password)) {
//      Serial.println("connected");
//    }
//    else {
//      Serial.println("failed, try again in 5 seconds");
//      delay(4000);
//    }
//  }
//}
void loop() {

//    if (!client.connected()) {
//    reconnect();
//}
  int sensorValue = analogRead(A0); // Đọc giá trị analog từ chân A0
  float voltage = sensorValue * (5.0 / 1023.0); // Chuyển giá trị analog sang điện áp (0–5V)
  float actualVoltage = voltage * (25.0 / 10.0); // Chuyển tỉ lệ từ 0–5V sang 0–25V

  Serial.print("Raw Value: ");
  Serial.print(sensorValue);
  Serial.print("  Voltage: ");
  Serial.print(voltage);
  Serial.print("V  Actual Voltage: ");
  Serial.print(actualVoltage);
  Serial.println("V");

  delay(500); // Đợi 1 giây trước khi đọc lại giá trị
  dustDensity = dustSensor.getDustDensity();
  Serial.println(dustDensity);
  delay(500);
}
