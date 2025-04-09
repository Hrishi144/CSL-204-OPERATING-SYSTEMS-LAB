#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int requests[20], n, head, size;
    int totalSeek = 0;

    printf("Enter disk size: ");
    scanf("%d", &size);

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    // Add head to requests and sort
    requests[n] = head;
    n++;
    bubbleSort(requests, n);

    // Find head position in sorted array
    int headIndex = 0;
    for (int i = 0; i < n; i++) {
        if (requests[i] == head) {
            headIndex = i;
            break;
        }
    }

    printf("\n--- SCAN Disk Scheduling ---\n");

    // Move right (toward higher cylinders)
    for (int i = headIndex; i < n - 1; i++) {
        int move = requests[i + 1] - requests[i];
        printf("Move from %d to %d: %d\n", requests[i], requests[i + 1], move);
        totalSeek += move;
    }

    // Go to the end if needed
    if (requests[n - 1] != size - 1) {
        int move = (size - 1) - requests[n - 1];
        printf("Move from %d to %d: %d\n", requests[n - 1], size - 1, move);
        totalSeek += move;
    }

    // Move left (from end back to lower requests)
    for (int i = headIndex - 1; i > 0; i--) {
        int move = requests[i] - requests[i - 1];
        printf("Move from %d to %d: %d\n", requests[i], requests[i - 1], move);
        totalSeek += move;
    }

    printf("\nTotal seek time: %d\n", totalSeek);
    return 0;
}
