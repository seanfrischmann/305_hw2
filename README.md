305_hw2
=======
Write an interactive Read-Eval-Print-Loop (REPL) for the language described below. The 
REPL reads an expression, evaluates it and pushes the result onto a stack, and prints the contents 
of the stack. The language will be revealed to you in part in this homework, and in part in the 
third homework. For this homework it must handle the following expressions: 
    • Numbers (sequences of digits, possibly with a leading ‘-’) are expressions. A number 
    expression is evaluated to its base 10 interpretation. A digit sequence with a leading ‘-’ 
    denotes a negative number (or zero, though ‘-0’ must be represented as ‘0’). A digit 
    sequence without a leading ‘-’ denotes a positive number (or zero). The value is pushed 
    onto the stack. 
    • Boolean literals (:true: and :false:) are expressions. :true: evaluates to :true:, and 
    :false: to :false: The value is pushed onto the stack. 
    • Error literal (:error:) is an expression. :error: evaluates to :error: The value is 
    pushed onto the stack. 
    • String literals are expressions. A string consists of a sequence of characters enclosed in 
    double quotation marks, as in "this is a string". Double quotes cannot appear inside 
    a string. A string expression evaluates to itself. The value is pushed onto the stack. 
    • Names (sequences of letters and digits, starting with a letter) are expressions. A name 
    expression is evaluated by looking the name up in the environment (see the ‘bind’ section 
    below). If the name is bound in the environment the value it is bound to the value of the 
    name expression. If the name is not found, the value of the name is the name itself. The
    value is pushed onto the stack. 
    • Applications of primitive functions. Only these primitive functions need be supported: 
    add, sub, mul, div, rem and neg. They refer to the integer addition, subtraction, 
    multiplication, division, remainder and negation operations. A primitive function is 
    applied by calling ‘native’ code to perform the operation (i.e. code you define in your 
    interpreter). 
        o The primitive operators add, sub, mul, div and rem are binary and therefore 
        consume the top two values from the stack, pushing the result1
         (a single value) 
        onto the stack. If there are not two values on the stack, or if the two values on the 
        stack are not both numbers, the value :error: is pushed onto the stack. In the 
        case that an error results2
        , any values popped off the stack must be pushed back 
        on the stack, in the same order, before :error: is pushed onto the stack. 
        o The operator neg is unary and therefore consumes the top value from the stack, 
        pushing the result (a single value) onto the stack. If there isn’t a numeric value on 
        the stack (i.e. the stack is empty or a non-number is on the stack) the value 
        :error: is pushed onto the stack. In the case that an error results, any value 
        popped off the stack must be pushed back on before :error: is pushed onto the 
        stack. 
    • bind binds a name to a value. 
        o bind is evaluated by popping two values from the stack. The second value 
        popped must be a name. The name is bound to the value (the first thing popped 
        off the stack): the name-value binding is stored in the ‘environment’ data structure 
        (see the ‘Names’ section above). The value that the name was bound to is pushed 
        onto the stack. 
        o If there are not two values on the stack, or if the second value is not a name, the 
        value :error: is pushed onto the stack. In the case that an error results, any 
        values popped off the stack must be pushed back on the stack, in the same order, 
        before :error: is pushed onto the stack. 
    • load is evaluated by popping one value from the stack, which must be a string denoting a 
    path, absolute or relative, to a file. The REPL evaluates expressions from the file popping 
    and pushing results as indicated by these rules. The value :true: is pushed onto the stack 
    if the contents of the file loads properly; if there is any error during loading (either because 
    the file does not exist or the contents of the file is not parsable according to these rules, 
    :error: is pushed onto the stack. 
    • pop removes the top element from the stack. If the stack is empty an error occurs and 
    :error: is pushed onto the stack. 
    • exc interchanges the top two values on the stack. If the stack is empty an error occurs and 
    :error: is pushed onto the stack. 
    • quit exits the repl. 
The prompt of your repl must be ‘repl>’. The repl must print the contents of the stack after each 
full line of code it evaluates (see examples below). If input is encountered that is not handled by 
the rules listed above, :error: is pushed onto the stack and evaluation continues with the next 
expression. Expressions must be separated by whitespace in the input stream (e.g. space, 
newline, tab).
