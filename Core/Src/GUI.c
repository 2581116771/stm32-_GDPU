//////////////////////////////////////////////////////////////////////////////////	 
//ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ö»ï¿½ï¿½Ñ§Ï°Ê¹ï¿½Ã£ï¿½Î´ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½É£ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Îºï¿½ï¿½ï¿½Í
//ï¿½ï¿½ï¿½ï¿½Ó²ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Æ¬ï¿½ï¿½STM32F103RCT6,ï¿½ï¿½ï¿½ï¿½Ô­ï¿½ï¿½MiniSTM32ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½,ï¿½ï¿½Æµ72MHZï¿½ï¿½ï¿½ï¿½ï¿½ï¿½12MHZ
//QDtech-TFTÒºï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ for STM32 IOÄ£ï¿½ï¿½
//xiaoï¿½ï¿½@ShenZhen QDtech co.,LTD
//ï¿½ï¿½Ë¾ï¿½ï¿½Õ¾:www.qdtft.com
//ï¿½Ô±ï¿½ï¿½ï¿½Õ¾ï¿½ï¿½http://qdtech.taobao.com
//wikiï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Õ¾ï¿½ï¿½http://www.lcdwiki.com
//ï¿½ï¿½Ë¾ï¿½á¹©ï¿½ï¿½ï¿½ï¿½Ö§ï¿½Ö£ï¿½ï¿½ÎºÎ¼ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½â»¶Ó­ï¿½ï¿½Ê±ï¿½ï¿½ï¿½ï¿½Ñ§Ï°
//ï¿½Ì»ï¿½(ï¿½ï¿½ï¿½ï¿½) :+86 0755-23594567
//ï¿½Ö»ï¿½:15989313508ï¿½ï¿½ï¿½ë¹¤ï¿½ï¿½
//ï¿½ï¿½ï¿½ï¿½:lcdwiki01@gmail.com    support@lcdwiki.com    goodtft@163.com
//ï¿½ï¿½ï¿½ï¿½Ö§ï¿½ï¿½QQ:3002773612  3002778157
//ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½QQÈº:324828016
//ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½:2018/08/09
//ï¿½æ±¾ï¿½ï¿½V1.0
//ï¿½ï¿½È¨ï¿½ï¿½ï¿½Ð£ï¿½ï¿½ï¿½ï¿½ï¿½Ø¾ï¿½ï¿½ï¿
//Copyright(C) ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½È«ï¿½ï¿½ï¿½ï¿½ï¿½Ó¼ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Þ¹ï¿½Ë¾ 2018-2028
//All rights reserved
/****************************************************************************************************
//=========================================ï¿½ï¿½Ô´ï¿½ï¿½ï¿½ï¿½================================================//
//     LCDÄ£ï¿½ï¿½                STM32ï¿½ï¿½Æ¬ï¿½ï¿½
//      VCC          ï¿½ï¿½        DC5V/3.3V      //ï¿½ï¿½Ô´
//      GND          ï¿½ï¿½          GND          //ï¿½ï¿½Ô´ï¿½ï¿½
//=======================================Òºï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ß½ï¿½ï¿½ï¿½==========================================//
//ï¿½ï¿½Ä£ï¿½ï¿½Ä¬ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ÎªSPIï¿½ï¿½ï¿½ï¿½
//     LCDÄ£ï¿½ï¿½                STM32ï¿½ï¿½Æ¬ï¿½ï¿½
//    SDI(MOSI)      ï¿½ï¿½          PB15         //Òºï¿½ï¿½ï¿½ï¿½SPIï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ð´ï¿½Åºï¿½
//    SDO(MISO)      ï¿½ï¿½          PB14         //Òºï¿½ï¿½ï¿½ï¿½SPIï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ý¶ï¿½ï¿½ÅºÅ£ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Òªï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ô²ï¿½ï¿½ï¿½ï¿½ï¿
//=======================================Òºï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ß½ï¿½ï¿½ï¿½==========================================//
//     LCDÄ£ï¿½ï¿½ 					      STM32ï¿½ï¿½Æ¬ï¿½ï¿½
//       LED         ï¿½ï¿½          PB9          //Òºï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ÅºÅ£ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Òªï¿½ï¿½ï¿½Æ£ï¿½ï¿½ï¿½5Vï¿½ï¿½3.3V
//       SCK         ï¿½ï¿½          PB13         //Òºï¿½ï¿½ï¿½ï¿½SPIï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½ï¿½Åºï¿½
//      DC/RS        ï¿½ï¿½          PB10         //Òºï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½/ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Åºï¿
//       RST         ï¿½ï¿½          PB12         //Òºï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Î»ï¿½ï¿½ï¿½ï¿½ï¿½Åºï¿½
//       CS          ï¿½ï¿½          PB11         //Òºï¿½ï¿½ï¿½ï¿½Æ¬Ñ¡ï¿½ï¿½ï¿½ï¿½ï¿½Åºï¿½
//=========================================ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½=========================================//
//ï¿½ï¿½ï¿½Ä£ï¿½é²»ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ü»ï¿½ï¿½ß´ï¿½ï¿½Ð´ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ü£ï¿½ï¿½ï¿½ï¿½Ç²ï¿½ï¿½ï¿½Òªï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ü£ï¿½ï¿½ï¿½ï¿½ï¿½Òªï¿½ï¿½ï¿½Ð´ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿
//	   LCDÄ£ï¿½ï¿½                STM32ï¿½ï¿½Æ¬ï¿½ï¿½
//      T_IRQ        ï¿½ï¿½          PC10         //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ð¶ï¿½ï¿½Åºï¿½
//      T_DO         ï¿½ï¿½          PC2          //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½SPIï¿½ï¿½ï¿½ß¶ï¿½ï¿½Åºï¿½
//      T_DIN        ï¿½ï¿½          PC3          //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½SPIï¿½ï¿½ï¿½ï¿½Ð´ï¿½Åºï¿½
//      T_CS         ï¿½ï¿½          PC13         //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Æ¬Ñ¡ï¿½ï¿½ï¿½ï¿½ï¿½Åºï¿½
//      T_CLK        ï¿½ï¿½          PC0          //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½SPIï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½ï¿½Åºï¿½
**************************************************************************************************/	
 /* @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
**************************************************************************************************/	
#include "lcd.h"
#include "string.h"
#include "font.h" 
#include "gui.h"

