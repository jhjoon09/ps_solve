#include <iostream>

#define MAX 1000000
#define endl '\n'

using namespace std;

struct SegTree{
	int start,end;
	int count;
	SegTree* left;
	SegTree* right;

	

	int add(int val, int count){
		if(val < start || end < val)
			return 0;

		this->count += count;

		if(start == end)
			return this->count;


		int mid = (start + end)/2;

		if(val <= mid){
			if(left == NULL)
				left = new SegTree({this->start, mid, 0, NULL, NULL});
			
			return left->add(val,count);
		}else{
			if(right == NULL)
				right = new SegTree({mid+1, this->end, 0, NULL, NULL});

			return right->add(val,count);
		}
	}

	int pop(int num){

		this->count--;
		if(start == end){
			return start;
		}

		if(this->left == NULL)
			return this->right->pop(num);

		if(this->right == NULL)
			return this->left->pop(num);

		if(this->left->count >= num)
			return this->left->pop(num);

		return this->right->pop(num - this->left->count);
	}
};


int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	SegTree seg = {1, MAX, 0, NULL, NULL};

	cin >> N;

	while(--N >= 0){
		int a,b,c;
		cin >> a >> b;

		if(a == 1)
			cout << seg.pop(b) << endl;
		else{
			cin >> c;
			seg.add(b,c);
		}
	}

	return 0;
}
