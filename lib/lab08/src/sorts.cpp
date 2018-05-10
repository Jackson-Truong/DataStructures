#include "doubly_linked_list.h"

namespace lab6 {
    // Auxiliary Functions
    unsigned partititon(int *to_sort, int low, int high);

    doubly_linked_list recursive_merge_sort(doubly_linked_list to_sort);

    doubly_linked_list merge(doubly_linked_list left, doubly_linked_list right);

    void quicksort(int *to_sort, int low, int high) {
        int hello;
        if(high-low<2){
            return;
        }

        hello = partititon(to_sort, low, high);
        quicksort(to_sort, low, hello-1);
        quicksort(to_sort,hello+1, high);
    }

    unsigned partititon(int *to_sort, int low, int high) {
    int pivot = to_sort[high];
    int i= low-1;
    for(int j=low; j<=high-1;j++){
        if(to_sort[j]<pivot){
            i++;
            int temp= to_sort[i];//swap
            to_sort[i]=to_sort[j];
            to_sort[j]= temp;
        }
    }
        int temp= to_sort[i+1];//swap
        to_sort[i+1]=to_sort[high];
        to_sort[high]= temp;
        return (i+1);

    }

    void mergesort(doubly_linked_list &to_sort) {
to_sort = recursive_merge_sort(to_sort);

    }

    doubly_linked_list recursive_merge_sort(doubly_linked_list to_sort) {
        if(to_sort.size()==1){
            return to_sort;
        }
        unsigned mid = to_sort.size()/2;
        doubly_linked_list half = to_sort.split(mid);
        to_sort = recursive_merge_sort(to_sort);
        half =recursive_merge_sort(half);
        to_sort = merge(to_sort, half);
        return to_sort;
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
            if(rightlength == right.size()){
                while(leftlength!=left.size()){
                    hello.append(left.get_data(leftlength));
                    leftlength++;
                }
                return hello;
            }
        }
    }
}