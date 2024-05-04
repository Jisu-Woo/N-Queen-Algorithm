#include <iostream>
#include <vector>

using namespace std;


// �ش� �ڸ��� �ֺ��� Queen�� �����ϴ��� üũ�ϴ� �Լ�
bool isOkay(vector <vector<int>>& B, int row, int col, int n) {

	for (int i = 0; i < n; i++) { // �ش� ��ġ�� ������(row) �� ������(col) ��ü Ȯ��  (0 ~ n - 1) 
		if (B[row][i] == 1 || B[i][col] == 1) {
			return false;
		}
	}

	int i = row;
	int j = col;
	while (i >= 0 && j >= 0) { // board���� ���� �����ϴ� ����
		if (B[i][j] == 1) {		//���� �� �밢�� üũ ( -,- )
			return false;
		}
		i -= 1;
		j -= 1;
	}
	i = row;
	j = col;
	while (i < n && j < n) { // board���� ���� �����ϴ� ����
		if (B[i][j] == 1) {	//������ �Ʒ� �밢�� üũ ( +,+ )
			return false;
		}
		i += 1;
		j += 1;
	}
	i = row;
	j = col;
	while (i >= 0 && j < n) { // board���� ���� �����ϴ� ����
		if (B[i][j] == 1) {	//������ �� �밢�� üũ ( -,+ )
			return false;
		}
		i -= 1;
		j += 1;
	}
	i = row;
	j = col;
	while (j >= 0 && i < n) { // board���� ���� �����ϴ� ����
		if (B[i][j] == 1) {	// ���� �Ʒ� �밢�� üũ ( +,- )
			return false;
		}
		i += 1;
		j -= 1;
	}

	//�����¿� �밢�� ��� üũ �Ŀ��� �����ٸ�
	return true;
}


bool backTracking(vector<vector<int>>& B, vector<vector<int>>& firstSolution, int row, int n, int& count) {
	// ������ ���� ��, �� �ϳ� ã�� ����
	if (row > n - 1) {
		count += 1; // �� count 1 ����

		// ù��° ���� ���
		if (count == 1) {
			firstSolution = B; // ù ��° �ظ� ���� (���� ���)
		}

		return false; // �ٸ� �� ã��
	}

	for (int j = 0; j <= n - 1; j++) { //�ش� ���� col ����
		if (isOkay(B, row, j, n) == true) { // �ֺ� üũ �� true���
			
			B[row][j] = 1; // �ش� �ڸ��� Queen ��ġ

			backTracking(B, firstSolution, row + 1, n, count); //���� ��(row + 1) ����

			// false ���� �� ���
			B[row][j] = 0; // �� �ڸ��� �θ�, ���� �ٿ��� Queen�� �� �� �����Ƿ�, ��ġ�ߴ� Queen�� ���ְ� �ٽ� Ž�� (��Ʈ��ŷ)
		}
	}

	// �ش� �ٿ� Queen ��ġ�� �Ұ� ��
	return false;
}

int main() {

	int n;
	cout << "n�� �Է��Ͻÿ� : ";
	cin >> n;

	vector<vector<int>> B(n, vector<int>(n, 0)); //��ü Board��
	vector<vector<int>> firstSolution;  //���߿� ����� ù��° ��
	int count = 0; //�ظ� ī��Ʈ�ϴ� ����

	// ù ��° ��(0)���� ����
	backTracking(B, firstSolution, 0, n, count);


	// ����� ���
	
	// �ذ� ���� ���
	if (count == 0) { 
		cout << "0";
		return 0;
	}

	// �ذ� 1�� �̻� ���� ���
	else if (count >= 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (firstSolution[i][j] == 1) { // �����ص� ù ��° �� ���
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