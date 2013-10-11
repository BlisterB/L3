(* Les fonctions *)

let rotation_g s = (String.sub s 1 ((String.length s) - 1)) ^ (String.sub s 0 1);;

let rotation_d s = (String.sub s ((String.length s) - 1) 1)  ^ (String.sub s 0 ((String.length s) - 1))

let rec iter_g s n = if (n >= 0) 
	then
		begin
			print_string(s);
			print_newline();
			iter_g (rotation_g s) (n-1);
		end;;

let rec iter_d s n = if (n >= 0) 
	then
		begin
			print_string(s);
			print_newline();
			iter_d (rotation_d s) (n-1);
		end;;

let enum_g s = iter_g s ((String.length s) - 1);;

let enum_d s = iter_d s ((String.length s) - 1);;

(* Main *)
let s = "abcdefg";;
(*Exercice 1*)
print_string ("Rotation gauche de " ^ s ^ " : " ^ (rotation_g s) ^ "\n");;
(*Exercice 2*)
print_string ("Rotation droite de " ^ s ^ " : " ^ (rotation_d s) ^ "\n\n");;
(*Exercice 3*)
let n = 5;;
print_string ("Exercice 3 : \nAppel de iter_g \"" ^ s ^ "\" "^ (string_of_int n) ^ " : \n");;
iter_g s n;;
print_string("\n");;
(*Exercice 4*)
print_string ("Exercice 4 : \nAppel de iter_d \"" ^ s ^ "\" "^ (string_of_int n) ^ " : \n");;
iter_d s n;;
print_string("\n");;
(*Exercice 5*)
print_string ("Exercice 5 : \nAppel de enum_g \"" ^ s ^ "\ :\n");;
enum_g s;;
print_string("\n");;
(*Exercice 6*)
print_string ("Exercice 6 : \nAppel de enum_d \"" ^ s ^ "\ :\n");;
enum_d s;;
print_string("\n");;
