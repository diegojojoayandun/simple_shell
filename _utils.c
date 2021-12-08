#include "main.h"
/**
 * @brief
 *
 */
void custom_prompt(char *color_prompt, char *color_text)
{
	prompt = _strcat(color_prompt,"$ ");
	prompt = _strcat(prompt,color_text);
}
