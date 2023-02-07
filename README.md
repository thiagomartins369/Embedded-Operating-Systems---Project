# Embedded-Operating-Systems---Project
This repository was created to host the codes created for the final project of the discipline of embedded operating systems, carried out in the Electronic Engineering course at the University of Brasília (UnB).

## Acionamento do Portão

### Configuração do setup
Antes de utilizar o código deve ser instalado a biblioteca (WiringPi)[https://github.com/WiringPi/WiringPi.git] para utilização das funções para escrita e leitura de arquivos.

1. Ir para diretório padrão
``` bash
cd
```
2. Deve ser copiado para armazenamento local o repositório com seguinte comando:
``` bash
git clone https://github.com/WiringPi/WiringPi.git
```
3. Após completo a clonagem do repositório dentro do seu diretório construa:
``` bash
./build
```
4. Verifique se foi instalado dando o comando:
``` bash
gpio -v
```

### Funcionamento das funções