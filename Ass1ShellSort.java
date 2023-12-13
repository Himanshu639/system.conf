//Implement the Heap/Shell sort algorithm implemented in Java demonstrating 
//heap/shell data structure with modularity of programming language


public class ShellSort {

    public void sort(int arr[]) {
        int n = arr.length;

        for (int gap = n / 2; gap > 0; gap /= 2) {
            
            for (int i = gap; i < n; i++) {
                
                int temp = arr[i];

                
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                    arr[j] = arr[j - gap];
                arr[j] = temp;
            }
        }
    }
    
    static void printArray(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    public static void main(String args[]) {
        int arr[] = {12, 11, 13, 5, 6};
        int n = arr.length;

        ShellSort shellSort = new ShellSort();
        shellSort.sort(arr);

        System.out.println("Sorted array is : ");
        printArray(arr);
    }
}
//TC : BC=0(nlogn) ; AC=0(nlog(n)^2) ; WC=0(n^2) SC=0(1)