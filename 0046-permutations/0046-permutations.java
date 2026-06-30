class Solution {
    public List<List<Integer>> permuteSlow(int[] nums) {
        List<Integer> numList = new ArrayList<>(Arrays.stream(nums).boxed().toList());
        List<List<Integer>> results = new ArrayList<>();
        backtrackSlow(numList, 0, results);
        return results; 
    }

    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> results = new ArrayList<>();
        backtrack(nums, 0, results);
        return results; 
    }

    private void backtrackSlow(List<Integer> numList, int start, List<List<Integer>> result) {
        if (start == numList.size()) {
            result.add(new ArrayList(numList));
            return;
        }
        for(int i = start; i < numList.size(); i++) {
            Collections.swap(numList, start, i);
            backtrackSlow(numList, start+1, result);
            Collections.swap(numList, i, start);
        }
    }

    private void backtrack(int[] nums, int start, List<List<Integer>> result) {
        if (start == nums.length) {
            // result.add(Arrays.stream(nums).boxed().toList());
            List<Integer> permutation = new ArrayList<>(nums.length);
            for (int num : nums) {
                permutation.add(num); // Autoboxing here is much faster than standard stream boxing
            }
            result.add(permutation);
            return;
        }
        for(int i = start; i < nums.length; i++) {
            swap(nums, start, i);
            backtrack(nums, start+1, result);
            swap(nums, i, start);
        }
    }

    private void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}