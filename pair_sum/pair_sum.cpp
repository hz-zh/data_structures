#include <iostream>
#include <vector>
#include <unordered_set>

bool hasPairWithSum(const std::vector<int>&, int, int mode = 0);

int main() {
	std::vector<int> nums = { 1,3,5,7,8,8,9,12,13 };
	int sum = 12;
	std::cout << "The result is " << hasPairWithSum(nums, sum, 0) << std::endl;

	return 0;
}

bool hasPairWithSum(const std::vector<int>& nums, int sum, int mode) {
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