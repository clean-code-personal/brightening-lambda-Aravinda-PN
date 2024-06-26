#include "brightener.h"

ImageBrightener::ImageBrightener(std::shared_ptr<Image> inputImage) : m_inputImage(inputImage) {
}

int ImageBrightener::BrightenWholeImage() {
	int attenuatedPixelCount = 0;
	m_inputImage->pixelRunner([&attenuatedPixelCount](uint8_t pixelGrayscale) {
		uint8_t outputGrayscale = pixelGrayscale;
		if (outputGrayscale > (255 - 25)) {
			++attenuatedPixelCount;
			outputGrayscale = 255;
		}
		else {
			outputGrayscale += 25;
		}

		return outputGrayscale;
		});
	return attenuatedPixelCount;
}
