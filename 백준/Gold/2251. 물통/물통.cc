#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

unsigned A, B, C;
class F;
class Element {
public:
	friend F;
	Element(unsigned char A, unsigned char B, unsigned char C) : A(A), B(B), C(C) { }
	bool operator ==(const Element& data) {
		if (this->A != data.A || this->B != data.B || this->C != data.C) return false;
		else return true;
	}

	unsigned char A, B, C;
};

class F {
public:
	static Element CA(const Element& data) {
		Element moved = data;
		if (moved.A < A) {
			if (A - moved.A < moved.C) {
				moved.C -= (A - moved.A);
				moved.A = A;
			}
			else {
				moved.A += moved.C;
				moved.C = 0;
			}
		}
		return moved;
	}
	static Element CB(const Element& data) {
		Element moved = data;
		if (moved.B < B) {
			if (B - moved.B < moved.C) {
				moved.C -= (B- moved.B);
				moved.B = B;
			}
			else {
				moved.B += moved.C;
				moved.C = 0;
			}
		}
		return moved;
	}
	static Element BC(const Element& data) {
		Element moved = data;
		if (moved.C < C) {
			if (C - moved.C < moved.B) {
				moved.B -= (C - moved.C);
				moved.C = C;
			}
			else {
				moved.C += moved.B;
				moved.B = 0;
			}
		}
		return moved;
	}
	static Element BA(const Element& data) {
		Element moved = data;
		if (moved.A < A) {
			if (A - moved.A < moved.B) {
				moved.B -= (A - moved.A);
				moved.A = A;
			}
			else {
				moved.A += moved.B;
				moved.B = 0;
			}
		}
		return moved;
	}
	static Element AC(const Element& data) {
		Element moved = data;
		if (moved.C < C) {
			if (C - moved.C < moved.A) {
				moved.A -= (C - moved.C);
				moved.C = C;
			}
			else {
				moved.C += moved.A;
				moved.A = 0;
			}
		}
		return moved;
	}
	static Element AB(const Element& data) {
		Element moved = data;
		if (moved.B < B) {
			if (B - moved.B < moved.A) {
				moved.A -= (B - moved.B);
				moved.B = B;
			}
			else {
				moved.B += moved.A;
				moved.A = 0;
			}
		}
		return moved;
	}

	static bool visit(vector<Element>& visited, const Element& data) {
		for (int i = 0; i < visited.size(); i++) {
			if (visited[i] == data) return true;
		}
		return false;
	}
};

int main(void) {
	cin >> A >> B >> C;

	queue<Element> que;
	vector<Element> visited;
	que.push(Element(0, 0, C));
	visited.push_back(que.front());

	while (!que.empty()) {
		Element cur = que.front();

		Element next = F::CA(cur);
		if (!F::visit(visited, next)) {
			que.push(next);
			visited.push_back(next);
		}
		next = F::CB(cur);
		if (!F::visit(visited, next)) {
			que.push(next);
			visited.push_back(next);
		}
		next = F::BC(cur);
		if (!F::visit(visited, next)) {
			que.push(next);
			visited.push_back(next);
		}
		next = F::BA(cur);
		if (!F::visit(visited, next)) {
			que.push(next);
			visited.push_back(next);
		}
		next = F::AC(cur);
		if (!F::visit(visited, next)) {
			que.push(next);
			visited.push_back(next);
		}
		next = F::AB(cur);
		if (!F::visit(visited, next)) {
			que.push(next);
			visited.push_back(next);
		}

		que.pop();
	}

	vector<unsigned> v;
	for (int i = 0; i < visited.size(); i++) {
		if (visited[i].A == 0) {
			v.push_back(visited[i].C);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
	cout << endl;

	return 0;
}