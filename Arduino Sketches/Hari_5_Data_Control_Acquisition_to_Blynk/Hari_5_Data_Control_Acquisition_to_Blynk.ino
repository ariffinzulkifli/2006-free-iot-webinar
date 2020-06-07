/*
 * Siri Webinar Practical Internet of Things
 * Connecting IoT Device to Blynk
 * 5 Jun 2020 (Jumaat)
 * 
 * Trainer: Mohamad Ariffin Zulkifli (Myinvent Technologies Sdn Bhd)
 * https://myduino.com
 * 
 * Webinar Platform: ZOOM
 * 
 * Group Telegram (https://t.me/joinchat/Fht1QxkL-0GOwyo_nX86Tg)
 * 
 * Training Kit:
 * Myduino IoT Training Kit (https://myduino.com/product/myd-002/)
 * 
 * Development Board:
 * Tools > Board: > NodeMCU 1.0 (ESP12-E Module)
 * 
 * Sambungan Elektronik:
 * ------------------------------
 * | LEDs & DHT11 | NodeMCU     |
 * ------------------------------
 * | LED L1     --> 2           |
 * | LED L2     --> 3           |
 * | LED L3     --> 4           |
 * | LED L4     --> 5           |
 * | LED GND    --> GND         |
 * | DHT VS     --> 3V3         |
 * | DHT D      --> D6          |
 * | DHT NC     --> NOT CONNECT |
 * | DHT GND    --> GND         |
 * ------------------------------
 * 
 * Library:
 * 1. Blynk https://github.com/ariffinzulkifli/FavoriotHTTP
 * 2. SimpleDHT https://www.arduinolibraries.info/libraries/simple-dht
 * 
 */
#define BLYNK_PRINT Serial

// penggunaan WiFi library mikropengawal ESP8266
#include <ESP8266WiFi.h>

// penggunaan library Blynk untuk mikropengawal ESP8266
#include <BlynkSimpleEsp8266.h>

// dapatkan Auth Token kita daripada emel yang dihantar oleh Blynk semasa kita create project
char auth[] = "AuthTokenSaya";

char ssid[] = "NamaWiFiSaya";  // nama pembolehubah global untuk nama dan password WiFi
char pass[] = "WiFiSayaPassword";

// penggunaan library untuk sensor DHT
#include <SimpleDHT.h>

int pinDHT11 = D5;            // IO NodeMCU yang bersambung pada DHT11 Data Pin
SimpleDHT11 dht11(pinDHT11);  // penamaan class library DHT kepada "dht11" dan nyatakan "pinDHT11"

void setup() {
  Serial.begin(9600); // arahan untuk initiate Serial Communication

  Blynk.begin(auth, ssid, pass);  // arahan mikropengawal untuk berhubung dengan WiFi router dan Blynk

}

void loop() {
  Blynk.run();  // arahan untuk library Blynk, membolehkan mikropengawal menunggu response dari widget Button untuk buat kawalan LED dan lain2

  // membuat pembolehubah suhu dan kelembapan dengan nilai asal = 0 bagi setiap loop
  byte suhu = 0;
  byte kelembapan = 0;

  // dengan arahan dht11.read mikropengawal akan ke Pin D5 untuk mendapatkan data suhu dan kelembapan
  // namun jika berlaku error semasa dapatan data, mikropengawal akan masuk ke function if dan buat pelaksaan arahan print error dan return
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&suhu, &kelembapan, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err=");  //  mikropengawal akan print "error" dan tunggu 0.5 saat
    Serial.println(err);
    delay(500); 
    
    return;                                   // mikropengawal akan ulang semula ke line 72 dan tidak meneruskan ke arahan seterusnya  
  }
  // jika mikropengawal berjaya mendapatkan data, mikropengawal akan meneruskan ke arahan seterusnya

  // arahan unutk mikropengawal menghantar data suhu dan kelembapan kepada widget Gauge
  Blynk.virtualWrite(V0, suhu);       // widget Gauge 1 pada aplikasi Blynk ditetapkan kepada virtual Pin V0 untuk visualkan nilai suhu
  Blynk.virtualWrite(V1, kelembapan); // widget Gauge 2 pada aplikasi Blynk ditetapkan kepada virtual Pin V1 untuk visualkan nilai suhu

}
