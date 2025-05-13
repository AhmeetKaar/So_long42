# so_long

Bu proje, basit bir 2D oyun motoru kullanılarak oluşturulmuş bir labirent oyunudur. `so_long`, 42 okulu eğitim programı kapsamında geliştirilmiştir ve grafik arayüzü için MinilibX kütüphanesinden yararlanılmıştır.

## 🔍 Proje Hakkında

Amaç, harita dosyasına göre dinamik olarak bir oyun ortamı oluşturmak ve oyuncunun çıkış noktasına ulaşmasını sağlamaktır. Oyuncu haritada karakterini yön tuşlarıyla hareket ettirir, tüm coin'leri toplar ve çıkış kapısına ulaşır.

## 📁 Dosya Yapısı

- `so_long/` - Proje kaynak dosyaları
- `maps/` - `.ber` uzantılı harita dosyaları
- `Makefile` - Derleme işlemlerini otomatikleştiren dosya

## 🛠️ Kurulum ve Çalıştırma

### 1. Derleme

Öncelikle proje dosyasının bulunduğu dizinde terminal açın ve aşağıdaki komutu çalıştırarak projeyi derleyin:

```bash
make
```
2. Oyunu Başlatma
Aşağıdaki komutu kullanarak oyunu başlatabilirsiniz:

bash
Kopyala
Düzenle
./so_long ./maps/map.ber
./so_long: Derlenen oyunu çalıştırır.

./maps/map.ber: maps klasörü altında bulunan .ber uzantılı harita dosyasını oyuna yükler.

🎮 Oynanış
Oyuncu karakterini yön tuşları ile hareket ettirir.

Amaç tüm coin'leri toplamak ve çıkış kapısından geçerek oyunu tamamlamaktır.

Harita sınırlı bir yapıya sahiptir ve dış sınırları duvarla kaplı olmalıdır.

📌 Kurallar
Harita yalnızca belirli karakterler içermelidir: 1, 0, P, C, E.

1 = Duvar

0 = Boş alan

P = Oyuncu başlangıç konumu

C = Coin

E = Çıkış

🧪 Test Haritaları
maps/ dizini içerisinde oyununuzu test edebileceğiniz farklı .ber haritaları yer almaktadır.
