#ifndef HEAP_H
#define HEAP_H
#include "HeapADT.h"
#include <iostream>
#include <algorithm>
using namespace std;

template <typename E, typename Comp> class heap : public HeapADT<E>
{
private:
    E* content;
    int maxsize;
    int n;


    void heapfy(int pos)
    {
        while(!isLeaf(pos))
        {
            if((righ(pos) <  n)&& Comp::prior(content[righ(pos)],content[left(pos)]))
            {
                left(pos)=righ(pos);
            }
            if(Comp::prior(content[pos],content[left(pos)]))return;
            swap(content[pos],content[left(pos)]);
            pos = left(pos);
        }

    }





public:
    heap (E* h,int num, int max )
       {

           content=h ;
           n=num;
           maxsize=max;
           buildMaxHeap ();
    }


    int size() const
    {
        return n;
    }
    bool isLeaf(int pos) const
    {
        return (pos >= n/2) && (pos < n);
    }
    int left(int pos) const
    {
        return (2*pos + 1 );
    }
    it righ(int pos) const
    {
        return(2*pos + 2 );
    }
    int parent(int pos) const
    {
        return(pos/2);
    }
    void buildMaxHeap()
    {
     for (int i=n/2-1; i>=0; i--)
     {
         heapfy(i);
     }
    }
    void insert(const E& it)
    {
        if(n < maxsize)
        {
            int nova = n++;
            content[nova] = it;
            while ((nova!=0) &&(Comp::prior(content[nova], content[parent(nova)])))
            {
                swap(content, nova, parent(nova));
                nova = parent(nova);

            }
        }
    }
    E removefirst()
    {
        if(n=0)
        {
            cout<<"Heap é vazia"<<endl;
        }
        else
        {
        swap(content[0],content[n]);
        content[n--];
        }
    }
    E remove(int pos)
    {
        swap(content[pos],content[n]);
        content[n--];
        while((pos!=0)&&(Comp::prior(content[pos],content[parent(pos)])))
        {
            swap(content[pos],content[parent(pos)]);
            pos = parent(pos);
        }
        return content[n];
    }
};





#endif // HEAP_H
