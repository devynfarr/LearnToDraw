﻿// LearnToDraw.cpp : Defines the entry point for the application.
//

#include "LearnToDraw.h"
#include <blend2d.h>

using namespace std;

int main(int argc, char* argv[]) {
	BLImage img(480, 480, BL_FORMAT_PRGB32);

	// Attach a rendering context into `img`.
	BLContext ctx(img);

	// Clear the image.
	ctx.setCompOp(BL_COMP_OP_SRC_COPY);
	ctx.fillAll();

	// Fill some path.
	BLPath path;
	path.moveTo(26, 31);
	path.cubicTo(642, 132, 587, -136, 25, 464);
	path.cubicTo(882, 404, 144, 267, 27, 31);

	ctx.setCompOp(BL_COMP_OP_SRC_OVER);
	ctx.setFillStyle(BLRgba32(0xFFFFFFFF));
	ctx.fillPath(path);

	// Detach the rendering context from `img`.
	ctx.end();

	// Let's use some built-in codecs provided by Blend2D.
	BLImageCodec codec;
	codec.findByName("PNG");
	img.writeToFile("bl-getting-started-1.png", codec);
	

	return 0;
}
