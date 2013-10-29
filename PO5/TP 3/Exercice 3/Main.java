class Main{
	public static void main(String arg[]){
		Ensemble ens = new Ensemble();

		ens.ajoute(3);
		ens.ajoute(1);
		ens.ajoute(4);
		
		Ensemble ens2 = new Ensemble();
		
		ens2.ajoute(1);
		ens2.ajoute(2);
		ens2.ajoute(5);
		
		System.out.println(ens.toString());
		System.out.println(ens2.toString());
		ens.diff(ens2);
		
		System.out.println(ens.toString());
	}
}
