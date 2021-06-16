#include <iostream>
#include <vector>
#include "svg.h"

void svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end()
{
    cout << "</svg>\n";
}

void svg_rect(double left, double baseline, size_t width, double height, string stroke , string fill = "black")
{
    cout << "<rect x ='" << left << "' y ='" << baseline << "' width ='" << width << "' height ='" << height << "' stroke ='" << stroke << "' fill ='" << fill << "' />\n";
}

void svg_text(double left, double baseline, string text)
{
    cout << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>\n";
}

void show_histogram_svg(const vector<size_t>& bins)
{
const auto IMAGE_WIDTH = 400;
const auto MAX_WIDTH = 350;
const auto IMAGE_HEIGHT = 300;
const auto TEXT_LEFT = 20;
const auto TEXT_BASELINE = 20;
const auto TEXT_WIDTH = 50;
const auto BIN_HEIGHT = 30;
const double BLOCK_WIDTH = 10;
svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
double top = 0;

size_t max_count = 0;
for (size_t count : bins) {
if (count > max_count) {
max_count = count;
}
}
const bool scaling_needed = (max_count * BLOCK_WIDTH) > MAX_WIDTH;

for (size_t bin : bins)
{
const double bin_width = BLOCK_WIDTH * bin;

size_t width = bin_width;
if (scaling_needed) {
const double scaling_factor = (double)MAX_WIDTH / (max_count * BLOCK_WIDTH);
width = (bin_width * scaling_factor);
}

string stroke = "red";
string fill = "red";


svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
svg_rect(TEXT_WIDTH, top, width, BIN_HEIGHT, stroke, fill);
top += BIN_HEIGHT;
}
svg_end();
}
