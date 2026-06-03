# PAP---Atmosense-Esta-o-Meteorol-gica-Compacta
# Estação Meteorológica Compacta

## Descrição do Projeto

A Estação Meteorológica Compacta é um projeto desenvolvido no âmbito da Prova de Aptidão Profissional (PAP), com o objetivo de monitorizar e apresentar informações atmosféricas em tempo real através de sensores eletrónicos e de um microcontrolador Arduino Mega.

O sistema é capaz de recolher dados relativos à temperatura ambiente, humidade relativa do ar, pressão atmosférica e qualidade do ar, apresentando as informações num display LCD para consulta local. Adicionalmente, os dados podem ser enviados para plataformas IoT através de um script desenvolvido em Python, permitindo a monitorização remota e o armazenamento online das leituras efetuadas.

Este projeto pretende demonstrar a aplicação prática de conceitos de eletrónica, programação, sistemas embebidos, aquisição de dados e Internet das Coisas (IoT), através da construção de uma solução compacta, acessível e funcional.

---

## Objetivos

* Monitorizar condições atmosféricas em tempo real;
* Recolher dados ambientais através de sensores eletrónicos;
* Apresentar informações num display LCD;
* Integrar múltiplos sensores num único sistema;
* Permitir a monitorização remota através de plataformas IoT;
* Desenvolver competências nas áreas de programação e eletrónica.

---

## Funcionalidades

* Leitura de temperatura ambiente;
* Leitura de humidade relativa do ar;
* Monitorização da pressão atmosférica;
* Monitorização da qualidade do ar;
* Leitura de precipitação;
* Monitorização da Velocidade do vento;
* Apresentação dos dados em tempo real num LCD;
* Comunicação série entre Arduino e computador;
* Integração com plataformas IoT para armazenamento e visualização de dados.

---

## Tecnologias Utilizadas

### Hardware

* Arduino Mega 2560
* Sensor DHT22
* Sensor BME280
* Sensor MQ-135
* Sensor FC-37
* Anemómetro
* Display LCD 16x2
* Cabos de ligação
* Ligadores
* Estrutura física da estação

### Software

* Arduino IDE
* Linguagem C/C++
* Python 3
* Bibliotecas Arduino:

  * DHT Sensor Library
  * Adafruit Unified Sensor
  * Adafruit BME280
  * LiquidCrystal I2C
    
* Bibliotecas Python:

  * pyserial
  * requests

---

## Arquitetura do Sistema

Sensores → Arduino Mega → Comunicação USB → Script Python → Plataforma IoT

O Arduino é responsável pela recolha e processamento dos dados dos sensores. Posteriormente, os dados são enviados através da porta série para um programa desenvolvido em Python, que efetua o envio para plataformas online de monitorização.

---

## Instalação

### 1. Instalar o Arduino IDE

Transferir e instalar o Arduino IDE:
https://www.arduino.cc/en/software

### 2. Instalar as bibliotecas necessárias

Instalar através do Gestor de Bibliotecas:

* DHT Sensor Library
* Adafruit Unified Sensor
* Adafruit BME280 Library
* LiquidCrystal I2C

### 3. Carregar o código para o Arduino

* Ligar o Arduino Mega a uma fonte de alimentação adequada (3.3-5V).
* Ligar o Anemómetro separadamente a uma fonte de alimentação adequada (10-30V).
* Selecionar a porta COM correta.
* Compilar e carregar o programa.

### 4. Instalar dependências Python

Executar:

pip install pyserial requests

### 5. Executar o script de monitorização

Executar o script Python responsável pela leitura da porta série e envio dos dados para a plataforma IoT utilizada.

---

## Resultados Obtidos

O projeto permitiu desenvolver uma estação meteorológica funcional capaz de monitorizar condições atmosféricas em tempo real, apresentando os dados localmente e disponibilizando-os remotamente através de plataformas online.

---

## Melhorias Futuras

* Implementação de conectividade Wi-Fi;
* Implementação de um Display TFT 2.2;

---

## Autor

Projeto desenvolvido por Rodrigo Baptista no âmbito da Prova de Aptidão Profissional (PAP).

