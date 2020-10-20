#ifndef HEAP_H
#define HEAP_H

#define Lc(x) (x << 1)
#define Rc(x) ((x << 1) | 1)
#define Fa(x) (x >> 1)

#define MAX     2147483647
#define ERROR	-2147483647
#define OK		1
#define TOP	    1

class heap
{
public:
    int *head;
    int tail,n;
    heap();
    ~heap();
    int clear();
    int size();
    int top();

    int build(int* const,const int);
    void push_up(const int);
    void push_down();
private:
    void swap(int &a,int &b);

};

#endif // HEAP_H
