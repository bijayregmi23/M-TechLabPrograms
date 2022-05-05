from ply import lex
from operator import add, sub, mul, truediv, lt, gt, eq, ne, le, ge


# For the homework, uncomment the import below
# from operator import lt, gt, eq, ne, le, ge


# List of token names - required
tokens = ('LT', 'GT',
          'LTE', 'GTE',
          'EQ', 'NE',
          'AND', 'OR',
          'NOT', 'BOOL',
          'FLOAT', 'INT',
          'ADD_OP', 'MULT_OP',
          'LPAREN', 'RPAREN',
          'false', 'true')


# global variables
token = None
lexer = None
parse_error = False


# Regular expression rules for simple tokens
# r indicates a raw string in Python - less backslashes
t_ADD_OP = r'\+|-'
t_MULT_OP = r'\*|/'
t_LPAREN = r'\('
t_RPAREN = r'\)'


# Regular expression rules with some action code
# The order matters
def t_FLOAT(t):
    r'\d*\.\d+|\d+\.\d*'
    t.value = float(t.value)  # string must be converted to float
    return t


def t_INT(t):
    r'\d+'
    t.value = int(t.value)  # string must be converted to int
    return t


# For the homework, you will add a function for boolean tokens
# A string containing ignored characters (spaces and tabs)
t_ignore = ' \t'
t_true = 'TRUE'
t_false = 'FALSE'


# Lexical error handling rule
def t_error(t):
    global parse_error
    parse_error = True
    print("ILLEGAL CHARACTER: {}".format(t.value[0]))
    t.lexer.skip(1)


# For homework 2, add the comparison operators to this dictionary
SUPPORTED_OPERATORS = {'+': add, '-': sub, '*': mul, '/': truediv,
                       '<': lt, '>': gt, '==': eq, '<=': le, '>=': ge, '!=': ne}


def command():
    """
    <command> ::= <arith_expr>
    """
    result = arith_expr()
    if not parse_error:  # no parsing error
        if token:  # if there are more tokens
            error('END OF COMMAND OR OPERATOR')
        else:
            print(result)


def bool_expr():
    """
    <bool_expr> ::= <bool_term> {OR <bool_term>}
    """
    result = bool_term()
    while token and token.type == 'OR':
        operation = SUPPORTED_OPERATORS[token.value]
        match()  # match the operator
        operand = bool_term()  # evaluate the operand
        if not parse_error:
            result = operation(result, operand)
    return result


def bool_term():
    """
    <bool_term> ::= <not_factor> {AND <not_factor>}
    """
    result = not_factor()
    while token and token.type == 'AND':
        operation = SUPPORTED_OPERATORS[token.value]
        match()  # match the operator
        operand = not_factor()  # evaluate the operand
        if not parse_error:
            result = operation(result, operand)
    return result


def not_factor():
    """
    <not_factor> ::= <{NOT} <bool_factor>
    """
    result = bool_factor()


def bool_factor():
    """
    <bool_factor> BOOL | LPAREN <bool_expr> RPAREN | <comparsion>
    """
    if token and token.type == 'BOOL':
        match()
        return result
        if token and token.type == 'LPAREN':
            match()
            return bool_expr()
        else:
            error(')')
        if token and token.type == 'RPAREN':
            match()
            return result


def comparisons():
    """
    <comparison> ::= <arith_expr> [COMP_OP <arith_expr>]
    """
    result = arith_expr()
    while token and token.type == 'COMP_OP':
        operation = SUPPORTED_OPERATORS[token.value]
        match()  # match the operator
        operand = arith_expr()  # evaluate the operand
        if not parse_error:
            result = operation(result, operand)
    return eval()


def arith_expr():
    """
    <arith_expr> ::= <term> { ADD_OP <term>}
    """
    result = term()
    while token and token.type == 'ADD_OP':
        operation = SUPPORTED_OPERATORS[token.value]
        match()  # match the operator
        operand = term()  # evaluate the operand
        if not parse_error:
            result = operation(result, operand)
    return result


def term():
    """
    <term> ::= <factor> {MULT_OP <factor>}
    """
    result = factor()
    while token and token.type == 'MULT_OP':
        operation = SUPPORTED_OPERATORS[token.value]
        match()  # match the operator
        operand = factor()  # evaluate the operand
        if not parse_error:
            result = operation(result, operand)
    return result


def factor():
    """
    <factor>::= LPAREN <arith_expr> RPAREN | FLOAT | INT
    """
    if token and token.type == 'LPAREN':
        match()
        result = arith_expr()
        if token and token.type == 'RPAREN':
            match()
            return result
        else:
            error(')')
    elif token and (token.type == 'FLOAT' or token.type == 'INT'):
        result = token.value
        match()
        return result
    else:
        error('NUMBER')


def match():
    """
    Get the next token
    """
    global token
    token = lexer.token()


def error(expected):
    """
    Print an error message when an unexpected token is encountered, sets
    a global parse_error variable.
    :param expected: (string) '(' or 'NUMBER' or or ')' or anything else...
    :return: None
    """
    global parse_error
    if not parse_error:
        parse_error = True
        print('Parser error')
        print("Expected:", expected)
        if token:
            print('Got: ', token.value)
            print('line', token.lineno, 'position', token.lexpos)


def main():
    global token
    global lexer
    global parse_error
    # Build the lexer
    lexer = lex.lex()
    # Prompt for a command
    more_input = True
    while more_input:
        input_command = input("Pluto 2.0>>>")
        if input_command == 'q':
            more_input = False
            print('Bye for now')
        elif input_command:
            parse_error = False
            # Send the command to the lexer
            lexer.input(input_command)
            token = lexer.token()  # Get the first token in a global variable
            command()


if __name__ == '__main__':
    main()
