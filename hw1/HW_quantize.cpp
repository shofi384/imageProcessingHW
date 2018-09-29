// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW_quantize:
//
// Quantize I1 to specified number of levels. Apply dither if flag is set.
// Output is in I2.
//
// //	Written by :	BASHIR AHAMED
//			SHOFIQUR RAHMAN
//			UCHA SAMADASHVILI
//
//	Semester   :	FALL 2018
//
void
HW_quantize(ImagePtr I1, int levels, bool dither, ImagePtr I2)
{
  int w = I1->width();
  int h = I1->height();
  int total =  w * h;

  int i, lut[MXGRAY];

  IP_copyImageHeader(I1, I2);

  double step = (double)MXGRAY/levels;
  double jump = (double)MXGRAY/(levels-1);
  int m = 0;
    
  for(i = 0; i < MXGRAY; ++i)
    lut[i] = CLIP((int)(floor(i/step) * jump), 0, 255);

  int type;
  ChannelPtr<uchar> p1, p2, endPtr;
  if(dither){
    for(int ch = 0; IP_getChannel(I1, ch, p1, type); ++ch) {
      IP_getChannel(I2, ch, p2, type);
      for(endPtr = p1 + total; endPtr > p1;){
	m = CLIP(*p1 + (rand() % (2*(int)step) - int(step)),0,255);
	*p2++ = lut[m];
	p1++;
      }
    }
  }
  else{
    for(int ch = 0; IP_getChannel(I1, ch, p1, type); ++ch) {
      IP_getChannel(I2, ch, p2, type);
      for(endPtr = p1 + total; endPtr > p1;)
	*p2++ = lut[*p1++];
    }
  }
}
