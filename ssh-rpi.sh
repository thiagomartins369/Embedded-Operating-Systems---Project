#!/bin/bash

# Obtém o nome da Raspberry Pi na rede local
hostname=$(avahi-resolve-host-name raspberrypi.local | awk '{print $2}')

# Verifica se o nome foi encontrado
if [ -z "$hostname" ]; then
  echo "Não foi possível encontrar o nome da Raspberry Pi na rede local."
  exit 1
fi

# Conecta-se à Raspberry Pi via SSH
ssh pi@$hostname
