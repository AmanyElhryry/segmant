/*
 *
SW_interface.h
 *
 *  Created on: Mar 4, 2023
 *      Author: Amany
 */

#ifndef SEV_INTERFACE_H_
#define SEV_INTERFACE_H_


ES_t SEV_enuInit(void);
ES_t SEV_Segmant_enuDisplayNum(u8 Copy_u8_num);
ES_t SEV_Segmant_enuEnableComma(void);
ES_t SEV_Segmant_enuDisableComma(void);
ES_t SEV_Segmant_enuEnableDot(void);
ES_t SEV_Segmant_enuDisableDot(void);

ES_t SEV_Segmant_enuClearDisplay(void);
#endif
