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
