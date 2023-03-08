/*
 * SW_program.c
 *
 *  Created on: Mar 4, 2023
 *      Author: Amany
 */


#include "STD_TYPE.h"
#include "error_status.h"
#include "SEV_private.h"
#include "SEV_config.h"
#include "SEV_interface.h"
#include "DIO_interface.h"

ES_t SEV_enuInit(void){
	ES_t Local_enuErorrState=ES_NOK;
u32 Local_u32Check=0;
Local_u32Check = DIO_enuSetPinDirection(SEG_PORTA,SEG_PINA,OUTPUT);
Local_u32Check |= DIO_enuSetPinDirection(SEG_PORTB,SEG_PINB,OUTPUT)<<3;
Local_u32Check |= DIO_enuSetPinDirection(SEG_PORTC,SEG_PINC,OUTPUT)<<6;
Local_u32Check |= DIO_enuSetPinDirection(SEG_PORTD,SEG_PIND,OUTPUT)<<9;
Local_u32Check |= DIO_enuSetPinDirection(SEG_PORTE,SEG_PINE,OUTPUT)<<12;
Local_u32Check |= DIO_enuSetPinDirection(SEG_PORTF,SEG_PINF,OUTPUT)<<15;
Local_u32Check |= DIO_enuSetPinDirection(SEG_PORTG,SEG_PING,OUTPUT)<<18;
 u8 Local_itrator=0;
 for(Local_itrator=0;Local_itrator<(sizeof(Local_u32Check)*8);Local_itrator+=3){
	if((Local_u32Check>>Local_itrator)&7 != ES_OK ) {
		Local_enuErorrState=ES_NOK;
	}
 }


#if SEV_COM <= DIO_PIN7 &&  SEV_COM_PORT<=DIO_PORTD
	DIO_enuSetPinDirection(SEV_COM_PORT,SEV_COM,OUTPUT);
#elif SEV_COM <= NOT_CONECTED ||  SEV_COM_PORT<=NOT_CONECTED

#endif

#if SEV_DOT <= DIO_PIN7 &&  SEV_DOT_PORT<=DIO_PORTD
	DIO_enuSetPinDirection(SEV_DOT_PORT,SEV_DOT,OUTPUT);
#elif SEV_COM <= NOT_CONECTED ||  SEV_DOT_PORT<=NOT_CONECTED

#endif

	 Local_enuErorrState=ES_OK;
	return Local_enuErorrState;
}
ES_t SEV_Segmant_enuDisplayNum(u8 Copy_u8_num){
	u8 SEG_NUM[]={0x3F,0x06,0x5B ,0x4F,0x66, 0x6D ,0x7D ,0x07,0x7F,0x6F}  ;
	ES_t Local_enuErorrState=ES_NOK;
 if(Copy_u8_num<=10){

#if SEV_TYPE == COMMON_ANOD
 DIO_enuSetPinValue(SEG_PORTA,SEG_PINA,(SEG_NUM[Copy_u8_num]>>0)&1);
DIO_enuSetPinValue(SEG_PORTB,SEG_PINB,(SEG_NUM[Copy_u8_num]>>1)&1);
DIO_enuSetPinValue(SEG_PORTC,SEG_PINC,(SEG_NUM[Copy_u8_num]>>2)&1);
DIO_enuSetPinValue(SEG_PORTD,SEG_PIND,(SEG_NUM[Copy_u8_num]>>3)&1);
DIO_enuSetPinValue(SEG_PORTE,SEG_PINE,(SEG_NUM[Copy_u8_num]>>4)&1);
DIO_enuSetPinValue(SEG_PORTF,SEG_PINF,(SEG_NUM[Copy_u8_num]>>5)&1);
 DIO_enuSetPinValue(SEG_PORTG,SEG_PING,(SEG_NUM[Copy_u8_num]>>6)&1);

#elif SEV_TYPE == COMMON_KATHOD
DIO_enuSetPinValue(SEG_PORTA,SEG_PINA,!(SEG_NUM[Copy_u8_num]>>0)&1);
DIO_enuSetPinValue(SEG_PORTB,SEG_PINB,!(SEG_NUM[Copy_u8_num]>>1)&1);
DIO_enuSetPinValue(SEG_PORTC,SEG_PINC,!(SEG_NUM[Copy_u8_num]>>2)&1);
DIO_enuSetPinValue(SEG_PORTD,SEG_PIND,!(SEG_NUM[Copy_u8_num]>>3)&1);
DIO_enuSetPinValue(SEG_PORTE,SEG_PINE,!(SEG_NUM[Copy_u8_num]>>4)&1);
DIO_enuSetPinValue(SEG_PORTF,SEG_PINF,!(SEG_NUM[Copy_u8_num]>>5)&1);
 DIO_enuSetPinValue(SEG_PORTG,SEG_PING,!(SEG_NUM[Copy_u8_num]>>6)&1);

#endif

 Local_enuErorrState=ES_OK;
 }
 else
 {
	 Local_enuErorrState=ES_OUTOFRANGE;
 }

return Local_enuErorrState;
}
ES_t SEV_Segmant_enuEnableComma(void){
	ES_t Local_enuErorrState=ES_NOK;
#if SEV_COM <= DIO_PIN7 &&  SEV_COM_PORT<=DIO_PORTD
#if SEV_TYPE == COMMON_CATHOD
	Local_enuErorrState=DIO_enuSetPinValue(SEV_COM_PORT,SEV_COM,LOW);
#elif SEV_TYPE == COMMON_ANOD
	Local_enuErorrState=DIO_enuSetPinValue(SEV_COM_PORT,SEV_COM,HIGH);
#endif
#elif SEV_COM <= NOT_CONECTED ||  SEV_COM_PORT<=NOT_CONECTED
#endif
		return Local_enuErorrState;
}
ES_t SEV_Segmant_enuDisableComma(void){

	ES_t Local_enuErorrState=ES_NOK;
#if SEV_COM <= DIO_PIN7 &&  SEV_COM_PORT<=DIO_PORTD
#if SEV_TYPE == COMMON_CATHOD
	Local_enuErorrState=DIO_enuSetPinValue(SEV_COM_PORT,SEV_COM,HIGH);
#elif SEV_TYPE == COMMON_ANOD
	Local_enuErorrState=DIO_enuSetPinValue(SEV_COM_PORT,SEV_COM,LOW);
#endif
#elif SEV_COM <= NOT_CONECTED ||  SEV_COM_PORT<=NOT_CONECTED
#endif
		return Local_enuErorrState;

}
ES_t SEV_Segmant_enuEnableDot(void){

	ES_t Local_enuErorrState=ES_NOK;
#if SEV_DOT <= DIO_PIN7 &&  SEV_DOT_PORT<=DIO_PORTD
#if SEV_TYPE == COMMON_CATHOD
	Local_enuErorrState=DIO_enuSetPinValue(SEV_DOT_PORT,SEV_DOT,HIGH);
#elif SEV_TYPE == COMMON_ANOD
	Local_enuErorrState=DIO_enuSetPinValue(SEV_DOT_PORT,SEV_DOT,LOW);
#endif
#elif SEV_DOT <= NOT_CONECTED ||  SEV_DOT_PORT<=NOT_CONECTED
#endif
		return Local_enuErorrState;

}
ES_t SEV_Segmant_enuDisableDot(void){

	ES_t Local_enuErorrState=ES_NOK;
#if SEV_DOT <= DIO_PIN7 &&  SEV_DOT_PORT<=DIO_PORTD
#if SEV_TYPE == COMMON_CATHOD
	Local_enuErorrState=DIO_enuSetPinValue(SEV_DOT_PORT,SEV_DOT,LOW);
#elif SEV_TYPE == COMMON_ANOD
	Local_enuErorrState=DIO_enuSetPinValue(SEV_DOT_PORT,SEV_DOT,HIGH);
#endif
#elif SEV_DOT <= NOT_CONECTED ||  SEV_DOT_PORT<=NOT_CONECTED
#endif
		return Local_enuErorrState;

}

