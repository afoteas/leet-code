func makeFancyString(s string) string {
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