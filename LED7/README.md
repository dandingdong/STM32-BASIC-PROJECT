# 7-Segment LED Driver for STM32F103C8T6

A lightweight, hardware-independent C driver for controlling single-digit **7-Segment LED** displays on the **STM32F103C8T6 (Blue Pill)** microcontroller using the STM32 HAL library.

## ✨ Features
* **Dual Type Support:** Supports both **Common Anode** (`LED_ANODE`) and **Common Cathode** (`LED_CATHODE`) configurations (currently configured for `LED_ANODE` in `main.c`).
* **Modular Struct Design:** Encapsulates GPIO port, pin mappings, and display type inside a clean `LED7` handle struct (`myLED7`).
* **Safe Input Handling:** Includes built-in bounds checking (`0–9`) to prevent out-of-range memory access.
* **Memory Optimized:** Lookup table (`segment_code`) is stored in Flash memory (`static const`) to save SRAM.

---

## 📁 Folder Structure
```text
LED7/
├── Core/               # STM32CubeMX generated startup & main application
│   ├── Inc/            # Header files (main.h, stm32f1xx_hal_conf.h, etc.)
│   └── Src/            # Source files (main.c, system_stm32f1xx.c, etc.)
├── myLib/              # Custom 7-Segment LED driver
│   ├── led7.h          # Struct definitions & function prototypes
│   └── led7.c          # Bit-shifting logic & lookup table implementation
├── LED7.ioc            # STM32CubeMX hardware configuration file
└── README.md           # Project documentation
```

---

## ⚙️ Hardware & Clock Configuration
* **MCU:** STM32F103C8T6
* **System Clock:** 8 MHz (Internal RC Oscillator - `HSI`, `PLL_NONE`)
* **GPIO Mode:** Output Push-Pull, No Pull-up/Pull-down, Low Speed

### Pinout Mapping (`GPIOA`)
Connect segments **A through G** of the Common Anode 7-segment display (via `220Ω–330Ω` current-limiting resistors) to **GPIOA**:

| LED Segment | STM32 Pin | Pin Function |
| :---: | :---: | :---: |
| **A** | `PA0` | `GPIO_Output` |
| **B** | `PA1` | `GPIO_Output` |
| **C** | `PA2` | `GPIO_Output` |
| **D** | `PA3` | `GPIO_Output` |
| **E** | `PA4` | `GPIO_Output` |
| **F** | `PA5` | `GPIO_Output` |
| **G** | `PA6` | `GPIO_Output` |
| **COM** | `3.3V` | Common Anode Supply |

---

## 🚀 Usage Example (`Core/Src/main.c`)

```c
#include "main.h"
#include "led7.h"

LED7 myLED7;

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();

  /* Initialize Common Anode 7-Segment LED on PA0 -> PA6 */
  LED7_Init(&myLED7, GPIOA, 
            GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3, 
            GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, LED_ANODE);

  while (1)
  {
    /* Display digit 9 on the 7-segment LED */
    LED7_print(&myLED7, 9);
  }
}
```
