class Main{
	public static void main(String arg[]){
		Ratio rat1 = new Ratio(4, 2);
		System.out.println("Ratio 1 : " + rat1);
		Ratio rat2 = new Ratio(5, 2);
		System.out.println("Ratio 2 : " + rat2 + "\n");
		
		System.out.println("Produit : " + rat1.produit(rat2));
		System.out.println("Addition : " + rat1.addition(rat2));
		System.out.println("Egalité : " + rat1.equals(rat2));
		System.out.println("Rat1 > Rat 2 ? : " + rat2.plusGrand(rat1));
	}
}
