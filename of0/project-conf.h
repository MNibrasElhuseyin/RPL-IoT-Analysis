




// --------- of0 ------------

#ifndef PROJECT_CONF_H_
#define PROJECT_CONF_H_

// 1. Amaç Fonksiyonu Olarak OF0 (Hop Count) Seçimi 
#undef RPL_CONF_OF_OCP
#define RPL_CONF_OF_OCP 0  // 0 = OF0 (Objective Function Zero)

#undef RPL_CONF_SUPPORTED_OFS
#define RPL_CONF_SUPPORTED_OFS {&rpl_of0}

// 2. Log Seviyesini Yükseltme (Analiz için gerekli) 
// Bu sayede Rank ve Rota bilgilerini loglarda görebilirsiniz
#undef LOG_CONF_LEVEL_RPL
#define LOG_CONF_LEVEL_RPL LOG_LEVEL_INFO

// 3. Z1 Mote Bellek Optimizasyonu 
//Zolertia Z1 kısıtlı RAM'e sahip olduğu için kuyruk boyutunu düşük tutuyoruz 
#undef QUEUEBUF_CONF_NUM
#define QUEUEBUF_CONF_NUM 8

#endif //PROJECT_CONF_H_ 






