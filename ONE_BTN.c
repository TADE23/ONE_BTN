#define TIME_BEF_START_ACTION 400 //you can change it
#define USER_BTN_PIN BTN_2_Pin    //you can change it
#define USER_PORT_BTN_PIN GPIOB   //you can change it

#include <stdbool.h>

void blink3(void) {
	HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 1);
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 0);
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 1);
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 0);
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 1);
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 0);
	HAL_Delay(300);
}

void blink4(void) {
	HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 1);
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 0);
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 1);
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 0);
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 1);
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 0);
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 1);
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 0);
	HAL_Delay(300);
}

void blink5(void) {
	HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 1);
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 0);
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 1);
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 0);
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 1);
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 0);
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 1);
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 0);
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 1);
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 0);
	HAL_Delay(300);
}

uint8_t click = 0; //to store num of click
	bool click_flug = true;
	bool flug_time_press = true; //for don't set new press btn time if it's already set

uint64_t time_press = 0; //time when btn was pressed
	bool flug_for_timer = false; //flug for store time when btn will be pressed


if (!HAL_GPIO_ReadPin(USER_PORT_BTN_PIN, USER_BTN_PIN) && click_flug) {
			if (flug_time_press) {
				flug_for_timer = true;
				//flug_time_press = false;
			}

			click_flug = false;
			click++;
		}
		if (HAL_GPIO_ReadPin(USER_PORT_BTN_PIN, USER_BTN_PIN)) { //only when but is unpress click can be incremented
			click_flug = true;
		}
		if (flug_for_timer) {
			time_press = HAL_GetTick();
			flug_for_timer = false;
		}
		if ((HAL_GetTick() - time_press >= TIME_BEF_START_ACTION)
				&& HAL_GPIO_ReadPin(USER_PORT_BTN_PIN, USER_BTN_PIN)) {
			//-------------------------------
			//action:
			switch (click) {
			case 1:
				HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 1);
				break;

			case 2:
				HAL_GPIO_WritePin(GPIOC, LED_PC14_Pin, 0);
				break;

			case 3:
				blink3();
				break;

			case 4:
				blink4();
				break;

			case 5:
				blink5();
				break;
			}
			//-------------------------------

			//-------------------------------
			//reset:
			flug_for_timer = false;	//initial value
			flug_time_press = true;	//initial value
			click_flug = true;	//initial value
			click = 0;		//initial value
			//-------------------------------
		}

		//------------------------------------------------------------
