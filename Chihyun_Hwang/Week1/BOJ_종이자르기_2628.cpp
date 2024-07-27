#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main() {
	int r, c;
	cin >> c >> r;
	int n;
	cin >> n;


	vector<int>w;
	vector<int>h;

	w.push_back(0);
	h.push_back(0);

	w.push_back(r);
	h.push_back(c);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		if (a == 0)
		{
			w.push_back(b);
		}
		else if (a == 1)
		{
			h.push_back(b);
		}
	}


	sort(w.begin(), w.end());
	sort(h.begin(), h.end());


	int wmax = -1;
	int hmax = -1;

	for (int i = 0; i < w.size() - 1; i++)
	{
		wmax = wmax < w[i + 1] - w[i] ? w[i + 1] - w[i] : wmax;
	}
	for (int i = 0; i < h.size() - 1; i++)
	{
		hmax = hmax < h[i + 1] - h[i] ? h[i + 1] - h[i] : hmax;
	}

	cout << wmax * hmax;
}