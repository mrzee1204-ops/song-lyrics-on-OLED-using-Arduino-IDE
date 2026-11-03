#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Deklarasi ukuran layar OLED (biasanya 128x64 untuk 0.96 inch)
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Deklarasi pin reset (-1 jika menggunakan pin reset bawaan ESP32/Arduino)
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C // Alamat I2C OLED biasanya 0x3C atau 0x3D

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);

  // Inisialisasi OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Berhenti di sini jika gagal
  }

  // Membersihkan buffer tampilan
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
}

// Fungsi untuk menampilkan teks di tengah layar dengan durasi tertentu
void tampilkanLirik(const char* teks, int durasi, int ukuranTeks = 1.5) {
  display.clearDisplay();
  display.setTextSize(ukuranTeks);
  
  // Variabel untuk menghitung bounding box teks
  int16_t x1, y1;
  uint16_t w, h;
  
  // Mengambil dimensi teks untuk proses centering
  display.getTextBounds(teks, 0, 0, &x1, &y1, &w, &h);
  
  // Kalkulasi posisi X dan Y agar teks berada tepat di tengah
  int x = (SCREEN_WIDTH - w) / 2;
  int y = (SCREEN_HEIGHT - h) / 2;
  
  display.setCursor(x, y);
  display.print(teks);
  display.display();
  
  // Jeda waktu sesuai tempo lagu (dalam milidetik)
  delay(durasi);
}

void loop() {
  // Lirik "Story of Another Us" - 5 Seconds of Summer
  // Format: tampilkanLirik("Teks", Durasi_Milidetik, Ukuran_Font);
  // Ukuran font 2 cocok untuk layar 0.96 inch, jika kata terlalu panjang bisa pakai 1.

  // "I got a long term plan"
  tampilkanLirik("I got a", 700);
  tampilkanLirik("long term", 600);
  tampilkanLirik("plan", 900);

  // "with short term fixes"
  tampilkanLirik("with", 400);
  tampilkanLirik("short term", 600);
  tampilkanLirik("fixes", 800);

  // "and a wasted heart"
  tampilkanLirik("and a", 500);
  tampilkanLirik("wasted heart", 700);

  // "that just eclipses"
  tampilkanLirik("that just", 700);
  tampilkanLirik("eclipses", 1300);

  // "and I'll push my luck"
  tampilkanLirik("and I'll", 500);
  tampilkanLirik("push my luck", 900);

  // "from trust to dust enough"
  tampilkanLirik("from trust", 800);
  tampilkanLirik("to dust", 600);
  tampilkanLirik("enough", 1000);

  // "that's the story of another us"
  tampilkanLirik("that's the", 600);
  tampilkanLirik("story", 500);
  tampilkanLirik("of another", 700);
  tampilkanLirik("us", 600);

  // "one last ditch a new beginning"
  tampilkanLirik("one last", 600);
  tampilkanLirik("ditch", 500);
  tampilkanLirik("a new", 600);
  tampilkanLirik("beginning", 850);

  // "so take this heart"
  tampilkanLirik("so take", 500);
  tampilkanLirik("this heart", 900);

  // "put yourself in it"
  tampilkanLirik("put", 400);
  tampilkanLirik("yourself", 650);
  tampilkanLirik("in it", 700);

  // "this surprise ending"
  tampilkanLirik("this", 400);
  tampilkanLirik("surprise", 600);
  tampilkanLirik("ending", 850);

  // "I'm depending on could be"
  tampilkanLirik("I'm", 400);
  tampilkanLirik("depending on", 900);
  tampilkanLirik("could be", 800);

  // "the story of another us"
  tampilkanLirik("the story", 700);
  tampilkanLirik("of another", 900);
  tampilkanLirik("us", 2500); // Tahan sedikit lebih lama di akhir

  // Layar mati sejenak sebelum mengulang (jika diletakkan di loop)
  display.clearDisplay();
  display.display();
  delay(3000); 
}