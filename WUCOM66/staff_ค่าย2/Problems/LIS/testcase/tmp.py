import random

def generate_input_sequence(length, min_val, max_val):
    return [random.randint(min_val, max_val) for _ in range(length)]

def longest_increasing_subsequence(nums):
    if not nums:
        return []
    
    dp = [1] * len(nums)
    for i in range(1, len(nums)):
        for j in range(i):
            if nums[i] > nums[j]:
                dp[i] = max(dp[i], dp[j] + 1)
    
    max_length = max(dp)
    lis = []
    for i in range(len(nums) - 1, -1, -1):
        if dp[i] == max_length:
            lis.append(nums[i])
            max_length -= 1
    return lis[::-1] if lis else []  # Ensure to return an empty list if no LIS is found

def validate_output(subsequence):
    # Check if the subsequence is strictly increasing
    for i in range(len(subsequence) - 1):
        if subsequence[i] >= subsequence[i + 1]:
            return False
    return True

# Generate and test multiple cases
num_test_cases = 1
for _ in range(num_test_cases):
    sequence_length = random.randint(1000, 1000)  # Vary the length of the sequence
    min_val = 0
    max_val = 100
    sequence = generate_input_sequence(sequence_length, min_val, max_val)
    lis = longest_increasing_subsequence(sequence)
    if validate_output(lis):
        print("Input Sequence:", sequence)
        print("Longest Increasing Subsequence:", lis)
        print()
