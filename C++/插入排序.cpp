struct SqList {
    int lenth;
    int key[10000];
};

void InsertSort(SqList &list) {
    for (int i = list.lenth - 2; i > 0; --i) {
        if (list.key[i] > list.key[i + 1]) {
            list.key[list.lenth] = list.key[i];  //list.key[n]为监视哨
            int j = i + 1;
            for (; list.key[j] < list.key[list.lenth]; ++j) {
                list.key[j - 1] = list.key[j];
            }
            list.key[j - 1] = list.key[list.lenth];
        }
    }   
}