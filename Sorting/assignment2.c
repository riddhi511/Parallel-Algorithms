#include <stdlib.h>
#define PERLINE 10

#define L1SZ 7
#define L2SZ 14

float list1[] = {2.0, 6.0, 10.0, 16.0, 22.0, 45.0, 90.0};
float list2[] = {3.0, 7.0, 9.0, 11.0, 13.0, 18.0, 31.0, 47.0, 53.0, 64.0, 72.0, 75.0, 81.0, 87.0};
float listout[L1SZ + L2SZ];

/* compute rank of a value in list ls of size sz */
int rank(float ls[], int sz, float val) {
    int r = 0, i;
    for (i = 0; i < sz; i++) {
        if (ls[i] < val) {
            r++;
        }
    }
    return r;
}

/* merge one element from l1 or l2 into output list */
void merge_lists(float l1[], int l1sz, float l2[], int l2sz, float ol[]) {
    int i;
    /* process list1 elements in parallel */
    forall i = 0 to l1sz-1 do {
        int ra = rank(l1, l1sz, l1[i]);
        int rb = rank(l2, l2sz, l1[i]);
        ol[ra + rb] = l1[i];
    }
    /* process list2 elements in parallel */
    forall i = 0 to l2sz-1 do {
        int ra = rank(l2, l2sz, l2[i]);
        int rb = rank(l1, l1sz, l2[i]);
        ol[ra + rb] = l2[i];
    }
}

/* display utility */
void display(float dk[], int sz, int per) {
    int i, ct, pm1;
    pm1 = per - 1;
    ct = 0;
    for (i = 0; i < sz; ++i, ++ct) {
        cout.width(5);
        cout << dk[i];
        if (ct == pm1) {
            cout << endl;
            ct = -1;
        }
    }
    if (ct != pm1) cout << endl;
}

int main() {
    int sz, l1size, l2size;
    cout.precision(3);
    sz = sizeof(listout);
    l1size = sizeof(list1);
    l2size = sizeof(list2);

    cout << "input1:" << endl;
    display(list1, l1size, PERLINE);

    cout << "input2:" << endl;
    display(list2, l2size, PERLINE);

    /* merge lists */
    merge_lists(list1, l1size, list2, l2size, listout);

    cout << "merged:" << endl;
    display(listout, sz, PERLINE);

    return 0;
}
