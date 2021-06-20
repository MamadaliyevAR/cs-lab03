#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"

using namespace std;


vector<double>
input_numbers(istream& in, size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cerr << "Enter " << i + 1 << " number:\t";
        in >> result[i];
    }
    return result;
}

Input
read_input(istream& in)
{
    Input data;
    cerr << "Enter number count: ";
    size_t number_count;
    in >> number_count;
    cerr << "Enter numbers: ";
    data.numbers = input_numbers(in, number_count);
    cerr << "Enter quantity of bins: ";
    in >> data.bin_count;
    return data;
}

void show_histogram_text (const vector<double>& bins)
{
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 4 - 1;

    size_t max_count = 0;
    for (size_t count : bins) {
        if (count > max_count) {
 max_count = count;
        }
    }
    const bool scaling_needed = max_count > MAX_ASTERISK;

    for (size_t bin : bins) {
        if (bin < 100) {
 cout << ' ';
        }
        if (bin < 10) {
 cout << ' ';
        }
 cout << bin << "|";

        size_t height = bin;
        if (scaling_needed) {
            const double scaling_factor = (double)MAX_ASTERISK / max_count;
 height = (size_t)(bin * scaling_factor);
        }

        for (size_t i = 0; i < height; i++) {
 cout << '*';
        }
 cout << '\n';
    }
}


int
main() {
    const auto input = read_input(cin);
    const auto bins = make_histogram(input);
    show_histogram_svg(bins);
}
