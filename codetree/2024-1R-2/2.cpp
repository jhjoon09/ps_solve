#include <iostream>
#include <map>
#include <set>

#define endl '\n'

using namespace std;

struct Node{
	int m_id;
	int p_id;
	int color;
	int score;
	int max_depth;
	set<int> child;
};

struct Tree{
	map<int, Node*> m;

	int init(void){
		Node* n = new Node;
		n->m_id = -1;
		n->p_id = -1;
		n->color = 0;
		n->score = 0;
		n->max_depth = 101;

		m.insert({-1, n});

		return 0;
	}

	int insert_node(int id, int p_id, int color, int max_depth){
		Node* p = (*m.find(p_id)).second;

		if(p->max_depth == 1)
			return -1;

		max_depth = max_depth > p->max_depth - 1 ? p->max_depth -1 : max_depth;
		p->child.insert(id);

		Node* n = new Node;
		n->m_id = id;
		n->p_id = p_id;
		n->color = (1 << color);
		n->score = (1 << color);
		n->max_depth = max_depth;

		m.insert({id, n});

		return 0;
	}

	int change_color(int id, int color){
		Node* n = (*m.find(id)).second;
		n->color = (1 << color);
		n->score = 1;
		
		for(set<int>::iterator iter = n->child.begin(); iter != n->child.end(); ++iter){
			change_color(*iter, color);
		}

		return 0;
	}

	int get_color(int id){
		Node* n = (*m.find(id)).second;
		int color = n->color;
		int ret = 0;
		
		for(ret = 0; ret <= 5; ++ret){
			if(color % 2 == 1)
				break;

			color /= 2;
		}

		return ret;
	}

	pair<int, long long> cal_color(int id){
		Node* n = (*m.find(id)).second;

		long long ret = 0;
		int color = 0;
		for(set<int>::iterator iter = n->child.begin(); iter != n->child.end(); ++iter){
			pair<int, long long> t = cal_color(*iter);

			color = color | t.first;
			ret += t.second;
		}

		color = color | n->color;
		int t_color = color;
		int score = 0;
		for(int i = 0; i <= 5; ++i){
			if(color % 2 == 1)
				++score;

			color /= 2;
		}

		ret += (score * score);

		return {t_color, ret};
	}

	long long get_score(void){
		Node* n = (*m.find(-1)).second;

		long long ret = 0;
		for(set<int>::iterator iter = n->child.begin(); iter != n->child.end(); ++iter){
			ret += cal_color(*iter).second;
		}

		return ret;
	}
};

Tree t;

int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Q;
	cin >> Q;

	t.init();

	while(--Q >= 0){
		int op;
		cin >> op;

		int a1,a2,a3,a4;
		long long ret;

		switch(op/100){
			case 1:
				cin >> a1 >> a2 >> a3 >> a4;
				t.insert_node(a1,a2,a3,a4);
				break;
			case 2:
				cin >> a1 >> a2;
				t.change_color(a1,a2);
				break;
			case 3:
				cin >> a1;
				ret = t.get_color(a1);
				cout << ret << endl;
				break;
			case 4:
				ret = t.get_score();
				cout << ret << endl;
				break;
		}

	}

	return 0;
}
