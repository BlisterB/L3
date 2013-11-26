class Monnaie extends Number{
	private int valeur;

	public Monnaie(int euro, int centimes){
		valeur = 0;
		valeur = euro * 100 + centimes;
	}

	//Redefinision des méthodes
	public byte byteValue(){
		return (byte)(valeur/100);
	}

	public double doubleValue(){
		return (double)valeur/100;
	}

	public float floatValue(){
		return (float)valeur/100;
	}

	public int intValue(){
		return (int)(valeur/100);//Le resultat est déjà un entier, mais je prevois un eventuel changement d'implementation
	}

	public long longValue(){
		return (long)(valeur/100);
	}

	public short shortValue(){
		return (short)(valeur/100);
	}

	//Methode

	public static long sommeTab(Number[] tab){
		long somme = 0;
		for(int i =0; i < tab.length; i++){
			somme += tab[i].longValue();
		}
		return somme;
	}

	//Main
	public static void main(String[] arg){
		Monnaie m = new Monnaie(42,8);
		System.out.println("byte : " + m.byteValue());
		System.out.println("double : " + m.doubleValue());
		System.out.println("float : " + m.floatValue());
		System.out.println("int : " + m.intValue());
		System.out.println("long : " + m.longValue());
		System.out.println("short : " + m.shortValue());
	}
}