import os
import sys
import os.path as p

file_header = "LIBRARY", "EXPORTS"

factory_lines = {
    "x64": "\t{0}=?{0}@@YAPEAUIWidget@@AEAV?$basic_istream@_WU?$char_traits@_W@std@@@std@@@Z",
    "Win32": "\t{0}=?{0}@@YAPAUIWidget@@AAV?$basic_istream@_WU?$char_traits@_W@std@@@std@@@Z",
}
info_lines = {
    "x64": "\tinfo=?info@@YAPEBDXZ",
    "Win32": "\tinfo=?info@@YAPBDXZ",
}

def main():
    directory = p.dirname(sys.argv[0])
    project_name = sys.argv[1]
    factory_line = factory_lines[sys.argv[2]]
    info_line = info_lines[sys.argv[2]]

    use_info = False
    factories = []
    with open(project_name + ".hpp") as f:
        for line in f:
            if line.startswith("IWidget* factory"):
                factories.append(line[9:line.index('(')])
            elif line.startswith("const char* info()"):
                use_info = True

    with open(project_name + sys.argv[2] + ".def", 'w') as f:
        print(*file_header, sep='\n', file=f)
        if use_info:
            print(info_line, file=f)
        
        for factory in factories:
            print(factory_line.format(factory), file=f)


if __name__ == "__main__":
    main()