/*******************************************************************
 * @name       :void GUI_DrawPoint(uint16_t x,uint16_t y,uint16_t color)
 * @date       :2018-08-09 
 * @function   :draw a point in LCD screen
 * @parameters :x:the x coordinate of the point
                y:the y coordinate of the point
								color:the color value of the point
 * @retvalue   :None
********************************************************************/
void GUI_DrawPoint(uint16_t x,uint16_t y,uint16_t color)
{
	LCD_SetCursor(x,y);//ï¿½ï¿½ï¿½Ã¹ï¿½ï¿½Î»ï¿½ï¿
	Lcd_WriteData_16Bit(color); 
}

/*******************************************************************
 * @name       :void LCD_Fill(uint16_t sx,uint16_t sy,uint16_t ex,uint16_t ey,uint16_t color)
 * @date       :2018-08-09 
 * @function   :fill the specified area
 * @parameters :sx:the bebinning x coordinate of the specified area
                sy:the bebinning y coordinate of the specified area
								ex:the ending x coordinate of the specified area
								ey:the ending y coordinate of the specified area
								color:the filled color value
 * @retvalue   :None
********************************************************************/
void LCD_Fill(uint16_t sx,uint16_t sy,uint16_t ex,uint16_t ey,uint16_t color)
{  	
	uint16_t i,j;
	uint16_t width=ex-sx+1; 		//ï¿½Ãµï¿½ï¿½ï¿½ï¿½Ä¿ï¿½ï¿
	uint16_t height=ey-sy+1;		//ï¿½ß¶ï¿½
	LCD_SetWindows(sx,sy,ex,ey);//ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½ï¿½ï¿½
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		Lcd_WriteData_16Bit(color);	//Ð´ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
	}
	LCD_SetWindows(0,0,lcddev.width-1,lcddev.height-1);//ï¿½Ö¸ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ÎªÈ«ï¿½ï¿½
}

/*******************************************************************
 * @name       :void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
 * @date       :2018-08-09 
 * @function   :Draw a line between two points
 * @parameters :x1:the bebinning x coordinate of the line
                y1:the bebinning y coordinate of the line
								x2:the ending x coordinate of the line
								y2:the ending y coordinate of the line
 * @retvalue   :None
********************************************************************/
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
	uint16_t t;
	int xerr=0,yerr=0,delta_x,delta_y,distance; 
	int incx,incy,uRow,uCol; 

	delta_x=x2-x1; //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
	delta_y=y2-y1; 
	uRow=x1; 
	uCol=y1; 
	if(delta_x>0)incx=1; //ï¿½ï¿½ï¿½Ãµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
	else if(delta_x==0)incx=0;//ï¿½ï¿½Ö±ï¿½ï¿½
	else {incx=-1;delta_x=-delta_x;} 
	if(delta_y>0)incy=1; 
	else if(delta_y==0)incy=0;//Ë®Æ½ï¿½ï¿½
	else{incy=-1;delta_y=-delta_y;} 
	if( delta_x>delta_y)distance=delta_x; //Ñ¡È¡ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
	else distance=delta_y; 
	for(t=0;t<=distance+1;t++ )//ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿
	{  
		LCD_DrawPoint(uRow,uCol);//ï¿½ï¿½ï¿½ï¿½
		xerr+=delta_x ; 
		yerr+=delta_y ; 
		if(xerr>distance) 
		{ 
			xerr-=distance; 
			uRow+=incx; 
		} 
		if(yerr>distance) 
		{ 
			yerr-=distance; 
			uCol+=incy; 
		} 
	}  
} 

