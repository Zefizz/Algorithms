/*Author: Zefizz*/
/*2017/04/09*/
/*An implementation of merge sort using C++ pointer*/
/*arrays and arithmetic. Sorts ints, can template to*/

#include <iostream>

/*print the array. Basic, may wat to overwrite*/
/*requires your class/type to have the operator<<*/
template<typename T>
void printArr(T* A, int a)
{
	for(int i=0; i<a; ++i)
		std::cout << A[i] << " ";
	std::cout << std::endl;
}

/*merge two already sorted arrays together in sorted order*/
/*requires your class/type to have the operator<*/
template<typename T>
T* sort(T* A, int sizea, T* B, int sizeb)
{
	//new array to store in
	T* combined = new T[sizea+sizeb];
	//indeces
	int a,b,c;
	a = b = c = 0;
	//while either is non-empty
	while(a<sizea || b<sizeb) {
		if(a<sizea && b<sizeb) {	//both non-empty
			if(A[a] < B[b])
				combined[c++] = A[a++];
			else
				combined[c++] = B[b++];
		}
		else if(a<sizea)	//B is empty
			combined[c++] = A[a++];
		else				//A is empty
			combined[c++] = B[b++];
	}
	/*std::cout << "combined result is" << std::endl;
	printArr(combined,c);*/

	/*we wat to free the memory when coming up the recursion,
	 *however ONLY free if A, B are the result of a merge,
	 *meaning that they have size at least two
	 *(we can't go deleting the origionals)*/
	if(sizea>1) delete [] A;  //result of previous merge, not orig
	if(sizeb>1) delete [] B;  //..

	return combined;
}



/*recursively merge and sort when base case reached*/
template<typename T>
T* merge(T* A, int sizea, T* B, int sizeb)
{
	//merge the first and second halves of the array
	//use pointer arithmetic to 'split' array into two
	if(sizea>1)
		A = merge(A,sizea/2,A+sizea/2,sizea-sizea/2);
	if(sizeb>1)
		B = merge(B,sizeb/2,B+sizeb/2,sizeb-sizeb/2);
	
	return sort(A,sizea,B,sizeb);
}

/*start the recursion*/
template<typename T>
void  mergeSort(T** A, int size)
{
	/*remember the returned array will be dynamicallly allocated*/
	/*free old array, and assign it to the new sorted one*/
	T* B = merge(*A,size/2,*A+size/2,size-size/2);
	delete [] *A;
	*A = B;
}

/*check for equality of two arrays*/
/*requires operator==*/
template<typename T>
bool assertEquals(T* A, int sizea, T* B, int sizeb)
{
	if(sizea!=sizeb)
		return false;

	for(int j=0; j<sizea; ++j) {
		if(A[j]!=B[j])
			return false;
	}
	return true;
}

