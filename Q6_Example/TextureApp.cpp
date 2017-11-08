#include "TextureApp.h"

#include <libpng/png.h>
#pragma warning(disable : 4996)
bool TextureApp::LoadPngImage(char *name, int &outWidth, int &outHeight, bool &outHasAlpha, GLubyte **outData)
{
	png_structp png_ptr;
	png_infop info_ptr;
	unsigned int sig_read = 0;
	int color_type, interlace_type;
	FILE *fp;

	if ((fp = fopen(name, "rb")) == NULL)
		return false;

	/* Create and initialize the png_struct
	* with the desired error handler
	* functions.  If you want to use the
	* default stderr and longjump method,
	* you can supply NULL for the last
	* three parameters.  We also supply the
	* the compiler header file version, so
	* that we know if the application
	* was compiled with a compatible version
	* of the library.  REQUIRED
	*/
	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING,
		NULL, NULL, NULL);

	if (png_ptr == NULL) {
		fclose(fp);
		return false;
	}

	/* Allocate/initialize the memory
	* for image information.  REQUIRED. */
	info_ptr = png_create_info_struct(png_ptr);
	if (info_ptr == NULL) {
		fclose(fp);
		png_destroy_read_struct(&png_ptr, NULL, NULL);
		return false;
	}

	/* Set error handling if you are
	* using the setjmp/longjmp method
	* (this is the normal method of
	* doing things with libpng).
	* REQUIRED unless you  set up
	* your own error handlers in
	* the png_create_read_struct()
	* earlier.
	*/
	if (setjmp(png_jmpbuf(png_ptr))) {
		/* Free all of the memory associated
		* with the png_ptr and info_ptr */
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
		fclose(fp);
		/* If we get here, we had a
		* problem reading the file */
		return false;
	}

	/* Set up the output control if
	* you are using standard C streams */
	png_init_io(png_ptr, fp);

	/* If we have already
	* read some of the signature */
	png_set_sig_bytes(png_ptr, sig_read);

	/*
	* If you have enough memory to read
	* in the entire image at once, and
	* you need to specify only
	* transforms that can be controlled
	* with one of the PNG_TRANSFORM_*
	* bits (this presently excludes
	* dithering, filling, setting
	* background, and doing gamma
	* adjustment), then you can read the
	* entire image (including pixels)
	* into the info structure with this
	* call
	*
	* PNG_TRANSFORM_STRIP_16 |
	* PNG_TRANSFORM_PACKING  forces 8 bit
	* PNG_TRANSFORM_EXPAND forces to
	*  expand a palette into RGB
	*/
	png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_STRIP_16 | PNG_TRANSFORM_PACKING | PNG_TRANSFORM_EXPAND, NULL);

	png_uint_32 width, height;
	int bit_depth;
	png_get_IHDR(png_ptr, info_ptr, &width, &height, &bit_depth, &color_type,
		&interlace_type, NULL, NULL);
	outWidth = width;
	outHeight = height;

	unsigned int row_bytes = png_get_rowbytes(png_ptr, info_ptr);
	*outData = (unsigned char*)malloc(row_bytes * outHeight);

	if (row_bytes / width == 4)
	{
		outHasAlpha = true;
	}
	else {
		outHasAlpha = false;
	}

	png_bytepp row_pointers = png_get_rows(png_ptr, info_ptr);

	for (int i = 0; i < outHeight; i++) {
		// note that png is ordered top to
		// bottom, but OpenGL expect it bottom to top
		// so the order or swapped
		memcpy(*outData + (row_bytes * (outHeight - 1 - i)), row_pointers[i], row_bytes);
	}

	/* Clean up after the read,
	* and free any memory allocated */
	png_destroy_read_struct(&png_ptr, &info_ptr, NULL);

	/* Close the file */
	fclose(fp);

	/* That's it */
	return true;
}

GLuint TextureApp::GenTexture(char* filepath)
{
	char *format = filepath;
	unsigned int textureID = 0;
	while (*format != 0) format++;
	while (format != filepath && *format != '.') format--;

	if (strcmp(format, ".png") == 0) {
		int w, h;
		bool alpha;
		GLubyte *image;
		if (!LoadPngImage(filepath, w, h, alpha, &image)) {
			printf("cannot find %s \n", filepath);
			return 0;
		}
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		if (alpha) {
			gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, w, h, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*)image);
		}
		else {
			gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, w, h, GL_BGR_EXT, GL_UNSIGNED_BYTE, (GLvoid*)image);
		}

		delete image;
	}
	else
	{
		IplImage *img = NULL;
		img = cvLoadImage(filepath, 1);

		if (img != NULL)
		{
			cvFlip(img);
			glGenTextures(1, &textureID);
			glBindTexture(GL_TEXTURE_2D, textureID);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, img->width, img->height, GL_BGR_EXT, GL_UNSIGNED_BYTE, img->imageData);
		}
		else printf("cannot find %s \n", filepath);
	}

	return textureID;
}

void TextureApp::ScreenShot(std::string& file)
{
	GLint vp[4];
	glGetIntegerv(GL_VIEWPORT, vp);

	int x, y, w, h;
	x = vp[0];
	y = vp[1];
	w = vp[2];
	h = vp[3];

	unsigned char *bottomup_pixel = (unsigned char *)malloc(w*h * 3 * sizeof(unsigned char));
	unsigned char *topdown_pixel = (unsigned char *)malloc(w*h * 3 * sizeof(unsigned char));

	//Byte alignment (that is, no alignment)
	glPixelStorei(GL_PACK_ALIGNMENT, 1);
	glReadPixels(x, y, w, h, GL_RGB, GL_UNSIGNED_BYTE, bottomup_pixel);

	for (int j = 0; j<h; j++)
		memcpy(&topdown_pixel[j*w * 3], &bottomup_pixel[(h - j - 1)*w * 3], w * 3 * sizeof(unsigned char));


	FILE *f0 = fopen((file + ".ppm").c_str(), "wb");
	if (f0 == NULL)
	{
		printf("[Error] : SaveScreen(), Cannot open %s for writting.\n", (file + ".ppm").c_str());
		exit(-1);
	}

	fprintf(f0, "P6\n%d %d\n255\n", w, h);
	fwrite(topdown_pixel, sizeof(unsigned char), w*h * 3, f0);
	fclose(f0);

	free(bottomup_pixel);
	free(topdown_pixel);

	IplImage *pic = cvLoadImage((file + ".ppm").c_str(), -1);
	cvSaveImage((file + ".jpg").c_str(), pic);
	remove((file + ".ppm").c_str());

	std::cout << file << " Saved" << std::endl;
}
