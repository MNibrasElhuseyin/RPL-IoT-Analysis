// --------------   mrhof ------------

#ifndef PROJECT_CONF_H_
#define PROJECT_CONF_H_

// 1. Algoritma Seçimi: MRHOF (ETX Metriği) 
#undef RPL_CONF_OF_OCP
#define RPL_CONF_OF_OCP 1  // 1 değeri MRHOF algoritmasını temsil eder

//2. RPL Modu Ayarı (RPL-Lite kullanımı için) 
#undef RPL_CONF_SUPPORTED_OFS
#define RPL_CONF_SUPPORTED_OFS {&rpl_mrhof}

// 3. Log Seviyesi Ayarları (Simülasyon çıktısı için kritik) 
#undef LOG_CONF_LEVEL_RPL
#define LOG_CONF_LEVEL_RPL LOG_LEVEL_INFO

#undef LOG_CONF_LEVEL_TCPIP
#define LOG_CONF_LEVEL_TCPIP LOG_LEVEL_WARN

#endif // PROJECT_CONF_H_







