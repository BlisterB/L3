type unop = Cos | Sin;;
type binop = Plus | Moins | Fois;;
type expr = 
		|Num of float
	    |Var of string
	    |Unop of unop * expr
	    |Binop of binop * expr * expr;;

(* Exercice 1 *)

let rec string_of_unop op = match op with
| Cos -> "cos"
| Sin -> "sin"
;;

let rec string_of_binop op = match op with
| Plus -> " + "
| Moins -> " - "
| Fois -> " * "
;;

(* Exercice 2 *)

let rec string_of_expr exp = match exp with
| Num (n) -> string_of_float n
| Var (s) -> s
| Unop (op,e)-> (string_of_unop op) ^ "(" ^ (string_of_expr e) ^ ")"
| Binop (op,e1,e2) -> "(" ^ (string_of_expr e1) ^ (string_of_binop op) ^ (string_of_expr e2) ^ ")"
;;

(*Exercice 3*)

let val_unop op = match op with
| Cos -> cos
| Sin -> sin
;;

let val_binop op= match op with
| Plus -> (+.)
| Moins -> (-.)
| Fois -> ( *.)
;;

(* Exercice 4 *)
let rec eval_expr l e = match e with
| Num n -> n
| Var v -> List.assoc v l
| Unop (op,e) -> (val_unop op) (eval_expr l e)
| Binop (op, e1, e2) -> (val_binop op) (eval_expr l e1) (eval_expr l e2)
;;

(* Exercice 5 *)

let rec eval_sous_expr e = match e with
| Num n -> Num(n)
| Var v  -> Var(v)
| Unop (op, Num f) -> Num((val_unop op) f)
| Unop (op, e) -> Unop(op, eval_sous_expr e)
| Binop (op, Num n1, Num n2) -> Num((val_binop op) n1 n2)
| Binop (op, e1, e2) -> Binop(op, eval_sous_expr e1, eval_sous_expr e2)
;;

(* Main *)
let e0 = Binop (Fois,
Unop (Cos, Binop(Plus, Var "x", Num 0.5)),
Binop(Moins, Var "theta", Num 2.));;
let e1 = Binop (Fois,
Unop (Cos, Binop(Plus, Var "x", Num 0.5)),
Binop(Moins, Num 3., Num 2.));;

print_string(string_of_expr e0 ^ "\n");;
let l = [("x", -0.5); ("theta", 4.)];;
print_string(string_of_float (eval_expr l e0) ^ "\n");;
print_string(string_of_expr (eval_sous_expr e1) ^ "\n");