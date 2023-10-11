#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXHEAP 50

typedef struct HuffmanNode {
 char data;
 int freq;
 struct HuffmanNode *left, *right;
}HuffmanNode;
HuffmanNode H[MAXHEAP]; //Initialize HEAP 
HuffmanNode HuffmanTree[MAXHEAP];
int current_index = -1;

int leftChild(int k)
{
    return 2*k+1;
}
int rightChild(int k)
{
    return 2*k+2;
}
void swap(HuffmanNode *a, HuffmanNode *b)
{
    HuffmanNode temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int index, int n)
{
    while (leftChild(index) < n)
    {
        if (H[index].freq <= H[leftChild(index)].freq && (rightChild(index) >= n || H[index].freq <= H[rightChild(index)].freq))
            return;
        if (H[leftChild(index)].freq < H[rightChild(index)].freq || rightChild(index) >= n){
            swap(&H[index], &H[leftChild(index)]);
            index = leftChild(index);
        }else{
            swap(&H[index], &H[rightChild(index)]);
            index = rightChild(index);
        }
    }
}
void Heap_BottomUp(int n)
{
    int index = (current_index-1) / 2; //last parent
    while (index >= 0)
    {
        heapify(index, n);
        index--;
    }
}
void insertTopDown(HuffmanNode node)
{
    int index = ++current_index;
    H[index] = node;
    while (index > 0)
    {
        int parent = (index-1)/2;
        if (H[index].freq < H[parent].freq){
            swap(&H[index], &H[parent]);
            index = parent;
        }else
            break;
    }
}
HuffmanNode *removeHeap()
{
    int index = 0;
    HuffmanNode *temp = malloc(sizeof(HuffmanNode));
    temp->data = H[index].data;
    temp->freq = H[index].freq;

    H[index] = H[current_index];
    heapify(index, current_index+1);
    current_index--;

    return temp;
}

void countFreq(char msg[], char key[], int value[])
{
    int index_kv = 0;
    char *p;
    for (int i=0; i<strlen(msg); i++)
    {
        if ( (p = strchr(key, msg[i])) == NULL){
            key[index_kv] = msg[i];
            value[index_kv]++;
            index_kv++;
        }else{
            value[p-key]++;
        }
    }
    key[index_kv] = '\0';
}

HuffmanNode *createHuffmanTree()
{
    while (current_index >= 1){
        HuffmanNode *new_node = malloc(sizeof(HuffmanNode));
        HuffmanNode *t1 = removeHeap();
        HuffmanNode *t2 = removeHeap();
        new_node->data = '-';
        new_node->freq = t1->freq + t2->freq;
        new_node->left = t1;
        new_node->right = t2;
        insertTopDown(*new_node);
        if (current_index == 1)
            printf("%d %d\n", new_node->left->freq, new_node->right->freq);
    }
    return removeHeap();
}

void inorder(HuffmanNode *t)
{
    if (t == NULL)
        return;
    inorder(t->left);
    printf("'%c':%d ", t->data, t->freq);
    inorder(t->right);
}

int main(void)
{
    char input[300], key[MAXHEAP] = "";
    int value[MAXHEAP] = {0};
    printf("Enter sentence : ");
    scanf("%[^\n]s", input);
    
    countFreq(input, key, value);
    printf("\n1. Frequency table of %lu characters\n", strlen(key));
    for (int i=0; i<strlen(key); i++){
        printf("'%c':%d ", key[i], value[i]);

        //insert in Heap
        current_index++;
        H[current_index].data = key[i];
        H[current_index].freq = value[i];
    }
    printf("\n");

    printf("\n2.1 A Min-Heap (the less frequency, the higher priority)\n");
    Heap_BottomUp(strlen(key));
    for (int i=0; i<strlen(key); i++){
        printf("'%c':%d ", H[i].data, H[i].freq);
    }
    printf("\n");

    printf("\n2.2 A Huffman Tree\n");
    HuffmanNode *root = createHuffmanTree();
    printf("%d", root->left->freq);
    // inorder(root);
    return 0;
}