/*****************************************************************************
 * @name       :void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
 * @date       :2018-08-09 
 * @function   :Draw a rectangle
 * @parameters :x1:the bebinning x coordinate of the rectangle
                y1:the bebinning y coordinate of the rectangle
								x2:the ending x coordinate of the rectangle
								y2:the ending y coordinate of the rectangle
 * @retvalue   :None
******************************************************************************/
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
	LCD_DrawLine(x1,y1,x2,y1);
	LCD_DrawLine(x1,y1,x1,y2);
	LCD_DrawLine(x1,y2,x2,y2);
	LCD_DrawLine(x2,y1,x2,y2);
}  

/*****************************************************************************
 * @name       :void LCD_DrawFillRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
 * @date       :2018-08-09 
 * @function   :Filled a rectangle
 * @parameters :x1:the bebinning x coordinate of the filled rectangle
                y1:the bebinning y coordinate of the filled rectangle
								x2:the ending x coordinate of the filled rectangle
								y2:the ending y coordinate of the filled rectangle
 * @retvalue   :None
******************************************************************************/  
void LCD_DrawFillRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
	LCD_Fill(x1,y1,x2,y2,POINT_COLOR);
}
 
/*****************************************************************************
 * @name       :void _draw_circle_8(int xc, int yc, int x, int y, uint16_t c)
 * @date       :2018-08-09 
 * @function   :8 symmetry circle drawing algorithm (internal call)
 * @parameters :xc:the x coordinate of the Circular center 
                yc:the y coordinate of the Circular center 
								x:the x coordinate relative to the Circular center 
								y:the y coordinate relative to the Circular center 
								c:the color value of the circle
 * @retvalue   :None
******************************************************************************/  
void _draw_circle_8(int xc, int yc, int x, int y, uint16_t c)
{
	GUI_DrawPoint(xc + x, yc + y, c);

	GUI_DrawPoint(xc - x, yc + y, c);

	GUI_DrawPoint(xc + x, yc - y, c);

	GUI_DrawPoint(xc - x, yc - y, c);

	GUI_DrawPoint(xc + y, yc + x, c);

	GUI_DrawPoint(xc - y, yc + x, c);

	GUI_DrawPoint(xc + y, yc - x, c);

	GUI_DrawPoint(xc - y, yc - x, c);
}

/*****************************************************************************
 * @name       :void gui_circle(int xc, int yc,uint16_t c,int r, int fill)
 * @date       :2018-08-09 
 * @function   :Draw a circle of specified size at a specified location
 * @parameters :xc:the x coordinate of the Circular center 
                yc:the y coordinate of the Circular center 
								r:Circular radius
								fill:1-filling,0-no filling
 * @retvalue   :None
******************************************************************************/  
void gui_circle(int xc, int yc,uint16_t c,int r, int fill)
{
	int x = 0, y = r, yi, d;

	d = 3 - 2 * r;


	if (fill) 
	{
		// ï¿½ï¿½ï¿½ï¿½ï¿½ä£¨ï¿½ï¿½Êµï¿½ï¿½Ô²ï¿½ï¿½
		while (x <= y) {
			for (yi = x; yi <= y; yi++)
				_draw_circle_8(xc, yc, x, yi, c);

			if (d < 0) {
				d = d + 4 * x + 6;
			} else {
				d = d + 4 * (x - y) + 10;
				y--;
			}
			x++;
		}
	} else 
	{
		// ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ä£¨ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ô²ï¿½ï¿½
		while (x <= y) {
			_draw_circle_8(xc, yc, x, y, c);
			if (d < 0) {
				d = d + 4 * x + 6;
			} else {
				d = d + 4 * (x - y) + 10;
				y--;
			}
			x++;
		}
	}
}

