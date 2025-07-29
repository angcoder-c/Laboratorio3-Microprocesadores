#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main() {
    array <int, 3> arr;
    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }
    sort(arr.end(), arr.begin());

    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}