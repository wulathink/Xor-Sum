#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

class BigXor {
	int M;
	int N;
	int *given_num_list;
	int *test_num_list;
private:
	int get_xor_num(int test_num)
	{
		int xor_result = 0;
		int ret = -1;

		for (int i = 0; i < N; i++) {
			int tmp_sum = test_num^given_num_list[i];
			if (tmp_sum > xor_result) {
				xor_result = tmp_sum;
				ret = given_num_list[i];
			}
		}
		return ret;
	}
public:
	void clear() {
		delete test_num_list;
		delete given_num_list;
	}
	BigXor() {}
	void Init() {
		scanf("%d %d", &N, &M);
		given_num_list = new int[N];
		test_num_list = new int[M];
		for (int j = 0; j < N; j++) {
			int given_num;
			scanf("%d", &given_num);
			*(given_num_list + j) = given_num;
		}
		for (int j = 0; j < M; j++) {
			int test_num;
			scanf("%d", &test_num);
			*(test_num_list + j) = test_num;
		}
	}
	void Print() {
		for (int j = 0; j < N; j++) {
			cout << *(given_num_list + j) << " ";
		}
		cout << "=============" << endl;
		for (int j = 0; j < M; j++) {
			cout << *(test_num_list + j) << " ";
		}
		cout << "~~~" << endl;
	}
	void GetResult() {
		for (int i = 0; i < M; i++) {
			cout << get_xor_num(*(test_num_list + i))<<endl;
		}		
	}
};

int main() 
{
	int case_cnt;
	scanf("%d", &case_cnt);
	
	BigXor* bx = new BigXor[case_cnt];
	for (int i = 0; i < case_cnt; i++) {
		(bx + i)->Init();
	}
	for (int i = 0; i < case_cnt; i++) {
		//(bx + i)->Print();
		cout << "Case #" << i << ":" << endl;
		(bx + i)->GetResult();
		(bx + i)->clear();
	}
	return 0;
}



