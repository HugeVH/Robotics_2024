#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>


//#define LED_PIN GPIO2
//#define LED_PIN GPIO_NUM_2

constexpr gpio_num_t LED_PIN = GPIO_NUM_2;

extern "C" void app_main();

void app_main() {

    //setup
gpio_config_t config;
config.mode = GPIO_MODE_OUTPUT;
config.pin_bit_mask = (1<<LED_PIN);
config.intr_type = GPIO_INTR_DISABLE;
config.pull_down_en = GPIO_PULLDOWN_DISABLE;
config.pull_up_en = GPIO_PULLUP_DISABLE;


 //uint64_t pin_bit_mask;          /*!< GPIO pin: set with bit mask, each bit maps to a GPIO */
 //   gpio_mode_t mode;               /*!< GPIO mode: set input/output mode                     */
 //   gpio_pullup_t pull_up_en;       /*!< GPIO pull-up                                         */
 //   gpio_pulldown_t pull_down_en;   /*!< GPIO pull-down                                       */
 //   gpio_int_type_t intr_type;      /*!< GPIO interrupt type                                  */

gpio_config(&config);

    //loop

    while(1)

{
    gpio_set_level(LED_PIN, 1);
    vTaskDelay(pdMS_TO_TICKS(1000));
    gpio_set_level(LED_PIN, 0);
    vTaskDelay(pdMS_TO_TICKS(1000));

}

}