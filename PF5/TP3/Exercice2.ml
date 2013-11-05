(*Les fonctions*)

let rec string_of_list l = match l with
| [] -> ""
| a::l' -> (string_of_int a) ^ (string_of_list l')
;;

let rec insert i l = match l with
| [] -> [i]
| a::l' -> 
	begin
		if a < i then a::(insert i l')
		else if a = i then a::l'
		else i::a::l'
	end
;;

let rec sort l = match l with
| [] -> []
| a::l' -> insert a (sort l')
;;

let rec union_sorted l1 l2 = match l1 with
| [] -> l2
| a::l' -> union_sorted l' (insert a (sort l2))
;;

let rec is_in_list v l = match l with
| [] -> false
| a::l -> if (a = v) then true else is_in_list v l
;;

let rec inter_sorted l1 l2 = match l1 with
| [] -> []
| a::l -> if (is_in_list a l2) then insert a (inter_sorted l l2) else inter_sorted l l2
;;

(*Le main*)

let l = [1; 2; 5; 9];;
print_string("La liste l est : " ^ string_of_list l ^ "\n\n");;

let i = 7;;
print_string("Ajout de " ^ string_of_int i ^ " dans l -> " ^ string_of_list(insert i l) ^ "\n");;

let l2 = [7;8;5;2;8];;
print_string("Trions la liste " ^ string_of_list l2 ^ " --> " ^ string_of_list(sort l2) ^ "\n");;

print_string("Union de " ^ string_of_list l ^ " et " ^ string_of_list l2 ^ " --> " ^ string_of_list (union_sorted l l2) ^ "\n");;

print_string("Intersection de " ^ string_of_list l ^ " et " ^ string_of_list l2 ^ " --> " ^ string_of_list (inter_sorted l l2) ^ "\n");;
