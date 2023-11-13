#include <bits/stdc++.h>
using namespace std;

int n;
int graph[20][20];

int ans = 1e9;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> graph[i][j];
		}
	}

	vector<int> team;
	for (int i = 0; i < n / 2; ++i) {
		team.push_back(1);
	}
	for (int i = 0; i < n / 2; ++i) {
		team.push_back(0);
	}

	sort(team.begin(), team.end());

	//// 디버깅
	//std::cout << "\n 팀 디버깅\n";
	//for (int i = 0; i < team.size(); ++i)
	//	std::cout << team[i] << " ";
	//std::cout  << "\n";


	do {
 

		int team1score = 0;
		int team2score = 0;

		for (int i = 0; i < team.size(); ++i) {
			
			// 1번팀원들을 모아야함
			if (team[i] == 1) {
				for (int j = 0; j < team.size(); ++j) {
					if (team[j] == 1) {
						team1score += graph[i][j];
						//team1score += graph[j][i];
					}
				}
			}

			// 0번 팀원들을 모아야함
			else if (team[i] == 0) {

				for (int j = 0; j < team.size(); ++j) {
					if (team[j] == 0) {
						team2score += graph[i][j];
						//team2score += graph[j][i];
					}
				}
			}
 
		}

		int tempans = abs(team1score - team2score);
		ans = min(ans, tempans);


	} while (next_permutation(team.begin(), team.end()));

	std::cout << ans << "\n";

	return 0;
}