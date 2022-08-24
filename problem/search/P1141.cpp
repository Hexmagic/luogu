#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class UnionFound {
public:
	vector<int> parent;
	UnionFound(int M):parent(M) {
		for (int i = 0; i < M; i++) {
			parent[i] = i;
		}
	}
	int find(int x) {
		while (x != parent[x]) {
			x = parent[x];
			parent[x] = parent[parent[x]];
		}
		return x;
	}
	void join(int a, int b) {
		int pa = find(a);
		int pb = find(b);
		if (pa != pb) {
			parent[pa] = pb;
		}
	}
};
int main() {
	int  n,m;
	//cin >> n >> m;	
    n=2;
    m=2;
	vector<string> arr(n);
    arr = {"01","10"};
	UnionFound ufo(n*n);
	// for (int i = 0; i < n; i++) {
    //     cin >> arr[i];
	// }
	vector<int> indexs(m);
	int a, b;
    indexs ={0,3};
	// for (int i = 0; i < m; i++) {
	// 	cin >> a >> b;
	// 	indexs[i] = (a-1) * n + (b-1);
	// }
	int ops[2][2] = { {0,-1},{-1,0}};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
            for (auto& op : ops) {
					int x = op[0] + i;
					int y = op[1] + j;
					if (x < 0 || y < 0)
						continue;
					if (arr[i][j] == '0') {
						if (arr[x][y] == '1') {
							ufo.join(x * n + y, i * n + j);
						}
					}
					else {
						if (arr[x][y] == '0') {
							ufo.join(x * n + y, i * n + j);
						}
					}
			}
		}
		
	}   
	unordered_map<int, int> cnt_map;
	for (int i = 0; i < n * n; i++) {
		int par = ufo.find(i);
		cnt_map[par]++;
	}
	for (auto& index : indexs) {
		int par = ufo.find(index);
		cout << cnt_map[par] << endl;
	}
	return 0;
}