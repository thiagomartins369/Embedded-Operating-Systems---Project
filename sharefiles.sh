#!/bin/bash

# Nome do diretório a ser enviado
dir_path=/home/thiago/MEGAsync/FGA-UnB/Materias/UnB_2022-2/Sistemas_Operacionais_Embarcados/Projeto_SOE/Embedded-Operating-Systems---Project/Acionamento_Portao

# Encontrar o endereço IP da Raspberry Pi
hostname=192.168.15.4

# Endereço IP do Raspberry Pi
raspberry_ip=$hostname


# Destino no Raspberry Pi
destination=/home/pi/Documents/Embedded_Operating_Systems_Project

# Envio de todos os arquivos do diretório
scp -r $dir_path pi@$raspberry_ip:$destination