/*****************************************************************************
 * @name       :void Draw_Triangel(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
 * @date       :2018-08-09 
 * @function   :Draw a triangle at a specified position
 * @parameters :x0:the bebinning x coordinate of the triangular edge 
                y0:the bebinning y coordinate of the triangular edge 
								x1:the vertex x coordinate of the triangular
								y1:the vertex y coordinate of the triangular
								x2:the ending x coordinate of the triangular edge 
								y2:the ending y coordinate of the triangular edge 
 * @retvalue   :None
******************************************************************************/ 
void Draw_Triangel(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
{
	LCD_DrawLine(x0,y0,x1,y1);
	LCD_DrawLine(x1,y1,x2,y2);
	LCD_DrawLine(x2,y2,x0,y0);
}

static void _swap(uint16_t *a, uint16_t *b)
{
	uint16_t tmp;
  tmp = *a;
	*a = *b;
	*b = tmp;
}

/*****************************************************************************
 * @name       :void Fill_Triangel(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
 * @date       :2018-08-09 
 * @function   :filling a triangle at a specified position
 * @parameters :x0:the bebinning x coordinate of the triangular edge 
                y0:the bebinning y coordinate of the triangular edge 
								x1:the vertex x coordinate of the triangular
								y1:the vertex y coordinate of the triangular
								x2:the ending x coordinate of the triangular edge 
								y2:the ending y coordinate of the triangular edge 
 * @retvalue   :None
******************************************************************************/ 
void Fill_Triangel(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
{
	uint16_t a, b, y, last;
	int dx01, dy01, dx02, dy02, dx12, dy12;
	long sa = 0;
	long sb = 0;
 	if (y0 > y1) 
	{
    _swap(&y0,&y1); 
		_swap(&x0,&x1);
 	}
 	if (y1 > y2) 
	{
    _swap(&y2,&y1); 
		_swap(&x2,&x1);
 	}
  if (y0 > y1) 
	{
    _swap(&y0,&y1); 
		_swap(&x0,&x1);
  }
	if(y0 == y2) 
	{ 
		a = b = x0;
		if(x1 < a)
    {
			a = x1;
    }
    else if(x1 > b)
    {
			b = x1;
    }
    if(x2 < a)
    {
			a = x2;
    }
		else if(x2 > b)
    {
			b = x2;
    }
		LCD_Fill(a,y0,b,y0,POINT_COLOR);
    return;
	}
	dx01 = x1 - x0;
	dy01 = y1 - y0;
	dx02 = x2 - x0;
	dy02 = y2 - y0;
	dx12 = x2 - x1;
	dy12 = y2 - y1;
	
	if(y1 == y2)
	{
		last = y1; 
	}
  else
	{
		last = y1-1; 
	}
	for(y=y0; y<=last; y++) 
	{
		a = x0 + sa / dy01;
		b = x0 + sb / dy02;
		sa += dx01;
    sb += dx02;
    if(a > b)
    {
			_swap(&a,&b);
		}
		LCD_Fill(a,y,b,y,POINT_COLOR);
	}
	sa = dx12 * (y - y1);
	sb = dx02 * (y - y0);
	for(; y<=y2; y++) 
	{
		a = x1 + sa / dy12;
		b = x0 + sb / dy02;
		sa += dx12;
		sb += dx02;
		if(a > b)
		{
			_swap(&a,&b);
		}
		LCD_Fill(a,y,b,y,POINT_COLOR);
	}
}

/*****************************************************************************
 * @name       :void LCD_ShowChar(uint16_t x,uint16_t y,uint16_t fc, uint16_t bc, uint8_t num,uint8_t size,uint8_t mode)
 * @date       :2018-08-09 
 * @function   :Display a single English character
 * @parameters :x:the bebinning x coordinate of the Character display position
                y:the bebinning y coordinate of the Character display position
								fc:the color value of display character
								bc:the background color of display character
								num:the ascii code of display character(0~94)
								size:the size of display character
								mode:0-no overlying,1-overlying
 * @retvalue   :None
******************************************************************************/ 
void LCD_ShowChar(uint16_t x,uint16_t y,uint16_t fc, uint16_t bc, uint8_t num,uint8_t size,uint8_t mode)
{  
    uint8_t temp;
    uint8_t pos,t;
	uint16_t colortemp=POINT_COLOR;
		   
	num=num-' ';//ï¿½Ãµï¿½Æ«ï¿½Æºï¿½ï¿½Ö
	LCD_SetWindows(x,y,x+size/2-1,y+size-1);//ï¿½ï¿½ï¿½Ãµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½ï¿½ï¿½
	if(!mode) //ï¿½Çµï¿½ï¿½Ó·ï¿½Ê½
	{		
		for(pos=0;pos<size;pos++)
		{
			if(size==12)temp=asc2_1206[num][pos];//ï¿½ï¿½ï¿½ï¿½1206ï¿½ï¿½ï¿½ï¿½
			else temp=asc2_1608[num][pos];		 //ï¿½ï¿½ï¿½ï¿½1608ï¿½ï¿½ï¿½ï¿½
			for(t=0;t<size/2;t++)
		    {                 
		        if(temp&0x01)Lcd_WriteData_16Bit(fc); 
				else Lcd_WriteData_16Bit(bc); 
				temp>>=1; 
				
		    }
			
		}	
	}
	else//ï¿½ï¿½ï¿½Ó·ï¿½Ê½
	{
		for(pos=0;pos<size;pos++)
		{
			if(size==12)temp=asc2_1206[num][pos];//ï¿½ï¿½ï¿½ï¿½1206ï¿½ï¿½ï¿½ï¿½
			else temp=asc2_1608[num][pos];		 //ï¿½ï¿½ï¿½ï¿½1608ï¿½ï¿½ï¿½ï¿½
			for(t=0;t<size/2;t++)
		    {   
				POINT_COLOR=fc;              
		        if(temp&0x01)LCD_DrawPoint(x+t,y+pos);//ï¿½ï¿½Ò»ï¿½ï¿½ï¿½ï¿½
		        temp>>=1; 
		    }
		}
	}
	POINT_COLOR=colortemp;	
	LCD_SetWindows(0,0,lcddev.width-1,lcddev.height-1);//ï¿½Ö¸ï¿½ï¿½ï¿½ï¿½ï¿½ÎªÈ«ï¿½ï¿½
}


void LCD_Show_3216_char(uint16_t x,uint16_t y,uint16_t fc, uint16_t bc, uint8_t num,uint8_t mode)
{
    uint16_t temp;
    uint8_t pos,t;
    uint16_t colortemp=POINT_COLOR;
    num=num-' ';//µÃµ½Æ«ÒÆºóµÄÖµ
    LCD_SetWindows(x,y,x+16-1,y+32-1);//ÉèÖÃµ¥¸öÎÄ×ÖÏÔÊ¾´°¿Ú
    if(!mode) //·Çµþ¼Ó·½Ê½£º×ÖÌå´øÓÐ±³¾°É«£¬ÏÔÊ¾Ê±»á½«Ô­À´ÏÔÊ¾µÄÄÚÈÝ¸²¸Çµô
    {
	for(pos=0;pos<32;pos++)
	{
	    temp = (asc2_3216[num][pos*2]<<8)|asc2_3216[num][pos*2+1];//µ÷ÓÃ3216×ÖÌå£¬ÐèÒª×Ô¼ºÈ¡Ä£¶¨Òå
	    for(t=0;t<16;t++)
	    {
		if(temp&0x8000)
		{
		    Lcd_WriteData_16Bit(fc);
		}
		else
		{
		    Lcd_WriteData_16Bit(bc);
		}
		temp<<=1;
	    }

	}
    }
    else//µþ¼Ó·½Ê½£º×ÖÌå²»´ø±³¾°É«£¬Ö±½Óµþ¼ÓÏÔÊ¾µ½Ô­À´ÏÔÊ¾µÄÄÚÈÝÉÏ
    {
        for(pos=0;pos<32;pos++)
	{
	    temp = (asc2_3216[num][pos*2]<<8)|asc2_3216[num][pos*2+1];//µ÷ÓÃ3216×ÖÌå£¬ÐèÒª×Ô¼ºÈ¡Ä£¶¨Òå
	    for(t=0;t<16;t++)
	    {
		POINT_COLOR=fc;
		if(temp&(0x8000))
		{
		    LCD_DrawPoint(x+t,y+pos);//»­Ò»¸öµã
		}
		temp<<=1;
	    }
	}
    }
    POINT_COLOR=colortemp;
    LCD_SetWindows(0,0,lcddev.width-1,lcddev.height-1);//»Ö¸´´°¿ÚÎªÈ«ÆÁ
}
/*****************************************************************************
 * @name       :void LCD_ShowString(uint16_t x,uint16_t y,uint8_t size,uint8_t *p,uint8_t mode)
 * @date       :2018-08-09 
 * @function   :Display English string
 * @parameters :x:the bebinning x coordinate of the English string
                y:the bebinning y coordinate of the English string
								p:the start address of the English string
								size:the size of display character
								mode:0-no overlying,1-overlying
 * @retvalue   :None
******************************************************************************/   	  
void LCD_ShowString(uint16_t x,uint16_t y,uint8_t size,uint8_t *p,uint8_t mode)
{         
    while((*p<='~')&&(*p>=' '))//ï¿½Ð¶ï¿½ï¿½Ç²ï¿½ï¿½Ç·Ç·ï¿½ï¿½Ö·ï¿½!
    {   
		if(x>(lcddev.width-1)||y>(lcddev.height-1)) 
		return;     
        LCD_ShowChar(x,y,POINT_COLOR,BACK_COLOR,*p,size,mode);
        x+=size/2;
        p++;
    }  
} 

/*****************************************************************************
 * @name       :uint32_t mypow(uint8_t m,uint8_t n)
 * @date       :2018-08-09 
 * @function   :get the nth power of m (internal call)
 * @parameters :m:the multiplier
                n:the power
 * @retvalue   :the nth power of m
******************************************************************************/ 
uint32_t mypow(uint8_t m,uint8_t n)
{
	uint32_t result=1;
	while(n--)result*=m;    
	return result;
}

/*****************************************************************************
 * @name       :void LCD_ShowNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size)
 * @date       :2018-08-09 
 * @function   :Display number
 * @parameters :x:the bebinning x coordinate of the number
                y:the bebinning y coordinate of the number
								num:the number(0~4294967295)
								len:the length of the display number
								size:the size of display number
 * @retvalue   :None
******************************************************************************/  			 
void LCD_ShowNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size)
{         	
	uint8_t t,temp;
	uint8_t enshow=0;
	for(t=0;t<len;t++)
	{
		temp=(num/mypow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				LCD_ShowChar(x+(size/2)*t,y,POINT_COLOR,BACK_COLOR,' ',size,0);
				continue;
			}else enshow=1; 
		 	 
		}
	 	LCD_ShowChar(x+(size/2)*t,y,POINT_COLOR,BACK_COLOR,temp+'0',size,0); 
	}
} 

