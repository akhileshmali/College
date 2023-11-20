public class pass1 {

    private static final int MAX_SYMBOLS = 100;
    private static final int MAX_LITERALS = 100;

    private String[] symbolTable = new String[MAX_SYMBOLS];
    private int[] symbolTableAddresses = new int[MAX_SYMBOLS];
    private String[] literalTable = new String[MAX_LITERALS];
    private int[] literalTableAddresses = new int[MAX_LITERALS];

    private int locationCounter = 0;

    public void assemble(String[] assemblyLines) {
        for (String line : assemblyLines) {
            String[] tokens = line.split("\t");

            if (tokens[0].equalsIgnoreCase("START")) {
                locationCounter = Integer.parseInt(tokens[1]);
            } else if (tokens[0].equalsIgnoreCase("MOVER")) {
                handleMOVERInstruction(tokens);
            } else if (tokens[0].equalsIgnoreCase("MOVEM")) {
                handleMOVEMInstruction(tokens);
            } else if (tokens[0].equalsIgnoreCase("MOVER") || tokens[0].equalsIgnoreCase("LTORG")) {
                handleLiteralInstruction(tokens);
            } else if (tokens[0].equalsIgnoreCase("DS")) {
                handleDSInstruction(tokens);
            } else if (tokens[0].equalsIgnoreCase("END")) {
                break;
            }

            locationCounter++;
        }

        printSymbolTable();
        printLiteralTable();
    }

    private void handleMOVERInstruction(String[] tokens) {
        // Nothing to do for MOVER instructions in pass 1
    }

    private void handleMOVEMInstruction(String[] tokens) {
        String symbol = tokens[2];

        if (!containsSymbol(symbol)) {
            addSymbol(symbol, locationCounter);
        }
    }

    private void handleLiteralInstruction(String[] tokens) {
        String literal = tokens[2];

        if (!containsLiteral(literal)) {
            addLiteral(literal, locationCounter);
        }
    }

    private void handleDSInstruction(String[] tokens) {
        // Nothing to do for DS instructions in pass 1
    }

    private boolean containsSymbol(String symbol) {
        for (int i = 0; i < symbolTable.length; i++) {
            if (symbolTable[i] != null && symbolTable[i].equals(symbol)) {
                return true;
            }
        }
        return false;
    }

    private void addSymbol(String symbol, int address) {
        for (int i = 0; i < symbolTable.length; i++) {
            if (symbolTable[i] == null) {
                symbolTable[i] = symbol;
                symbolTableAddresses[i] = address;
                break;
            }
        }
    }

    private boolean containsLiteral(String literal) {
        for (int i = 0; i < literalTable.length; i++) {
            if (literalTable[i] != null && literalTable[i].equals(literal)) {
                return true;
            }
        }
        return false;
    }

    private void addLiteral(String literal, int address) {
        for (int i = 0; i < literalTable.length; i++) {
            if (literalTable[i] == null) {
                literalTable[i] = literal;
                literalTableAddresses[i] = address;
                break;
            }
        }
    }

    private void printSymbolTable() {
        System.out.println("Symbol Table:");
        System.out.println("Symbol\tAddress");
        for (int i = 0; i < symbolTable.length; i++) {
            if (symbolTable[i] != null) {
                System.out.println(symbolTable[i] + "\t" + symbolTableAddresses[i]);
            }
        }
    }

    private void printLiteralTable() {
        System.out.println("Literal Table:");
        System.out.println("Literal\tAddress");
        for (int i = 0; i < literalTable.length; i++) {
            if (literalTable[i] != null) {
                System.out.println(literalTable[i] + "\t" + literalTableAddresses[i]);
            }
        }
    }


		public static void main(String[] args) {
			String[] assemblyLines = readAssemblyProgramFromFile("input.txt");
			Pass1Assembler assembler = new Pass1Assembler();
			assembler.assemble(assemblyLines);
		}
	
		private static String[] readAssemblyProgramFromFile(String fileName) {
			try (BufferedReader reader = new BufferedReader(new FileReader(input.txt))) {
				List<String> lines = new ArrayList<>();
				while ((line = reader.readLine()) != null) {
					lines.add(line);
				}
				return lines.toArray(new String[0]);
			} catch (IOException e) {
				System.err.println("Error reading file: " + e.getMessage());
				System.exit(1);
				return null;
			}
		}
		
	
	
}
