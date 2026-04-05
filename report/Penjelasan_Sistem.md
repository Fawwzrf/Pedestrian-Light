# Penjelasan Sistem Pedestrian Light 🚦🏃‍♂️

### Wiring Diagram
Pada wiring diagram diatas bisa dilihat bahwa rangkaian menggunakan Arduino Uno sebagai otak kendali dengan total 5 LED (3 untuk Traffic Light, 2 untuk Pedestrian) dan 5 Resistor, serta 1 Push Button. Setiap LED dihubungkan dengan resistor 330ohm untuk membatasi arus agar LED tidak terbakar.

### Pemetaan Pin GPIO
| Komponen | Warna LED | Pin Digital |
| :--- | :--- | :---: |
| **Traffic Light (TF)** | Merah, Kuning, Hijau | 9, 10, 11 |
| **Pedestrian Light (PD)** | Merah, Hijau | 12, 13 |
| **Push Button** | - | 2 |

- Anoda dihubungkan ke Resistor, lalu masuk ke masing-masing Pin Digital (9-13) sesuai tabel di atas.
- Semua katoda LED dihubungkan ke jalur Common Ground (GND) pada Arduino.
- Salah satu kaki Push Button dihubungkan ke Pin 2 dan kaki lainnya ke Ground (GND).

### Penjelasan Kode
Inisialisasi variabel `const int` setiap LED sesuai dengan pin output dan variabel `volatile bool` sebagai flag permintaan penyeberangan.

Fungsi `setup()` berisi konfigurasi LED sebagai output menggunakan for loop, pengaturan Pin 2 sebagai `INPUT_PULLUP`, dan inisialisasi `attachInterrupt` pada mode `FALLING`. Di akhir fungsi terdapat kondisi default yaitu LED Hijau TF dan LED Merah PD menyala.

Fungsi `loop()` berisi pengecekan kondisi variabel flag `pdRequest`. Jika bernilai true, maka fungsi `executePedestrianSequence()` akan dipanggil untuk menjalankan proses penyeberangan.

Fungsi `executePedestrianSequence()` merupakan fungsi inti dalam sistem ini yang berisi flow transisi lampu. Dimulai dari menyalakan LED Merah TF dan LED Hijau PD secara bersamaan, menunggu selama 7s, kemudian mematikan LED Hijau PD dan menyalakan kembali LED Merah PD. Dilanjutkan dengan LED Kuning TF yang berkedip 4x sebagai peringatan sebelum sistem kembali ke kondisi default yaitu menyalakan LED Hijau TF.
