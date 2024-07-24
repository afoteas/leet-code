class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        ret = []
        while words:
            tempWidth = 0
            line = []
            while tempWidth < maxWidth and words:
                if tempWidth + len(words[0]) < maxWidth:
                    popopo = words.pop(0)
                    line.append(popopo)
                    if tempWidth:
                        tempWidth+=len(popopo) + 1
                    else:
                        tempWidth=len(popopo)
                elif tempWidth == 0 and len(words[0]) == maxWidth:
                    line.append(words.pop(0))
                    break
                else:
                    break
            spaces = len(line) - 1
            wordLen = len("".join(line))
            remaining = maxWidth - wordLen
            wordLine = ""
            if spaces:
                basicSpace = remaining // spaces
                extraSpace = remaining % spaces
                i = 0
                for word in line:
                    if not wordLine:
                        wordLine+=word
                    else:
                        if words:
                            if extraSpace == i:
                                wordLine+=f"{basicSpace*' '}"
                            else:
                                wordLine+=f"{(basicSpace+1)*' '}"
                                i+=1
                            wordLine+=word
                        else:
                            wordLine+=f" {word}"
            else:
                wordLine+=f"{line[0]}{remaining*' '}"
            if words:
                ret.append(wordLine)
            else:
                ret.append(f"{wordLine}{(maxWidth - len(wordLine))*' '}")
        return ret



        