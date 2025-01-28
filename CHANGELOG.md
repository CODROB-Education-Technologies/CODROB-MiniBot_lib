# Changelog

## [1.0.7] - 2025-01-25
### Added
- Test kodları oluşturuldu:
  - LCD ekran testi.
  - Tüm butonlar için ayrı ayrı testler.
  - Motorlar için testler:
    - Servo motor.
    - DC motor.
    - Step motor.
  - Modüller için testler:
    - Mikrofon sensörü.
    - PIR hareket sensörü.
    - Matris buton sensörü.
    - NTC sıcaklık sensörü.
    - Trafik ışığı modülü.
  - Röle ve duman sensörü için test kodları.
- `keywords.txt` dosyası eklendi:
  - Arduino IDE desteği için fonksiyonlar eklendi.
- Tüm açıklamalar Türkçe ve İngilizce olarak güncellendi.

### Fixed
- IR kütüphanesiyle çakışma sorunları giderildi.
- Seri port kullanımındaki karışıklıklar IoTBot sınıfı üzerinden düzenlendi.

---

## [1.0.6] - 2025-01-20
### Added
- `IRremote` desteği eklendi.
- Kod yapısı ESP32'ye uygun optimize edildi.

### Fixed
- LCD başlatma sırasında oluşan uyumsuzluklar düzeltildi.

---

## [1.0.5] - 2025-01-15
### Added
- IoTBot'a DHT11 sıcaklık ve nem sensörü desteği eklendi.
- IoTBot için NeoPixel LED desteği sağlandı.

---

## [1.0.4] - 2025-01-10
### Added
- Yeni buton kontrol işlevleri eklendi.
- Buzzer test kodları düzenlendi.

### Fixed
- Encoder kontrol fonksiyonlarında iyileştirmeler yapıldı.

---

## [1.0.3] - 2025-01-05
### Added
- Potansiyometre okuma işlevi eklendi.
- Röle kontrolü için destek sağlandı.

---

## [1.0.2] - 2025-01-01
### Fixed
- Motor kontrol algoritmalarında düzeltmeler yapıldı.
- Trafik ışığı modül desteği optimize edildi.

---

## [1.0.1] - 2024-12-25
### Added
- IoTBot sınıfı ve temel sensör işlevleri eklendi.

---

## [1.0.0] - 2024-12-20
### Added
- İlk sürüm yayımlandı.
