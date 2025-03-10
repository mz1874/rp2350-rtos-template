#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include "pico/stdlib.h"

void led_task(void *pvParameters)
{
    const char *taskName = (const char *)pvParameters;
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true)
    {
        printf("Task '%s' is running on core %d\n", taskName, get_core_num());
        gpio_put(LED_PIN, 1);
        vTaskDelay(100);
        gpio_put(LED_PIN, 0);
        vTaskDelay(100);
    }
}

void hello_task(void *pvParameters)
{
    const char *taskName = (const char *)pvParameters;
    while (true)
    {
        printf("Task '%s' is running on core %d\n", taskName, get_core_num());
        printf("hello\r\n");
        vTaskDelay(100);
    }
}

int main()
{
    stdio_init_all();

    xTaskCreate(led_task, "LED_Task", 1024, (void *)"Task1", 1, NULL);
    // vTaskCoreAffinitySet(NULL, 1 << 0); // 1 << 1 表示 Core 1
    xTaskCreate(hello_task, "hello_task", 1024, (void *)"Task2", 1, NULL);
    // vTaskCoreAffinitySet(NULL, 1 << 1); // 1 << 1 表示 Core 1
    vTaskStartScheduler();

    while (1)
    {
    };
}