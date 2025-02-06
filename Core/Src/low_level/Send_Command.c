#include "keyboard_usbd_hid.h"
#include "usbd_hid.h"
#include <stdbool.h>


#define KEYCODE_TABLE_SIZE 49

extern USBD_HandleTypeDef hUsbDeviceFS;

bool command_first = 0;

typedef struct
{
	uint8_t MODIFIER;
	uint8_t RESERVED;
	uint8_t KEYCODE1;
	uint8_t KEYCODE2;
	uint8_t KEYCODE3;
	uint8_t KEYCODE4;
	uint8_t KEYCODE5;
	uint8_t KEYCODE6;
} keyboardHID;


uint8_t keycode_table[KEYCODE_TABLE_SIZE] = {
    // Символы 'a'-'z'
    0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B,
    0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13,
    0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B,
    0x1C, 0x1D,
	// Символы '0'-'9'
    0x27, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26,

    0x2D, // -
    0x2E, // =
    0x2F, // [
    0x30, // ]
    0x31, // "\"
    0x33, // ;
    0x34, // '
    0x35, // `
    0x36, // ,
    0x37, // .
    0x38, // "/"
	0x2C  // пробел
};

uint8_t get_hid_keycode(char c, uint8_t *modifier)
{
    *modifier = 0x00;

    // Символы 'a'-'z'
    if (c >= 'a' && c <= 'z')
    {
        return keycode_table[c - 'a'];
    }
    // Символы 'A'-'Z'
    else if (c >= 'A' && c <= 'Z')
    {
        *modifier = 0x02; // Shift
        return keycode_table[c - 'A'];
    }
    // Символы '0'-'9'
    else if (c >= '0' && c <= '9')
    {
        return keycode_table[c - '0' + 26];
    }
    // Часто используемые символы
    else
    {
    	switch (c)
        {
        		case ' ': return keycode_table[47]; // Пробел
        		case '-': *modifier = 0x00; return keycode_table[36]; // -
        		case '=': *modifier = 0x00; return keycode_table[37]; // =
        		case '[': *modifier = 0x00; return keycode_table[38]; // [
        		case ']': *modifier = 0x00; return keycode_table[39]; // ]
        		case '\\': *modifier = 0x00; return keycode_table[40]; // "\"
        		case ';': *modifier = 0x00; return keycode_table[41]; // ;
        		case '\'': *modifier = 0x00; return keycode_table[42]; // '
        		case '`': *modifier = 0x00; return keycode_table[43]; // `
        		case ',': *modifier = 0x00; return keycode_table[44]; // ,
        		case '.': *modifier = 0x00; return keycode_table[45]; // .
        		case '/': *modifier = 0x00; return keycode_table[46]; // /

        		// Символы с Shift
        		case '!': *modifier = 0x02; return keycode_table[27]; // Shift + 1
        		case '@': *modifier = 0x02; return keycode_table[28]; // Shift + 2
        		case '#': *modifier = 0x02; return keycode_table[29]; // Shift + 3
        		case '$': *modifier = 0x02; return keycode_table[30]; // Shift + 4
        		case '%': *modifier = 0x02; return keycode_table[31]; // Shift + 5
        		case '^': *modifier = 0x02; return keycode_table[32]; // Shift + 6
        		case '&': *modifier = 0x02; return keycode_table[33]; // Shift + 7
        		case '*': *modifier = 0x02; return keycode_table[34]; // Shift + 8
        		case '(': *modifier = 0x02; return keycode_table[35]; // Shift + 9
        		case ')': *modifier = 0x02; return keycode_table[26]; // Shift + 0
        		case '_': *modifier = 0x02; return keycode_table[36]; // Shift + -
        		case '+': *modifier = 0x02; return keycode_table[37]; // Shift + =
        		case '{': *modifier = 0x02; return keycode_table[38]; // Shift + [
        		case '}': *modifier = 0x02; return keycode_table[39]; // Shift + ]
        		case '|': *modifier = 0x02; return keycode_table[40]; // Shift + "\"
        		case ':': *modifier = 0x02; return keycode_table[41]; // Shift + ;
        		case '"': *modifier = 0x02; return keycode_table[42]; // Shift + '
        		case '~': *modifier = 0x02; return keycode_table[43]; // Shift + `
        		case '<': *modifier = 0x02; return keycode_table[44]; // Shift + ,
        		case '>': *modifier = 0x02; return keycode_table[45]; // Shift + .
        		case '?': *modifier = 0x02; return keycode_table[46]; // Shift + /
        		default: return 0x00;
        }
    }
}


keyboardHID keyboardhid = {0, 0, 0, 0, 0, 0, 0, 0};

