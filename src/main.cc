#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

// ASCII characters from darkest to lightest
const std::string grayscale = "@%#*+=-:. ";

// Function to convert RGB to grayscale
unsigned char rgbToGray(unsigned char r, unsigned char g, unsigned char b) {
    return static_cast<unsigned char>(0.2126 * r + 0.7152 * g + 0.0722 * b);
}

int main() {
    // Open the JPEG file
    std::ifstream file("skibidi.jpg", std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Failed to open image file!" << std::endl;
        return 1;
    }

    // Skip JPEG header (you need to parse the JPEG structure for a more accurate implementation)
    file.seekg(2); // Skip the first two bytes (JPEG magic number)

    // Read the width and height (simplified, assumes a specific format)
    unsigned int width = 80; // Adjust to your terminal width
    unsigned int height = 40; // Adjust to your terminal height

    // Resize image to fit terminal window
    std::vector<unsigned char> image(width * height * 3);

    // Read pixel data (simplified, assumes a specific format)
    file.read(reinterpret_cast<char*>(image.data()), image.size());

    // Convert pixel data to grayscale and display
    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            unsigned char r = image[(y * width + x) * 3];
            unsigned char g = image[(y * width + x) * 3 + 1];
            unsigned char b = image[(y * width + x) * 3 + 2];

            unsigned char gray = rgbToGray(r, g, b);

            // Map grayscale value to ASCII character
            unsigned int index = static_cast<unsigned int>(gray / 255.0f * (grayscale.size() - 1));
            std::cout << grayscale[index];
        }
        std::cout << std::endl;
    }

    return 0;
}