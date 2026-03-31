// vector<unsigned long long>prefix(nums.size() ,0);
// vector<unsigned long long>pro(nums.size() , -1) ;what unsigned do

// unsigned means the variable cannot store negative numbers.

// It only stores 0 and positive values.

// Meaning of unsigned long long

// Normally:

// long long

// Range:

// -9,223,372,036,854,775,808
// to
//  9,223,372,036,854,775,807

// But with unsigned:

// unsigned long long

// Range becomes:

// 0
// to
// 18,446,744,073,709,551,615

// So you lose negative numbers but double the positive range.

// Your Code
// vector<unsigned long long> prefix(nums.size(), 0);
// vector<unsigned long long> pro(nums.size(), -1);
// What happens here?
// -1

// is converted to unsigned, so it becomes the maximum value.

// So:

// -1 → 18446744073709551615

// That means your pro vector is actually initialized with:

// 18446744073709551615

// // not -1.

//leetcode 3862

//