/*****************************************************************************
 * @name       :void GUI_DrawFont16(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s,uint8_t mode)
 * @date       :2018-08-09 
 * @function   :Display a single 16x16 Chinese character
 * @parameters :x:the bebinning x coordinate of the Chinese character
                y:the bebinning y coordinate of the Chinese character
								fc:the color value of Chinese character
								bc:the background color of Chinese character
								s:the start address of the Chinese character
								mode:0-no overlying,1-overlying
 * @retvalue   :None
******************************************************************************/ 
void GUI_DrawFont16(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s,uint8_t mode)
{
	uint8_t i,j;
	uint16_t k;
	uint16_t HZnum;
	uint16_t x0=x;
	HZnum=sizeof(tfont16)/sizeof(typFNT_GB16);	//ï¿½Ô¶ï¿½Í³ï¿½Æºï¿½ï¿½ï¿½ï¿½ï¿½Ä¿
	
			
	for (k=0;k<HZnum;k++) 
	{
	  if ((tfont16[k].Index[0]==*(s))&&(tfont16[k].Index[1]==*(s+1)))
	  { 	LCD_SetWindows(x,y,x+16-1,y+16-1);
		    for(i=0;i<16*2;i++)
		    {
				for(j=0;j<8;j++)
		    	{	
					if(!mode) //ï¿½Çµï¿½ï¿½Ó·ï¿½Ê½
					{
						if(tfont16[k].Msk[i]&(0x80>>j))	Lcd_WriteData_16Bit(fc);
						else Lcd_WriteData_16Bit(bc);
					}
					else
					{
						POINT_COLOR=fc;
						if(tfont16[k].Msk[i]&(0x80>>j))	LCD_DrawPoint(x,y);//ï¿½ï¿½Ò»ï¿½ï¿½ï¿½ï¿½
						x++;
						if((x-x0)==16)
						{
							x=x0;
							y++;
							break;
						}
					}

				}
				
			}
			
			
		}				  	
		continue;  //ï¿½ï¿½ï¿½Òµï¿½ï¿½ï¿½Ó¦ï¿½ï¿½ï¿½ï¿½ï¿½Ö¿ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ë³ï¿½ï¿½ï¿½ï¿½ï¿½Ö¹ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ø¸ï¿½È¡Ä£ï¿½ï¿½ï¿½ï¿½Ó°ï¿½ï¿
	}

	LCD_SetWindows(0,0,lcddev.width-1,lcddev.height-1);//ï¿½Ö¸ï¿½ï¿½ï¿½ï¿½ï¿½ÎªÈ«ï¿½ï¿½
} 

