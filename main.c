#include<lpc21xx.h>
#include"header.h"
#include"macro.h"
u8 d1,d2,d3,d4;
u8 sa,addr,data;

int main()
{
        float temp,vout;
        u32 adcout;
        uart0_init(9600);
        adc_init();
        i2c_init();
        rtc_write();
        uart0_tx_string("========================================\n\r");
        uart0_tx_string("SMART PRECISION AGRICULTURE SYSTEM       \n\r");
        uart0_tx_string("========================================\n\r");

        while(1)
        {


                uart0_string("soil sensor\r\n");
                adcout=adc_read(0);
                vout=(adcout*100)/1023;
                uart0_float(vout);
                uart0_string("% \r\n");
                d1=(u8)vout&0xff;
                soil_sensor(vout);
				 delay_ms(300);

                uart0_string("WATER LEVEAL \r\n");
                adcout=adc_read(1);
                vout=(adcout*100)/1023;
                uart0_float(vout);
                uart0_string("%\r\n");
                d2=(u8)vout&0xff;
                water_sensor(vout);
                delay_ms(300); 
				uart0_string("temp sensor\r\n");
                adcout=adc_read(2);
            //    vout=(adcout*3.3)/1023;
            //   temp=(vout/0.01);
			 temp=((float)adcout*330.f)/1023.0f;
                uart0_float(temp);
                uart0_string("c\r\n");
                d3=(u8)temp&0xff;
                temp_sensor(temp); 
				 delay_ms(300);

              uart0_string("ldr sensor\r\n");
                adcout=adc_read(3);
                vout=(adcout*3.3)/1023;
                uart0_int(adcout);
                uart0_string("c \r\n");
                d4=(u8)adcout&0xff;
                ldr_sensor(adcout);
				 delay_ms(300);

                uart0_string("RAIN SENSOR\r\n");
                if((IOPIN0&RAIN))
                {
                        uart0_string("rain is detected\r\n");
                        uart0_tx_string("Pump Status : OFF\r\n");
                }
                else
                {
                        uart0_string("rain is not detected\r\n");
                        uart0_tx_string("Pump Status : READY\r\n");
                } 

 				uart0_string("PIR SESNOR\r\n");
                if((IOPIN0&PIR))
                {

                        uart0_tx_string("Motion Status : DETECTED\r\n");
                        uart0_tx_string("Security : ALERT\r\n");
                }
                else
                {
                        uart0_tx_string("Motion Status : CLEAR \r\n");
                        uart0_tx_string("Security : NORMAL \r\n");
                }
				 delay_ms(300);
                uart0_string("FLAME SENSOR\r\n");
                if((IOPIN0&FLAME)==0)
                {
                        uart0_tx_string("Flame Status : DETECTED \r\n");
                        uart0_tx_string("Alarm : ON\r\n");
               		   IOCLR0=buz;
			    }
                else
                {
                        uart0_tx_string("Flame Status : SAFE \r\n");
                        uart0_tx_string("Alarm : OFF\r\n");
                		IOSET0=buz;
				}
			   delay_ms(300);
 //uart0_string("DHT22 SENSOR\r\n");
                //if((IOPIN0&DHT22)==0)
                //uart0_string("DHT22 is detected\r\n");
                //else
                //uart0_string("DHT22 is not detected\r\n");
                eeprom(d1,d2,d3,d4);
                rtc();
                //esp_read();
              
			//wifi_connect();
                delay_ms(3000);
                uart0_string("\r\n");
        }
}

	

