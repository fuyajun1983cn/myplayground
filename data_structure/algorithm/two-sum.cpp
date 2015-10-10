#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int index1, index2;
    vector<int> answer(2);

    for (int i = 1; i < nums.size(); ++i) {
      index1 = i;
      if (nums[index1 - 1] >= target)
	continue;
      
      for (int j = i + 1; j <= nums.size(); ++j) {
	index2 = j;
	if (nums[index2 - 1] >= target)
	  continue;
	
	if (nums[index1 - 1] + nums[index2 - 1] == target)
	  break;
      }
    }

    answer[0] = index1;
    answer[1] = index2;

    return answer;
  }

  vector<int> twoSum2(vector<int>& nums, int target) {
     
    int index1, index2;
    vector<int> answer(2);
    int remains;

    for (int i = 0; i < nums.size(); ++i) {
      index1 = i;
      index2 = -1;
      remains = target - nums[index1];
      cout<<"remains "<<remains<<endl;

      for (int j = i + 1; j < nums.size(); ++j) {
	if (nums[j] == remains) {
	  cout<<"index2 "<<j<<endl;
	  index2 = j;
	  break;
	}
      }

      if (index2 != -1)
	break;
    }

    answer[0] = index1 + 1;
    answer[1] = index2 + 1;

    return answer;
  }

  /**
   *  只适用于数组数据以及target为非负数的情况
   */
  vector<int> twoSum3(vector<int>& nums, int target) {

    int index1, index2;
    vector<int> answer(2);

    for (int i = 0; i <= target/2; ++i) {

      index1 = -1;
      index2 = -1;

      for (int j = 0; j < nums.size(); ++j) {
	if (nums[j] == i) {
	  if (index1 == -1) {
	  cout<<"index1 "<<j<<endl;
	  index1 = j;
	  continue;
	  }
	}

	if (nums[j] == target -i ) {
	  if (index2 == -1) {
	  cout<<"index2 "<<j<<endl;
	  index2 = j;
	  }
	}

	if (index1 != -1 && index2 != -1)
	  break;
	
      }

      if (index1 != -1 && index2 != -1)
	break;
    }

    if (index1 > index2) {
      int temp = index1;
      index1 = index2;
      index2 = temp;
    }

    answer[0] = index1 + 1;
    answer[1] = index2 + 1;

    return answer;

  }

  /**
   * 算法思想：
   * 1. 先将数组排序。
   * 2. 从两头遍历，找到符合条件的解
   */
  vector<int> twoSum4(vector<int>& nums, int target)
  {
  }

  /**
   * 算法思想：
   * 1. 在遍历数组的过程中，将target - num[i]的值存入到另一个数组中。
   * 2. 在遍历的过程中，不停地从这个数组中查询当前遍历的数字是否包含在该数组中。
   */
  vector<int> twoSum5(vector<int>& nums, int target)
  {
    vector<int> answer(2);
    vector<int> temp;
    int index1, index2;

    for (int i = 0; i < nums.size(); ++i) {

      if (find(temp.begin(), temp.end(), nums[i]) != temp.end()) {
	index1 = i + 1;
	auto p = find(nums.begin(), nums.end(), target - nums[i]);
	index2 = distance(nums.begin(), p) + 1;
	break;
      } else {
	temp.push_back(target - nums[i]);
      }

    }

      if (index1 > index2) {
	int t = index1;
	index1 = index2;
	index2 = t;
      }

      answer[0] = index1;
      answer[1] = index2;

      return answer;

  }

};

  int main(int argc, char *argv[])
  {
    //vector<int> data{0,4, 3,0};
    //vector<int> data{2,7,11,15};
    vector<int> data{-4, -3, 5, 6};
    //vector<int> data{-3, 4, 3, 90};
    int target = 1;

    Solution s;
    vector<int> answer = s.twoSum5(data, target);

    cout<<"answer: ["<<answer[0]<<", "<<answer[1]<<"]"<<endl;

    return 0;
  }
  
    
