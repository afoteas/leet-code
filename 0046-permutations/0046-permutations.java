class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<Integer> numList = new ArrayList<>(Arrays.stream(nums).boxed().toList());
        List<List<Integer>> results = new ArrayList<>();
        backtrack(numList, 0, results);
        return results;

        
    }

    private void backtrack(List<Integer> numList, int start, List<List<Integer>> result) {
        if (start == numList.size()) {
            result.add(new ArrayList(numList));
            return;
        }
        for(int i = start; i < numList.size(); i++) {
            Collections.swap(numList, start, i);
            backtrack(numList, start+1, result);
            Collections.swap(numList, i, start);
        }
    }
}