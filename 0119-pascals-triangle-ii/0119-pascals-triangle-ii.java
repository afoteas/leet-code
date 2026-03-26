class Solution {
    public List<Integer> getRow(int rowIndex) {
        if (rowIndex == 0) return Arrays.asList(1);
        // if (rowIndex == 1) return Arrays.asList(1, 1);
        if (rowIndex == 1) return List.of(1, 1);

        List<Integer> prev = getRow(rowIndex - 1);
        List<Integer> row = new ArrayList<>(Collections.nCopies(rowIndex + 1, 1));

        for (int i = 1; i < rowIndex; i++) {
            row.set(i, prev.get(i - 1) + prev.get(i));
        }

        return row;
    }
}