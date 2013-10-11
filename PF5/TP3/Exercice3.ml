(* FONCTIONS *)

let rec list_sigma l = match l with
| [] -> 0
| a::l' -> a + (list_sigma l')
;;

let rec mem l v = match l with
| [] -> false
| a::l' -> if(a=v) then true else (mem l' v)
;;

let rec map f l = match l with
| [] -> []
| a::l' -> (l, a)::map f l'
;;

let rec string_of_list l = match l with
| [] -> ""
| a::l' -> string_of_int(a) ^ ", " ^ (string_of_list l')
;;

(* MAIN *)

let l = [1; 2; 3; 4; 5];;

(*1*)
print_string("Exercice 1 : " ^ string_of_int(list_sigma l) ^ "\n");;

(*2*)
print_string("Exercice 2 : " ^ string_of_bool(mem l 42) ^ "\n");;

(*3*)
print_string("Exercice 3 : " ^ string_of_list(let succ x = x + 1 in (map succ [1;2;3])) ^ "\n");;
