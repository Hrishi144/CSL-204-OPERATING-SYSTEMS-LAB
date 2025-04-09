
#include <stdio.h>

int requests[20], n, disk_size, head, seek_time = 0;

// Function to sort the disk requests in ascending order
void bubbleSort(int arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    printf("Enter head position: ");
    scanf("%d", &head);

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    printf("Enter disk requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    // Add head position to the request list
    requests[n] = head;
    n++;

    // Sort the requests in ascending order
    bubbleSort(requests, n);

    // Find the position of head in sorted request array
    int head_index = 0;
    for (int i = 0; i < n; i++) {
        if (requests[i] == head) {
            head_index = i;
            break;
        }
    }

    printf("\n--- C-SCAN Disk Scheduling ---\n");

    // Move right from head to the highest request
    for (int i = head_index; i < n - 1; i++) {
        int distance = requests[i + 1] - requests[i];
        printf("Move from %d to %d : %d\n", requests[i], requests[i + 1], distance);
        seek_time += distance;
    }

    // Go from last request to end of disk
    if (requests[n - 1] != disk_size - 1) {
        int distance = (disk_size - 1) - requests[n - 1];
        printf("Move from %d to %d : %d\n", requests[n - 1], disk_size - 1, distance);
        seek_time += distance;
    }

    // Jump from end to start of disk (C-SCAN wrap-around)
    printf("Jump from %d to 0 : %d\n", disk_size - 1, disk_size - 1);
    seek_time += (disk_size - 1);

    // Continue from start (0) to remaining left-side requests
    for (int i = 0; i < head_index; i++) {
        int from = (i == 0) ? 0 : requests[i - 1];
        int distance = requests[i] - from;
        printf("Move from %d to %d : %d\n", from, requests[i], distance);
        seek_time += distance;
    }

    printf("\nTotal seek time: %d\n", seek_time);
    return 0;
}
