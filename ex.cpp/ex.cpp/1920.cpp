#include <iostream>
using namespace std;

void quickSort(int arr[], int left, int right) {

    int i = left, j = right;

    int tmp;

    int pivot = arr[(left + right) / 2];

    while (i <= j) {

        while (arr[i] < pivot)

            i++;

        while (arr[j] > pivot)

            j--;

        if (i <= j) {

            tmp = arr[i];

            arr[i] = arr[j];

            arr[j] = tmp;

            i++;

            j--;

        }

    }

    if (left < j)

        quickSort(arr, left, j);

    if (i < right)

        quickSort(arr, i, right);

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;

    int Aarray[100001];





    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        Aarray[i] = a;
    }


    quickSort(Aarray, 0, N - 1);
    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        int start = 0;
        int end = N - 1;
        bool check = false;


        while (start <= end) {
            int mid = (end + start) / 2;
            if (Aarray[mid] == a) {
                cout << "1" << "\n";
                check = true;
                break;
            }
            else if (Aarray[mid] > a) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        if (check == false) {
            cout << "0" << "\n";
        }
    }
}
