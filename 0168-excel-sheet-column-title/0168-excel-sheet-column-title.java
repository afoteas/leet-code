class Solution {
    public String convertToTitle(int columnNumber) {
        StringBuilder sb = new StringBuilder();
        while (columnNumber > 0) {
            int tmp = columnNumber%26;
            if (tmp == 0) {
                sb.append('Z');
                columnNumber = (columnNumber-tmp-1)/26;
            } else {
                sb.append((char)('A' + tmp - 1) );
                columnNumber = (columnNumber-tmp)/26;
            }
            System.out.println("tmp:" + tmp + ", columnNumber:" + columnNumber);
        }

        return sb.reverse().toString(); 
        
    }
}