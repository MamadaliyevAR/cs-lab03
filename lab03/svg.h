#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED

#include <vector>

using namespace std;

void svg_begin(double width, double height);
void svg_end();
void svg_rect(double left, double baseline, size_t width, double height, string stroke , string fill);
void svg_text(double left, double baseline, string text);
void show_histogram_svg(const vector<size_t>& bins);

#endif // SVG_H_INCLUDED
