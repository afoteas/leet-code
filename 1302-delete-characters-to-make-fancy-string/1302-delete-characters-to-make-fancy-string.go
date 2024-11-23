func makeFancyStringSlow(s string) string {
	if len(s) == 0 {
		return s
	}

	var ret []rune
	var previous rune
	count := 0

	for _, c := range s {
		if c == previous {
			if count < 2 {
				ret = append(ret, c)
				count++
			}
		} else {
			ret = append(ret, c)
			previous = c
			count = 1
		}
	}

	return string(ret)
}

func makeFancyString(s string) string {
    result := make([]byte, 0, len(s))
    var character byte
    var cnt int

    for i := 0; i < len(s); i++ {
        currentCharacter := s[i]
        if(character != currentCharacter){
            character = currentCharacter
            cnt = 1
            result = append(result, character)
        }else if(cnt < 2){
            cnt++
            result = append(result, character)
        }
    }

    return string(result)
}