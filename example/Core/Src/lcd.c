// link with lcd.h
#include "LCD.h"


//Initialization
void LCD_Init(void) {
  LCD_SendCommand(0x02);
  LCD_SendCommand(0x28);
  LCD_SendCommand(0x0C);
  LCD_SendCommand(0x06);
}

//apply command
void LCD_SendCommand(uint8_t command) {
  HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, (command >> 4) & 1);
  HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, (command >> 5) & 1);
  HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, (command >> 6) & 1);
  HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, (command >> 7) & 1);
  HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_SET);
  HAL_Delay(1);
  HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_RESET);
  HAL_Delay(1);
  HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, command & 1);
  HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, (command >> 1) & 1);
  HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, (command >> 2) & 1);
  HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, (command >> 3) & 1);
  HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_SET);
  HAL_Delay(1);
  HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_RESET);
  HAL_Delay(1);
}

//make data ready to send
void LCD_SendData(uint8_t data) {
  HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, (data >> 4) & 1);
  HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, (data >> 5) & 1);
  HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, (data >> 6) & 1);
  HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, (data >> 7) & 1);
  HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_SET);
  HAL_Delay(1);
  HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_RESET);
  HAL_Delay(1);
  HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, data & 1);
  HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, (data >> 1) & 1);
  HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, (data >> 2) & 1);
  HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, (data >> 3)& 1);
  HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_SET);
  HAL_Delay(1);
  HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_RESET);
  HAL_Delay(1);
}

//clear lcd's screen
void LCD_Clear(void) {
	LCD_SendCommand(0x01);
	HAL_Delay(2);
}

//send data to LCD
void LCD_WriteString(char* str) {
	while(*str) {
		LCD_SendData(*str++);
		HAL_Delay(1);
	}
}
