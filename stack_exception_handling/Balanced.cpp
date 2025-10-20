// filename: Balanced.cpp
#include "StackType.h"
// #include "StackType.cpp"
#include <iostream>
using namespace std;

bool IsOpen(char symbol);
bool IsClosed(char symbol);
bool Matches(char symbol, char openSymbol);

int main()
{
  //  using namespace std;
  char symbol;
  StackType stack;
  bool balanced = true;
  char openSymbol;

  cout << "Enter an expression and press return." << endl;
  cin.get(symbol);
  while (symbol != '\n' && balanced)
  {
    try
    {
      if (IsOpen(symbol))
        stack.Push(symbol);

      else if (IsClosed(symbol))
      {
        if (stack.IsEmpty())
          balanced = false;
        else
        {
          openSymbol = stack.Top();
          // pop topmost and make room for the next comparison
          stack.Pop();
          // Check is the topmost and latest symbol matches closing sym
          balanced = Matches(symbol, openSymbol);
          // if balance is false, it stops reading values
        }
      }
    }

    catch (FullStack)
    {
      cout << "Stack is full. \n Expression is not well formed." << endl;
      return 1;
    }
    catch (EmptyStack)
    {
      balanced = false;
    }
    cin.get(symbol);
  }

  // Check for the end comparison that does not return into the while loop
  if (!stack.IsEmpty())
  {
    balanced = false; 
  };

  if (balanced)
    cout << "Expression is well formed." << endl;
  else
    cout << "Expression is not well formed." << endl;
  return 0;
}

bool IsOpen(char symbol)
{
  if ((symbol == '(') || (symbol == '{') || (symbol == '['))
    return true;
  else
    return false;
}

bool IsClosed(char symbol)
{
  if ((symbol == ')') || (symbol == '}') || (symbol == ']'))
    return true;
  else
    return false;
}

bool Matches(char symbol, char openSymbol)
{
  return (((openSymbol == '(') && symbol == ')') || ((openSymbol == '{') && symbol == '}') || ((openSymbol == '[') && symbol == ']'));
}