void press_enter()
{
    HAL_Delay(250);
    keyboardhid.MODIFIER = 0x00;
    keyboardhid.KEYCODE1 = 0x28; // HID код клавиши Enter
    USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&keyboardhid, sizeof(keyboardhid));

    HAL_Delay(50);

    // Освобождение нажатия клавиши Enter
    keyboardhid.KEYCODE1 = 0x00;
    USBD_HID_SendReport(&hUsbDeviceFS,(uint8_t*)&keyboardhid, sizeof(keyboardhid));
}


void write_text(const char* str)
{
    while (*str)
    {
        char c = *str;
        uint8_t modifier = 0x00;
        uint8_t keycode = get_hid_keycode(c, &modifier);

        if (keycode != 0)
        {
            HAL_Delay(250);
            keyboardhid.MODIFIER = modifier;
            keyboardhid.KEYCODE1 = keycode;

            USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&keyboardhid, sizeof(keyboardhid));

            HAL_Delay(50);

            // Освобождение нажатия клавиши
            keyboardhid.KEYCODE1 = 0x00;
            keyboardhid.MODIFIER = 0x00;
            USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&keyboardhid, sizeof(keyboardhid));
        }
        str++;
    }
}

void write_command(const char* str) {
    uint8_t modifier_button = 0x00; // Для модификаторов (CTRL, ALT, SHIFT)
    uint8_t keycode = 0x00;         // Для функциональных клавиш (например, F4)
    uint8_t keycode_2 = 0x00;       // Для символов
    uint8_t modifier_character = 0x00; // Для символов, требующих модификатор

    char filtered_string[256] = {0}; // Новая строка без модификаторов и F-клавиш
    size_t filtered_index = 0;

    // Проверяем наличие флага command_first
    size_t len = 0;
    if (command_first) {
        len = strlen(str) - 3; // Убираем флаг "-f" из строки
        command_first = 0;
    } else {
        len = strlen(str);
    }

    // Обработка исходной строки
    while (*str && len--) {
        // Проверяем модификаторы
        if (strstr(str, "alt")) {
            modifier_button |= 0x04; // ALT
            str += 3;
        } else if (strstr(str, "ctrl")) {
            modifier_button |= 0x01; // CTRL
            str += 4;
        } else if (strstr(str, "shift")) {
            modifier_button |= 0x02; // SHIFT
            str += 5;
        } else if (strstr(str, "f") == str && *(str + 1) >= '1' && *(str + 1) <= '9') {
            keycode = (*(str + 1) - '0' - 1) + 0x3A; // F1-F9
            str += 2;
        } else if (strstr(str, "f10") == str) {
            keycode = 0x43; // F10
            str += 3;
        } else if (strstr(str, "f11") == str) {
            keycode = 0x57; // F11
            str += 3;
        } else if (strstr(str, "f12") == str) {
            keycode = 0x58; // F12
            str += 3;
        } else if (*str == ' ') {
        	while(*str == ' ') {
        		str++;
        		continue;
        	}
        }
        else {
            // Копируем оставшиеся символы в новую строку
            filtered_string[filtered_index++] = *str;
        }

    }

    filtered_string[filtered_index] = '\0'; // Завершаем строку

    // Проходим по оставшейся строке и обрабатываем символы, если есть
    str = filtered_string;
    if (*str) {
        keycode_2 = get_hid_keycode(*str, &modifier_character);
    }

    // Отправляем комбинацию
    HAL_Delay(200);
    keyboardhid.MODIFIER = modifier_button;
    keyboardhid.KEYCODE1 = keycode;
    keyboardhid.KEYCODE2 = keycode_2;

    USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&keyboardhid, sizeof(keyboardhid));
    HAL_Delay(50);

    // Освобождаем клавиши
    keyboardhid.MODIFIER = 0x00;
    keyboardhid.KEYCODE1 = 0x00;
    keyboardhid.KEYCODE2 = 0x00;

    USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&keyboardhid, sizeof(keyboardhid));
}



void send_command_to_device(const char* message)
{

	    const char* part1 = message;
	    const char* part2 = strchr(message, '#');

	    if (part2) // Если '#' найден, разделить строку на две части
	    {

	    	if(strstr(message, "-f")) {
	    		command_first = 1;
	    	}

	        size_t part1_len = part2 - part1;
	        char cmd1[part1_len + 1];
	        strncpy(cmd1, part1, part1_len);
	        cmd1[part1_len] = '\0';

	        const char* cmd2 = part2 + 1;

	        if(command_first) {
	        	write_command(cmd2);
	        	write_text(cmd1);
	        	press_enter();
	        }
	        else {
	        	write_text(cmd1);
	        	press_enter();
	        	write_command(cmd2);
	        }
	    }
	    else
	    {
	    	write_text(message);
	        press_enter();
	    }
}






