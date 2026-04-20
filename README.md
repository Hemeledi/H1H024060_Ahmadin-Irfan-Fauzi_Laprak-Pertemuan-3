Percobaan 3A
Pertanyaan 3
const int PIN_LED = 8: mendefinisikan pin 8 sebagai konstanta untuk LED.
	
char mode = '0': menyimpan mode aktif. Nilai default '0' berarti LED mati.

unsigned long waktuSebelumnya: menyimpan millis() terakhir kali LED di-toggle. Harus unsigned long untuk menghindari overflow pada ~49 hari.

const long intervalBlink = 500: LED berpindah kondisi setiap 500 ms sehingga periode satu kedip penuh = 1 detik.

if (Serial.available() > 0): hanya membaca jika buffer tidak kosong, mencegah pembacaan nilai -1.

mode = '2': flag yang memberi tahu bagian blink di bawah bahwa mode kedip aktif.

if (mode == '2'): blok ini berjalan setiap iterasi loop. Dengan millis(), tidak ada delay sehingga pembacaan serial tetap responsif selama LED berkedip.

waktuSekarang - waktuSebelumnya >= intervalBlink: teknik non-blocking untuk mengukur selang waktu tanpa memblokir CPU.

statusLED = !statusLED: toggle boolean, lalu ditulis ke pin dengan operator ternary.

Percobaan 3B 
Pertanyaan 3

#include <Wire.h>: library bawaan Arduino untuk protokol I2C. Mengaktifkan fungsi komunikasi pada pin SDA (A4) dan SCL (A5).

#include <LiquidCrystal_I2C.h>: library tambahan untuk LCD dengan modul I2C backpack (PCF8574). Menyederhanakan pengiriman data ke LCD menjadi perintah tingkat tinggi.

LiquidCrystal_I2C lcd(0x27, 16, 2): membuat objek lcd dengan alamat I2C 0x27, 16 kolom, 2 baris.

Serial.begin(9600): memulai komunikasi UART dengan baud rate 9600 bps. Harus dipanggil di setup() sebelum menggunakan Serial.print().

lcd.init() + lcd.backlight(): inisialisasi LCD dan menyalakan lampu latar.

analogRead(pinPot): membaca tegangan pada pin A0 dan mengonversinya ke nilai integer 0–1023 menggunakan ADC 10-bit internal ATmega328P.

volt = nilai × (5.0 / 1023.0): konversi nilai ADC ke tegangan nyata. Faktor 5.0/1023 adalah resolusi per step (±4.887 mV).

map(nilai, 0, 1023, 0, 100): memetakan nilai ADC ke rentang 0–100 secara linear untuk persentase.

Serial.print() dengan format terstruktur: mengirimkan data ke Serial Monitor via UART. \t adalah tab untuk alignment kolom.

lcd.setCursor(0, 0): memindahkan kursor LCD ke kolom 0 baris 0 (baris pertama).

lcd.setCursor(0, 1): memindahkan kursor LCD ke kolom 0 baris 1 (baris kedua) untuk bar.

(char)255: karakter blok penuh pada LCD karakter. Mencetak kotak hitam penuh sebagai elemen bar visual.

delay(200): program berhenti 200ms sebelum pembacaan berikutnya. Cukup untuk update visual tanpa beban berlebih pada I2C bus.



