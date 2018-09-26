// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW_clip:
//
// Clip intensities of image I1 to [t1,t2] range. Output is in I2.
// If    input<t1: output = t1;
// If t1<input<t2: output = input;
// If      val>t2: output = t2;
//
void
HW_clip(ImagePtr I1, int t1, int t2, ImagePtr I2)
{
	// copy the image header of the input image I1 (width, height) into the output image I2
	
	IP_copyImageHeader(I1, I2);
	
	int w = I1->width();
	int h = I1->height();
	int total = w*h;

	int i, lut[MXGRAY];

	// create the loop up table
	
	for( i = 0; i < t1; && i < MXGRAY; ++i)
		lut[i] = t1;

	for(i = t2; i < MXGRAY; ++i)
		lut[i] t2;


}
