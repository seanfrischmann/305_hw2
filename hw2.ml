(*===========================================================================
 * +++hw2.ml+++|
 * ____________|
 *
 *Author: Sean Frischmann
 *Class: Cse 305
 *=========================================================================*)

fun print_stack([]) = ()
   | print_stack(stack) =
       let
         val temp = stack;
         val head = hd(temp);
         val tail = tl(temp);
       in
         print(head);
         print("\n");
         print_stack(tail);
      end;

fun hw2 =
    let
         val stack = [];
         val splitter = String.tokens (fn c => c = #" ");
         val buf = "";
         val input = "";
    in
         print("repl> ");
         buf = TextIO.inputLine TextIO.stdIn;
         input = splitter(buf);
         print(buf);
         print(input);
   end;
