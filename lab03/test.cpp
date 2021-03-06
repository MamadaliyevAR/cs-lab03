#include "histogram.h"

#include <cassert>

void
test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}

void same_numbers()
{
double min = 0;
double max = 0;
find_minmax({ 5, 5, 5 }, min, max);
assert(min == 5);
assert(max == 5);
}

void one_number()
{
double min = 0;
double max = 0;
find_minmax({ 1 }, min, max);
assert(min == 1);
assert(max == 1);

}

void empty_array()
{
double min = 0;
double max = 0;
find_minmax({}, min, max);
assert(min == 0);
assert(max == 0);
}
int
main() {
    test_positive();
    same_numbers();
    one_number();
    empty_array();
}
