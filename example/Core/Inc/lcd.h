#ifndef LCD_H
#define LCD_H

//link file with main.h file
#include "main.h"
 
//function to use
void LCD_Init(void);
void LCD_SendCommand(uint8_t command);
void LCD_SendData(uint8_t data);
void LCD_Clear(void);
void LCD_WriteString(char* str);

#endif