/*****************************************************************************
 * @name       :void GUI_DrawFont24(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s,uint8_t mode)
 * @date       :2018-08-09 
 * @function   :Display a single 24x24 Chinese character
 * @parameters :x:the bebinning x coordinate of the Chinese character
                y:the bebinning y coordinate of the Chinese character
								fc:the color value of Chinese character
								bc:the background color of Chinese character
								s:the start address of the Chinese character
								mode:0-no overlying,1-overlying
 * @retvalue   :None
******************************************************************************/ 
void GUI_DrawFont24(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s,uint8_t mode)
{
	uint8_t i,j;
	uint16_t k;
	uint16_t HZnum;
	uint16_t x0=x;
	HZnum=sizeof(tfont24)/sizeof(typFNT_GB24);	//ï¿½Ô¶ï¿½Í³ï¿½Æºï¿½ï¿½ï¿½ï¿½ï¿½Ä¿
		
			for (k=0;k<HZnum;k++) 
			{
			  if ((tfont24[k].Index[0]==*(s))&&(tfont24[k].Index[1]==*(s+1)))
			  { 	LCD_SetWindows(x,y,x+24-1,y+24-1);
				    for(i=0;i<24*3;i++)
				    {
							for(j=0;j<8;j++)
							{
								if(!mode) //ï¿½Çµï¿½ï¿½Ó·ï¿½Ê½
								{
									if(tfont24[k].Msk[i]&(0x80>>j))	Lcd_WriteData_16Bit(fc);
									else Lcd_WriteData_16Bit(bc);
								}
							else
							{
								POINT_COLOR=fc;
								if(tfont24[k].Msk[i]&(0x80>>j))	LCD_DrawPoint(x,y);//ï¿½ï¿½Ò»ï¿½ï¿½ï¿½ï¿½
								x++;
								if((x-x0)==24)
								{
									x=x0;
									y++;
									break;
								}
							}
						}
					}
					
					
				}				  	
				continue;  //ï¿½ï¿½ï¿½Òµï¿½ï¿½ï¿½Ó¦ï¿½ï¿½ï¿½ï¿½ï¿½Ö¿ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ë³ï¿½ï¿½ï¿½ï¿½ï¿½Ö¹ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ø¸ï¿½È¡Ä£ï¿½ï¿½ï¿½ï¿½Ó°ï¿½ï¿
			}

	LCD_SetWindows(0,0,lcddev.width-1,lcddev.height-1);//ï¿½Ö¸ï¿½ï¿½ï¿½ï¿½ï¿½ÎªÈ«ï¿½ï¿½
}

