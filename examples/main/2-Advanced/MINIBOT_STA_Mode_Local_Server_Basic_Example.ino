#include <MINIBOT.h> // 📌 MINIBOT Kütüphanesi / MINIBOT Library

MINIBOT MINIBOT; // 📌 MINIBOT Nesnesi / MINIBOT Object

// 📌 **Web Sayfası İçeriği (HTML, CSS, JavaScript)**

// ✅ **JavaScript (Web Sayfası İçin)**
// Kullanıcı butona tıkladığında bir mesaj gösterecek.
const char WEBPageScript[] PROGMEM = R"rawliteral(
<script>
  function sayHello() {
    alert("Hello from MINIBOT!");
  }
</script>
)rawliteral";

// ✅ **CSS (Web Sayfası Stili)**
// Web sayfasının görünümünü ayarlamak için CSS kullanıyoruz.
const char WEBPageCSS[] PROGMEM = R"rawliteral(
<style>
  body { text-align: center; font-family: Arial, sans-serif; }
  button { font-size: 20px; padding: 10px; margin: 20px; }
</style>
)rawliteral";

// ✅ **HTML (Web Sayfası İçeriği)**
// ESP32 tarafından sunulacak HTML kodu
const char WEBPageHTML[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>MINIBOT Web Server</title>
  %s <!-- CSS Dosyası Buraya Eklenir -->
  %s <!-- JavaScript Dosyası Buraya Eklenir -->
</head>
<body>
  <h1>MINIBOT Web Sayfası</h1>
  <button onclick="sayHello()">Tıklayın</button>
</body>
</html>
)rawliteral";

// 📌 **Kullanıcı için Kolaylaştırılmış Wi-Fi Tanımlamaları**
const char *wifi_ssid = "INTERNET";          // 📌 Wi-Fi Ağ Adı (SSID) / WiFi Network Name (SSID)
const char *wifi_password = "INTERNET_2022"; // 📌 Wi-Fi Şifresi / WiFi Password

const char *ap_ssid = "CODROB Server"; // 📌 AP Modu için SSID / AP Mode SSID
const char *ap_password = "12345678";  // 📌 AP Modu için Şifre / AP Mode Password (En az 8 karakter)

// 📌 **Kurulum Fonksiyonu (Setup)**
void setup()
{
  MINIBOT.serialStart(115200); // 📌 **Seri Haberleşmeyi Başlat / Start Serial Communication**

  // 📌 **STA veya AP Modunda Bağlantı Kur**
  MINIBOT.serverStart("STA", wifi_ssid, wifi_password);

  // 📌 **Eğer STA bağlantısı başarısız olursa AP moduna geç**
  if (!MINIBOT.wifiConnectionControl())
  {
    MINIBOT.serverStart("AP", ap_ssid, ap_password);
  }

  // 📌 **ESP32 Üzerinde Web Sayfasını Yayınla**
  MINIBOT.serverCreateLocalPage("dashboard", WEBPageScript, WEBPageCSS, WEBPageHTML);
}

// 📌 **Ana Döngü (Loop)**
void loop()
{
  MINIBOT.serverContinue(); // 📌 **AP modunda DNS yönlendirmeyi sürdür**
}
