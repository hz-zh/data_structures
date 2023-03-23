#include <iostream>
#include <vector>
#include <unordered_set>

bool hasPairWithSum(const std::vector<int>&, int, int mode = 0);

int main() {
	std::vector<int> nums = { 1,3,5,7,8,8,9,12,13 };
	int sum = 12;
	std::cout << "The result for quadratic is " << hasPairWithSum(nums, sum, 0) << std::endl;
	std::cout << "The result for linear is " << hasPairWithSum(nums, sum, 1) << std::endl;
	std::cout << "The result for linear2 is " << hasPairWithSum(nums, sum, 2) << std::endl;


	return 0;
}

bool hasPairWithSum(const std::vector<int>& nums, int sum, int mode) {
	if (mode == 0) {
		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < nums.size(); j++) {
				if (i != j) {
					if ((nums[i] + nums[j]) == sum) {
						std::cout << "Position " << i << " (" << nums[i] << ") has a pair with position " << j << " (" << nums[j] << ")" << std::endl;
						return true;
					}
				}
			}
		}
	}
	else if (mode == 1) {
		int start = 0;
		int end = nums.size() - 1;

		while (start < end) {
			if (nums[start] + nums[end] == sum) {
				std::cout << "\n" << start << "-" << end;
				return true;
			}
			else if (nums[start] + nums[end] > sum) {
				end--;
			}
			else start++;
		}
	}
	else if (mode == 2) {
		std::unordered_set<int> compliments;

		for (int x : nums) {
			if (compliments.find(x) != compliments.end()) {
				return true;
			}
			compliments.insert(sum - x);
		}
	}
	return false;
}

