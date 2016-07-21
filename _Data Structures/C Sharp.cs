using System;
using System.Collections;           // Stack + Queue
using System.Collections.Generic;   // Dictionary

public class Program
{
  public static void Main(string[] args)
  {
    
    Dictionary<char, int> dict = new Dictionary<char, int>();
	dict.Add('n', 2);
    dict.ContainsKey('n');
	char key = 'n';
    dict[key] = 324;

    string[] names = new string[2];
    int[] numbers = new int[5] { 4, 3, 8, 0, 5 };

    Stack<string> s = new Stack<string>();
    s.Push("{");
    s.Pop();
    s.Peek();
    Queue<string> numbers = new Queue<string>();
    numbers.Enqueue("one");
    numbers.Enqueue("two");
    numbers.Enqueue("three");
    numbers.Enqueue("four");
    numbers.Enqueue("five");
    numbers.Peek();
    Queue<string> queueCopy = new Queue<string>(numbers.ToArray());

    Console.Write(" " + var);
    Console.WriteLine("");
    int line;
    line = int.Parse(Console.ReadLine());

    public enum Days { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday }
    Days day = Days.Monday;

    ArrayList list = new ArrayList();
    list.Add("John Doe");
    list.Add("Jane Doe");
    list.Add("Someone Else");
    foreach (string name in list)
      Console.WriteLine(name);
  }

  abstract class FourLeggedAnimal
  {
    public abstract string Describe();
    public int AgeInMonths { get; set; }    // Property
  }


  class Dog : FourLeggedAnimal
  {

    public override string Describe()
    {
      return "I'm a dog!";
    }
  }

  class Cat : FourLeggedAnimal
  {
    public override string Describe()
    {
      return "I'm a cat!";
    }
  }
}




#region Instructions
/*
 * You are tasked with writing an algorithm that determines the value of a used car, 
 * given several factors.
 * 
 *    AGE:    Given the number of months of how old the car is, reduce its value one-half 
 *            (0.5) percent.
 *            After 10 years, it's value cannot be reduced further by age. This is not 
 *            cumulative.
 *            
 *    MILES:    For every 1,000 miles on the car, reduce its value by one-fifth of a
 *              percent (0.2). Do not consider remaining miles. After 150,000 miles, it's 
 *              value cannot be reduced further by miles.
 *            
 *    PREVIOUS OWNER:    If the car has had more than 2 previous owners, reduce its value 
 *                       by twenty-five (25) percent. If the car has had no previous  
 *                       owners, add ten (10) percent of the FINAL car value at the end.
 *                    
 *    COLLISION:        For every reported collision the car has been in, remove two (2) 
 *                      percent of it's value up to five (5) collisions.
 *                    
 * 
 *    Each factor should be off of the result of the previous value in the order of
 *        1. AGE
 *        2. MILES
 *        3. PREVIOUS OWNER
 *        4. COLLISION
 *        
 *    E.g., Start with the current value of the car, then adjust for age, take that  
 *    result then adjust for miles, then collision, and finally previous owner. 
 *    Note that if previous owner, had a positive effect, then it should be applied 
 *    AFTER step 4. If a negative effect, then BEFORE step 4.
 */
#endregion

using System;
using NUnit.Framework;

namespace CarPricer
{
    class Program
    {
        static void Main(string[] args)
        {
            UnitTests uTest = new UnitTests();
            uTest.CalculateCarValue();
        }
    }

    public class Car
    {
        public decimal PurchaseValue { get; set; }
        public int AgeInMonths { get; set; }
        public int NumberOfMiles { get; set; }
        public int NumberOfPreviousOwners { get; set; }
        public int NumberOfCollisions { get; set; }
    }

    public class PriceDeterminator
    {
        public decimal DetermineCarPrice(Car car)
        {
            decimal reducedValue        = car.PurchaseValue;
            const int MAX_MONTHS        = 10 * 12;
            const int MAX_MILES         = 150000;
            const int MAX_OWNERS        = 2;
            const int MAX_COLLISIONS    = 5;

            //  AGE:    
            //      Given the number of months of how old the car is, reduce its value one-half (0.5) percent.
            //      After 10 years, it's value cannot be reduced further by age. This is not cumulative.
            
            int ageIterator = ((car.AgeInMonths < MAX_MONTHS) ? car.AgeInMonths : MAX_MONTHS);
            for (int i = ageIterator; i > 0; i--)
            {
                reducedValue -= car.PurchaseValue * 0.005m;
            }

            //  MILES:    
            //      For every 1,000 miles on the car, reduce its value by one-fifth of a  percent (0.2). 
            //      Do not consider remaining miles. 
            //      After 150,000 miles, it's value cannot be reduced further by miles.
            
            int milesMult = ((car.NumberOfMiles < MAX_MILES) ? (car.NumberOfMiles / 1000) : (MAX_MILES / 1000));
            reducedValue -= reducedValue * (milesMult * 0.002m);

            //  PREVIOUS OWNER:    
            //      If the car has had more than 2 previous owners, reduce its value by twenty-five (25) percent.
            
            if (car.NumberOfPreviousOwners > MAX_OWNERS)
            {
                reducedValue -= reducedValue * 0.25m;
            }

            //  COLLISION:        
            //      For every reported collision the car has been in, remove two (2) percent of it's value up 
            //      to five (5) collisions.  
            
            int collisionMult = ((car.NumberOfCollisions < MAX_COLLISIONS) ? car.NumberOfCollisions : MAX_COLLISIONS);
            reducedValue -= reducedValue * (collisionMult * 0.02m);

            //  PREVIOUS OWNER:   
            //      If the car has had no previous owners, add ten (10) percent of the FINAL car value at the end.  
            
            if (car.NumberOfPreviousOwners == 0)
            {
                reducedValue += reducedValue * 0.10m;
            }

            return Math.Round(reducedValue, 2);
        }
    }


    public class UnitTests
    {
        public void CalculateCarValue()
        {
            AssertCarValue(25313.40m, 35000m, 3 * 12, 50000, 1, 1);
            AssertCarValue(19688.20m, 35000m, 3 * 12, 150000, 1, 1);
            AssertCarValue(19688.20m, 35000m, 3 * 12, 250000, 1, 1);
            AssertCarValue(20090.00m, 35000m, 3 * 12, 250000, 1, 0);
            AssertCarValue(21657.02m, 35000m, 3 * 12, 250000, 0, 1);
        }

        private static void AssertCarValue(decimal expectValue, decimal purchaseValue,
        int ageInMonths, int numberOfMiles, int numberOfPreviousOwners, int
        numberOfCollisions)
        {
            Car car = new Car
            {
                AgeInMonths = ageInMonths,
                NumberOfCollisions = numberOfCollisions,
                NumberOfMiles = numberOfMiles,
                NumberOfPreviousOwners = numberOfPreviousOwners,
                PurchaseValue = purchaseValue
            };
            PriceDeterminator priceDeterminator = new PriceDeterminator();
            var carPrice = priceDeterminator.DetermineCarPrice(car);
            Assert.AreEqual(expectValue, carPrice);
        }
    }
}