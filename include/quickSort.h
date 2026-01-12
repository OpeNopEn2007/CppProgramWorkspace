void quickSort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int pivot = a[r], i = l;

    for (int j = i; j < r; j++)
    {
        if (a[j] < pivot)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
        }
    }
    int temp = a[i];
    a[i] = a[r];
    a[r] = temp;
    quickSort(a, l, i - 1);
    quickSort(a, i + 1, r);
}