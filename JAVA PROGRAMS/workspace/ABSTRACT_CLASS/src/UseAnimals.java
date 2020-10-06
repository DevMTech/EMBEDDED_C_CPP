
public class UseAnimals 
{
	public static void main(String[] args)
	{
		Dog myDog = new Dog();
		Cow myCow = new Cow();
		Cat myCat = new Cat();
		myDog.setName("My dog Murphy");
		myCow.setName("My cow Elsie");
		myCat.setName("My cat Mini");
		System.out.print(myDog.getName() + " says ");
		myDog.speak();
		System.out.print(myCow.getName() + " says ");
		myCow.speak();
		System.out.print(myCat.getName() + " says ");
		myCat.speak();
		
		
		Animal Dog1 = new Dog();
		Animal Cow1 = new Cow();
		Animal Cat1 = new Cat();
		
		Dog1.setName("Doggy");
		Cat1.setName("Catty");
		Cow1.setName("Guy");
		
		System.out.print("\n"+Dog1.getName() + " says ");
		Dog1.speak();
		System.out.print(Cat1.getName() + " says ");
		Cat1.speak();
		System.out.print(Cow1.getName() + " says ");
		Cow1.speak();
	}
}