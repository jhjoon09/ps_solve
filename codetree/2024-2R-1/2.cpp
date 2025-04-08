#include <iostream>
#include <set>
#include <map>

#define MAX 1000000000

using namespace std;

struct Node{
	long long sum;
	int count;
	int start,end;
	Node* left;
	Node* right;

	int init_node(void){
		if(left != NULL){
			left->init_node();
			delete left;
		}

		if(right != NULL){
			right -> init_node();
			delete right;
		}

		sum = 0;
		count = 0;
		start = 0;
		end = 0;
		left = NULL;
		right = NULL;
		return 0;
	}

	int insert_node(int v){
		if(v < start || end < v)
			return 0;

		++count;
		sum += v;

		if(start == end && start == v){
			return 0;
		}

		int mid = (start + end)/2;

		if(v <= mid){
			if(left == NULL){
				left = new Node;
				left->sum = 0;
				left->count = 0;
				left->start = start;
				left->end = mid;
				left->left = NULL;
				left->right = NULL;
			}
			left->insert_node(v);
		}else{
			if(right == NULL){
				right = new Node;
				right -> sum = 0;
				right->count = 0;
				right -> start = mid+1;
				right -> end = end;
				right->left = NULL;
				right->right = NULL;
			}
			right->insert_node(v);
		}

		return 0;
	}

	int remove_node(int v){
		if(v < start || end < v)
			return 0;

		--count;
		sum -= v;

		if(left != NULL){
			left -> remove_node(v);
		}


		if(right != NULL){
			right -> remove_node(v);
		}

		return 0;
	}

	int get_pos(int k){
		if(count < k)
			return 0;

		if(count == 1)
			return sum;

		if(left != NULL){
			if(left->count >= k){
				return left->get_pos(k);
			}
			
			k -= left->count;
		}

		if(right != NULL){
			return right->get_pos(k);
		}

		return 0;
	}

	long long get_sum(int k){
		if(k < start)
			return 0;

		if(end <= k)
			return sum;

		if(sum == 0)
			return 0;

		long long ret = 0;

		if(left != NULL)
			ret += left->get_sum(k);

		if(right != NULL)
			ret += right->get_sum(k);

		return ret;
	}
};

struct DB{
	map<int, string> vn;
	map<string, int> nv;
	Node top;

	void init(void){
		vn.clear();
		nv.clear();
		top.init_node();
		top = {0,0, 0, MAX, NULL, NULL};
	}

	int insert(string n, int v){
		if(nv.find(n) != nv.end())
			return 0;
		if(vn.find(v) != vn.end())
			return 0;
		nv.insert(make_pair(n,v));
		vn.insert(make_pair(v,n));
		top.insert_node(v);
		return 1;
	}

	int remove(string n){
		if(nv.find(n) == nv.end())
			return 0;

		int v = (*nv.find(n)).second;

		nv.erase(n);
		vn.erase(v);
		top.remove_node(v);
		return v;
	}

	string rank(int k){
		if(vn.size() < k)
			return "None";

		int ret = top.get_pos(k);
		return vn.find(ret)->second;
	}

	long long sum(int k){
		long long ret = top.get_sum(k);

		return ret;
	}

};

DB table;

int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int Q;
	string op;

	cin >> Q;
	while(--Q>=0){
		cin >> op;

		if(op == "init"){
			table.init();
		}else if(op == "insert"){
			string name;
			int value;
			cin >> name >> value;
			int ret = table.insert(name, value);
			cout << ret << endl;
		}else if(op == "delete"){
			string name;
			cin >> name;

			int ret = table.remove(name);
			cout << ret << endl;
		}else if(op == "rank"){
			int k;
			cin >> k;

			string ret = table.rank(k);
			cout << ret << endl;
		}else{
			int k;
			cin >> k;

			long long ret = table.sum(k);
			cout << ret << endl;
		}
	}

	return 0;
}
