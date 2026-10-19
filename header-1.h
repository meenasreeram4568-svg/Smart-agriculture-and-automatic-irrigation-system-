typedef unsigned int u32;
   typedef unsigned char u8;
   
   extern void lcd_data(unsigned char data);
   extern void lcd_cmd(unsigned char cmd);
   extern void lcd_string(char *ptr);
   extern void lcd_int(int num);
  extern void lcd_float(float num);
  extern void delay_ms(unsigned int ms);
  extern void lcd_init(void);
  extern void adc_init(void);
  extern unsigned int adc_read(unsigned ch_num);
  extern void uart0_init(unsigned int baud);
  extern void uart0_tx(unsigned char data);
  extern unsigned uart0_rx(void);
  extern void uart0_string(char *ptr);
	 extern void uart0_tx_string(char *ptr);
  extern void uart0_int(int num);
  extern void uart0_float(float f);
//	extern void uart0_float_int(float num);
  extern void soil_sensor(float num);
  extern void water_sensor(float num);
  extern void ldr_sensor(int num);
  extern void temp_sensor(float num);
  
extern void rtc(void);
extern void rtc_read(void);
extern void convert_dec(void);
extern void uart0_display(void);
extern unsigned char bcd_dec(unsigned char bcd);
extern void rtc_write(void);
extern void uart0_diaplay(void);
extern unsigned char bcd_dec(unsigned char bcd);
extern void rtc_write(void);
extern void uart0_diaplay(void);
extern void i2c_init(void);
extern void i2c_write(u8 sa,u8 addr,u8 data);
extern u8 i2c_read(u8 sa,u8 addr);
extern void eeprom(u8 d1,u8 d2,u8 d3,u8 d4);
extern void wifi_connect(void);
extern void esp_read(void);




