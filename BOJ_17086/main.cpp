#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n, m;
vvi bd;
vvb visit1;

const auto dx = vi{ -1,-1,-1,0,0,1,1,1 };
const auto dy = vi{ -1,0,1,-1,1,-1,0,1 };

int bfs(int i, int j) {
	auto visit = vvb(n, vb(m, false));
	auto q = queue<pair<pii, int>>{};
	q.push({ {i, j}, 0 });
	visit[i][j] = true;

	while (!q.empty()) {
		auto [p, dist] = q.front();
		const auto& [y, x] = p;
		q.pop();

		if (1 == bd[y][x]) {
			return dist;
		}

		for (auto d = 0; d < 8; ++d) {
			const auto nx = x + dx[d];
			const auto ny = y + dy[d];

			if (nx < 0 || m <= nx ||
				ny < 0 || n <= ny) {
				continue;
			}

			if (visit[ny][nx]) {
				continue;
			}

			q.push({ {ny, nx}, dist + 1 });
			visit[ny][nx] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> m;

	bd = vvi(n, vi(m));
	for (auto&& r : bd) {
		for (auto&& x : r) {
			cin >> x;
		}
	}

	auto ans = int{ 0 };
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < m; ++j) {
			ans = max(ans, bfs(i, j));
		}
	}

	cout << ans;

	return 0;
}