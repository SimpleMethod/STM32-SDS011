# STM32 SDS011
Library supporting SDS011 sensor on STM32F4 (NUCLEO-F411RE)

### Usage
1. Use  of structure
```cpp
/* USER CODE BEGIN PV */
SDS sds;
/* USER CODE END PV */
```

2. Library initialization
```cpp
/* USER CODE BEGIN 2 */
	sdsInit(&sds, &huart1);
/* USER CODE END 2 */
```

3. Addition HAL_UART_RxCpltCallback
```cpp
/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
sds_uart_RxCpltCallback(&sds,huart);
}
/* USER CODE END 4 */
```
