#include <iostream>
#include <vector>

using namespace std;


// 해당 자리의 주변에 Queen이 존재하는지 체크하는 함수
bool isOkay(vector <vector<int>>& B, int row, int col, int n) {

	for (int i = 0; i < n; i++) { // 해당 위치의 가로줄(row) 및 세로줄(col) 전체 확인  (0 ~ n - 1) 
		if (B[row][i] == 1 || B[i][col] == 1) {
			return false;
		}
	}

	int i = row;
	int j = col;
	while (i >= 0 && j >= 0) { // board범위 내에 존재하는 동안
		if (B[i][j] == 1) {		//왼쪽 위 대각선 체크 ( -,- )
			return false;
		}
		i -= 1;
		j -= 1;
	}
	i = row;
	j = col;
	while (i < n && j < n) { // board범위 내에 존재하는 동안
		if (B[i][j] == 1) {	//오른쪽 아래 대각선 체크 ( +,+ )
			return false;
		}
		i += 1;
		j += 1;
	}
	i = row;
	j = col;
	while (i >= 0 && j < n) { // board범위 내에 존재하는 동안
		if (B[i][j] == 1) {	//오른쪽 위 대각선 체크 ( -,+ )
			return false;
		}
		i -= 1;
		j += 1;
	}
	i = row;
	j = col;
	while (j >= 0 && i < n) { // board범위 내에 존재하는 동안
		if (B[i][j] == 1) {	// 왼쪽 아래 대각선 체크 ( +,- )
			return false;
		}
		i += 1;
		j -= 1;
	}

	//상하좌우 대각선 모두 체크 후에도 괜찮다면
	return true;
}


bool backTracking(vector<vector<int>>& B, vector<vector<int>>& firstSolution, int row, int n, int& count) {
	// 끝까지 도달 시, 해 하나 찾은 상태
	if (row > n - 1) {
		count += 1; // 해 count 1 증가

		// 첫번째 해일 경우
		if (count == 1) {
			firstSolution = B; // 첫 번째 해를 저장 (이후 출력)
		}

		return false; // 다른 해 찾기
	}

	for (int j = 0; j <= n - 1; j++) { //해당 줄의 col 돌기
		if (isOkay(B, row, j, n) == true) { // 주변 체크 후 true라면
			
			B[row][j] = 1; // 해당 자리에 Queen 설치

			backTracking(B, firstSolution, row + 1, n, count); //다음 줄(row + 1) 실행

			// false 리턴 된 경우
			B[row][j] = 0; // 이 자리에 두면, 다음 줄에서 Queen을 둘 수 없으므로, 설치했던 Queen을 없애고 다시 탐색 (백트래킹)
		}
	}

	// 해당 줄에 Queen 설치가 불가 시
	return false;
}

int main() {

	int n;
	cout << "n을 입력하시오 : ";
	cin >> n;

	vector<vector<int>> B(n, vector<int>(n, 0)); //전체 Board판
	vector<vector<int>> firstSolution;  //나중에 출력할 첫번째 해
	int count = 0; //해를 카운트하는 변수

	// 첫 번째 줄(0)부터 진행
	backTracking(B, firstSolution, 0, n, count);


	// 결과값 출력
	
	// 해가 없을 경우
	if (count == 0) { 
		cout << "0";
		return 0;
	}

	// 해가 1개 이상 있을 경우
	else if (count >= 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (firstSolution[i][j] == 1) { // 저장해둔 첫 번째 해 출력
					cout << "Q";
				}
				else {
					cout << "_";
				}
			}
			cout << endl;
		}
		cout << count;
	}
	return 0;

}