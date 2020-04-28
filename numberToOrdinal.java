/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/

public class Main
{
	public static void main(String[] args) {
	   
	 /*  int i = 55;
	   String result;
	   result = Integer.ToString(i) ; //+ "th"
		System.out.println(result);  */
		
    int a = 1213;
    String suffix = "th" ;
    
    if ( a == 0)
        suffix = "";
    else 
    {
        if (isTeenNumber(a))
        suffix = "teen" ;
        else
             {
                if (a % 10 == 1)
                    suffix = "st" ;
                else
                {
                    if (a % 10 == 2)
                        suffix = "nd" ;
                    else
                    {
                         if (a % 10 == 3)
                            suffix = "rd" ;
                         else 
                         {
                            suffix = "th";
                         }
                    }
                }
             }
             
    }
    
    System.out.println(Integer.toString(a) + suffix); 
		
	}
	
	
	static boolean isTeenNumber(int i) {
        int last_digit = i % 10;
        int second_last_digit =  (i % 100) / 10;
        System.out.println (last_digit);
        System.out.println (second_last_digit);
        
        
        if (second_last_digit != 1)
            return false;
        else
        {
            if (last_digit==1 ||last_digit==2 ||last_digit==3)
            return true;
            else
            return false;
        }
    }
}
