class Solution:
    def simplifyPath(self, path: str) -> str:
        path = path.replace("//","/")
        print(path)
        paths = path.split("/")
        ret_paths = []
        for i in range(0,len(paths)):
            if paths[i]=="..":
                if ret_paths:
                    ret_paths.pop()
            elif paths[i] not in  ["", "."]:
                ret_paths.append(paths[i])
        ret=""
        for path in ret_paths:
            ret+="/"+path
        if ret:
            return ret
        else:
            return "/"

        