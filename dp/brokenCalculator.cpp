class Solution {
public:
    int brokenCalc(int startValue, int target) {
        // Base case: if startValue is greater than or equal to target
        if (startValue >= target) {
            return startValue - target; // Just decrement startValue to reach target
        }
        // If target is even, it's more optimal to divide the target by 2
        if (target % 2 == 0) {
            return 1 + brokenCalc(startValue, target / 2);
        } else {
            // If target is odd, subtract 1 from it to make it even, then continue
            return 1 + brokenCalc(startValue, target + 1);
        }
    }
};