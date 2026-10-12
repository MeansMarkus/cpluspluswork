/*Problem

Write a function that checks whether the brackets in a string are balanced.

cpp
bool isBalanced(const std::string& s);

A string is balanced if:

Every opening bracket (, [, { has a matching closing bracket of the same type.
Brackets close in the correct order, so the most recently opened bracket closes first.
Any character that isn’t a bracket is ignored.
Examples
Input	Output	Why
"()"	true	Simple match
"([]{})"	true	Nested and sequential
"(]"	false	Wrong bracket type
"([)]"	false	Wrong closing order
"((("	false	Never closed
"int main() { return arr[0]; }"	true	Other characters are ignored
""	true	An empty string is balanced
Constraints
0 ≤ s.length() ≤ 10^5
Aim for O(n) time.
Use only the C++ standard library. */


#include <iostream>
#include <string>
#include <cassert>

bool isBalanced(const std::string& s) {
    std::string stack;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stack += c;
        } else if (c == ')' || c == ']' || c == '}') {
            if (stack.empty()) {
                return false;
            }

            const char opening = stack.back();
            stack.pop_back();

            if ((c == ')' && opening != '(') ||
                (c == ']' && opening != '[') ||
                (c == '}' && opening != '{')) {
                return false;
            }
        }
    }

    return stack.empty();
}

int main() {
    assert(isBalanced("()") == true);
    assert(isBalanced("([]{})") == true);
    assert(isBalanced("(]") == false);
    assert(isBalanced("([)]") == false);
    assert(isBalanced("(((") == false);
    assert(isBalanced("") == true);
    std::cout << "All tests passed!\n";
    return 0;
}

/*
Explanation:

This program checks whether brackets are balanced.

A string is balanced when:
1. Every opening bracket has a matching closing bracket.
2. The closing bracket has the correct type.
3. Brackets close in the reverse order in which they were opened.

For example:

    "([])" is balanced.

The brackets are opened in this order:

    (
    [

Therefore, they must be closed in the reverse order:

    ]
    )

The program uses a stack to remember opening brackets.

A stack follows the rule "last in, first out".
This means the most recently added item is removed first.
That is exactly how nested brackets must behave.

The std::string named "stack" is being used as a stack of characters.

These operations are used:

    stack += c;

Adds an opening bracket to the top of the stack.
This is the stack's "push" operation.

    stack.back();

Looks at the most recently added opening bracket.
This is the stack's "top" operation.

    stack.pop_back();

Removes the most recently added opening bracket.
This is the stack's "pop" operation.

    stack.empty();

Checks whether there are no unmatched opening brackets.

The function processes the input one character at a time.

If the character is an opening bracket, it is added to the stack:

    '(' -> push '('
    '[' -> push '['
    '{' -> push '{'

If the character is a closing bracket, the function first checks
whether the stack is empty. If it is empty, there is no opening bracket
available to match the closing bracket, so the string is invalid.

Otherwise, the function gets the opening bracket at the top of the
stack and removes it. The closing bracket must match that opening bracket:

    ')' must match '('
    ']' must match '['
    '}' must match '{'

If the types do not match, the function immediately returns false.

Characters that are not brackets are ignored. For example, letters,
spaces, numbers, and semicolons do not affect the stack.

After every character has been processed, the function checks whether
the stack is empty.

If the stack is empty:
    Every opening bracket was correctly closed, so the result is true.

If the stack is not empty:
    At least one opening bracket was never closed, so the result is false.

Example: "([)]"

1. Read '(' -> stack contains '('
2. Read '[' -> stack contains "(["
3. Read ')' -> the top is '[', but ')' requires '('
4. The brackets are mismatched, so return false

Example: "([]{})"

1. Read '(' -> stack contains "("
2. Read '[' -> stack contains "(["
3. Read ']' -> matches '['; remove '['
4. Read '{' -> stack contains "({"
5. Read '}' -> matches '{'; remove '{'
6. Read ')' -> matches '('; remove '('
7. The stack is empty, so return true

Complexity:

The input is scanned once, so the time complexity is O(n), where n is
the length of the string.

In the worst case, the stack can contain all opening brackets, so the
space complexity is O(n).
*/