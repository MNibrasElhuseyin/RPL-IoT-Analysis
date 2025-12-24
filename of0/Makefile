CONTIKI_PROJECT = udp-client udp-server
all: $(CONTIKI_PROJECT)

# RPL-Lite kütüphanesini zorunlu kılar
ROUTING = rpl-lite

# project-conf.h dosyasını projeye dahil eder
CFLAGS += -DPROJECT_CONF_H=\"project-conf.h\"

CONTIKI=../../..
include $(CONTIKI)/Makefile.include
