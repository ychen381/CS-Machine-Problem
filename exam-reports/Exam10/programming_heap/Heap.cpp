#include "Heap.h"

/**
 * Inserts an integer element into the heap.
 *
 * @param item The integer to be inserted.
 */
void Heap::insert(const int &item)
{
    // TODO: Implement this function
    items_.push_back(item);
    heapup(items_.size()-1);
}

void Heap::heapup(int idx){
  if(idx==rootIdx()){
    return;
  }
  if (items_[idx]>items_[parentIdx(idx)]){
    std::swap(items_[idx],items_[parentIdx(idx)]);
  }
  heapup(parentIdx(idx));

}

/**
 * Removes the maximum item from the heap.
 *
 * @return the maximum item in the heap.
 */
int Heap::remove()
{
    // TODO: Implement this function
    int max=items_[1];
    items_[1]=items_[items_.size()-1];
    items_.pop_back();
    heapdown(1);
    return max;
}

void Heap::heapdown(int idx){
  if(!hasChild(idx)){
    return;
  }
  int max=maxPriorityChild(idx);
  if(items_[idx]<items_[max]){
    std::swap(items_[idx],items_[max]);
  }
  heapdown(max);
}

Heap::Heap()
{
    items_.resize(1);
}

int Heap::rootIdx() const
{
    return 1;
}

int Heap::maxPriorityChild(int currIdx) const
{
    if (rightChildIdx(currIdx) >= (int)items_.size())
    {
        return leftChildIdx(currIdx);
    }
    else if (items_.at(rightChildIdx(currIdx)) > items_.at(leftChildIdx(currIdx)))
    {
        return rightChildIdx(currIdx);
    }
    else
    {
        return leftChildIdx(currIdx);
    }
}

int Heap::rightChildIdx(int currIdx) const
{
    return 2 * currIdx + 1;
}

int Heap::leftChildIdx(int currIdx) const
{
    return 2 * currIdx;
}

int Heap::parentIdx(int currIdx) const
{
    return currIdx / 2;
}

bool Heap::hasChild(int currIdx) const
{
    return leftChildIdx(currIdx) < (int) items_.size();
}

bool Heap::empty() const
{
    return items_.size() == 1;
}

void Heap::getItems(std::vector<int> & heap) const
{
    for (const int & i : items_) {
        heap.push_back(i);
    }
}
