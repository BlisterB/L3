public class Triangle extends Figure{
	private int base, hauteur;
	
	
	public Triangle(int x, int y, int base, int hauteur){
		super(x, y);
		this.base = base;
		this.hauteur = hauteur;
	}
	
	public void affiche(){
		System.out.printf("Triangle\nCentre : (%d,%d)\nBase : %d\nHauteur : %d\n", this.getPosX(), this.getPosY(), base, hauteur);
	}
	
	public int getBase(){ return base;}
	
	public int getHauteur(){ return hauteur;}
	
	public Figure 
}