/*****************************************************************************
 * @name       :void GUI_DrawFont32(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s,uint8_t mode)
 * @date       :2018-08-09 
 * @function   :Display a single 32x32 Chinese character
 * @parameters :x:the bebinning x coordinate of the Chinese character
                y:the bebinning y coordinate of the Chinese character
								fc:the color value of Chinese character
								bc:the background color of Chinese character
								s:the start address of the Chinese character
								mode:0-no overlying,1-overlying
 * @retvalue   :None
******************************************************************************/ 
void GUI_DrawFont32(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s,uint8_t mode)
{
	uint8_t i,j;
	uint16_t k;
	uint16_t HZnum;
	uint16_t x0=x;
	HZnum=sizeof(tfont32)/sizeof(typFNT_GB32);	//ï¿½Ô¶ï¿½Í³ï¿½Æºï¿½ï¿½ï¿½ï¿½ï¿½Ä¿
	for (k=0;k<HZnum;k++) 
			{
			  if ((tfont32[k].Index[0]==*(s))&&(tfont32[k].Index[1]==*(s+1)))
			  { 	LCD_SetWindows(x,y,x+32-1,y+32-1);
				    for(i=0;i<32*4;i++)
				    {
						for(j=0;j<8;j++)
				    	{
							if(!mode) //ï¿½Çµï¿½ï¿½Ó·ï¿½Ê½
							{
								if(tfont32[k].Msk[i]&(0x80>>j))	Lcd_WriteData_16Bit(fc);
								else Lcd_WriteData_16Bit(bc);
							}
							else
							{
								POINT_COLOR=fc;
								if(tfont32[k].Msk[i]&(0x80>>j))	LCD_DrawPoint(x,y);//ï¿½ï¿½Ò»ï¿½ï¿½ï¿½ï¿½
								x++;
								if((x-x0)==32)
								{
									x=x0;
									y++;
									break;
								}
							}
						}
					}
					
					
				}				  	
				continue;  //ï¿½ï¿½ï¿½Òµï¿½ï¿½ï¿½Ó¦ï¿½ï¿½ï¿½ï¿½ï¿½Ö¿ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ë³ï¿½ï¿½ï¿½ï¿½ï¿½Ö¹ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ø¸ï¿½È¡Ä£ï¿½ï¿½ï¿½ï¿½Ó°ï¿½ï¿
			}
	
	LCD_SetWindows(0,0,lcddev.width-1,lcddev.height-1);//ï¿½Ö¸ï¿½ï¿½ï¿½ï¿½ï¿½ÎªÈ«ï¿½ï¿½
} 

