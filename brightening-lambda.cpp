#include <iostream>
#include "brightener.h"

int main() {
	auto image = std::make_shared<Image>(512, 512);
	
	if (image->isValid()) {
		std::cout << "Brightening a 512 x 512 image\n";
		ImageBrightener brightener(image);
		int attenuatedCount = brightener.BrightenWholeImage();
		std::cout << "Attenuated " << attenuatedCount << " pixels\n";
		return 0;
	}
	else {
		std::cout << "Not a valid image... did nothing\n";
		return 1;
	}
}
