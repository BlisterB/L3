(*Les fonctions*)

let rec string_of_list l = match l with
| [] -> ""
| a::l' -> (string_of_int a) ^ (string_of_list l')
;;

let rec insert i l = match l with
| [] -> [a]
| a::l' -> 
	begin
		if a < i then a::(insert i l')
		else if a = i then 1
		else i::a::l'
	end
;;

let rec sort 

(*Le main*)

let l = [1; 2; 5; 9];;
print_string("La liste l est : " ^ string_of_list ^ "\n\n");;

let i = 3;;
print_string("Ajout de " ^ string_of_int i ^ " dans l -> " ^ string_of_list(insert i l) ^ "\n");
