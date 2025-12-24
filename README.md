# IoT RPL Yönlendirme Protokolü Analizi (OF0 vs MRHOF)

Bu proje, **RPL (Düşük Güçlü ve Kayıplı Ağlar için IPv6 Yönlendirme Protokolü)** performansını, bir IoT ortamında farklı Amaç Fonksiyonları (Objective Functions - OF) altında analiz etmektedir. Çalışma, Contiki-NG işletim sistemi ve Cooja simülatörü kullanarak **OF0 (Objective Function Zero)** ve **MRHOF (Minimum Rank with Hysteresis Objective Function)** algoritmalarını karşılaştırmaktadır.

## 📌 Proje Özeti
- **Protokol:** RPL (RFC 6550)
- **Amaç Fonksiyonları:** OF0 (RFC 6552) ve MRHOF (RFC 6719)
- **Donanım Platformu:** Zolertia Z1 Mote (MSP430, 8KB RAM)
- **Simülatör:** Cooja (Contiki-NG)
- **Ağ Topolojisi:** 1 Kök (Root) + 10 İstemci (Client) Düğüm (Rastgele Konumlandırma)

## 📊 Temel Bulgular
10 dakikalık simülasyonlardan elde edilen deneysel sonuçlar, hız ve kararlılık arasında belirgin farklar olduğunu göstermektedir:

| Metrik | OF0 (Hop Count) | MRHOF (ETX) | Analiz |
| :--- | :--- | :--- | :--- |
| **Güvenilirlik (PDR)** | %100 | %100 | Her iki protokol de bu topolojide tam paket teslimi sağladı. |
| **Ort. Gecikme** | **72.53 ms** | 75.02 ms | OF0, en kısa fiziksel yolu seçtiği için biraz daha hızlıdır (~2.5ms). |
| **Kararlılık (Ebeveyn Değişimi)** | Düşük | **Yüksek** | MRHOF, Histerezis mekanizması sayesinde daha kararlıdır. |
| **Kontrol Yükü (DAO)** | 264 pkt | **228 pkt** | OF0, kararsızlık nedeniyle daha fazla rota güncellemesi gönderir. |
| **Bellek Verimliliği** | Düşük | **Daha İyi** | MRHOF, Z1 donanımında bellek taşması hatalarını %15 azalttı. |

## 🚀 Simülasyon Nasıl Çalıştırılır

### Ön Gereksinimler
- **Contiki-NG:** Contiki-NG  (Docker/Sanal Makine).
- **Cooja Simülatörü:** `.csc` simülasyon dosyasını çalıştırmak için gereklidir.

### Kurulum ve Çalıştırma
1.  **Depoyu Klonlayın:**
    ```bash
    git clone https://github.com/MNibrasElhuseyin/RPL-IoT-Analysis.git
    cd RPL-IoT-Analysis
    ```

2.  **Mote'ları Derleyin:**
    Proje dizinin içinde ki mrhof veya of0 gidin ve Z1 mote için sunucu ve istemci yazılımlarını derleyin:
    ```bash
    make TARGET=z1 udp-server
    make TARGET=z1 udp-client
    ```

3.  **Cooja'da Açın:**
    - Cooja'yı başlatın: `contiki-ng/tools/cooja/./gradlew run`
    - `File > Open Simulation` menüsüne gidin ve `mrhof.csc` veya `of0.csc` dosyasını seçin.
    - 11 düğümlü (1 Sunucu, 10 İstemci) topoloji yüklenecektir.

4.  **Simülasyonu Başlatın:**
    - Cooja kontrol panelindeki **Start** butonuna tıklayın.
    - `Mote Output` penceresinden RPL loglarını (ebeveyn değişimi, DIS mesajları vb.) izleyin.
    - Paket akışını görselleştirmek için `Timeline` ve `Network` görünümlerini kullanın.

## 📝 Sonuç
- **OF0 Kullanın:** Hızın kritik olduğu, gecikmeye duyarlı ve basit sensör ağları için.
- **MRHOF Kullanın:** Bağlantı güvenilirliği ve ağ kararlılığının öncelikli olduğu kayıplı ortamlar için.
- **Donanım Notu:** Z1 mote'un 8KB RAM'i, 10 düğümden büyük RPL ağları için darboğaz oluşturmaktadır; ölçeklenebilirlik için CC2538 (32KB RAM) gibi donanımlara geçilmesi önerilir.

---
