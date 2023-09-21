# PASS 1 OF TWO PASS ASSEMBLER

class initialize:
	AD={"START":01,"END":02,"ORIGIN":03,"EQU":04,"LTORG":05}
	IS={"STOP":00,"ADD":01,"SUB":02,"MULT":03,"MOVER":04,"MOVEM":05,"COMP":06,"BC":07,"DIV":08,"READ":09,"PRINT":10}
	DL={"DS":01,"DC":02}
	RG={"AREG":01,"BREG":02,"CREG":03,"DREG":04}
	CC={"EQ":01,"LT":02,"GT":03,"LE":04,"GE":05,"NE":06,"ANY":07}
	
	
class assembler:
	input_file=open("input.txt",r)
	input_file.seek(0)
	loc_ctr=0
	self.initialize()
	read_file=input_file.readline()
	for i in read_file:
		if i=="START":
			
	
