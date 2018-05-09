#include "doubly_linked_list.h"

namespace lab6 {
    // Auxiliary Functions
    unsigned partition(int *to_sort, int low, int high);

    doubly_linked_list recursive_merge_sort(doubly_linked_list to_sort);

    doubly_linked_list merge(doubly_linked_list left, doubly_linked_list right);

    void quicksort(int *to_sort, int low, int high) {

    }

    unsigned partititon(int *to_sort, int low, int high) {

    }

    void mergesort(doubly_linked_list &to_sort) {

    }

    doubly_linked_list recursive_merge_sort(doubly_linked_list to_sort) {

    }

    //Used for the merging the two lists
    doubly_linked_list merge(doubly_linked_list left, doubly_linked_list right) {
        doubly_linked_list hello;
        int leftlength = 0;
        int rightlength = 0;
        while (leftlength != left.size() && rightlength != right.size()) {
            if (left.get_data(leftlength) > right.get_data(rightlength)) {
                hello.append(right.get_data(rightlength));
                rightlength++;
            } else if (left.get_data(leftlength) < right.get_data(rightlength)) {
                hello.append(left.get_data(leftlength));
                leftlength++;
            } else {//equal to each other
                hello.append(left.get_data(leftlength));
                leftlength++;
                hello.append(right.get_data(rightlength));
                rightlength++;
            }
            if (leftlength == left.size()) {
                while (rightlength != right.size()) {
                    hello.append(right.get_data(rightlength));
                    rightlength++;
                }
                return hello;
            }
        }
    }
}