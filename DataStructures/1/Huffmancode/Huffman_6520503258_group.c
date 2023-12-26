//6520503258 Kanesh Orachunlertmitri
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
char key[MAXHEAP] = "";
int value[MAXHEAP] = {0}, current_index = -1;

HuffmanNode *createNewNode(char data, int freq)
{
    HuffmanNode *new_node = malloc(sizeof(HuffmanNode));
    new_node->data = data;
    new_node->freq = freq;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
HuffmanNode *createNode(HuffmanNode node)
{
    HuffmanNode *new_node = createNewNode(node.data, node.freq);
    new_node->left = node.left;
    new_node->right = node.right;
    return new_node;
}
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
HuffmanNode removeHeap()
{
    int index = 0;
    HuffmanNode temp = H[index];

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
        HuffmanNode new_node;
        HuffmanNode t1 = removeHeap();
        HuffmanNode t2 = removeHeap();
        new_node.data = '-';
        new_node.freq = t1.freq + t2.freq;
        new_node.left = createNode(t1);
        new_node.right = createNode(t2);
        insertTopDown(new_node);
    }
    return &H[0];
}
void inorder(HuffmanNode *t)
{
    if (t == NULL)
        return;
    inorder(t->left);
    printf("'%c':%d ", t->data, t->freq);
    inorder(t->right);
}
void printCode(HuffmanNode *t, int arr[], int top, char buffer[][20])
{
    if (t->left != NULL){
        arr[top] = 0;
        printCode(t->left, arr, top+1, buffer);
    }

    if (t->right != NULL){
        arr[top] = 1;
        printCode(t->right, arr, top+1, buffer);
    }

    if (t->left == NULL && t->right == NULL){
        printf("%c: ", t->data);
        for (int i=0; i<top; i++){
            printf("%d", arr[i]);
            buffer[strchr(key, t->data) - key][i] = arr[i] + '0';
        }
        buffer[strchr(key, t->data) - key][top] = '\0';
        printf("\n");
    }
}

int main(void)
{
    char input[300];
    printf("Enter sentence : ");
    scanf("%[^\n]s", input);
    
    countFreq(input, key, value);
    printf("\n1. Frequency table of %lu characters\n", strlen(key));
    for (int i=0; i<strlen(key); i++){
        printf("'%c':%d ", key[i], value[i]);

        //insert in Heap
        current_index++;
        H[current_index] = *createNewNode(key[i], value[i]);
        
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
    inorder(root);
    printf("\n");

    printf("\n3. Huffman code for each character\n");
    char huffmancode[strlen(key)][20]; //binary for character
    int arr[strlen(key)], top = 0; //buffer binary
    printCode(root, arr, top, huffmancode);

    printf("\n4. Encoded sentence\n");
    for (int i=0; i<strlen(input); i++)
        printf("%s ", huffmancode[strchr(key, input[i]) - key]);
    return 0;
}