#include <ESP8266WiFi.h>
#include <ESP8266Ping.h>

const char* ssid     = "ASUS";
const char* password = "26112712";

const IPAddress remote_ip(8, 8, 8, 8);
int timer1 = 1;
int timer0 = 0;
void setup() {
  Serial.begin(9600);
  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println("Connecting to WiFi");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("WiFi connected with ip ");
  Serial.println(WiFi.localIP());

  Serial.print("Pinging ip ");
  Serial.println(remote_ip);


}

void loop() {

  if (Ping.ping(remote_ip, 3)) ///можно указать кол-во пинг (remote_ip,5)
  {
    if (timer1 > 1)
    {
      Serial.println("В сети!");
      Serial.print("Отсутствовал инет: ");
      Serial.print(timer1);
      Serial.println(" минут(ы)");
      timer0 = 0;
      timer1 = 1;
    }
    Serial.println("В сети!");
  }
  else
  {
    if (timer0 >= 1)
    {
      Serial.print("Нет сети: ");
      Serial.print(timer1);
      Serial.println(" минут(ы)");
      timer0 = timer0 + 1;
      timer1 = timer1 + 1;
    }
    else
    {
      timer0 = timer0 + 1
    }
  }
  delay(2000);
}
