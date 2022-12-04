/*Nombre: Adrian Vasconez (00208899)
Fecha: 2021-10-20
QuickSort eligiendo pivote aleatoriamente*/

/*Respuesta a 23.5.4: Sin esas lineas de codigo, el sort
no funciona. El lazo while anterior solo asegura que
haya una particion de los valores, pero no que high
se encuentre en la posicion adecuada. Consideremos el
caso {2,3,2,1}. Al usar el sort sin esas lineas,
obtenemos {2,1,2,3}, que no esta ordenado.*/

import java.util.Random;

public class RandomQuickSort {  
  public static void quickSort(int[] list) {
    Random random = new Random();
    quickSort(list, 0, list.length - 1, random);
  }

  private static void quickSort(int[] list, int first, int last, Random random) {
    if (last > first) {
      int pivotIndex = partition(list, first, last, random);
      quickSort(list, first, pivotIndex - 1, random);
      quickSort(list, pivotIndex + 1, last, random);
    }
  }

  /** Partition the array list[first..last] */
  private static int partition(int[] list, int first, int last, Random random) {
    // Exchange first element with random element
    int r = random.nextInt(last - first + 1) + first;
    int firstElement = list[first];
    list[first] = list[r];
    list[r] = firstElement;
    
    int pivot = list[first]; // Choose the new first element as the pivot
    int low = first + 1; // Index for forward search
    int high = last; // Index for backward search

    while (high > low) {
      // Search forward from left
      while (low <= high && list[low] <= pivot)
        low++;

      // Search backward from right
      while (low <= high && list[high] > pivot)
        high--;

      // Swap two elements in the list
      if (high > low) {
        int temp = list[high];
        list[high] = list[low];
        list[low] = temp;
      }
    }

    while (high > first && list[high] >= pivot)
      high--;

    // Swap pivot with list[high]
    if (pivot > list[high]) {
      list[first] = list[high];
      list[high] = pivot;
      return high;
    }
    else {
      return first;
    }
  }

  /** A test method */
  public static void main(String[] args) {
    int[] list = {2,3,2,1,-5,-8,10,98,3,7,50};
    quickSort(list);
    for (int i = 0; i < list.length; i++)
      System.out.print(list[i] + " ");
  }
}
