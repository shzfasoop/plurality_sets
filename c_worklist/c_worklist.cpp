#include <set>
#include <iterator>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    char a[] = "Stolpovskiy",
        b[] = "Nikita",
        c[] = "Vladimirovich";
    set<char> sa(begin(a), prev(end(a))),
        sb(begin(b), prev(end(b))),
        sc(begin(c), prev(end(c)));

    set<char> abc_union;
    set_union(begin(sa), end(sa),
        begin(sb), end(sb),
        inserter(abc_union, begin(abc_union)));
    set_union(begin(abc_union), end(abc_union),
        begin(sc), end(sc),
        inserter(abc_union, begin(abc_union)));
    cout << "Union of abc: ";
    ostream_iterator<char> out(cout, "");
    copy(begin(abc_union), end(abc_union), out);

    set<char> abc_inter;
    set_intersection(begin(sa), end(sa),
        begin(sb), end(sb),
        inserter(abc_inter, begin(abc_inter)));
    set_intersection(begin(abc_inter), end(abc_inter),
        begin(sc), end(sc),
        inserter(abc_inter, begin(abc_inter)));
    cout << "\nIntersection of abc: ";
    copy(begin(abc_inter), end(abc_inter), out);

    set<char> ab_diff;
    set_difference(begin(sa), end(sa),
        begin(sb), end(sb),
        inserter(ab_diff, begin(ab_diff)));
    cout << "\nDifference of a and b: ";
    copy(begin(ab_diff), end(ab_diff), out);

    set<char> ba_diff;
    set_difference(begin(sb), end(sb),
        begin(sa), end(sa),
        inserter(ba_diff, begin(ba_diff)));
    cout << "\nDifference of b and a: ";
    copy(begin(ba_diff), end(ba_diff), out);

    set<char> ab_sym_diff;
    set_symmetric_difference(begin(sa), end(sa),
        begin(sb), end(sb),
        inserter(ab_sym_diff, begin(ab_sym_diff)));
    cout << "\nSymmetric difference of a and b: ";
    copy(begin(ab_sym_diff), end(ab_sym_diff), out);
    cout << endl;
    system("pause");
}