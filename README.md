# carb-OS

**carb-OS** es un sistema operativo ligero diseñado para dispositivos basados en Arduino, optimizado para la gestión de sensores y la comunicación con tecnología LoRa. Este sistema operativo permite la ejecución de tareas multitarea cooperativa, facilita la integración con sensores, y permite enviar datos a través de LoRa, haciéndolo ideal para aplicaciones de monitoreo remoto.

## Características Principales

1. **Multitarea Cooperativa**: carb-OS utiliza un sistema de planificación basado en intervalos de tiempo (`millis()`) para ejecutar múltiples tareas de forma concurrente.
2. **Gestión de Sensores**: El sistema permite integrar y leer sensores, enviando sus datos a través de LoRa.
3. **Compatibilidad con LoRa**: Integra la biblioteca `LoRa.h` para transmitir datos de sensores y mensajes de diagnóstico a través de módulos LoRa compatibles.

## Requisitos de Hardware

- **Arduino Nano** o compatible
- **Módulo LoRa** (Ej. SX1276/77/78/79)
- **Sensores**: Sensores analógicos compatibles, conectados a pines de entrada (Ej. A0, A1)

## Requisitos de Software

- **Biblioteca LoRa**: Instala la biblioteca `LoRa.h` desde el Administrador de Bibliotecas de Arduino.

## Configuración de carb-OS

### Pines de LoRa
Ajusta los pines en el archivo principal para conectar tu módulo LoRa:
- `LORA_SS`: Pin de selección de chip (CS)
- `LORA_RST`: Pin de reset del módulo
- `LORA_DIO0`: Pin DIO0 del módulo LoRa

Ejemplo de configuración:
```cpp
#define LORA_SS 10   // Pin CS del módulo LoRa
#define LORA_RST 9   // Pin RST del módulo LoRa
#define LORA_DIO0 2  // Pin DIO0 del módulo LoRa
