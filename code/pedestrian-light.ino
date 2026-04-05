// C++ code
//
// Inisialisasi
const int rledtf = 9, yledtf = 10, gledtf = 11; //Trafficlight
const int rledpd = 12, gledpd = 13; //Pedestrianlight
const int buttonpd = 2; //Pedestrianbutton
volatile bool pdRequest = false; //Interuption Variable

void setup() 
{
  // Konfigurasi LED sebagai OUTPUT
  for (int i = 9; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }

  // Konfigurasi Tombol sebagai INPUT_PULLUP
  pinMode(buttonpd, INPUT_PULLUP);
  
  // Inisialisasi Interrupt 
  attachInterrupt(digitalPinToInterrupt(buttonpd), requestPedestrian, FALLING);
  
  //Kondisi default = Trafictlight LED hijau dan Pedestrian LED merah Aktif
  digitalWrite(gledtf, HIGH);
  digitalWrite(rledpd, HIGH);
}

void loop() {
  // Jika tombol ditekan, jalankan sequence penyeberangan
  if (pdRequest) {
    executePedestrianSequence();
    pdRequest = false; // Reset var
  }
}

// Fungsi Interrupt hanya untuk menangkap input
void requestPedestrian() {
  pdRequest = true;
}

// Fungsi transisi lampu saat ada orang menyeberang
void executePedestrianSequence() {
  // Lampu Merah TF nyala, Lampu Hijau PD nyala
  digitalWrite(gledtf, LOW);
  digitalWrite(rledtf, HIGH);
  digitalWrite(rledpd, LOW);
  digitalWrite(gledpd, HIGH);
  
  delay(7000); // Waktu menyeberang 7 detik

  digitalWrite(gledpd, LOW);
  digitalWrite(rledpd, HIGH);
  digitalWrite(rledtf, LOW);
  
  //Kuning TF kedip 3x (Peringatan)
  for (int i = 0; i <= 3; i++) {
    digitalWrite(yledtf, HIGH);
    delay(500);
    digitalWrite(yledtf, LOW);
    delay(500);
  }

  // LED Traffic Hijau kembali nyala
  digitalWrite(gledtf, HIGH);
}