class Pass1Macro:
    def __init__(self, filename):
        self.filename = filename
        self.lines = []
        with open(filename, "r") as input_file:
            for line in input_file:
                self.lines.append(line.rstrip().split(" "))

    def pass1(self):
        self.mdt = []
        self.mnt = {}
        self.pntab = {}
        self.kptab = {}
        self.kptr = 100
        self.mdtptr = 0
        i = 0
        while i < len(self.lines):
            if self.lines[i][0] == "MACRO":
                macro_name = self.lines[i+1][0]
                params = self.lines[i+1][1].split(",")
                startptr = self.kptr
                self.pntab[macro_name] = {}
                kp = 0
                for param in params:
                    if "=" in param:
                        kp += 1
                        key = param.split("=")[0]
                        if len(param.split("=")) == 2:
                            val = param.split("=")[1]
                        else:
                            val = ""
                        self.kptab[self.kptr] = (key, val)
                        self.kptr += 1
                        self.pntab[macro_name][len(self.pntab[macro_name]) + 1] = param.split("=")[0]
                self.mnt[macro_name] = (len(self.pntab[macro_name])-kp, kp, self.mdtptr, startptr)
                i += 2
                while self.lines[i][0] != "MEND":
                    inst = " ".join(self.lines[i])
                    for key in self.pntab[macro_name]:
                        inst = inst.replace(self.pntab[macro_name][key], f"(P,{key})")
                    self.mdt.append(inst)
                    self.mdtptr += 1
                    i += 1
                self.mdt.append(self.lines[i][0])
                self.mdtptr += 1
            else:
                i += 1

        print("Macro Name Table:")
        print(self.mnt)
        print("Keyword Parameter Name Table:")
        print(self.kptab)
        print("Parameter Name Table:")
        print(self.pntab)
        print("Macro Definition Table:")
        print(self.mdt)

obj = Pass1Macro("prog1.asm")
obj.pass1()