ES_t SEV_Segmant_enuClearDisplay(void){
	ES_t Local_enuErorrState=ES_NOK;

#if SEV_TYPE == COMMON_CATHOD
DIO_enuSetPinValue(SEG_PORTA,SEG_PINA,LOW);
DIO_enuSetPinValue(SEG_PORTB,SEG_PINB,LOW);
DIO_enuSetPinValue(SEG_PORTC,SEG_PINC,LOW);
DIO_enuSetPinValue(SEG_PORTD,SEG_PIND,LOW);
DIO_enuSetPinValue(SEG_PORTE,SEG_PINE,LOW);
DIO_enuSetPinValue(SEG_PORTF,SEG_PINF,LOW);
DIO_enuSetPinValue(SEG_PORTG,SEG_PING,LOW);

#elif SEV_TYPE == COMMON_ANOD
DIO_enuSetPinValue(SEG_PORTA,SEG_PINA,HIGH;
DIO_enuSetPinValue(SEG_PORTB,SEG_PINB,HIGH;
DIO_enuSetPinValue(SEG_PORTC,SEG_PINC,HIGH;
DIO_enuSetPinValue(SEG_PORTD,SEG_PIND,HIGH;
DIO_enuSetPinValue(SEG_PORTE,SEG_PINE,HIGH;
DIO_enuSetPinValue(SEG_PORTF,SEG_PINF,HIGH;
 DIO_enuSetPinValue(SEG_PORTG,SEG_PINGHIGH);

#endif

 Local_enuErorrState=ES_OK;


return Local_enuErorrState;
}
