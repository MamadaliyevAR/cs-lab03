#include <curl/curl.h>
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
read_input(istream& in,bool prompt)
{
    Input data;
    if (prompt)
    {
        cerr << "Enter number count: ";
    }
    size_t number_count;
    in >> number_count;

    if(prompt)
    {
        cerr << "Enter numbers: ";
    }
    data.numbers = input_numbers(in, number_count);

    if(prompt)
    {
        cerr <<"Enter bin count:";
    }
    in>>data.bin_count;

    return data;
}


int
main(int argc, char* argv[])
{
    if (argc > 1)
    {
        CURL* curl = curl_easy_init();
        if(curl)
        {
            CURLcode res;
            curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
            /* ask libcurl to show us the verbose output */
            // curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, FALSE);
            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
            if (res != CURLE_OK)
            {
                cerr << curl_easy_strerror(res);
                exit(1);
            }

        }
        return 0;
    }

    // curl_global_init(CURL_GLOBAL_ALL);
    const auto input = read_input(cin, true);
    const vector<size_t> bins = make_histogram(input);
    // show_histogram_text(bins);
    show_histogram_svg(bins);
}
