 /**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */
template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */if(first[curDim]!=second[curDim]){
        return (first[curDim]<second[curDim]);
      }
      else{
        return first<second;
      }

}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
     double dp=0;
     double dc=0;
     for (int i=0;i<Dim;i++){
       dp=dp+(potential[i]-target[i])*(potential[i]-target[i]);
       dc=dc+(currentBest[i]-target[i])*(currentBest[i]-target[i]);
     }
     if(dp==dc){
       return potential<currentBest;
     }
     else if(dp<dc){
       return true;
     }
     else{
       return false;
     }
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */

    points=newPoints;

  //  std::cout << "size()"<<points.size() << '\n';
    if(points.size()!=0){
    KDTree_Helper(0,points.size()-1,0);}


}

template <int Dim>
void KDTree<Dim>::KDTree_Helper(int left,int right,int d){
  //std::cout << right << '\n';
  int median= (left+right)/2;
  //std::cout << right << '\n';
  select(left,right,median,d);
  //std::cout << right << '\n';
  if (right==left){
    return;
  }
  if(left<median){
    KDTree_Helper(median+1,right,(d+1)%Dim);
  }
  if(right>median){
    KDTree_Helper(left,median-1,(d+1)%Dim);
  }
}

template <int Dim>
void KDTree<Dim>::select(int left,int right,int k,int curDim){
  //  std::cout << "select" << '\n';
    if (left >= right){
    //  std::cout << right << '\n';
      //std::cout << "left==right" << '\n';
      return ;
    }

    int pivotIndex= (left+right)/2;
    //std::cout << pivotIndex << '\n';
//std::cout << "int pivotIndex=(l+r)/2" << '\n';
    pivotIndex=partition(left,right,pivotIndex,curDim);
//std::cout << "first call partition" << '\n';
    if (pivotIndex == k){
    //  std::cout << "pivotIndex==k" << '\n';
      return;
    }
    else if(k<pivotIndex){
      //std::cout << "k<pivotIndex" << '\n';
      return select(left,pivotIndex-1,k,curDim);
    }
    else{
      //std::cout << "else" << '\n';
      return select(pivotIndex+1, right, k,curDim);
    }
  }


template <int Dim>
int KDTree<Dim>::partition(int left,int right,int pivotIndex,int curDim){
  //std::cout << "partition called" << '\n';
//  std::cout << Dim << '\n';
  //std::cout << pivotIndex << '\n';
//  std::cout << points[pivotIndex] << '\n';
    Point<Dim> pivot=points[pivotIndex];

    Point<Dim> temp1=points[pivotIndex];

    points[pivotIndex]=points[right];

    points[right]=temp1;

    int storeIndex=left;


    for(int i=left;i<right;i++){

      if (smallerDimVal(points[i],pivot,curDim)){
        Point<Dim> temp2=points[storeIndex];
        points[storeIndex]=points[i];
        points[i]=temp2;
        storeIndex++;
      }
    }
    Point<Dim> temp3=points[storeIndex];
    points[storeIndex]=points[right];
    points[right]=temp3;

    return storeIndex;
}




template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */

     Point<Dim> val = N_helper(0, query, 0, points.size()-1, points[(points.size()-1)/2]);

    return val;



}



// heloer function of findNearestNeighbor
template<int Dim>
Point<Dim> KDTree<Dim>::N_helper(int curDim, const Point<Dim> &query, int left, int right, const Point<Dim> &currentBest) const
{

    Point<Dim> ret_val = currentBest;
    // check which side has been visited
    bool target_left = true;
    //basic case
    if (left == right)
    {

        if (shouldReplace(query, currentBest, points[left]))
        {
            //return current best and radius
             ret_val = points[left];
             return ret_val;
        }
        ret_val = currentBest;
        return ret_val;
    }

    int median = (left + right)/2;

    //goes to right subtree
    if (smallerDimVal(points[median], query, curDim) && right > median)
    {
        ret_val = N_helper((curDim+1)%Dim, query, median+1, right, currentBest);
        target_left = false;

    }
    //goes to left subtree
    if (smallerDimVal(query, points[median], curDim) && left < median)
    {
        ret_val = N_helper((curDim+1)%Dim, query, left, median-1, currentBest);
        target_left = true;

    }

    //visit the parent
    if (shouldReplace(query, ret_val, points[median]))
        ret_val = points[median];


    Point<Dim> curr = points[median];

    //check the other side
    if (target_left && right > median)
            ret_val = N_helper((curDim+1)%Dim, query, median+1, right, ret_val);
    if (!target_left && left < median)
            ret_val = N_helper((curDim+1)%Dim, query, left, median-1, ret_val);

    return ret_val;

}
