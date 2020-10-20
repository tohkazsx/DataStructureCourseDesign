#include "heap.h"
#include<iostream>
using namespace std;
heap::heap()
{
    head=NULL;
    tail = n =0;
}
heap::~heap(){
    delete[]head;
}
/********public method****************/
//清空堆
int heap::clear(){
    delete [] head;
    tail=0;
    return 1;
}
//返回堆中元素个数
int heap::size(){
    return tail;
}
//返回堆顶元素
int heap::top(){
    if(head==NULL||tail==0)
        return ERROR;
    else
        return head[TOP];
}

/********private method**************/
void heap::swap(int &a,int &b)
{
      int tmp = a;
      a = b;
      b = tmp;
}

int heap::build(int* const A, const int _n)
{
    if (head != NULL)
            clear();
        head = new(nothrow) int[_n + 1];
        if (head == NULL)
            return ERROR;

        tail = n = _n;
        for(int i = 1; i <= n; ++i)
            head[i] = A[i - 1];
        head[0] = MAX;
        return OK;
}

void heap::push_up(const int pos)
{
    int cur = pos;
       while (cur > TOP)
       {
           int fa = Fa(cur);
           if (head[fa] >= head[cur])
               break;
           swap(head[fa], head[cur]);
           cur = fa;
       }
}

void heap::push_down()
{
    int cur = TOP;
        while (cur <= tail)
        {
            int lc = Lc(cur), rc = Rc(cur);
            if ((lc > tail && rc > tail) || (head[cur] >= head[lc] && head[cur] >= head[rc]))
                break;
            if (rc > tail)
            {
                if (head[cur] < head[lc])
                    swap(head[cur], head[lc]), cur = lc;
                else
                    break;
            }
            else
            {
                if ((head[cur] < head[lc]) ^ (head[cur] < head[rc]))
                {
                    if (head[cur] < head[lc])
                        swap(head[cur], head[lc]), cur = lc;
                    else
                        swap(head[cur], head[rc]), cur = rc;
                }
                else
                {
                    if (head[lc] > head[rc])
                        swap(head[cur], head[lc]), cur = lc;
                    else
                        swap(head[cur], head[rc]), cur = rc;
                }
            }
        }
}


