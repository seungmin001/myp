#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<long long int> p;
vector<long long int> m;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 3; i++)
	{
		int num;
		cin >> num;
		p.clear();
		m.clear();

		for (int j = 0; j < num; j++)
		{
			long long int value;
			cin >> value;
			if (value > 0)
				p.push_back(value);
			else if (value < 0)
				m.push_back(value);
		}

		sort(p.begin(), p.end());
		sort(m.begin(), m.end());

		if (p.size() == 0 && m.size() != 0)
		{
			cout << "-" << endl;
			continue;
		}
		else if (p.size() != 0 && m.size() == 0)
		{
			cout << "+" << endl;
			continue;
		}
		else if (p.size() == 0 && m.size() == 0)
		{
			cout << "0" << endl;
			continue;
		}

		int pi, mi;
		pi = mi = 0;

		while (true)
		{
			if (pi < p.size() && mi < m.size())
			{
				long long int temp = p[pi] + m[mi];
				if (temp < 0)
				{
					m[mi] += p[pi];
					p[pi] = 0;
					pi++;
				}
				else if (temp > 0)
				{
					p[pi] += m[mi];
					m[mi] = 0;
					mi++;
				}
				else
				{
					mi++;
					pi++;
				}

			}
			else if (pi >= p.size() && mi < m.size())
			{
				cout << "-" << endl;
				break;
			}
			else if (pi < p.size() && mi >= m.size())
			{
				cout << "+" << endl;
				break;
			}
			else
			{
				cout << "0" << endl;
				break;
			}
		}


	}

}