/*****************************************************************************
 * @name       :void Show_Str(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *str,uint8_t size,uint8_t mode)
 * @date       :2018-08-09 
 * @function   :Display Chinese and English strings
 * @parameters :x:the bebinning x coordinate of the Chinese and English strings
                y:the bebinning y coordinate of the Chinese and English strings
								fc:the color value of Chinese and English strings
								bc:the background color of Chinese and English strings
								str:the start address of the Chinese and English strings
								size:the size of Chinese and English strings
								mode:0-no overlying,1-overlying
 * @retvalue   :None
******************************************************************************/	   		   
void Show_Str(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *str,uint8_t size,uint8_t mode)
{					
	uint16_t x0=x;
  	uint8_t bHz=0;     //ï¿½Ö·ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
    while(*str!=0)//ï¿½ï¿½ï¿½ï¿½Î´ï¿½ï¿½ï¿½ï¿½
    { 
        if(!bHz)
        {
			if(x>(lcddev.width-size/2)||y>(lcddev.height-size)) 
			return; 
	        if(*str>0x80)bHz=1;//ï¿½ï¿½ï¿½ï¿½
	        else              //ï¿½Ö·ï¿½
	        {          
		        if(*str==0x0D)//ï¿½ï¿½ï¿½Ð·ï¿½ï¿½ï¿½
		        {         
		            y+=size;
					x=x0;
		            str++; 
		        }  
		        else
				{
					if(size>16)//ï¿½Ö¿ï¿½ï¿½ï¿½Ã»ï¿½Ð¼ï¿½ï¿½ï¿½12X24 16X32ï¿½ï¿½Ó¢ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½,ï¿½ï¿½8X16ï¿½ï¿½ï¿½ï¿½
					{  
//					LCD_ShowChar(x,y,fc,bc,*str,16,mode);
					LCD_Show_3216_char(x,y,fc,bc,*str,mode);
					x+=16; //ï¿½Ö·ï¿½,ÎªÈ«ï¿½Öµï¿½Ò»ï¿½ï¿½
					}
					else
					{
					LCD_ShowChar(x,y,fc,bc,*str,size,mode);
					x+=size/2; //ï¿½Ö·ï¿½,ÎªÈ«ï¿½Öµï¿½Ò»ï¿½ï¿½
					}
				} 
				str++; 
		        
	        }
        }else//ï¿½ï¿½ï¿½ï¿½
        {   
			if(x>(lcddev.width-size)||y>(lcddev.height-size)) 
			return;  
            bHz=0;//ï¿½Ðºï¿½ï¿½Ö¿ï¿½
			if(size==32)
			GUI_DrawFont32(x,y,fc,bc,str,mode);	 	
			else if(size==24)
			GUI_DrawFont24(x,y,fc,bc,str,mode);	
			else
			GUI_DrawFont16(x,y,fc,bc,str,mode);
				
	        str+=2; 
	        x+=size;//ï¿½ï¿½Ò»ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Æ«ï¿½ï¿½
        }						 
    }   
}

/*****************************************************************************
 * @name       :void Gui_StrCenter(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *str,uint8_t size,uint8_t mode)
 * @date       :2018-08-09 
 * @function   :Centered display of English and Chinese strings
 * @parameters :x:the bebinning x coordinate of the Chinese and English strings
                y:the bebinning y coordinate of the Chinese and English strings
								fc:the color value of Chinese and English strings
								bc:the background color of Chinese and English strings
								str:the start address of the Chinese and English strings
								size:the size of Chinese and English strings
								mode:0-no overlying,1-overlying
 * @retvalue   :None
******************************************************************************/ 
void Gui_StrCenter(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *str,uint8_t size,uint8_t mode)
{
	uint16_t len=strlen((const char *)str);
	uint16_t x1=(lcddev.width-len*8)/2;
	Show_Str(x1,y,fc,bc,str,size,mode);
} 
 
/*****************************************************************************
 * @name       :void Gui_Drawbmp16(uint16_t x,uint16_t y,const unsigned char *p)
 * @date       :2018-08-09 
 * @function   :Display a 16-bit BMP image
 * @parameters :x:the bebinning x coordinate of the BMP image
                y:the bebinning y coordinate of the BMP image
								p:the start address of image array
 * @retvalue   :None
******************************************************************************/ 
void Gui_Drawbmp16(uint16_t x,uint16_t y,const unsigned char *p) //ï¿½ï¿½Ê¾40*40 QQÍ¼Æ¬
{
  	int i; 
	unsigned char picH,picL; 
	LCD_SetWindows(x,y,x+40-1,y+40-1);//ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
    for(i=0;i<40*40;i++)
	{	
	 	picL=*(p+i*2);	//ï¿½ï¿½ï¿½Ýµï¿½Î»ï¿½ï¿½Ç°
		picH=*(p+i*2+1);				
		Lcd_WriteData_16Bit(picH<<8|picL);  						
	}	
	LCD_SetWindows(0,0,lcddev.width-1,lcddev.height-1);//ï¿½Ö¸ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½ï¿½ï¿½ÎªÈ«ï¿½ï¿½
}
