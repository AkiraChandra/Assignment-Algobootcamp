#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Nilai;
    Node *Selanjutnya;
}*buntut = NULL, *kepala = NULL;

Node *createNode(int Nilai)
{
    Node *nodebaru = (Node*)malloc(sizeof(Node));
    nodebaru->Nilai = Nilai;
    nodebaru->Selanjutnya = NULL;

    return nodebaru;
}

void pushbuntut(int Nilai)
{
    Node *nodebaru = createNode(Nilai);
    if(!buntut)
    {
        kepala = buntut = nodebaru;
    }else{
        buntut->Selanjutnya = nodebaru;
        buntut = buntut->Selanjutnya;
    }
}

void pushkepala(int Nilai)
{
    Node *nodebaru = createNode(Nilai);
    if(!buntut)
    {
        kepala = buntut = nodebaru;
    }else
    {
        nodebaru->Selanjutnya = kepala;
        kepala = nodebaru;
    }
}

void pushpriority(int Nilai)
{
    Node *nodebaru = createNode(Nilai);
    Node *Sekarang = kepala;
    if(!buntut)
    {
        kepala = buntut = nodebaru;
    }else if (kepala->Nilai > nodebaru->Nilai) pushkepala(nodebaru->Nilai);
    else if(buntut->Nilai < nodebaru->Nilai) pushbuntut(nodebaru->Nilai);
    else
    {
        while(Sekarang->Selanjutnya->Nilai < nodebaru->Nilai)
        {
            Sekarang = Sekarang->Selanjutnya;
        }
        nodebaru->Selanjutnya= Sekarang->Selanjutnya;
        Sekarang->Selanjutnya = nodebaru;

    }
}

void hapus()
{
    Node *Sekarang = kepala->Selanjutnya;
    kepala->Selanjutnya=NULL;
    free(kepala);
    kepala = Sekarang;
}

void Tampilkan()
{
    Node *Sekarang = kepala;
    while(Sekarang){
        printf(" Node %d ", Sekarang->Nilai);
        Sekarang = Sekarang->Selanjutnya;
    }
    puts("");
}

int main()
{
pushpriority(15);
pushpriority(16);
pushpriority(17);
pushpriority(18);
pushpriority(19);
pushpriority(20);
pushpriority(4);
pushpriority(25);
pushpriority(27);
Tampilkan();
hapus();
puts("setelah dihapus");
Tampilkan();
puts("setelah dihapus ");
hapus();
Tampilkan();
    return 0;
}